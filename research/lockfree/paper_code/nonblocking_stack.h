
#ifdef NONBLOCKING_STACK

// #define ENABLE_SLEEP_TUNING
// #define ENABLE_MEM_REUSE

#define GC_MAX_THREADS  300
#define CONFLICT_ARRAY_SIZE  80000000
#define GC_BLOCK_NUM        1000
// #define GC_BLOCK_SIZE       (80000000/NUM_OF_THREADS)
#define GC_BLOCK_SIZE       (65536)
#define GC_RESERVE_SIZE     (64)

#define LOG_NUM             1

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

thread_local int local_gc_idx = -1;
thread_local int num_of_modop = 0;
#include <string>
#include <vector>

template <typename T>
class Stack
  {
    struct GarbageCollector;
    struct Stack_synobj;
    typedef struct Stack_synobj synobj_t;

    typedef struct wrapper_s{
        wrapper_s* gc_next;
        T value;
#ifdef ENABLE_REVALIDATION
        int version;
#endif
    } wrapper_t;
    typedef T value_t;

    #include "single_snapshot_util.h"
    struct Stack_synobj{
      size_t idx_;

      GarbageCollector* parent_gc;
      Template_Synobj<wrapper_t,value_t> synobj;

      void insert_mod(wrapper_t** addr, wrapper_t* old_val, value_t new_val)
      {
          synobj.insert_mod(addr, old_val, new_val);
      }
      void apply_mod()
      {
          synobj.apply_mod();
      }

      void reclaim_wrappers ()
      {
          synobj.reclaim_wrappers();
      }
      Stack_synobj& operator =(Stack_synobj& that)
      {
          idx_=that.idx_;
          synobj=that.synobj;
          return *this;
      }

    };

    ;
    public:
    public:
    Stack (int capacity) : capacity_(capacity) {
       gc = new GarbageCollector ();
       struct Stack_synobj* state_tmp=new Stack_synobj ();
       state_tmp->synobj.parent_gc = gc;
       state_tmp->synobj.version_number = 0;
       state_tmp->idx_ = 0;
       array_ = new wrapper_t* [capacity_];
       std::memset(array_,0,capacity_*sizeof(wrapper_t*));
        /*
       for (int i=0; i<capacity_; i+=1)
         {
            WRP_WRITE(array_[i]) = 0;
         }
        */
       state = state_tmp;
    }

    ~Stack() {
#ifdef CHECK_CORRECTNESS
        printf("%d, %d\n", state.load()->synobj.version_number, state.load()->idx_);
        for (int i = 0; i < state.load()->idx_; i++) {
            elem_counter[read_wrapper(array_[i])]--;
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
    bool push(T t) ;
    bool pop(T& t) ;
    bool isFull() ;
    bool isEmpty() ;
    unsigned size() {

       size_t __ret__8;
       READ_OP_BEGIN
         // read operation begin

         __ret__8 = SNAPSHOT(idx_);
         // read operation end
       READ_OP_END
       return __ret__8;
    }
    private:
    const size_t capacity_;
    ;
    wrapper_t** array_;
  };
template <typename T>
bool Stack<T>::push(T t) {

   bool ret;
   WRITE_OP_BEGIN
     // write operation begin

     T array__newstate_idx__copy=0;
     if (SNAPSHOT(idx_)<capacity_)
       {
          array__newstate_idx__copy = t;
          MOD_WRITE(array_[newstate->idx_],array__newstate_idx__copy);
          newstate->idx_++;
          ret = true;
       }
     else
       {
          ret = false;
       }

     // write operation end
   WRITE_OP_END
#ifdef CHECK_CORRECTNESS
    elem_counter[t] ++;
#endif
   return ret;
}
template <typename T>
bool Stack<T>::pop(T& t) {

   bool ret;
   WRITE_OP_BEGIN
     // write operation begin

     if (SNAPSHOT(idx_)>0)
       {
          T tmp_var_0;
          MOD_READ(array_[SNAPSHOT(idx_)-1],tmp_var_0);
          t = tmp_var_0;
          newstate->idx_--;
          ret = true;
       }
     else
       {
          ret = false;
       }

     // write operation end
   WRITE_OP_END

#ifdef CHECK_CORRECTNESS
    elem_counter[t] --;
#endif
   return ret;
}
template <typename T>
bool Stack<T>::isFull() {

   bool __ret__4;
   READ_OP_BEGIN
     // read operation begin

     __ret__4 = SNAPSHOT(idx_)>capacity_;
     // read operation end
   READ_OP_END
   return __ret__4;
}
template <typename T>
bool Stack<T>::isEmpty() {

   bool __ret__6;
   READ_OP_BEGIN
     // read operation begin

     __ret__6 = SNAPSHOT(idx_)<=0;
     // read operation end
   READ_OP_END
   return __ret__6;
}


/*************************************************
    Adapter for benchmark
**************************************************/

template <class T>
class lightweight_struct {
    Stack<T> queue;
public:
    lightweight_struct(int _size): queue(_size) {}
    void push(T send_v, int percent_v) {
        queue.push(send_v);
    }
    T pop(int percent_v) {
        T ret;
        bool res = queue.pop(ret);
        assert(res);
        return ret;
    }
};

#endif // NONBLOCKING_STACK

