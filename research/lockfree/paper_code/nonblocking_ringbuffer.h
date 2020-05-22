
#ifdef NONBLOCKING_RINGBUFFER

// #define ENABLE_SLEEP_TUNING
// #define ENABLE_MEM_REUSE

#define GC_MAX_THREADS  300
#define CONFLICT_ARRAY_SIZE  80000000
#define GC_BLOCK_NUM        80000
// #define GC_BLOCK_SIZE       (80000000/NUM_OF_THREADS)
// #define GC_BLOCK_SIZE       (1048576/NUM_OF_THREADS)
#define GC_SYNOBJ_BLOCK_SIZE       (32)
#define GC_BLOCK_SIZE       (65536)
#define GC_RESERVE_SIZE     (1000)
// #define GC_RESERVE_SIZE     (4)
#define LOG_NUM             N_THREADS

thread_local int local_gc_idx = -1;



#include "tvec.h"
#define _SIM_LOCAL_POOL_SIZE_            4

typedef int Object;
// typedef int ArgVal;
typedef struct ArgVal_t{
    int op_type;
    int param;
} ArgVal;
// typedef int RetVal;
typedef struct RetVal_t{
    bool succ;
    int ret;
} RetVal;

typedef union pointer_t {
    struct StructData{
        int64_t seq : 32;
        int32_t index : 32;
    } struct_data;
    int64_t raw_data;
} pointer_t;


typedef struct HalfObjectState {
    ToggleVector applied;
    RetVal ret[N_THREADS];
} HalfObjectState;


typedef struct ObjectState {
    ToggleVector applied;
    RetVal ret[N_THREADS];
    // int32_t pad[PAD_CACHE(sizeof(HalfObjectState))];
} ObjectState;

typedef struct ThreadState {
    ToggleVector mask CACHE_ALIGN;
    ToggleVector toggle;
    ToggleVector my_bit;
    int local_index;
    int backoff;
} SimThreadState;

thread_local SimThreadState* th_state;

typedef struct SimStruct {
    volatile pointer_t sp CACHE_ALIGN;
    volatile ToggleVector a_toggles CACHE_ALIGN;
    volatile ArgVal announce[N_THREADS] CACHE_ALIGN;
    volatile ObjectState pool[N_THREADS * _SIM_LOCAL_POOL_SIZE_ + 1] CACHE_ALIGN;
    int MAX_BACK CACHE_ALIGN;
} SimStruct;

void SimThreadStateInit() {
    th_state = (SimThreadState*) getAlignedMemory(CACHE_LINE_SIZE, sizeof(SimThreadState));

    int pid = local_gc_idx;
    th_state->local_index = 0;
    TVEC_SET_ZERO(&th_state->mask);
    TVEC_SET_ZERO(&th_state->my_bit);
    TVEC_SET_ZERO(&th_state->toggle);
    TVEC_REVERSE_BIT(&th_state->my_bit, pid);
    TVEC_SET_BIT(&th_state->mask, pid);
    th_state->toggle = TVEC_NEGATIVE(th_state->mask);
}

void SimInit(SimStruct* &stack) {
    stack = (SimStruct*) getAlignedMemory(CACHE_LINE_SIZE, sizeof(SimStruct));
    stack->sp.struct_data.index = _SIM_LOCAL_POOL_SIZE_ * N_THREADS;
    stack->sp.struct_data.seq = 0;
    TVEC_SET_ZERO((ToggleVector *)&stack->a_toggles);
    TVEC_SET_ZERO((ToggleVector *)&stack->pool[_SIM_LOCAL_POOL_SIZE_ * N_THREADS].applied);
    FullFence();
}

