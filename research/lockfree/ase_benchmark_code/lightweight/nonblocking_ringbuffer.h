
#ifdef NONBLOCKING_RINGBUFFER

#include "ringbuffer_header.h"

template <typename T>
class RingBuffer
  {
    struct GarbageCollector;
    struct RingBuffer_synobj;
    typedef struct RingBuffer_synobj synobj_t;

    typedef struct wrapper_s{
        wrapper_s* gc_next;
        T value;
        int version;
    } wrapper_t;
    typedef T value_t;

    #include "nonblocking_sync.h"

    struct RingBuffer_synobj{
      synobj_t* gc_next;

      size_t tail;size_t head;
      Template_Synobj<wrapper_t,value_t> synobj;

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


    public:
    RingBuffer (int capacity) : capacity_(capacity) {
       gc = new GarbageCollector ();
       struct RingBuffer_synobj* state_tmp=new RingBuffer_synobj ();
       state_tmp->synobj.parent_gc = gc;
       state_tmp->synobj.version_number = 1;
       state_tmp->head = 0;
       state_tmp->tail = 0;
       data = new wrapper_t* [capacity_];
       std::memset(data,0,capacity_*sizeof(wrapper_t*));
       state = state_tmp;
    }
     ~RingBuffer() {
#ifdef CHECK_CORRECTNESS
        printf("%d, %d, %d\n", state.load()->synobj.version_number, state.load()->head, state.load()->tail);
        for (int i = state.load()->head; i < state.load()->tail; i++) {
            elem_counter[read_wrapper(data[i%capacity_])]--;
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
   bool ret;
   WRITE_OP_BEGIN
     // write operation begin

     ret = false;
     T data_index_copy=0;
     if (SNAPSHOT(tail)-SNAPSHOT(head)>=capacity_)
       {
          ret = false;
       }
     else
       {
          int index=SNAPSHOT(tail);
          SNAPSHOT_WRITE(tail, SNAPSHOT(tail)+1);
          data_index_copy = item;
          MOD_WRITE(data[index%capacity_],data_index_copy);
          ret = true;
       }

     // write operation end
   WRITE_OP_END

#ifdef CHECK_CORRECTNESS
   if(ret) elem_counter[item] ++;
#endif
   return ret;
}
template <class T>
bool RingBuffer<T>::pop(T& result) {
   bool ret;

   WRITE_OP_BEGIN
     // write operation begin
     ret = false;
     if (SNAPSHOT(tail)<=SNAPSHOT(head))
       {
          ret = false;
       }
     else
       {
          T tmp_var_0;
          MOD_READ(data[newstate->head%capacity_],tmp_var_0);
          result = tmp_var_0;
          SNAPSHOT_WRITE(head, SNAPSHOT(head)+1);
          ret = true;
       }
     // write operation end
   WRITE_OP_END
#ifdef CHECK_CORRECTNESS
   if(ret) elem_counter[result] --;
#endif
   return ret;
}
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
