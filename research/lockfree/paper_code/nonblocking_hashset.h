
#ifdef NONBLOCKING_HASHSET

#include <vector>
#include <queue>
#include <cstring>

thread_local int snapshot_idx;
#define MAX_N_SNAPSHOT         6000000
// #define ENABLE_SLEEP_TUNING
#define ENABLE_REVALIDATION

#define GC_MAX_THREADS  256
#define CONFLICT_ARRAY_SIZE  80000000
// #define CONFLICT_ARRAY_SIZE 1000
// #define CONFLICT_ARRAY_SIZE 10
// #define GC_BLOCK_SIZE       (8000000/NUM_OF_THREADS)
#define RECLAIM_THRESHOLD   (1000)
#define GC_BLOCK_SIZE       (131072)
#define GC_RESERVE_SIZE     (10000)
#define LOG_NUM             1
#define READ_NUM        5
#define NODE_NUM        1

#ifdef ENABLE_SLEEP_TUNING
#define SLEEP_NANOSEC   10000
struct timespec req = {
    .tv_sec = 0,
    .tv_nsec = SLEEP_NANOSEC
};
void inline nanosleep_invoke() {
    struct timespec rem;
    nanosleep(&req, &rem);
}
#else
void inline nanosleep_invoke() {;}
#endif

