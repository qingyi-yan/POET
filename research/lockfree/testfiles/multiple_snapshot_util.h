
#define CONFLICT_HANDLE goto retry;

template <class wrapper_type, class value_type>
struct Template_ModifyLog
{
    wrapper_type**   addr;
    wrapper_type*    old_val;
    value_type       new_val;
};

struct GarbageCollector;

std::atomic<synobj_t*> state_array[MAX_N_SNAPSHOT];
GarbageCollector* gc_array[MAX_N_SNAPSHOT];

template <class wrapper_type, class value_type>
struct Template_Synobj
{
    GarbageCollector *parent_gc;
    void* parent_obj;
    int obj_block_id;
    int version_number;
#ifdef ENABLE_REVALIDATION
    void* read_set[READ_NUM];
    int read_num;
    int max_read_num;
    int base_version;
    int copy_version;
#endif


    typedef Template_ModifyLog<wrapper_type,value_type> ModifyLog;
    ModifyLog logs[LOG_NUM];
    volatile int log_num;
    int total_log_num;

    Template_Synobj() {
        version_number = -1;
        log_num = 0;
        total_log_num = 0;
#ifdef ENABLE_REVALIDATION
        read_num = 0;
        max_read_num = READ_NUM;
#endif
    }

    void insert_mod(wrapper_type** addr, wrapper_type* old_val, value_type new_val) {
        for (int i = 0; i < log_num; i++) {
          if (logs[i].addr == addr) {
            logs[i].new_val = new_val;
            return;
          }
        }
        logs[log_num].addr = addr;
        logs[log_num].old_val = old_val;
        logs[log_num].new_val = new_val;
        log_num ++;
        total_log_num = log_num;
    }

    void apply_mod () {
        if (log_num == 0) return;
printf("shoudn't call apply_mod\n");
exit(0);
        parent_gc->conflict_array->publish(parent_obj, version_number);

        int gc_idx = parent_gc->get_gc_idx();
        wrapper_type* new_val = parent_gc->wrapper_to_reuse[gc_idx]->front();

        for (int i = 0; i < log_num; i++) {
            std::atomic<wrapper_type*>* tmp_atomic = reinterpret_cast<std::atomic<wrapper_type*>*>(logs[i].addr);
            wrapper_type* old_val = logs[i].old_val;
            new_val->value = logs[i].new_val;
#ifdef ENABLE_REVALIDATION
            new_val->version = version_number;
#endif
            if (tmp_atomic->load() == old_val) {
                bool ret = std::atomic_compare_exchange_weak(tmp_atomic,&old_val,new_val);
                if(ret) parent_gc->wrapper_to_reuse[gc_idx]->pop();
            }
        }
        log_num = 0;
    }

    void reclaim_wrappers() {
#ifdef ENABLE_MEM_REUSE
        if (log_num == 0) return;
        wrapper_type* old_wrapper;
        int gc_idx = parent_gc->get_gc_idx();
        for (int i = 0; i < total_log_num; i++) {
          old_wrapper = logs[i].m_data_old;
          if (old_wrapper != 0) {
            parent_gc->wrapper_to_reuse[gc_idx]->push(old_wrapper);
          }
        }
#endif
        log_num = 0;
    }

    Template_Synobj<wrapper_type,value_type>& operator =(Template_Synobj<wrapper_type,value_type>& that) {
        that.apply_mod();
        this->version_number = that.version_number + 1;
        this->log_num = 0;
        this->total_log_num = 0;
#ifdef ENABLE_REVALIDATION
        this->copy_version = that.version_number;
        this->base_version = that.version_number;
        this->read_num = 0;
#endif
        return *this;
    }

    Template_Synobj<wrapper_type,value_type>& reload(Template_Synobj<wrapper_type,value_type>& that) {
#ifdef ENABLE_REVALIDATION
        that.apply_mod();
        this->version_number = that.version_number + 1;
        this->copy_version = that.version_number;
#endif
        return *this;
    }

};

