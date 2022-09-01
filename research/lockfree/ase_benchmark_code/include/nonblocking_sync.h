
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

#ifdef ENABLE_DATA_PARTITION
std::atomic<synobj_t*> state_array[MAX_N_SNAPSHOT];
GarbageCollector* gc_array[MAX_N_SNAPSHOT];
#else
std::atomic<synobj_t*> state;
GarbageCollector* gc;
#endif

template <class wrapper_type, class value_type>
struct Template_Synobj
{
    GarbageCollector *parent_gc;
    void* parent_obj;
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

#ifdef ENABLE_GC_NODE_ALLOCATOR
    void free_node (gc_node_t* n) {
        nodes[node_num] = n;
        node_num ++;
    }
#endif


    void apply_mod () {
        if (log_num == 0) return;
        parent_gc->conflict_array.publish(parent_obj, version_number);

        int gc_idx = parent_gc->get_gc_idx();
        wrapper_type* new_val = parent_gc->wrapper_queue[gc_idx]->front();

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
                    parent_gc->wrapper_queue[gc_idx]->pop();
                    new_val = parent_gc->wrapper_queue[gc_idx]->front();
                }
            }
        }
        log_num = 0;
    }

    inline void reclaim_wrappers() {
        #ifdef ENABLE_GC_REUSE
        if (total_log_num == 0) return;
        wrapper_type* old_wrapper;
        int gc_idx = parent_gc->get_gc_idx();
        for (int i = 0; i < total_log_num; i++) {
          old_wrapper = logs[i].old_val;
          if (old_wrapper != 0) {
            parent_gc->wrapper_queue[gc_idx]->push(old_wrapper);
          }
        }
        #endif
        total_log_num = 0;
        log_num = 0;
    }

#ifdef ENABLE_GC_NODE_ALLOCATOR
    inline void reclaim_nodes() {
        #ifdef ENABLE_GC_REUSE
        if (node_num == 0) return;
        gc_node_t* old_node;
        int gc_idx = parent_gc->get_gc_idx();
        for (int i = 0; i < node_num; i++) {
          old_node = nodes[i];
          parent_gc->node_queue[gc_idx]->push(old_node);
        }
        #endif
        node_num = 0;
    }
