
#ifdef NONBLOCKING_STACK

#include "stack_header.h"

template <typename T>
class Stack
  {
    struct GarbageCollector;
    struct Stack_synobj;
    typedef struct Stack_synobj synobj_t;

    typedef struct wrapper_s{
        wrapper_s* gc_next;
        T value;
        int version;
    } wrapper_t;
    typedef T value_t;

    #include "nonblocking_sync.h"
    struct Stack_synobj{
      synobj_t* gc_next;
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
       state = state_tmp;
    }

    ~Stack() {
#ifdef CHECK_CORRECTNESS
        printf("%d, %d\n", state.load()->synobj.version_number, state.load()->idx_);
        for (int i = 0; i < state.load()->idx_; i++) {
            elem_counter[read_wrapper(array_[i%capacity_])]--;
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
     ret = false;
     T array__newstate_idx__copy=0;
     if (SNAPSHOT(idx_)<capacity_)
       {
          array__newstate_idx__copy = t;
          MOD_WRITE(array_[newstate->idx_],array__newstate_idx__copy);
          SNAPSHOT_WRITE(idx_, SNAPSHOT(idx_)+1);
          ret = true;
       }
     else
       {
          ret = false;
       }

     // write operation end
   WRITE_OP_END
#ifdef CHECK_CORRECTNESS
    if(ret) elem_counter[t] ++;
#endif
   return ret;
}
template <typename T>
bool Stack<T>::pop(T& t) {

   bool ret;
   WRITE_OP_BEGIN
     // write operation begin
     ret = false;

     if (SNAPSHOT(idx_)>0)
       {
          T tmp_var_0;
          MOD_READ(array_[SNAPSHOT(idx_)-1],tmp_var_0);
          t = tmp_var_0;
          SNAPSHOT_WRITE(idx_, SNAPSHOT(idx_)-1);
          ret = true;
       }
     else
       {
          ret = false;
       }

     // write operation end
   WRITE_OP_END

#ifdef CHECK_CORRECTNESS
    if(ret) elem_counter[t] --;
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

