

#define CONFLICT_HANDLE goto retry;
#define likely(x)      __builtin_expect(!!(x), 1)
#define unlikely(x)    __builtin_expect(!!(x), 0)

template <class wrapper_type, class value_type>
struct Template_ModifyLog
{
    wrapper_type**   addr;
    wrapper_type*    old_val;
    value_type       new_val;
};

struct GarbageCollector;

template <class wrapper_type, class value_type>
struct Template_Synobj
{
    GarbageCollector *parent_gc;
    void* parent_obj;
    int version_number;
    synobj_t* gc_next;


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
#ifdef ENABLE_GC_NODE_ALLOCATOR
    gc_node_t* nodes[NODE_NUM];
    int node_num;
#endif

    Template_Synobj() {
        version_number = -1;
        log_num = 0;
        total_log_num = 0;
#ifdef ENABLE_GC_NODE_ALLOCATOR
        node_num = 0;
#endif
#ifdef ENABLE_REVALIDATION
        read_num = 0;
        max_read_num = READ_NUM;
#endif
    }

    inline void insert_mod(wrapper_type** addr, wrapper_type* old_val, value_type new_val) {
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

#ifdef ENABLE_GC_NODE_ALLOCATOR
    void free_node (gc_node_t* n) {
        nodes[node_num] = n;
        node_num ++;
    }
#endif

    inline void apply_mod () {
        if (log_num == 0) return;
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
                if(ret) {
                    parent_gc->wrapper_to_reuse[gc_idx]->pop();
                    new_val = parent_gc->wrapper_to_reuse[gc_idx]->front();
                }
            }
        }
        log_num = 0;
    }

    inline void reclaim_wrappers() {
        if (total_log_num == 0) return;
        wrapper_type* old_wrapper;
        int gc_idx = parent_gc->get_gc_idx();
        for (int i = 0; i < total_log_num; i++) {
          old_wrapper = logs[i].old_val;
          if (old_wrapper != 0) {
            parent_gc->wrapper_to_reuse[gc_idx]->push(old_wrapper);
          }
        }
        total_log_num = 0;
    }

#ifdef ENABLE_GC_NODE_ALLOCATOR
    void reclaim_nodes() {
        if (node_num == 0) return;
        gc_node_t* old_node;
        int gc_idx = parent_gc->get_gc_idx();
        for (int i = 0; i < node_num; i++) {
          old_node = nodes[i];
          // assert(old_node);
          parent_gc->node_to_reuse[gc_idx]->push(old_node);
        }
        node_num = 0;
    }
#endif

    inline Template_Synobj<wrapper_type,value_type>& operator =(Template_Synobj<wrapper_type,value_type>& that) {
        that.apply_mod();
        this->version_number = that.version_number + 1;
        this->log_num = 0;
        this->total_log_num = 0;
#ifdef ENABLE_GC_NODE_ALLOCATOR
        this->node_num = 0;
#endif

#ifdef ENABLE_REVALIDATION
        this->copy_version = that.version_number;
        this->base_version = that.version_number;
        this->read_num = 0;
#endif
        return *this;
    }

#ifdef ENABLE_REVALIDATION
    Template_Synobj<wrapper_type,value_type>& reload(Template_Synobj<wrapper_type,value_type>& that) {
        that.apply_mod();
        this->version_number = that.version_number + 1;
        this->copy_version = that.version_number;
        return *this;
    }
#endif

};

// conflict array
struct ConflictArray {
    volatile void* ringbuffer[CONFLICT_ARRAY_SIZE];
    inline void publish (void *item, int idx) {
        ringbuffer[idx] = item;
    }
};

template <class U>
struct GC_SynObj_Queue {
    GarbageCollector *parent_gc;
    struct GC_SynObj_Block {
        U* elems;
        int newest_version;

        GC_SynObj_Block() {
            elems = new U [GC_BLOCK_SIZE];
            // std::memset(elems, 0, GC_BLOCK_SIZE*sizeof(U));
            newest_version = -1;
        }
    };

    std::vector<GC_SynObj_Block*> block_list;

    int active_block_begin;
    int active_block_end;
    int active_block_max_n;

    int block_idx;
    U* curr_block;