#endif

    Template_Synobj<wrapper_type,value_type>& operator =(Template_Synobj<wrapper_type,value_type>& that) {
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


struct ConflictArray {
    #ifdef ENABLE_DATA_PARTITION
    static GC_Array_Allocator<volatile void*> allocator;
    static unsigned mask;
    static unsigned shift;
    #else
    GC_Array_Allocator<volatile void*> allocator;
    unsigned mask;
    unsigned shift;
    #endif
    volatile void** buffer;

    ConflictArray() {
        #ifdef ENABLE_DATA_PARTITION
        if(allocator.array_size == 0) {
        #endif
            shift = CONFLICT_ARRAY_SHIFT;
            mask = (1<<CONFLICT_ARRAY_SHIFT) - 1;
            allocator.array_size = 1 << CONFLICT_ARRAY_SHIFT;
            #ifdef ENABLE_DATA_PARTITION
            allocator.array_num_per_block = MAX_N_SNAPSHOT + 1;
            #else
            allocator.array_num_per_block = 1;
            #endif
        #ifdef ENABLE_DATA_PARTITION
        }
        #endif
        buffer = allocator.allocate();
    }

    void publish (void* item, int idx) {
        buffer[idx & mask] = item;
    }

    volatile void* &operator [] (int idx) {
        return buffer[idx & mask];
    }
};

struct ActivityArray {
    #ifdef ENABLE_DATA_PARTITION
    static GC_Array_Allocator<volatile int> allocator;
    #else
    GC_Array_Allocator<volatile int> allocator;
    #endif
    volatile int* buffer;
    ActivityArray() {
        #ifdef ENABLE_DATA_PARTITION
        if(allocator.array_size == 0) {
        #endif
            allocator.array_size = GC_MAX_THREADS;
            #ifdef ENABLE_DATA_PARTITION
            allocator.array_num_per_block = MAX_N_SNAPSHOT + 1;
            #else
            allocator.array_num_per_block = 1;
            #endif
        #ifdef ENABLE_DATA_PARTITION
        }
        #endif
        buffer = allocator.allocate();
    }

    volatile int &operator [] (int idx) {
        return buffer[idx];
    }
};


struct GC_Retired_SynObj;
struct RetiredSynObjArray {
    #ifdef ENABLE_DATA_PARTITION
    static GC_Array_Allocator<GC_Retired_SynObj> allocator;
    #else
    GC_Array_Allocator<GC_Retired_SynObj> allocator;
    #endif
    GC_Retired_SynObj* buffer;
    RetiredSynObjArray () {
        #ifdef ENABLE_DATA_PARTITION
        if(allocator.array_size == 0) {
        #endif
            allocator.array_size = GC_MAX_THREADS;
            #ifdef ENABLE_DATA_PARTITION
            allocator.array_num_per_block = MAX_N_SNAPSHOT + 1;
            #else
            allocator.array_num_per_block = 1;
            #endif
        #ifdef ENABLE_DATA_PARTITION
        }
        #endif
        buffer = allocator.allocate();
    }

    GC_Retired_SynObj& operator [] (int idx) {
        return buffer[idx];
    }
};

struct GC_Retired_SynObj {
    GarbageCollector *parent_gc;

    synobj_t* head;
    synobj_t* tail;
    unsigned size;
    unsigned max_size;

    GC_Retired_SynObj () {
        parent_gc = 0;

        head = 0;
        tail = 0;
        size = 0;
        max_size = GC_BLOCK_SIZE;
    }

    inline void reclaim (GC_Queue<synobj_t>* parent_queue) {
        if (size < max_size) return;
        int thread_num = parent_gc->thread_count.load();
        int v = parent_gc->activity_array[0];

        for (int i = 1; i < thread_num; i++) {
            int _v = parent_gc->activity_array[i];
            if (_v < v) v = _v;
        }

        unsigned new_size = 0;
        synobj_t* curr = head;
        synobj_t* prev = 0;

        synobj_t* free_head = 0;
        synobj_t* free_tail = tail;

        while ((curr!=0) && (curr->synobj.version_number >= v)) {
            prev = curr;
            curr = curr->gc_next;
            new_size ++;
        }
        if (curr == 0) return;
        free_head = curr;

        if (prev != 0) {
            tail = prev;
            tail->gc_next = 0;
        } else {
            head = tail = 0;
        }
        size = new_size;
        parent_queue->push_list(free_head, free_tail);
    }

    inline void retire_synobj (synobj_t* obj, GC_Queue<synobj_t>* parent_queue) {
        obj->gc_next = head;
        head = obj;
        if (tail == 0) tail = obj;
        size ++;
#ifdef ENABLE_GC_REUSE
        reclaim(parent_queue);
#endif
    }
};

struct GarbageCollector {
#ifdef ENABLE_DATA_PARTITION
    static std::atomic<int> thread_count;
    static GC_Queue<synobj_t>*  synobj_queue[GC_MAX_THREADS];
    static GC_Queue<wrapper_t>* wrapper_queue[GC_MAX_THREADS];
    static synobj_t* read_obj[GC_MAX_THREADS];
    #ifdef ENABLE_GC_NODE_ALLOCATOR
    static GC_Queue<gc_node_t>* node_queue[GC_MAX_THREADS];
    #endif
#else
    std::atomic<int> thread_count;
    GC_Queue<synobj_t>*  synobj_queue[GC_MAX_THREADS];
    GC_Queue<wrapper_t>* wrapper_queue[GC_MAX_THREADS];
    synobj_t* read_obj[GC_MAX_THREADS];
    #ifdef ENABLE_GC_NODE_ALLOCATOR
    GC_Queue<gc_node_t>* node_queue[GC_MAX_THREADS];
    #endif
#endif
    ActivityArray activity_array;
    ConflictArray conflict_array;
    RetiredSynObjArray retired_synobj_array;

    synobj_t *allocate_synobj(int gc_idx) {
      synobj_t *res_obj;
      res_obj = synobj_queue[gc_idx]->pop_front();
      res_obj->synobj.parent_gc = this;
      res_obj->synobj.parent_obj = res_obj;
      res_obj->reclaim_wrappers();
      #ifdef ENABLE_GC_NODE_ALLOCATOR
      res_obj->synobj.reclaim_nodes();
      #endif
      return res_obj;
    }

    void retire_synobj(int gc_idx, synobj_t* obj) {
        #ifdef ENABLE_GC_REUSE
        retired_synobj_array[gc_idx].retire_synobj(obj, synobj_queue[gc_idx]);
        #endif
    }

    void reclaim_synobj(int gc_idx, synobj_t* obj) {
        synobj_queue[gc_idx]->push(obj);
    }

#ifdef ENABLE_GC_NODE_ALLOCATOR
    gc_node_t *allocate_node(int gc_idx) {
      gc_node_t* res_node = node_queue[gc_idx]->pop_front();
      return res_node;
    }
#endif

    GarbageCollector () {
#ifdef ENABLE_GC_REUSE
      for (int i = 0; i < GC_MAX_THREADS; i++) {
        retired_synobj_array[i].parent_gc = this;
      }
#endif
    }

    inline int get_gc_idx () {
      return local_gc_idx;
    }
};


#ifdef ENABLE_DATA_PARTITION
inline int get_gc_idx() {
  if (local_gc_idx == -1) {
    int local_idx = GarbageCollector::thread_count.fetch_add(1);
    GarbageCollector::read_obj[local_idx] = new synobj_t;
    GarbageCollector::read_obj[local_idx]->synobj.parent_gc = 0;
    GarbageCollector::wrapper_queue[local_idx] = new GC_Queue<wrapper_t>();
    GarbageCollector::synobj_queue[local_idx] = new GC_Queue<synobj_t>();
#ifdef ENABLE_GC_NODE_ALLOCATOR
    GarbageCollector::node_queue[local_idx] = new GC_Queue<gc_node_t>();
#endif
    local_gc_idx = local_idx;
  }
  return local_gc_idx;
}
#else
inline int get_gc_idx() {
  if (local_gc_idx == -1) {
    int local_idx = gc->thread_count.fetch_add(1);
    gc->read_obj[local_idx] = new synobj_t;
    gc->read_obj[local_idx]->synobj.parent_gc = 0;
    gc->wrapper_queue[local_idx] = new GC_Queue<wrapper_t>();
    gc->synobj_queue[local_idx] = new GC_Queue<synobj_t>();
#ifdef ENABLE_GC_NODE_ALLOCATOR
    gc->node_queue[local_idx] = new GC_Queue<gc_node_t>();
#endif
    local_gc_idx = local_idx;
  }
  return local_gc_idx;
}
#endif

inline synobj_t *allocate_synobj() {
  synobj_t* ret;
  int gc_idx = get_gc_idx();
  #ifdef ENABLE_DATA_PARTITION
  GarbageCollector* gc = gc_array[snapshot_idx];
  #endif
  ret = gc->allocate_synobj(gc_idx);
  return ret;
}

inline void retire_synobj (synobj_t *x) {
#ifdef ENABLE_GC_REUSE
  int gc_idx = get_gc_idx();
  #ifdef ENABLE_DATA_PARTITION
  GarbageCollector* gc = gc_array[snapshot_idx];
  #endif
  gc->retire_synobj(gc_idx, x);
#endif
}

inline void reclaim_synobj (synobj_t *x) {
  int gc_idx = get_gc_idx();
  #ifdef ENABLE_DATA_PARTITION
  GarbageCollector* gc = gc_array[snapshot_idx];
  #endif
  gc->reclaim_synobj(gc_idx, x);
}

#ifdef ENABLE_GC_NODE_ALLOCATOR
inline gc_node_t *allocate_node() {
  int gc_idx = get_gc_idx();
  #ifdef ENABLE_DATA_PARTITION
  return GarbageCollector::node_queue[gc_idx]->pop_front();
  #else
  return gc->node_queue[gc_idx]->pop_front();
  #endif
}
#endif

inline synobj_t *get_read_synobj() {
  int gc_idx = get_gc_idx();
  #ifdef ENABLE_DATA_PARTITION
  GarbageCollector* gc = gc_array[snapshot_idx];
  #endif
  synobj_t* ret = gc->read_obj[gc_idx];
  ret->parent_gc = gc;
  return ret;
}

inline synobj_t* load_current_state(synobj_t* oldstate) {
#ifdef ENABLE_GC_REUSE
  int gc_idx = get_gc_idx();
  #ifdef ENABLE_DATA_PARTITION
  GarbageCollector* gc = gc_array[snapshot_idx];
  #endif
  gc->activity_array[local_gc_idx] = oldstate->synobj.version_number;
#endif
  return oldstate;
}

inline value_t& write_wrapper(wrapper_t* &param)
{
  if (!param) {
    int gc_idx = get_gc_idx();
    #ifdef ENABLE_DATA_PARTITION
    GarbageCollector* gc = gc_array[snapshot_idx];
    #endif
    GC_Queue<wrapper_t> *free_wrapper = gc->wrapper_queue[gc_idx];
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
      printf("full read array %d %d\n", newstate->synobj.read_num, newstate->synobj.max_read_num);
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

  #ifdef ENABLE_DATA_PARTITION
  GarbageCollector* gc = gc_array[snapshot_idx];
  #endif
  for (int curr_v = base_version + 1; curr_v <= version; curr_v++) {
    // int i = curr_v & gc->conflict_array->mask;
    synobj_t *state_tmp = (synobj_t*)gc->conflict_array[curr_v];
    assert(state_tmp!=0);
    if (state_tmp->synobj.version_number != curr_v) {printf("check_conflict read failed\n"); return false;} // has been overridden
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
        #ifdef ENABLE_DATA_PARTITION
        return (oldstate == state_array[snapshot_idx].load());
        #else
        return (oldstate == state.load());
        #endif
    }
  }
  wrapper_t* tmp = param;
  res = (tmp?(tmp->value):0);
  #ifdef ENABLE_DATA_PARTITION
  return (oldstate == state_array[snapshot_idx].load());
  #else
  return (oldstate == state.load());
  #endif
}

inline bool check_conflict(synobj_t *oldstate, wrapper_t* &param, value_t &res)
{
  wrapper_t* tmp = param;
  res = (tmp?(tmp->value):0);

  int old_version_number = oldstate->synobj.version_number;
  #ifdef ENABLE_DATA_PARTITION
  int cur_version_number = state_array[snapshot_idx].load()->synobj.version_number;
  #else
  int cur_version_number = state.load()->synobj.version_number;
  #endif

  #ifdef ENABLE_DATA_PARTITION
  GarbageCollector* gc = gc_array[snapshot_idx];
  #endif
  for (int curr_v = old_version_number + 1; curr_v <= cur_version_number; curr_v++) {
    // int i = curr_v & gc->conflict_array->mask;
    synobj_t *state_tmp = (synobj_t*) gc->conflict_array[curr_v];
    if (state_tmp==0) {assert(curr_v == cur_version_number); break;};
    if (state_tmp->synobj.version_number != curr_v) return false;

    for (int log_i = 0; log_i < state_tmp->synobj.total_log_num; log_i++) {
      if (state_tmp->synobj.logs[log_i].addr == &param) {
          res = (state_tmp->synobj.logs[log_i].old_val?(state_tmp->synobj.logs[log_i].old_val->value):0);
          return true;
      }
    }

  }
  return true;
}
#endif

#ifdef ENABLE_DATA_PARTITION

#define READ_OP_BEGIN(idx)  \
                        snapshot_idx = (idx)%N_SNAPSHOT; \
                        synobj_t *oldstate, *newstate; \
                        newstate = get_read_synobj(); \
                        retry: oldstate = state_array[snapshot_idx].load(); \
                        oldstate = load_current_state(oldstate); \
                        *newstate = *oldstate;

#define READ_OP_END     ;


#define WRITE_OP_BEGIN(idx)  \
                        snapshot_idx = (idx)%N_SNAPSHOT; \
                        synobj_t *oldstate, *newstate; \
                        newstate = allocate_synobj();  \
                        oldstate = state_array[snapshot_idx].load(); \
                        while (true) { \
                            bool modified = false; \
                            oldstate = load_current_state(oldstate); \
                            *newstate = *oldstate;

#ifdef ENABLE_REVALIDATION

#define WRITE_OP_END        if (!modified) {reclaim_synobj(newstate); break;} \
                            if (!state_array[snapshot_idx].compare_exchange_weak(oldstate,newstate)) {\
                                while(true) { \
                                    oldstate = state_array[snapshot_idx].load(); \
                                    newstate->reload(*oldstate); \
                                    if (revalidate(newstate) == false) CONFLICT_HANDLE; \
                                    if (state_array[snapshot_idx].compare_exchange_weak(oldstate,newstate)) { break;}\
                                    nanosleep_invoke(); \
                                } \
                            } \
                            newstate->apply_mod(); retire_synobj(newstate); break; \
                            retry: nanosleep_invoke();oldstate=state_array[snapshot_idx].load(); \
                        }

#else

#define WRITE_OP_END        if (!modified) {reclaim_synobj(newstate); break;}\
                            if (state_array[snapshot_idx].compare_exchange_weak(oldstate,newstate)) {\
                                newstate->apply_mod(); retire_synobj(newstate);\
                                break; \
                            } \
                            retry: oldstate=state_array[snapshot_idx].load(); nanosleep_invoke(); \
                        }