thread_local int local_gc_idx = -1;
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
    typedef struct wrapper_s {
        wrapper_s* gc_next;
        hash_entry* value;
        int version;
    } wrapper_t;

    struct hash_entry {
        wrapper_t* next;
        key_type key;
    };
    typedef hash_entry* value_t;
    typedef hash_entry  gc_node_t;
    #define ENABLE_GC_NODE_ALLOCATOR

    wrapper_t** table;
    size_t hash_length;
    ;
    #include "../lightweight/single_snapshot_util.h"
    struct hash_set_synobj{
      hash_set_synobj* gc_next;
      GarbageCollector *parent_gc;
      Template_Synobj<wrapper_t,value_t> synobj;

      void insert_mod(wrapper_t** addr, wrapper_t* old_val, value_t new_val)
      {
        synobj.insert_mod(addr, old_val, new_val);
      }
      void apply_mod ()
      {
        synobj.apply_mod();
      }

      void reclaim_wrappers ()
      {
        synobj.reclaim_wrappers();
      }

      hash_set_synobj& operator =(hash_set_synobj& that)
      {
        // table_entry = that.table_entry;
        synobj = that.synobj;
        return *this;
      }

      hash_set_synobj& reload(hash_set_synobj& that)
      {
        synobj.reload(that.synobj);
        return *this;
      }
    };

    public:
    bool search(int k) {
       int index=0;
       bool ret = 0;
       hash_entry* p=0;

       READ_OP_BEGIN
         index = 0;
         ret = 0;
         index = k%hash_length;
         hash_entry* tmp_var_0;
         MOD_READ_R(table[index],tmp_var_0);
         p = tmp_var_0;
         while (p) {
            if (p->key==k) {
                ret = true;
                break;
            } else if (p->key > k) {
                ret = false;
                break;
            }
            hash_entry* tmp_var_1;
            MOD_READ_R(p->next,tmp_var_1);
            p = tmp_var_1;
         }
       READ_OP_END
       return ret;
    }
    bool insert(key_type k) {
       bool ret = 1;
       int index=0;
       hash_entry* p=0;
       hash_entry* p_prev=0;
       hash_entry* new_p = allocate_node();

       WRITE_OP_BEGIN;
         hash_entry* table_index_copy=0;
         hash_entry* p_prev_next_copy=0;
         ret = 1;
         // index = 0;
         p = 0;
         p_prev = 0;
         index = k%hash_length;
         hash_entry* tmp_var_2;
         MOD_READ(table[index],tmp_var_2);
         p = tmp_var_2;
         while (p) {
            if (p->key==k) {
                ret = false;
                break;
            } else if (p->key > k) {
                ret = true;
                break;
            }
            p_prev = p;
            hash_entry* tmp_var_3;
            MOD_READ(p->next,tmp_var_3);
            p = tmp_var_3;
         }
         if (ret) {
              new_p->key = k;
              WRP_WRITE(new_p->next) = p;

              if (p_prev == 0) {
                table_index_copy = new_p;
                MOD_WRITE(table[index],table_index_copy);
              } else {
                p_prev_next_copy = new_p;
                MOD_WRITE(p_prev->next,p_prev_next_copy);
              }
         }
       WRITE_OP_END
#ifdef CHECK_CORRECTNESS
       if (ret) elem_counter[k] ++;
#endif
       return ret;
    }
    bool erase(int k) {
       hash_entry* prev;
       size_t index=0;
       bool ret = 0;
       hash_entry* curr=0;

       WRITE_OP_BEGIN
         hash_entry* table_index_copy=0;
         hash_entry* prev_next_copy=0;
         prev = 0;
         // index = 0;
         ret = 0;
         curr = 0;
         index = k%hash_length;
         hash_entry* tmp_var_5;
         MOD_READ(table[index],tmp_var_5);
         curr = tmp_var_5;
         while (curr) {
            if (curr->key==k) {
                ret = true;
                if (prev == 0) {
                    hash_entry* tmp_var_6;
                    MOD_READ(curr->next,tmp_var_6);
                    table_index_copy = tmp_var_6;
                    MOD_WRITE(table[index],table_index_copy);
                } else {
                    hash_entry* tmp_var_7;
                    MOD_READ(curr->next,tmp_var_7);
                    prev_next_copy = tmp_var_7;
                    MOD_WRITE(prev->next,prev_next_copy);
                }
                FREE_NODE(curr);
                break;
            } else if (curr->key > k) {
                break;
            } else {
                prev = curr;
                hash_entry* tmp_var_8;
                MOD_READ(curr->next,tmp_var_8);
                curr = tmp_var_8;
            }
        }
       WRITE_OP_END
#ifdef CHECK_CORRECTNESS
       if (ret) elem_counter[k] --;
#endif
       return ret;
    }
    public:
    hash_set (int init_hash_length)  {
printf("init begin\n");
       gc = new GarbageCollector ();
       struct hash_set_synobj* state_tmp=new hash_set_synobj ();
       state_tmp->synobj.parent_gc = gc;
       state_tmp->synobj.version_number = 0;
       state = state_tmp;
printf("init done\n");
       hash_length = init_hash_length;
       table = (wrapper_t**)calloc(init_hash_length,sizeof(wrapper_t*));
    }
    ;
    ~hash_set() {
#ifdef CHECK_CORRECTNESS
        int final_count = 0;
        int bucket_num = hash_length;
        for (int bucket_idx = 0; bucket_idx < bucket_num; bucket_idx++) {
            hash_entry *curr = WRP_READ(table[bucket_idx]);
            int prev_k = -1;
            while (curr) {
                key_type k = curr->key;
                if (k <= prev_k) {
                    printf("error k(%d) <= prev_k(%d)\n", k, prev_k);
                }
                prev_k = k;

                if (k%bucket_num != bucket_idx) {
                    printf("error %u%%%d != %d\n", k, bucket_num, bucket_idx);
                }

                if (elem_counter[k].load()!=1) {
                    printf("error elem_count[%d]!=1 (%d)\n", k, elem_counter[k].load());
                }
                elem_counter[k] = 0;
                curr = WRP_READ(curr->next);
                final_count ++;
            }
        }

        for (int i = 0; i < MAX_VAL; i++) {
            if (elem_counter[i].load() != 0) {
                printf("error elem_count[%d] != 0 (%d)\n", i, elem_counter[i].load());
            }
        }
        printf("check done %d\n", final_count);
#endif
       // free(table);
    }
    ;
  };


/*************************************************
    Adapter for benchmark
**************************************************/

template <class T>
class heavyweight_struct {
    hash_set<T> set;
public:
    //heavyweight_struct(): set(MAX_VAL/10) {}
    heavyweight_struct(): set(MAX_VAL) {}
    bool insert(T send_v) {
        return set.insert(send_v);
    }
    void erase(T send_v) {
        set.erase(send_v);
    }
    bool find(T send_v) {
        return set.search(send_v);
    }
};



#endif // NONBLOCKING_HASHSET