// conflict array
struct ConflictArray {
    volatile void* ringbuffer[CONFLICT_ARRAY_SIZE];
    void publish (void *item, int idx) {
        ringbuffer[idx] = item;
    }
};

template <class U>
struct GC_SynObj_Queue {
    GarbageCollector *parent_gc;
    struct GC_Block {
        int block_id;
        U* elems;
        GC_Block() {
            elems = new U [GC_BLOCK_SIZE];
        }
    };

    int head_block_i;
    int tail_block_i;

    GC_Block* blocks[GC_BLOCK_NUM];
    U* cur_block;
    int cur_local_idx;
    int cur_block_id;

    GC_SynObj_Queue (GarbageCollector *p_gc) {
        parent_gc = p_gc;
        head_block_i = 0;
        tail_block_i = 0;
        GC_Block *new_block = new struct GC_Block;
#ifdef ENABLE_MEM_REUSE
        new_block->block_id = parent_gc->block_count ++;
#endif
        blocks[tail_block_i] = new_block;
        cur_block = new_block->elems;
        cur_local_idx = 0;
        cur_block_id = 0;
    }

    inline void allocate_block() {
        GC_Block *new_block = 0;
#ifdef ENABLE_MEM_REUSE
        if (tail_block_i > head_block_i) {
            int head_block_id = blocks[head_block_i]->block_id;
            int thread_num = parent_gc->thread_count.load();
            int i;
            for (i = 0; i < thread_num; i++) {
                if (head_block_id >= parent_gc->activity_array[i]-1000) {
                    break; // cannot be reused
                }
            }

            if (i == thread_num) { // can be reused
                new_block = blocks[head_block_i];
                head_block_i ++;
            }
        }
        if (new_block == 0)
#endif
            new_block = new struct GC_Block;
        tail_block_i ++;
        blocks[tail_block_i] = new_block;
#ifdef ENABLE_MEM_REUSE
        new_block->block_id = parent_gc->block_count ++;
#endif
        cur_block = new_block->elems;
        cur_local_idx = 0;
        cur_block_id = new_block->block_id;
    }

    inline U* pop() {
        if (cur_local_idx == GC_BLOCK_SIZE-1) {
            allocate_block();
        }
        int local_idx = cur_local_idx ++;
        return &cur_block[local_idx];
    }

};

template <class U>
struct GC_Queue {
    int elem_num;
    U* elems;

    int reclaim_elem_num;
    int reclaim_elem_max;
    U** reclaim_elems;

    bool use_reclaim_elems;

    GC_Queue () {
        elem_num = GC_BLOCK_SIZE;
        elems = new U [GC_BLOCK_SIZE];
        reclaim_elem_num = 0;
        reclaim_elem_max = 2*GC_BLOCK_SIZE;
        reclaim_elems = new U* [reclaim_elem_max];
        use_reclaim_elems = false;
    }
#ifdef ENABLE_MEM_REUSE
    inline void push (U *item) {
        if (reclaim_elem_num < reclaim_elem_max) {
            reclaim_elems[reclaim_elem_num] = item;
            reclaim_elem_num ++;
            if (reclaim_elem_num == reclaim_elem_max) {
                use_reclaim_elems = true;
            }
        }
    }
#endif
    inline U* front() {
#ifdef ENABLE_MEM_REUSE
        if (use_reclaim_elems) {
            if (reclaim_elem_num == 0) {
                use_reclaim_elems = false;
            } else {
                return reclaim_elems[reclaim_elem_num-1];
            }
        }
#endif
        if (elem_num == 0) {
            elem_num = GC_BLOCK_SIZE;
            elems = new U [GC_BLOCK_SIZE];
        }
        return &elems[elem_num-1];
    }
    inline void pop() {
#ifdef ENABLE_MEM_REUSE
        if (use_reclaim_elems) {
            reclaim_elem_num --;
        } else {
            elem_num --;
        }
#else
        elem_num --;
#endif
    }
};


struct GarbageCollector {
    ConflictArray *conflict_array;
#ifdef ENABLE_MEM_REUSE
    std::atomic<int> block_count;
    volatile int activity_array[GC_MAX_THREADS];
#endif