#endif

#else // end of ENABLE_DATA_PARTITION

// !ENABLE_DATA_PARTITION
#define READ_OP_BEGIN  \
                        synobj_t *oldstate, *newstate; \
                        newstate = get_read_synobj(); \
                        retry: oldstate = state.load(); \
                        oldstate = load_current_state(oldstate); \
                        *newstate = *oldstate;

#define READ_OP_END     ;


#define WRITE_OP_BEGIN  \
                        synobj_t *oldstate, *newstate; \
                        newstate = allocate_synobj();  \
                        oldstate = state.load(); \
                        while (true) { \
                            bool modified = false; \
                            oldstate = load_current_state(oldstate); \
                            *newstate = *oldstate;

#ifdef ENABLE_REVALIDATION

#define WRITE_OP_END        if (!modified) {reclaim_synobj(newstate); break;} \
                            if (!state.compare_exchange_weak(oldstate,newstate)) {\
                                while(true) { \
                                    oldstate = state.load(); \
                                    newstate->reload(*oldstate); \
                                    if (revalidate(newstate) == false) CONFLICT_HANDLE; \
                                    if (state.compare_exchange_weak(oldstate,newstate)) { break;}\
                                    nanosleep_invoke(); \
                                } \
                            } \
                            newstate->apply_mod(); retire_synobj(newstate); break; \
                            retry: nanosleep_invoke();oldstate=state.load(); \
                        }

