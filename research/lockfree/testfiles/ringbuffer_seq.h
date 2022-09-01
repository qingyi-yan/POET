#include "TATAS.h"
#include <vector>

#include <string>
template <typename T>
class RingBuffer  
  {
    public:
    public:
    RingBuffer (int capacity) : capacity_(capacity) {
       head = 0;
       tail = 0;
       data = new T [capacity_];
    }
    ;
    bool push(T v) ;
    bool pop(T& v) ;
    bool isFull() ;
    bool isEmpty() ;
    std::string toString() {
       
       { 
         AcquireLock acq(lock1);
       
       return "Capacity: "+std::to_string(capacity_)+"\n"+"Index: "+std::to_string(tail-head);
        }
    }
    unsigned size() {
       
       { 
         AcquireLock acq(lock1);
       
       return tail-head;
        }
    }
    private:
    T* data;
    const size_t capacity_;
    size_t head;
    size_t tail;
    private:
    mutable TATAS lock1;
  };
template <typename T>
bool RingBuffer<T>::push(T item) {
   int __ret__1=-1;
   
   { 
     AcquireLock acq(lock1);
   
   if (tail-head>=capacity_)  
     {
        __ret__1 = false;
     }
   if (__ret__1!=false)  
     {
        int index=tail++;
        data[index%capacity_] = item;
        __ret__1 = true;
     }
    }
   return __ret__1;
}
template <class T>
bool RingBuffer<T>::pop(T& result) {
   int __ret__2=-1;
   
   { 
     AcquireLock acq(lock1);
   
   if (tail<=head)  
     {
        __ret__2 = false;
     }
   if (__ret__2!=false)  
     {
        result = data[head%capacity_];
        head++;
        __ret__2 = true;
     }
    }
   return __ret__2;
}
template <class T>
bool RingBuffer<T>::isFull() {
   
   { 
     AcquireLock acq(lock1);
   
   return tail-head>=capacity_;
    }
}
template <class T>
bool RingBuffer<T>::isEmpty() {
   
   { 
     AcquireLock acq(lock1);
   
   return tail<=head;
    }
}