    static std::atomic<int> thread_count;
    static GC_SynObj_Queue<synobj_t> *obj_to_reuse[GC_MAX_THREADS];
    static GC_Queue<wrapper_t> *wrapper_to_reuse[GC_MAX_THREADS];
#ifdef ENABLE_GC_NODE_ALLOCATOR
    static GC_Queue<gc_node_t> *node_to_reuse[GC_MAX_THREADS];
#endif
    static synobj_t *read_obj[GC_MAX_THREADS];
    static synobj_t *old_obj[GC_MAX_THREADS];
    static synobj_t *new_obj[GC_MAX_THREADS];

    synobj_t *allocate_synobj(int gc_idx) {
      synobj_t *res_obj;
      res_obj = obj_to_reuse[gc_idx]->pop();
      res_obj->synobj.parent_gc = this;
      res_obj->synobj.parent_obj = res_obj;
      res_obj->synobj.obj_block_id = obj_to_reuse[gc_idx]->cur_block_id;
      res_obj->reclaim_wrappers();
      return res_obj;
    }

#ifdef ENABLE_GC_NODE_ALLOCATOR
    gc_node_t *allocate_node(int gc_idx) {
      gc_node_t *res_node;
      res_node = node_to_reuse[gc_idx]->front();
      node_to_reuse[gc_idx]->pop();
      return res_node;
    }
#endif
    GarbageCollector () {
      conflict_array = new ConflictArray;
    }

    inline int get_gc_idx () {
      if (local_gc_idx == -1) {
        int local_idx = thread_count.fetch_add(1);

        read_obj[local_idx] = new synobj_t;
        read_obj[local_idx]->synobj.parent_gc = this;
        obj_to_reuse[local_idx] = new GC_SynObj_Queue<synobj_t>(this);
        wrapper_to_reuse[local_idx] = new GC_Queue<wrapper_t>();

#ifdef ENABLE_GC_NODE_ALLOCATOR
        node_to_reuse[local_idx] = new GC_Queue<gc_node_t>();
#endif
        local_gc_idx = local_idx;
      }
      return local_gc_idx;
    }
};


inline int get_gc_idx() {
  if (local_gc_idx == -1) {
    int local_idx = GarbageCollector::thread_count.fetch_add(1);

    GarbageCollector::read_obj[local_idx] = new synobj_t;
    GarbageCollector::read_obj[local_idx]->synobj.parent_gc = gc_array[0];
    GarbageCollector::obj_to_reuse[local_idx] = new GC_SynObj_Queue<synobj_t>(gc_array[0]);
    GarbageCollector::wrapper_to_reuse[local_idx] = new GC_Queue<wrapper_t>();
#ifdef ENABLE_GC_NODE_ALLOCATOR
    GarbageCollector::node_to_reuse[local_idx] = new GC_Queue<gc_node_t>();
#endif
    local_gc_idx = local_idx;
  }
  return local_gc_idx;
}

inline synobj_t *allocate_synobj() {
  int gc_idx = get_gc_idx();
  GarbageCollector* gc = gc_array[snapshot_idx];
  gc->new_obj[gc_idx] = gc->allocate_synobj(gc_idx);
  return gc->new_obj[gc_idx];
}

#ifdef ENABLE_GC_NODE_ALLOCATOR
inline gc_node_t *allocate_node() {
  int gc_idx = get_gc_idx();
  GarbageCollector* gc = gc_array[snapshot_idx];
  return gc->allocate_node(gc_idx);
}
#endif

inline synobj_t *get_read_synobj() {
  int gc_idx = get_gc_idx();
  GarbageCollector* gc = gc_array[snapshot_idx];
  return gc->read_obj[gc_idx];
}

inline synobj_t *get_old_synobj() {
  int gc_idx = get_gc_idx();
  GarbageCollector* gc = gc_array[snapshot_idx];
  return gc->old_obj[gc_idx];
}