#if 0
inline RetVal SimApplyOp(SimStruct *stack) {
    int pid = local_gc_idx;
    ArgVal arg = 100;

    ToggleVector diffs, l_toggles, pops;
    pointer_t new_sp, old_sp;
    HalfObjectState *lsp_data, *sp_data;
    int i, j, prefix, mybank, push_counter;
    ArgVal tmp_arg;

    mybank = TVEC_GET_BANK_OF_BIT(pid);
    TVEC_REVERSE_BIT(&th_state->my_bit, pid);
    TVEC_NEGATIVE_BANK(&th_state->toggle, &th_state->toggle, mybank);
    lsp_data = (HalfObjectState *)&stack->pool[pid * _SIM_LOCAL_POOL_SIZE_ + th_state->local_index];
    stack->announce[pid] = arg;                                                  // stack->announce the operation
    TVEC_ATOMIC_ADD_BANK(&stack->a_toggles, &th_state->toggle, mybank);          // toggle pid's bit in stack->a_toggles, Fetch&Add acts as a full write-barrier

    for (j = 0; j < 2; j++) {
        // old_sp = stack->sp;                                                      // read reference to struct ObjectState
        old_sp.raw_data = stack->sp.raw_data;                                                      // read reference to struct ObjectState
        sp_data = (HalfObjectState *)&stack->pool[old_sp.struct_data.index];     // read reference of struct ObjectState in a local variable lsp_data
        TVEC_ATOMIC_COPY_BANKS(&diffs, &sp_data->applied, mybank);
        TVEC_XOR_BANKS(&diffs, &diffs, &th_state->my_bit, mybank);               // determine the set of active processes
        if (TVEC_IS_SET(diffs, pid))                                             // if the operation has already been applied return
            break;
        *lsp_data = *sp_data;
        // l_toggles = stack->a_toggles;                                            // This is an atomic read, since a_toogles is volatile
        volatile ToggleVector _l_toggles;
        int _i;
        LOOP(l_toggles.cell[_i] = stack->a_toggles.cell[_i], _i);

        if (old_sp.raw_data != stack->sp.raw_data)
            continue;
        diffs = TVEC_XOR(lsp_data->applied, l_toggles);
        push_counter = 0;
        TVEC_SET_ZERO(&pops);
        for (i = 0, prefix = 0; i < _TVEC_CELLS_; i++, prefix += _TVEC_BIWORD_SIZE_) {
/*
            ReadPrefetch(&stack->announce[prefix]);
#if N_THREADS > 7
            ReadPrefetch(&stack->announce[prefix + 8]);
#endif
#if N_THREADS > 15
            ReadPrefetch(&stack->announce[prefix + 16]);
#endif
#if N_THREADS > 23
            ReadPrefetch(&stack->announce[prefix + 24]);
#endif
*/
            while (diffs.cell[i] != 0L) {
                register int pos, proc_id;

                pos = bitSearchFirst(diffs.cell[i]);
                proc_id = prefix + pos;
                diffs.cell[i] ^= ((bitword_t)1) << pos;
                tmp_arg = stack->announce[proc_id];
            }
        }

        lsp_data->applied = l_toggles;                                           // change applied to be equal to what was read in stack->a_toggles
        new_sp.struct_data.seq = old_sp.struct_data.seq + 1;                     // increase timestamp
        new_sp.struct_data.index = _SIM_LOCAL_POOL_SIZE_ * pid + th_state->local_index;  // store in mod_dw.index the index in stack->pool where lsp_data will be stored
        if (old_sp.raw_data==stack->sp.raw_data &&
            CAS64(&stack->sp.raw_data, old_sp.raw_data, new_sp.raw_data)) {
            th_state->local_index = (th_state->local_index + 1) % _SIM_LOCAL_POOL_SIZE_;
            return lsp_data->ret[pid];
        }
        else {
            // rollback(&th_state->pool, push_counter);
        }
    }
    // return stack->pool[stack->sp.struct_data.index].ret[pid];                    // return the value found in the record stored there
    return 0;                    // return the value found in the record stored there
}
#endif