    GC_SynObj_Queue (GarbageCollector *p_gc) {
        parent_gc = p_gc;
        block_list.reserve(GC_RESERVE_SIZE);

        active_block_begin = 0;
        active_block_end = 0;
        active_block_max_n = GC_RESERVE_SIZE;

        GC_SynObj_Block* new_block = new GC_SynObj_Block;
        block_list.push_back(new_block);
        curr_block = new_block->elems;
        block_idx = 0;
    }

    ~GC_SynObj_Queue() {
        // free each block, not implemented
    }

    inline void resize() {
        printf("shouldn't consume so many snapshots\n");
        exit(0);
    }

    inline bool full() {
        return ((active_block_end+1-active_block_begin) == active_block_max_n);
    }

    inline void reclaim () {
        int thread_num = parent_gc->thread_count.load();
        int v = parent_gc->activity_array[0];

        for (int i = 1; i < thread_num; i++) {
            int _v = parent_gc->activity_array[i];
            if (_v < v) {
                v = _v;
            }
        }

        assert(full());

        int new_active_block_begin = -1;
        for (int i = active_block_end-1; i >= active_block_begin; i--) {
            int newest_version = block_list[i%active_block_max_n]->newest_version;
            if (newest_version < v) {
                new_active_block_begin = i+1;
                break;
            }
        }

        if (new_active_block_begin == -1) resize();

        active_block_begin = new_active_block_begin;
    }

    inline U* pop() {
        if (unlikely(block_idx == GC_BLOCK_SIZE)) {
            block_list[active_block_end%active_block_max_n]->newest_version = curr_block[block_idx-1].synobj.version_number;
            if (full()) {
                reclaim();
                assert(!full());
            }
            active_block_end ++;
            GC_SynObj_Block* new_block;
            if (active_block_end >= active_block_max_n) {
                new_block = block_list[active_block_end%active_block_max_n];
                assert(new_block);
            } else {
                new_block = new GC_SynObj_Block;
                block_list.push_back(new_block);
            }
            curr_block = new_block->elems;
            block_idx = 0;
        }
        return &(curr_block[block_idx++]);
    }

};

template <class U>
struct GC_Wrapper_Queue {
    U* free_list;
    int free_list_len;
    std::vector<U*> block_list;
    int block_idx;
    U* curr_block;

    bool allocate_from_block;

    GC_Wrapper_Queue () {
        free_list = 0;
        free_list_len = 0;
        block_list.reserve(GC_RESERVE_SIZE);
        curr_block = new U [GC_BLOCK_SIZE];
        block_list.push_back(curr_block);
        block_idx = 0;
        allocate_from_block = true;
    }
    ~GC_Wrapper_Queue() {
        // printf("%d %d\n", free_list.size(), block_list.size()*GC_BLOCK_SIZE);
    }
    inline void push (U *item) {
        item->gc_next = free_list;
        free_list = item;
        free_list_len ++;
    }
    inline U* front() {
begin_allocate_wrapper_from_block:
        if (allocate_from_block) {
            if (unlikely(block_idx == GC_BLOCK_SIZE)) {
                if (free_list_len > GC_BLOCK_SIZE) {
                    allocate_from_block = false;
                    goto begin_allocate_wrapper_from_list;
                }
                curr_block = new U [GC_BLOCK_SIZE];
                block_idx = 0;
                block_list.push_back(curr_block);
            }
            return &(curr_block[block_idx]);
        }

begin_allocate_wrapper_from_list:
        if (unlikely(free_list == NULL)) {
            allocate_from_block = true;
            goto begin_allocate_wrapper_from_block;
        }

        return free_list;
    }
    inline void pop() {
        if (allocate_from_block) {
            block_idx ++;
        } else {
            free_list = free_list->gc_next;
            free_list_len --;
        }
    }
};



template <class U>
struct GC_Node_Queue {
    std::vector<U*> free_list;
    std::vector<U*> block_list;
    int block_idx;
    U* curr_block;

    bool allocate_from_block;