inline synobj_t *get_new_synobj() {
  int gc_idx = get_gc_idx();
  GarbageCollector* gc = gc_array[snapshot_idx];
  return gc->new_obj[gc_idx];
}
inline synobj_t* load_current_state(synobj_t* oldstate) {
#ifdef ENABLE_MEM_REUSE
  int gc_idx = get_gc_idx();
  GarbageCollector* gc = gc_array[snapshot_idx];
  while (oldstate->obj_block_id>=gc->activity_array[gc_idx].load()+1000) {
    gc->activity_array[gc_idx] = oldstate->obj_block_id;
    oldstate = state_array[snapshot_idx].load();
  }
#endif
  return oldstate;
}

inline value_t& write_wrapper(wrapper_t* &param)
{
  if (!param) {
    int gc_idx = get_gc_idx();
    GarbageCollector* gc = gc_array[snapshot_idx];
    GC_Queue<wrapper_t> *free_wrapper = gc->wrapper_to_reuse[gc_idx];
    wrapper_t *new_wrapper = free_wrapper->front();
    free_wrapper->pop();
    new_wrapper->value = 0;
#ifdef ENABLE_REVALIDATION
    new_wrapper->version = 0;
#endif
    param = new_wrapper;
  }
  return param->value;
}

inline value_t read_wrapper(wrapper_t* param)
{
    return (param?(param->value):0);
}

#ifdef ENABLE_REVALIDATION
// double check if addresses accessed are still older than base version
inline bool revalidate (synobj_t *newstate) {
    int read_num = newstate->synobj.read_num;
    void **read_set = newstate->synobj.read_set;
    int base_version = newstate->synobj.base_version;
    int i;
    for (i = 0; i < read_num; i++) {
        wrapper_t* wrapper = *((wrapper_t **) read_set[i]);
        if (wrapper) {
          int val_version = wrapper->version;
          if (val_version > base_version) return false;
        }
    }

    // typename synobj_t::ModifyLog* write_set = newstate->synobj.logs;
    Template_ModifyLog<wrapper_t,value_t>* write_set = newstate->synobj.logs;
    int write_num = newstate->synobj.log_num;
    for (i = 0; i < write_num; i++) {
        wrapper_t* wrapper = (*(newstate->synobj.logs[i].addr));
        if (wrapper) {
          int val_version = wrapper->version;
          if (val_version > base_version) return false;
        }
    }

    return true;
}

// for write operations such as insert and erase
inline bool check_conflict (synobj_t *oldstate, synobj_t *newstate, wrapper_t* &param, value_t &res)
{
  wrapper_t* tmp = param;
  if (tmp && (tmp->version > newstate->synobj.base_version)) return false;

  for (int i = 0; i < newstate->synobj.log_num; i++) {
     if (newstate->synobj.logs[i].addr == &param) {
         res = newstate->synobj.logs[i].new_val;
         return true;
     }
   }
   res = (tmp?(tmp->value):0);
   newstate->synobj.read_set[newstate->synobj.read_num] = &param;
   newstate->synobj.read_num ++;
   if (newstate->synobj.read_num == newstate->synobj.max_read_num) {
      printf("full read array\n");
   }
   return true;
}

// for read operation such as find
inline bool check_conflict(synobj_t *read_obj, wrapper_t* &param, value_t &res)
{
  wrapper_t* tmp = param;
  res = (tmp?(tmp->value):0);
  int version = (tmp?(tmp->version):0);
  int base_version = read_obj->synobj.base_version;
  if (base_version >= version) return true;

  GarbageCollector* gc = gc_array[snapshot_idx];
  for (int i = base_version + 1; i <= version; i++) {
    synobj_t *state_tmp = (synobj_t*)gc->conflict_array->ringbuffer[i];
    for (int log_i = 0; log_i < state_tmp->synobj.total_log_num; log_i++) {
      if (state_tmp->synobj.logs[log_i].addr == &param) {
          res = (state_tmp->synobj.logs[log_i].old_val?(state_tmp->synobj.logs[log_i].old_val->value):0);
          return true;
      }
    }
  }
  return true;
}

