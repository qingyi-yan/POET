#define ENABLE_DATA_PARTITION // data partitioned

// unsafe revalidation

#include "nonblocking_header.h"
#include <pthread.h>
#include <stdlib.h>
#include <utility>
template <class key_type>
class hash_set  
  {
    struct GarbageCollector;
    struct hash_set_synobj;
    typedef struct hash_set_synobj synobj_t;
    struct hash_entry;
    typedef hash_entry gc_node_t;
    #define ENABLE_GC_NODE_ALLOCATOR
    typedef struct {
        hash_entry* value;
        int version;
    } wrapper_t;
    typedef hash_entry* value_t;
    
    #include "nonblocking_sync.h"
    struct hash_entry{
      wrapper_t* next;
      key_type key;
    };
    wrapper_t** table;
    size_t hash_length;
    struct hash_set_synobj{
      ;
      hash_entry* table_entry;
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
      hash_set_synobj& operator =(hash_set_synobj& that)
      {
          
          synobj=that.synobj;
          return *this;
      }
      
    };
    
    ;
    public:
    bool search(int k) {
        
       bool ret=-1;
       hash_entry* p=(hash_entry*)(-1);
       READ_OP_BEGIN(k%hash_length)
         // read operation begin
         
         ret = false;
         hash_entry* tmp_var_0;
         SNAPSHOT_READ(table_entry,tmp_var_0);
         p = tmp_var_0;
         while (p)
           {
              if (p->key==k) 
                {
                   ret = true;
                   break;
                }
              else if (p->key>k) 
                {
                   ret = false;
                   break;
                }
              hash_entry* tmp_var_1;
              MOD_READ_R(p->next,tmp_var_1);
              p = tmp_var_1;
           }
         // read operation end
       READ_OP_END
       return ret;
    }
    bool insert(int k) {
        
       hash_entry* new_p=allocate_node();
       bool ret=-1;
       hash_entry* p=(hash_entry*)(-1);
       hash_entry* p_prev=(hash_entry*)(-1);
       WRITE_OP_BEGIN(k%hash_length)
         // write operation begin
         
         hash_entry* table_k_copy=0;
         hash_entry* p_prev_next_copy=0;
         ret = true;
         hash_entry* tmp_var_2;
         MOD_READ(table[k%hash_length],tmp_var_2);
         p = tmp_var_2;
         p_prev = 0;
         while (p)
           {
              if (p->key==k) 
                {
                   ret = false;
                   break;
                }
              else if (p->key>k) 
                {
                   ret = true;
                   break;
                }
              p_prev = p;
              hash_entry* tmp_var_3;
              MOD_READ(p->next,tmp_var_3);
              p = tmp_var_3;
           }
         if (ret) 
           {
              new_p->key = k;
              WRP_WRITE(new_p->next) = p;
              if (p_prev==0) 
                {
                   table_k_copy = new_p;
                   SNAPSHOT_WRITE(table_entry,table_k_copy);
                }
              else 
                {
                   p_prev_next_copy = new_p;
                   MOD_WRITE(p_prev->next,p_prev_next_copy);
                }
           }
         
         // write operation end
       WRITE_OP_END
       return ret;
    }
    bool erase(int k) {
        
       bool ret=-1;
       hash_entry* curr=(hash_entry*)(-1);
       hash_entry* prev=(hash_entry*)(-1);
       WRITE_OP_BEGIN(k%hash_length)
         // write operation begin
         
         hash_entry* table_k_copy=0;
         hash_entry* prev_next_copy=0;
         ret = false;
         hash_entry* tmp_var_4;
         MOD_READ(table[k%hash_length],tmp_var_4);
         curr = tmp_var_4;
         prev = 0;
         while (curr)
           {
              if (curr->key==k) 
                {
                   ret = true;
                   break;
                }
              else if (curr->key>k) 
                {
                   ret = false;
                   break;
                }
              prev = curr;
              hash_entry* tmp_var_5;
              MOD_READ(curr->next,tmp_var_5);
              curr = tmp_var_5;
           }
         if (ret) 
           {
              if (prev==0) 
                {
                   hash_entry* tmp_var_6;
                   MOD_READ(curr->next,tmp_var_6);
                   table_k_copy = tmp_var_6;
                   SNAPSHOT_WRITE(table_entry,table_k_copy);
                }
              else 
                {
                   hash_entry* tmp_var_7;
                   MOD_READ(curr->next,tmp_var_7);
                   prev_next_copy = tmp_var_7;
                   MOD_WRITE(prev->next,prev_next_copy);
                }
           }
         
         // write operation end
       WRITE_OP_END
       return ret;
    }
    hash_set (int init_hash_length)  {
       gc = new GarbageCollector ();
       struct hash_set_synobj* state_tmp=new hash_set_synobj ();
       state_tmp->synobj.parent_gc = gc;
       state_tmp->synobj.version_number = 1;
       state = state_tmp;
       hash_length = init_hash_length;
       table = (hash_entry**)calloc(init_hash_length,sizeof (hash_entry*));
       if (table==NULL) 
         {
            "ERROR: hash_set calloc failure \n"
            printf();
            exit(0);
         }
    }
    ;
    ~hash_set() {
       free(table);
    }
    ;
  };