#else

#define WRITE_OP_END        if (!modified) {reclaim_synobj(newstate); break;}\
                            if (state.compare_exchange_weak(oldstate,newstate)) {\
                                newstate->apply_mod(); retire_synobj(newstate);\
                                break; \
                            } \
                            retry: oldstate=state.load(); nanosleep_invoke(); \
                        }

#endif

#endif // end of !ENABLE_DATA_PARTITION


#define MOD_READ(addr,val)   if(!check_conflict(oldstate,newstate,addr,val)) goto retry
#define MOD_WRITE(addr,val)  newstate->insert_mod(&(addr),addr,val);modified=true;
#define WRP_READ(addr)       read_wrapper(addr)
#define WRP_WRITE(addr)      write_wrapper(addr)

#define SNAPSHOT(var)  newstate->var
#define SNAPSHOT_WRITE(var,src)  newstate->var=src;modified=true;
#define SNAPSHOT_READ(var,dst)   dst = newstate->var;
#define FREE_NODE(x)             newstate->synobj.free_node(x);

#ifdef ENABLE_REVALIDATION
#define MOD_READ_R(addr,val) if(!check_conflict(newstate,addr,val)) goto retry
#else
#define MOD_READ_R(addr,val) if(!check_conflict(oldstate,addr,val)) goto retry
#endif
