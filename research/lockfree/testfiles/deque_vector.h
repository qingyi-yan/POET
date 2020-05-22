#include "TATAS.h"
#include <vector>

#include <stdio.h>
#include <iostream>
#include <cstring>
#define VECTOR_SIZE 4
template <class T>
class deque  
  {
    public:
    std::size_t counter;
    std::size_t curr_max_size;
    T* list_base;
    typedef T value_type;
    typedef T& reference;
    typedef T* iterator;
    typedef std::size_t size_type;
    public:
    deque ()  {
       counter = 0;
       curr_max_size = VECTOR_SIZE-1;
       list_base = new T [VECTOR_SIZE];
    }
    ~deque() {
       delete list_base;
    }
    iterator begin() {
       iterator it=(T*)(-1);
       { 
         AcquireLock acq(lock1);
       
       it = list_base;
        }
       return it;
    }
    iterator end() {
       iterator it=(T*)(-1);
       { 
         AcquireLock acq(lock1);
       
       it = list_base+counter;
        }
       return it;
    }
    std::size_t size() {
       
       { 
         AcquireLock acq(lock1);
       
       return counter;
        }
    }
    bool empty() {
       
       { 
         AcquireLock acq(lock1);
       
       return counter<1;
        }
    }
    reference operator [](std::size_t n) {
       
       { 
         AcquireLock acq(lock1);
       
       return list_base[n];
        }
    }
    reference front() {
       
       { 
         AcquireLock acq(lock1);
       
       return list_base[0];
        }
    }
    reference back() {
       
       { 
         AcquireLock acq(lock1);
       
       return list_base[counter-1];
        }
    }
    void push_front(T x) {
       
       { 
         AcquireLock acq(lock1);
       
       if (counter==curr_max_size)  
         {
            std::size_t new_vector_size=curr_max_size+1<<1;
            T* new_base=new T [new_vector_size];
            std::memcpy(new_base+1,list_base,counter*sizeof(T));
            
            list_base = new_base;
            list_base[0] = x;
            curr_max_size = new_vector_size-1;
         }
       else  
         {
            std::memmove(list_base+1,list_base,counter*sizeof(T));
            list_base[0] = x;
         }
       counter++;
        }
    }
    void push_back(T x) {
       
       { 
         AcquireLock acq(lock1);
       
       if (counter==curr_max_size)  
         {
            std::size_t new_vector_size=curr_max_size+1<<1;
            T* new_base=new T [new_vector_size];
            std::memcpy(new_base,list_base,counter*sizeof(T));
            
            list_base = new_base;
            list_base[counter] = x;
            curr_max_size = new_vector_size-1;
         }
       else  
         {
            list_base[counter] = x;
         }
       counter++;
        }
    }
    void pop_front() {
       
       { 
         AcquireLock acq(lock1);
       
       if (counter>0)  
         {
            std::memcpy(list_base,list_base+1,(counter-1)*sizeof(T));
            counter--;
         }
        }
    }
    T pop_back() {
       T r;
       
       { 
         AcquireLock acq(lock1);
       
       r = list_base[counter-1];
       return r;
       counter--;
        }
    }
    iterator insert(iterator pos,T x) {
       std::size_t pos_distance=0;
       iterator it=(T*)(-1);
       { 
         AcquireLock acq(lock1);
       
       pos_distance = pos-list_base;
       it = list_base+pos_distance;
       if (counter==curr_max_size)  
         {
            std::size_t new_vector_size=curr_max_size+1<<1;
            T* new_list_base=new T [new_vector_size];
            if (pos_distance>0)  
              {
                 std::memcpy(new_list_base,list_base,pos_distance*sizeof(T));
              }
            new_list_base[pos_distance] = x;
            std::memcpy(new_list_base+pos_distance+1,list_base+pos_distance,(counter-pos_distance)*sizeof(T));
            
            list_base = new_list_base;
            curr_max_size = new_vector_size-1;
            counter++;
         }
       else  
         {
            std::memmove(list_base+pos_distance+1,list_base+pos_distance,(counter-pos_distance)*sizeof(T));
            list_base[pos_distance] = x;
            counter++;
         }
        }
       return it;
    }
    iterator erase(iterator pos) {
       std::size_t pos_distance=0;
       { 
         AcquireLock acq(lock1);
       
       pos_distance = pos-list_base;
       return &list_base[pos_distance];
       std::memmove(list_base+pos_distance,list_base+pos_distance+1,(counter-pos_distance-1)*sizeof(T));
       counter--;
        }
    }
    private:
    mutable TATAS lock1;
  };