    GC_Node_Queue () {
        curr_block = new U [GC_BLOCK_SIZE];
        std::memset(curr_block, 0, GC_BLOCK_SIZE*sizeof(U));
        block_list.push_back(curr_block);
        block_idx = 0;
        allocate_from_block = true;
    }
    ~GC_Node_Queue() {
        // printf("%d %d\n", free_list.size(), block_list.size()*GC_BLOCK_SIZE);
    }
    inline void push (U *item) {
        free_list.push_back(item);
    }
    inline U* pop() {
begin_allocate_node_from_block:
        if (allocate_from_block) {
            if (unlikely(block_idx == GC_BLOCK_SIZE)) {
                if (free_list.size()>GC_BLOCK_SIZE) {
                    allocate_from_block = false;
                    goto begin_allocate_node_from_list;
                }
                curr_block = new U [GC_BLOCK_SIZE];
                std::memset(curr_block, 0, GC_BLOCK_SIZE*sizeof(U));
                block_idx = 0;
                block_list.push_back(curr_block);
            }
            return &(curr_block[block_idx++]);
        }

begin_allocate_node_from_list:
        if (unlikely(free_list.empty())) {
            allocate_from_block = true;
            goto begin_allocate_node_from_block;
        }

        U* ret = free_list.back();
        free_list.pop_back();
        return ret;
    }
};

/*
template <class U>
struct GC_Node_Queue {
    std::vector<U*> free_list;

    GC_Node_Queue () {
        free_list.reserve(GC_RESERVE_SIZE);
    }
    inline void push (U *item) {
        free_list.push_back(item);
    }
    inline U* pop() {
        U* new_node;
        if (free_list.empty()) {
            new_node = new U;
            std::memset(new_node, 0, sizeof(U));
        } else {
            new_node = free_list.back();
            free_list.pop_back();
        }
        return new_node;
    }
};
*/

struct GarbageCollector {
    std::atomic<int> thread_count;
    // std::atomic<int> reclaim_count;

    GC_SynObj_Queue<synobj_t> *obj_to_reuse[GC_MAX_THREADS];
    GC_Wrapper_Queue<wrapper_t> *wrapper_to_reuse[GC_MAX_THREADS];
#ifdef ENABLE_GC_NODE_ALLOCATOR
    GC_Node_Queue<gc_node_t> *node_to_reuse[GC_MAX_THREADS];
#endif

    synobj_t *read_obj[GC_MAX_THREADS];
    synobj_t *old_obj[GC_MAX_THREADS];
    synobj_t *new_obj[GC_MAX_THREADS];

    volatile int activity_array[GC_MAX_THREADS];
    ConflictArray *conflict_array;

    inline synobj_t *allocate_synobj(int gc_idx) {
      synobj_t *res_obj;
      res_obj = obj_to_reuse[gc_idx]->pop();
      res_obj->synobj.parent_gc = this;
      res_obj->synobj.parent_obj = res_obj;
      res_obj->reclaim_wrappers();
#ifdef ENABLE_GC_NODE_ALLOCATOR
      res_obj->synobj.reclaim_nodes();
#endif
      return res_obj;
    }

#ifdef ENABLE_GC_NODE_ALLOCATOR
    gc_node_t *allocate_node(int gc_idx) {
      gc_node_t* res_node = node_to_reuse[gc_idx]->pop();
      return res_node;
    }
#endif


    GarbageCollector () {
      thread_count = 0;
      conflict_array = new ConflictArray;
      // reclaim_count = 0;

      for (int i = 0; i < GC_MAX_THREADS; i++) {
        activity_array[i] = -1;
      }
    }

    ~GarbageCollector() {
        // printf("reclaim_count %d\n", reclaim_count.load());
        for (int i = 0; i < thread_count.load(); i++) {
            delete obj_to_reuse[i];
            delete wrapper_to_reuse[i];
        }
    }

    inline int get_gc_idx () {
      if (local_gc_idx == -1) {
        int local_idx = thread_count.fetch_add(1);

        read_obj[local_idx] = new synobj_t;
        read_obj[local_idx]->synobj.parent_gc = this;
        obj_to_reuse[local_idx] = new GC_SynObj_Queue<synobj_t>(this);
        wrapper_to_reuse[local_idx] = new GC_Wrapper_Queue<wrapper_t>();
#ifdef ENABLE_GC_NODE_ALLOCATOR
        node_to_reuse[local_idx] = new GC_Node_Queue<gc_node_t>();
#endif
        local_gc_idx = local_idx;
      }
      return local_gc_idx;
    }
};

std::atomic<synobj_t*> state;
GarbageCollector* gc;

inline int get_gc_idx() {
  int gc_idx = gc->get_gc_idx();
  return gc_idx;
}

inline synobj_t *allocate_synobj() {
  int gc_idx = gc->get_gc_idx();
  gc->new_obj[gc_idx] = gc->allocate_synobj(gc_idx);
  return gc->new_obj[gc_idx];
}

