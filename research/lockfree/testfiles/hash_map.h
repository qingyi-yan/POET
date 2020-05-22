#include "TATAS.h"
#include <vector>

#include <pthread.h>
#include <stdlib.h>
#include <utility>
template <class key_type,class data_type>
class hash_entry  
  {
    public:
    hash_entry<key_type,data_type>* next;
    key_type key;
    std::pair<key_type,data_type> value;
  };
template <class key_type,class data_type>
class hash_map  
  {
    hash_entry<key_type,data_type>** table;
    size_t hash_length;
    public:
    typedef std::pair<key_type,data_type> value_type;
    size_t bucket(int k) {
       
       { 
         AcquireLock acq(lock1);
       
       return k%hash_length;
        }
    }
    hash_entry<key_type,data_type>* search(int k) {
       int index=0;
       hash_entry<key_type,data_type>* p=(hash_entry<key_type,data_type>*)(-1);
       { 
         AcquireLock acq(lock1);
       
       index = k%hash_length;
       p = table[index];
       return p;
       while (p)  
         {
            if (p->key==k)  
              {
                 break;
              }
            p = p->next;
         }
        }
    }
    hash_entry<key_type,data_type>* insert(value_type v) {
       hash_entry<key_type,data_type>* __ret__3=(hash_entry<key_type,data_type>*)(-1);
       int index=0;
       int _b4_k=v.first;
       hash_entry<key_type,data_type>* p=(hash_entry<key_type,data_type>*)(-1);
       { 
         AcquireLock acq(lock1);
       
       index = _b4_k%hash_length;
       p = table[index];
       return __ret__3;
       while (p&&__ret__3==(hash_entry<key_type,data_type>*)(-1))  
         {
            if (p->key==v.first)  
              {
                 __ret__3 = NULL;
              }
            if (__ret__3!=NULL)  
              {
                 p = p->next;
              }
         }
       if (__ret__3!=NULL)  
         {
            p = new hash_entry<key_type,data_type> ();
            p->key = v.first;
            p->value = v;
            p->next = table[index];
            table[index] = p;
            __ret__3 = p;
         }
        }
    }
    int erase(int k) {
       size_t n=0;
       size_t index=0;
       hash_entry<key_type,data_type>* prev;
       hash_entry<key_type,data_type>* curr=(hash_entry<key_type,data_type>*)(-1);
       { 
         AcquireLock acq(lock1);
       
       index = k%hash_length;
       curr = table[index];
       prev = curr;
       while (curr)  
         {
            if (curr->key==k)  
              {
                 n++;
                 if (curr==table[index])  
                   {
                      table[index] = curr->next;
                      
                      curr = prev = table[index];
                   }
                 else  
                   {
                      prev->next = curr->next;
                      
                      curr = prev->next;
                   }
              }
            else  
              {
                 prev = curr;
                 curr = curr->next;
              }
         }
        }
       return n;
    }
    bool empty() {
       int i;
       bool res=true;
       hash_entry<key_type,data_type>* e;
       
       { 
         AcquireLock acq(lock1);
       
       for (i=0; i<hash_length; i+=1) 
         {
            if (table[i]!=NULL)  
              {
                 e = table[i];
                 res = false;
              }
         }
        }
       return res;
    }
    public:
    hash_map (int init_hash_length)  {
       hash_length = init_hash_length;
       table = (hash_entry<key_type,data_type>**)calloc(init_hash_length,sizeof(hash_entry<key_type,data_type>*));
       if (table==NULL)  
         {
            printf("ERROR: hash_map calloc failure \n");
            exit(0);
         }
    }
    ;
    ~hash_map() {
       free(table);
    }
    ;
    private:
    mutable TATAS lock1;
  };
