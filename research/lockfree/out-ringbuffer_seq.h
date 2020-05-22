// unable to partition data

// unsafe revalidation

#include "nonblocking_header.h"
#include <string>
template <typename T>
class RingBuffer  
  {
    struct GarbageCollector;
    struct RingBuffer_synobj;
    typedef struct RingBuffer_synobj synobj_t;
    
    typedef struct {
        T value;
        int version;
    } wrapper_t;
    typedef T value_t;
    
    #include "nonblocking_sync.h"
    struct RingBuffer_synobj{
      size_t tail;size_t head;
       
      synobj_t* gc_next;
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
      RingBuffer_synobj& operator =(RingBuffer_synobj& that)
      {
          tail=that.tail;
          head=that.head;
          synobj=that.synobj;
          return *this;
      }
      
    };
    
    ;
    public:
    RingBuffer (int capacity) : capacity_(capacity) {
       gc = new GarbageCollector ();
       struct RingBuffer_synobj* state_tmp=new RingBuffer_synobj ();
       state_tmp->synobj.parent_gc = gc;
       state_tmp->synobj.version_number = 1;
       state = state_tmp;
       state_tmp->head = 0;
       state_tmp->tail = 0;
       data = new wrapper_t* [capacity_];
       std::memset (data,0,capacity_*sizeof wrapper_t*,);
    }
    ;
    bool push(T v) ;
    bool pop(T& v) ;
    bool isFull() ;
    bool isEmpty() ;
    unsigned size() {
        
       int __ret__4;
       READ_OP_BEGIN
         // read operation begin
         
         __ret__4 = SNAPSHOT(tail)-SNAPSHOT(head);
         // read operation end
       READ_OP_END
       return __ret__4;
    }
    private:
    wrapper_t** data;
    const size_t capacity_;
    ;
    ;
  };
template <typename T>
bool RingBuffer<T>::push (T item) {
    
   bool ret;
   WRITE_OP_BEGIN
     // write operation begin
     
     T data_index_copy=0;
     if (SNAPSHOT(tail)-SNAPSHOT(head)>=capacity_) 
       {
          ret = false;
       }
     else 
       {
          int index=SNAPSHOT(tail);
          SNAPSHOT_WRITE(tail,SNAPSHOT(tail)+1);;
          data_index_copy = item;
          MOD_WRITE(data[index%capacity_],data_index_copy);
          ret = true;
       }
     
     // write operation end
   WRITE_OP_END
   return ret;
}
template <class T>
bool RingBuffer<T>::pop (T& result) {
    
   bool ret;
   WRITE_OP_BEGIN
     // write operation begin
     
     if (SNAPSHOT(tail)<=SNAPSHOT(head)) 
       {
          ret = false;
       }
     else 
       {
          T tmp_var_0;
          MOD_READ(data[SNAPSHOT(head)%capacity_],tmp_var_0);
          result = tmp_var_0;
          SNAPSHOT_WRITE(head,SNAPSHOT(head)+1);;
          ret = true;
       }
     
     // write operation end
   WRITE_OP_END
   return ret;
}
template <class T>
bool RingBuffer<T>::isFull () {
   
}
template <class T>
bool RingBuffer<T>::isEmpty () {
   
}