#else
inline bool check_conflict(synobj_t *oldstate, synobj_t *newstate, wrapper_t* &param, value_t &res)
{
  for (int i = 0; i < newstate->synobj.log_num; i++) {
    if (newstate->synobj.logs[i].addr == &param) {
        res = newstate->synobj.logs[i].new_val;
        return (oldstate == state_array[snapshot_idx].load());
    }
  }
  wrapper_t* tmp = param;
  res = (tmp?(tmp->value):0);
  return (oldstate == state_array[snapshot_idx].load());
}

inline bool check_conflict(synobj_t *oldstate, wrapper_t* &param, value_t &res)
{
  wrapper_t* tmp = param;
  res = (tmp?(tmp->value):0);

  int old_version_number = oldstate->synobj.version_number;
  int cur_version_number = state_array[snapshot_idx].load()->synobj.version_number;

  GarbageCollector* gc = gc_array[snapshot_idx];
  for (int i = old_version_number + 1; i <= cur_version_number; i++) {
    synobj_t *state_tmp = (synobj_t*) gc->conflict_array->ringbuffer[i];
    if (state_tmp == 0) continue;

    for (int i = 0; i < state_tmp->synobj.total_log_num; i++) {
      if (state_tmp->synobj.logs[i].addr == &param) {
          res = (state_tmp->synobj.logs[i].old_val?(state_tmp->synobj.logs[i].old_val->value):0);
          return true;
      }
    }

  }
  return true;
}
#endif


#define READ_OP_BEGIN(idx)  \
                        snapshot_idx = (idx)%N_SNAPSHOT; \
                        synobj_t *oldstate, *newstate; \
                        newstate = get_read_synobj(); \
                        oldstate = state_array[snapshot_idx].load(); \
                        oldstate = load_current_state(oldstate); \
                        *newstate = *oldstate;

#define READ_OP_END     ;


#define WRITE_OP_BEGIN(idx)  \
                        snapshot_idx = (idx); \
                        synobj_t *oldstate, *newstate; \
                        newstate = allocate_synobj();  \
                        oldstate = state_array[snapshot_idx].load(); \
                        while (true) { \
                            bool modified = false; \
                            oldstate = load_current_state(oldstate); \
                            *newstate = *oldstate;

#ifdef ENABLE_REVALIDATION

#define WRITE_OP_END        if (!modified) break; \
                            if (!state.compare_exchange_weak(oldstate,newstate)) {\
                                while(true) { \
                                    oldstate = state_array[snapshot_idx].load(); \
                                    newstate->reload(*oldstate); \
                                    if (revalidate(newstate) == false) CONFLICT_HANDLE; \
                                    if (state_array[snapshot_idx].compare_exchange_weak(oldstate,newstate)) break;\
                                    nanosleep_invoke(); \
                                } \
                            } \
                            newstate->apply_mod(); break; \
                            retry: nanosleep_invoke();oldstate=state_array[snapshot_idx].load(); \
                        }

#else

#define WRITE_OP_END        if (!modified) break;\
                            if (state_array[snapshot_idx].compare_exchange_weak(oldstate,newstate)) {\
                                newstate->apply_mod(); \
                                break; \
                            } \
                            retry: oldstate=state_array[snapshot_idx].load(); nanosleep_invoke(); \
                        }

#endif

#define MOD_READ(addr,val)   if(!check_conflict(oldstate,newstate,addr,val)) goto retry
#define MOD_WRITE(addr,val)  newstate->insert_mod(&(addr),addr,val);modified=true;
#define WRP_READ(addr)       read_wrapper(addr)
#define WRP_WRITE(addr)      write_wrapper(addr)

#define SNAPSHOT(var)  newstate->var
#define SNAPSHOT_WRITE(var,src)  newstate->var=src;modified=true;
#define SNAPSHOT_READ(var,dst)   dst = newstate->var;

#ifdef ENABLE_REVALIDATION
#define MOD_READ_R(addr,val) check_conflict(newstate,addr,val)
#else
#define MOD_READ_R(addr,val) check_conflict(oldstate,addr,val)
#endif