#ifdef ENABLE_SLEEP_TUNING
#define SLEEP_NANOSEC   SLEEP_TIME
thread_local struct timespec req = {
    .tv_sec = 0,
    .tv_nsec = SLEEP_NANOSEC
};
void inline nanosleep_invoke() {
    struct timespec rem;
    req.tv_nsec <<= 5;
    if (req.tv_nsec > 2000000) req.tv_nsec = SLEEP_TIME;
    nanosleep(&req, &rem);
}
void inline nanosleep_reduce() {
    req.tv_nsec >>= 1;
    if (req.tv_nsec == 0) req.tv_nsec = SLEEP_TIME;
}
#else
void inline nanosleep_invoke() {;}
#endif


thread_local void* last_state;
thread_local int fc_idx;
thread_local int num_of_modop = 0;
#include <string>
#include <vector>


template <typename T>
class RingBuffer
  {
    SimStruct* stack;
    struct GarbageCollector;
    struct RingBuffer_synobj;
    typedef struct RingBuffer_synobj synobj_t;
    typedef std::atomic<synobj_t*> atomic_synobj_t __attribute__((aligned (64)));

    typedef struct wrapper_s{
        wrapper_s* gc_next;
        T value;
#ifdef ENABLE_REVALIDATION
        int version;
#endif
    } wrapper_t;
    typedef T value_t;

    struct OpType {
        unsigned op_type;
        T param;
    };

    // OpType Announce[GC_MAX_THREADS];
    // bitvector Act;

    struct RetType {
        bool succ;
        T ret;
    };

    #include "single_snapshot_util.h"

    volatile synobj_t* fc_state;
    struct RingBuffer_synobj{
      ObjectState fcobj;

      size_t tail;size_t head;
      Template_Synobj<wrapper_t,value_t> synobj;

      // etType rvals[GC_MAX_THREADS];
      // bitvector applied;

      inline void insert_mod(wrapper_t** addr, wrapper_t* old_val, value_t new_val)
      {
          synobj.insert_mod(addr, old_val, new_val);
      }
      inline void apply_mod()
      {
          synobj.apply_mod();
      }

      inline void reclaim_wrappers ()
      {
          synobj.reclaim_wrappers();
      }

      inline RingBuffer_synobj& operator =(RingBuffer_synobj& that)
      {
          tail=that.tail;
          head=that.head;
          synobj=that.synobj;
          return *this;
      }
    };

    void fc_init() {
        if (local_gc_idx == -1) {
            get_gc_idx();
            last_state = 0;
            SimThreadStateInit();
        }
    }

inline void SimApplyOp(SimStruct *stack, RetVal& fc_ret) {
   synobj_t *oldstate, *newstate;
   newstate = allocate_synobj();

    int pid = local_gc_idx;
    // ArgVal arg = 100;

    ToggleVector diffs, l_toggles, pops;
    pointer_t new_sp, old_sp;
    HalfObjectState *lsp_data, *sp_data;
    int i, j, prefix, mybank, push_counter;
    ArgVal tmp_arg;

    mybank = TVEC_GET_BANK_OF_BIT(pid);
    TVEC_REVERSE_BIT(&th_state->my_bit, pid);
    TVEC_NEGATIVE_BANK(&th_state->toggle, &th_state->toggle, mybank);
    // lsp_data = (HalfObjectState *)&stack->pool[pid * _SIM_LOCAL_POOL_SIZE_ + th_state->local_index];
    lsp_data = (HalfObjectState *)(&(newstate->fcobj));

    // stack->announce[pid] = arg;                                                  // stack->announce the operation
    TVEC_ATOMIC_ADD_BANK(&stack->a_toggles, &th_state->toggle, mybank);          // toggle pid's bit in stack->a_toggles, Fetch&Add acts as a full write-barrier

    for (j = 0; j < 2; j++) {
        // old_sp = stack->sp;                                                      // read reference to struct ObjectState
        // old_sp.raw_data = stack->sp.raw_data;
        // oldstate = fc_state;
        volatile synobj_t* _old_state = fc_state;
        oldstate = const_cast<synobj_t*>(_old_state);
        oldstate = load_current_state(oldstate);
        // sp_data = (HalfObjectState *)&stack->pool[old_sp.struct_data.index];     // read reference of struct ObjectState in a local variable lsp_data
        sp_data = (HalfObjectState *)(&(oldstate->fcobj));     // read reference of struct ObjectState in a local variable lsp_data
        TVEC_ATOMIC_COPY_BANKS(&diffs, &sp_data->applied, mybank);
        TVEC_XOR_BANKS(&diffs, &diffs, &th_state->my_bit, mybank);               // determine the set of active processes
        if (TVEC_IS_SET(diffs, pid))                                             // if the operation has already been applied return
            break;
        *lsp_data = *sp_data;
        *newstate = *oldstate;
        // l_toggles = stack->a_toggles;                                            // This is an atomic read, since a_toogles is volatile
        volatile ToggleVector _l_toggles;
        int _i;
        LOOP(l_toggles.cell[_i] = stack->a_toggles.cell[_i], _i);

        // if (old_sp.raw_data != stack->sp.raw_data) continue;
        if (oldstate != fc_state) continue;
        diffs = TVEC_XOR(lsp_data->applied, l_toggles);
        push_counter = 0;
        TVEC_SET_ZERO(&pops);
        for (i = 0, prefix = 0; i < _TVEC_CELLS_; i++, prefix += _TVEC_BIWORD_SIZE_) {
            ReadPrefetch(&stack->announce[prefix]);
#if N_THREADS > 7
            ReadPrefetch(&stack->announce[prefix + 8]);
#endif
#if N_THREADS > 15
            ReadPrefetch(&stack->announce[prefix + 16]);
#endif
#if N_THREADS > 23
            ReadPrefetch(&stack->announce[prefix + 24]);
#endif
            while (diffs.cell[i] != 0L) {
                register int pos, proc_id;

                pos = bitSearchFirst(diffs.cell[i]);
                proc_id = prefix + pos;
                diffs.cell[i] ^= ((bitword_t)1) << pos;
                tmp_arg.op_type = stack->announce[proc_id].op_type;
                tmp_arg.param = stack->announce[proc_id].param;
switch (tmp_arg.op_type) {
case 1: {
     bool ret;
     T item = tmp_arg.param;
     T data_index_copy=0;
     if (SNAPSHOT(tail)-SNAPSHOT(head)>=capacity_)
       {
          ret = false;
       }
     else
       {
          int index=SNAPSHOT(tail);
          SNAPSHOT(tail) = SNAPSHOT(tail)+1;
          data_index_copy = item;
          MOD_WRITE(data[index%capacity_],data_index_copy);
          ret = true;
       }
    lsp_data->ret[prefix+pos].succ = ret;
    break;
}
case 2: {
     bool ret;
     T result;
     if (SNAPSHOT(tail)<=SNAPSHOT(head))
       {
          ret = false;
       }
     else
       {
          T tmp_var_0;
          MOD_READ(data[newstate->head%capacity_],tmp_var_0);
          result = tmp_var_0;
          SNAPSHOT(head) = SNAPSHOT(head)+1;
          ret = true;
       }
    lsp_data->ret[prefix+pos].succ = ret;
    lsp_data->ret[prefix+pos].ret = result;
    break;
}
default: {
    printf("unknown op_type %d\n", tmp_arg.op_type);
}
}
            }
        }

        lsp_data->applied = l_toggles;                                           // change applied to be equal to what was read in stack->a_toggles
        // new_sp.struct_data.seq = old_sp.struct_data.seq + 1;                     // increase timestamp
        // new_sp.struct_data.index = _SIM_LOCAL_POOL_SIZE_ * pid + th_state->local_index;  // store in mod_dw.index the index in stack->pool where lsp_data will be stored
        /*
        if (old_sp.raw_data==stack->sp.raw_data &&
            CAS64(&stack->sp.raw_data, old_sp.raw_data, new_sp.raw_data)) {
            th_state->local_index = (th_state->local_index + 1) % _SIM_LOCAL_POOL_SIZE_;
            return lsp_data->ret[pid];
        }
        else {
            // rollback(&th_state->pool, push_counter);
        }
        */
        if ((fc_state == oldstate) && CAS64(&fc_state, oldstate, newstate)) {
            newstate->apply_mod();
            retire_synobj(newstate);
            break;
        }
retry: ;
    }
    // return stack->pool[stack->sp.struct_data.index].ret[pid];                    // return the value found in the record stored there
/*
    volatile synobj_t* _old_state = fc_state;
    oldstate = const_cast<synobj_t*>(_old_state);
    oldstate->synobj.apply_mod(local_gc_idx);
*/
    fc_ret.succ = fc_state->fcobj.ret[local_gc_idx].succ;
    fc_ret.ret = fc_state->fcobj.ret[local_gc_idx].ret;
}





    public:
    public:
    RingBuffer (int capacity) : capacity_(capacity) {
       SimInit(stack);
       gc = new GarbageCollector ();
       struct RingBuffer_synobj* state_tmp=new RingBuffer_synobj ();
       state_tmp->synobj.parent_gc = gc;
       state_tmp->synobj.version_number = 0;
       state_tmp->head = 0;
       state_tmp->tail = 0;
       data = new wrapper_t* [capacity_];
       std::memset(data,0,capacity_*sizeof(wrapper_t*));
       // state = state_tmp;
       fc_state = state_tmp;
    }
     ~RingBuffer() {
#ifdef CHECK_CORRECTNESS
/*
        printf("%d, %d, %d\n", state.load()->synobj.version_number, state.load()->head, state.load()->tail);
        for (int i = state.load()->head; i < state.load()->tail; i++) {
            elem_counter[read_wrapper(data[i])]--;
        }
*/
        printf("%d, %d, %d\n", fc_state->synobj.version_number, fc_state->head, fc_state->tail);
        for (int i = fc_state->head; i < fc_state->tail; i++) {
            elem_counter[read_wrapper(data[i])]--;
        }
        bool succ = true;
        for (int i = 0; i < MAX_VAL; i++) {
            if (elem_counter[i]!=0) {
                printf("elem_counter[%d] != 0(%d)\n", i, elem_counter[i].load());
                succ = false;
            }
        }
        if (succ) {
            printf("Check done: Correct\n");
        } else {
            printf("\n\nCheck failed.\n");
        }
#endif
        delete gc;
    }

    ;
    bool push(T v) ;
    bool pop(T& v) ;
    bool isFull() ;
    bool isEmpty() ;
    unsigned size() {

       int __ret__8;

       READ_OP_BEGIN
         // read operation begin

         __ret__8 = SNAPSHOT(tail)-SNAPSHOT(head);
         // read operation end
       READ_OP_END
       return __ret__8;
    }
    private:
    wrapper_t** data;
    const size_t capacity_;
    ;
    ;
  };

