#include "TATAS.h"
#include <vector>

#include <string>
template <typename T>
class Stack  
  {
    public:
    public:
    Stack (int capacity) : capacity_(capacity),idx_(0) {
       array_ = new T [capacity_];
       for (int i=0; i<capacity_; i+=1) 
         {
            array_[i] = 0;
         }
    }
    ;
    bool push(T t) ;
    bool pop(T& t) ;
    bool peek(T& t) ;
    bool isFull() ;
    bool isEmpty() ;
    std::string toString() {
       
       { 
         AcquireLock acq(lock1);
       
       return "Capacity: "+std::to_string(capacity_)+"\n"+"Index: "+std::to_string(idx_);
        }
    }
    unsigned size() {
       
       { 
         AcquireLock acq(lock1);
       
       return idx_;
        }
    }
    private:
    const size_t capacity_;
    size_t idx_;
    T* array_;
    private:
    mutable TATAS lock1;
  };
template <typename T>
bool Stack<T>::push(T t) {
   int __ret__1=-1;
   
   { 
     AcquireLock acq(lock1);
   
   if (idx_<capacity_)  
     {
        array_[idx_++] = t;
        __ret__1 = true;
     }
   else  
     {
        __ret__1 = false;
     }
    }
   return __ret__1;
}
template <typename T>
bool Stack<T>::pop(T& t) {
   int __ret__2=-1;
   
   { 
     AcquireLock acq(lock1);
   
   if (idx_>0)  
     {
        t = array_[idx_-1];
        idx_--;
        __ret__2 = true;
     }
   else  
     {
        __ret__2 = false;
     }
    }
   return __ret__2;
}
template <typename T>
bool Stack<T>::peek(T& t) {
   int __ret__3=-1;
   
   { 
     AcquireLock acq(lock1);
   
   if (idx_>0)  
     {
        t = array_[idx_-1];
        __ret__3 = true;
     }
   else  
     {
        __ret__3 = false;
     }
    }
   return __ret__3;
}
template <typename T>
bool Stack<T>::isFull() {
   
   { 
     AcquireLock acq(lock1);
   
   return idx_>capacity_;
    }
}
template <typename T>
bool Stack<T>::isEmpty() {
   
   { 
     AcquireLock acq(lock1);
   
   return idx_<0;
    }
}