#ifdef ENABLE_GC_NODE_ALLOCATOR
inline gc_node_t *allocate_node() {
  int gc_idx = get_gc_idx();
  return gc->allocate_node(gc_idx);
}
#endif

inline void retire_synobj (synobj_t *x) {
  return;
  // int gc_idx = gc->get_gc_idx();
  // gc->obj_to_reuse[gc_idx]->push(x);
}

inline synobj_t *get_read_synobj() {
  int gc_idx = gc->get_gc_idx();
  return gc->read_obj[gc_idx];
}

inline synobj_t *get_old_synobj() {
  int gc_idx = gc->get_gc_idx();
  return gc->old_obj[gc_idx];
}

inline synobj_t *get_new_synobj() {
  int gc_idx = gc->get_gc_idx();
  return gc->new_obj[gc_idx];
}
inline synobj_t* load_current_state(synobj_t* oldstate) {
  // int gc_idx = gc->get_gc_idx();
  // printf("%d, %d\n", gc->activity_array[gc_idx], oldstate->synobj.version_number);
  // assert(gc->activity_array[gc_idx] <= oldstate->synobj.version_number);
  gc->activity_array[local_gc_idx] = oldstate->synobj.version_number;
  return oldstate;
}

inline value_t& write_wrapper(wrapper_t* &param)
{
  if (!param) {
    int gc_idx = gc->get_gc_idx();
    GC_Wrapper_Queue<wrapper_t> *free_wrapper = gc->wrapper_to_reuse[gc_idx];
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
        return (oldstate == state);
    }
  }
  wrapper_t* tmp = param;
  res = (tmp?(tmp->value):0);
  return (oldstate == state);
}

inline bool check_conflict(synobj_t *oldstate, wrapper_t* &param, value_t &res)
{
  wrapper_t* tmp = param;
  res = (tmp?(tmp->value):0);

  int old_version_number = oldstate->synobj.version_number;
  int cur_version_number = state->synobj.version_number;

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


#define READ_OP_BEGIN   synobj_t *oldstate, *newstate; \
                        newstate = get_read_synobj(); \
                        oldstate = state.load(); \
                        oldstate = load_current_state(oldstate); \
                        *newstate = *oldstate;

#define READ_OP_END     ;


#define WRITE_OP_BEGIN  synobj_t *oldstate, *newstate; \
                        newstate = allocate_synobj();  \
                        oldstate = state.load(); \
                        while (true) { \
                            oldstate = load_current_state(oldstate); \
                            *newstate = *oldstate;

#ifdef ENABLE_REVALIDATION

#define WRITE_OP_END        if (newstate->synobj.log_num == 0) break; \
                            if (!state.compare_exchange_weak(oldstate,newstate)) {\
                                while(true) { \
                                    oldstate = state.load(); \
                                    newstate->synobj.reload(oldstate->synobj); \
                                    if (revalidate(newstate) == false) CONFLICT_HANDLE; \
                                    if (state.compare_exchange_weak(oldstate,newstate)) break;\
                                    nanosleep_invoke(); \
                                } \
                            } \
                            newstate->apply_mod(); break; \
                            retry: nanosleep_invoke(); oldstate=state.load(); \
                        }

#else

#define WRITE_OP_END        if (state == oldstate) \
                            if (state.compare_exchange_weak(oldstate,newstate)) {\
                                retire_synobj(newstate); \
                                newstate->apply_mod(); \
                                break; \
                            } \
                            retry: oldstate=state.load(); nanosleep_invoke(); \
                        }

#endif

#define MOD_READ(addr,val)   if(!check_conflict(oldstate,newstate,addr,val)) goto retry
#define MOD_WRITE(addr,val)  newstate->insert_mod(&(addr),addr,val)
#define WRP_READ(addr)       read_wrapper(addr)
#define WRP_WRITE(addr)      write_wrapper(addr)
#define SNAPSHOT(var)        newstate->var
#define SNAPSHOT_WRITE(x,y)  newstate->x=y
#define FREE_NODE(x)         newstate->synobj.free_node(x);

#ifdef ENABLE_REVALIDATION
#define MOD_READ_R(addr,val) check_conflict(newstate,addr,val)
#else
#define MOD_READ_R(addr,val) check_conflict(oldstate,addr,val)
#endif