template <typename T>
bool RingBuffer<T>::push(T item) {
   fc_init();
   ArgVal arg;
   RetVal ret;
   stack->announce[local_gc_idx].param = item;
   stack->announce[local_gc_idx].op_type = 1;
   SimApplyOp(stack, ret);
#ifdef CHECK_CORRECTNESS
   assert(ret.succ);
   elem_counter[item] ++;
#endif
   return ret.succ;
}
template <class T>
bool RingBuffer<T>::pop(T& result) {
   fc_init();
   RetVal ret;
   stack->announce[local_gc_idx].op_type = 2;
   SimApplyOp(stack, ret);
   result = ret.ret;
#ifdef CHECK_CORRECTNESS
   assert(ret.succ);
   elem_counter[result] --;
#endif
   return ret.succ;
}








#if 0
template <typename T>
bool RingBuffer<T>::push(T item) {
// printf("begin push %d\n", item);
   fc_init();
// printf("fc_idx %d\n", fc_idx);
   Announce[fc_idx].param = item;
   Announce[fc_idx].op_type = 1;
   offset_i.reverse();

/*
printf("%u\n", Act.bits[0]);
printf("%u\n", Act.bits[1]);
printf("%u\n", Act.bits[2]);
printf("%u\n", Act.bits[3]);
printf("%u\n", Act.bits[4]);
printf("%u\n", offset_i.bit);
printf("%d\n", offset_i.idx);
*/
   Act.fetch_and_add(offset_i);
/*
printf("Act\n");
printf("%u\n", Act.bits[0]);
printf("%u\n", Act.bits[1]);
printf("%u\n", Act.bits[2]);
printf("%u\n", Act.bits[3]);
printf("%u\n", Act.bits[4]);
printf("offset_i\n");
printf("%u\n", offset_i.bit);
*/
   bitvector active;
   bitvector diffs;

   bool ret;

   synobj_t *oldstate, *newstate;
   newstate = allocate_synobj();
   oldstate = state.load();

   int fc_loop_count = 0;
   while (true) {
     fc_loop_count ++;
     if (fc_loop_count >2) break;
     oldstate = load_current_state(oldstate);

     active.copy(Act);
     uint64_t applied_bit;
     oldstate->applied.compute_xor(active, diffs);
/*
printf("diffs\n");
printf("%u\n", diffs.bits[0]);
printf("%u\n", diffs.bits[1]);
printf("%u\n", diffs.bits[2]);
printf("%u\n", diffs.bits[3]);
printf("%u\n", diffs.bits[4]);
printf("mask_i\n");
printf("%u\n", mask_i.bit);
*/
     diffs.compute_and(mask_i, applied_bit);
     if (applied_bit == 0) break;
     // assert(applied_bit != 0);
     *newstate = *oldstate;
/*
printf("%u\n", active.bits[0]);
printf("%u\n", active.bits[1]);
printf("%u\n", active.bits[2]);
printf("%u\n", active.bits[3]);
printf("%u\n", active.bits[4]);
*/

     if(!flatcombining_operation(oldstate, newstate, diffs)) goto retry;
     newstate->applied.copy(active);

     if (state == oldstate) {
        if (state.compare_exchange_weak(oldstate,newstate)) {
            newstate->apply_mod();
            retire_synobj(newstate);
            break;
        }
     }
retry:
     oldstate = state.load();
   }

   RetType fc_ret = state.load()->rvals[fc_idx];
   ret = fc_ret.succ;
   // assert(ret);
#ifdef CHECK_CORRECTNESS
   if(ret) elem_counter[item] ++;
#endif
// printf("end push %d\n", item);
   return ret;
}
template <class T>
bool RingBuffer<T>::pop(T& result) {
// printf("begin push %d\n", item);
   fc_init();
// printf("fc_idx %d\n", fc_idx);
   Announce[fc_idx].op_type = 2;
   offset_i.reverse();

/*
printf("%u\n", Act.bits[0]);
printf("%u\n", Act.bits[1]);
printf("%u\n", Act.bits[2]);
printf("%u\n", Act.bits[3]);
printf("%u\n", Act.bits[4]);
printf("%u\n", offset_i.bit);
printf("%d\n", offset_i.idx);
*/
   Act.fetch_and_add(offset_i);
/*
printf("Act\n");
printf("%u\n", Act.bits[0]);
printf("%u\n", Act.bits[1]);
printf("%u\n", Act.bits[2]);
printf("%u\n", Act.bits[3]);
printf("%u\n", Act.bits[4]);
printf("offset_i\n");
printf("%u\n", offset_i.bit);
*/
   bitvector active;
   bitvector diffs;

   bool ret;

   synobj_t *oldstate, *newstate;
   newstate = allocate_synobj();
   oldstate = state.load();

   int fc_loop_count = 0;
   while (true) {
     fc_loop_count ++;
     if (fc_loop_count >2) break;
     oldstate = load_current_state(oldstate);

     active.copy(Act);
     uint64_t applied_bit;
     oldstate->applied.compute_xor(active, diffs);
/*
printf("diffs\n");
printf("%u\n", diffs.bits[0]);
printf("%u\n", diffs.bits[1]);
printf("%u\n", diffs.bits[2]);
printf("%u\n", diffs.bits[3]);
printf("%u\n", diffs.bits[4]);
printf("mask_i\n");
printf("%u\n", mask_i.bit);
*/
     diffs.compute_and(mask_i, applied_bit);
     if (applied_bit == 0) break;

     *newstate = *oldstate;
     // assert(applied_bit != 0);
/*
printf("%u\n", active.bits[0]);
printf("%u\n", active.bits[1]);
printf("%u\n", active.bits[2]);
printf("%u\n", active.bits[3]);
printf("%u\n", active.bits[4]);
*/

     if(!flatcombining_operation(oldstate, newstate, diffs)) goto retry;
     newstate->applied.copy(active);

     if (state == oldstate) {
        if (state.compare_exchange_weak(oldstate,newstate)) {
            newstate->apply_mod();
            retire_synobj(newstate);
            break;
        }
     }
retry:
     oldstate = state.load();
   }

   RetType fc_ret = state.load()->rvals[fc_idx];
   result = fc_ret.ret;
   ret = fc_ret.succ;
   // assert(ret);
#ifdef CHECK_CORRECTNESS
   if(ret) elem_counter[result] --;
#endif
// printf("end push %d\n", item);
   return ret;



// printf("begin pop\n");
/*
   get_gc_idx();
   fcreq_t* req = fcreq_array[local_gc_idx];

   req->op_type = 2;
   bool ret;

   synobj_t *oldstate, *newstate;
   newstate = allocate_synobj();
   oldstate = state.load();
   newstate->fcobj.req_status.reset();

   while (true) {
     oldstate = load_current_state(oldstate);
     *newstate = *oldstate;

     req = fcreq_array[local_gc_idx];
     if (req->op_type == -1) break;
     if(!flatcombining_operation(oldstate, newstate)) goto retry;

     if (state == oldstate) {
        if (state.compare_exchange_weak(oldstate,newstate)) {
            newstate->apply_mod();
            break;
        }
     }
retry:
     req = fcreq_array[local_gc_idx];
     if (req->op_type == -1) break;
     if (oldstate->fcobj.req_status[local_gc_idx] == true) {
        oldstate->fcobj.apply_fclog(local_gc_idx);
        if(fcreq_array[local_gc_idx]->op_type == -1)
            break;
     }
     oldstate = state.load();
   }


   retire_synobj(newstate);
   req = fcreq_array[local_gc_idx];
   ret = req->succ;
   result = req->ret;
#ifdef CHECK_CORRECTNESS
   if(ret) elem_counter[result] --;
#endif
// printf("end pop\n");
   return ret;
*/
}
#endif
template <class T>
bool RingBuffer<T>::isFull() {

   bool __ret__4;

   READ_OP_BEGIN
     // read operation begin

     __ret__4 = SNAPSHOT(tail)-SNAPSHOT(head)>=capacity_;
     // read operation end
   READ_OP_END
   return __ret__4;
}
template <class T>
bool RingBuffer<T>::isEmpty() {

   bool __ret__6;

   READ_OP_BEGIN
     // read operation begin

     __ret__6 = SNAPSHOT(tail)<=SNAPSHOT(head);
     // read operation end
   READ_OP_END
   return __ret__6;
}


/*************************************************
    Adapter for benchmark
**************************************************/

template <class T>
class lightweight_struct {
    RingBuffer<T> queue;
public:
    lightweight_struct(int _size): queue(_size) {}
    void push(T send_v, int percent_v) {
        if (send_v == 0) send_v = 1;
        queue.push(send_v);
    }
    T pop(int percent_v) {
        T ret;
        bool res = queue.pop(ret);
        return ret;
    }
};

#endif // NONBLOCKING_RINGBUFFER
