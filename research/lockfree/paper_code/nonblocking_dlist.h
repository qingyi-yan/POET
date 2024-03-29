
#ifdef NONBLOCKING_DLIST

// #define ENABLE_SLEEP_TUNING
// #define ENABLE_MEM_REUSE

#define GC_MAX_THREADS  1000
#define CONFLICT_ARRAY_SIZE  80000000
#define GC_BLOCK_NUM        1000
#define LOG_NUM             2
#define GC_BLOCK_SIZE       (65536)
#define NODE_NUM            1
#define GC_RESERVE_SIZE     (64)

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

#include <string>
#include <vector>

thread_local int local_gc_idx = -1;
thread_local int num_of_modop = 0;


template <class T>
class DoublyLinkedListWrap
  {
    struct GarbageCollector;
    struct DoublyLinkedListWrap_synobj;
    typedef struct DoublyLinkedListWrap_synobj synobj_t;
    struct DoublyLinkedEntryWrap;
    typedef DoublyLinkedEntryWrap gc_node_t;
    #define ENABLE_GC_NODE_ALLOCATOR
    typedef struct wrapper_s {
        wrapper_s* gc_next;
        DoublyLinkedEntryWrap* value;
#ifdef ENABLE_REVALIDATION
        int version;
#endif
    } wrapper_t;
    typedef DoublyLinkedEntryWrap* value_t;

    struct DoublyLinkedEntryWrap
    {
      T o;
      wrapper_t* next;
      wrapper_t* prev;
      public:
      DoublyLinkedEntryWrap () : o(0),next(0),prev(0) {
      }
      DoublyLinkedEntryWrap (const T& _o) : o(_o),next(0),prev(0) {
      }
      ~DoublyLinkedEntryWrap() {
      }
      T& GetEntry() {
         return o;
      }
    };

    #include "single_snapshot_util.h"

    struct DoublyLinkedListWrap_synobj{
      unsigned count;
      DoublyLinkedEntryWrap* head;
      DoublyLinkedEntryWrap* end;

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
      DoublyLinkedListWrap_synobj& operator =(DoublyLinkedListWrap_synobj& that)
      {
          end=that.end;
          head=that.head;
          count = that.count;
          synobj=that.synobj;
          return *this;
      }
    };

    public:
    DoublyLinkedListWrap ()  {
       gc = new GarbageCollector ();
       struct DoublyLinkedListWrap_synobj* state_tmp=new DoublyLinkedListWrap_synobj ();
       state_tmp->synobj.parent_gc = gc;
       state_tmp->synobj.version_number = 0;
       state_tmp->count = 0;
       state_tmp->head = 0;
       state_tmp->end = 0;
       state = state_tmp;
    }
    public:
    ~DoublyLinkedListWrap() {
#ifdef CHECK_CORRECTNESS
       struct DoublyLinkedListWrap_synobj* oldstate;
       oldstate=state.load();
       printf("%d\n", oldstate->count);
       int my_count = oldstate->count;
       DoublyLinkedEntryWrap* my_e;

       my_e = oldstate->head;
       while (my_count > 1) {
           if (my_e == 0) {
               printf("DeleteAll error 1\n");
           }
           my_e = read_wrapper(my_e->next);

           my_count --;
       }
       if (my_e == oldstate->end) {
           printf("DeleteAll success 1\n");
       } else {
           printf("DeleteAll error 3\n");
       }
       my_count = oldstate->count;
       my_e = oldstate->end;
       while (my_count > 1) {
           if (my_e == 0) {
               printf("DeleteAll error 4\n");
           }
           elem_counter[(my_e->o)] --;
           my_e = read_wrapper(my_e->prev);
           my_count --;
       }
       if (my_e == oldstate->head) {
           elem_counter[(my_e->o)] --;
           printf("DeleteAll success 2\n");
       } else {
           printf("DeleteAll error 6\n");
       }

       bool issucc = true;
       for (int i = 0; i < MAX_VAL; i++) {
           if (elem_counter[i].load() != 0) {
               printf("%d shouldn't be %d\n", i, elem_counter[i].load());
               issucc = false;
           }
       }
       if (issucc) {
           printf("DeleteAll success 3\n");
       } else {
           printf("DeleteAll error 7\n");
       }
#endif
       return;
    }
    DoublyLinkedEntryWrap* AppendLast(const T& o) {

       DoublyLinkedEntryWrap* e=allocate_node();
       e->o = o;
       WRP_WRITE(e->next)=0;
       WRP_WRITE(e->prev)=0;
       WRITE_OP_BEGIN

         DoublyLinkedEntryWrap* newstate_end_next_copy=0;
         SNAPSHOT(count) = SNAPSHOT(count)+1;
         if (SNAPSHOT(end)==0)
           {
              SNAPSHOT_WRITE(head,e);
              SNAPSHOT_WRITE(end,e);
           }
         else
           {
              WRP_WRITE(e->prev) = SNAPSHOT(end);
              newstate_end_next_copy = e;
              DoublyLinkedEntryWrap* tmp_var_2=newstate->end;
              MOD_WRITE(tmp_var_2->next,newstate_end_next_copy);
              SNAPSHOT_WRITE(end,e);
           }

         // write operation end
       WRITE_OP_END

#ifdef CHECK_CORRECTNESS
       elem_counter[o] ++;
#endif
       return e;
    }
    DoublyLinkedEntryWrap* PushFirst(const T& o) {

       DoublyLinkedEntryWrap* e=allocate_node();
       e->o = o;
       WRP_WRITE(e->next)=0;
       WRP_WRITE(e->prev)=0;
       WRITE_OP_BEGIN
         // write operation begin

         DoublyLinkedEntryWrap* newstate_head_prev_copy=0;
         SNAPSHOT(count) = SNAPSHOT(count)+1;
         if (SNAPSHOT(head)==0)
           {
              SNAPSHOT_WRITE(head,e);
              SNAPSHOT_WRITE(end,e);
           }
         else
           {
              WRP_WRITE(e->next) = SNAPSHOT(head);
              newstate_head_prev_copy = e;
              DoublyLinkedEntryWrap* tmp_var_3=newstate->head;
              MOD_WRITE(tmp_var_3->prev,newstate_head_prev_copy);
              SNAPSHOT_WRITE(head,e);;
           }

         // write operation end
       WRITE_OP_END

#ifdef CHECK_CORRECTNESS
       elem_counter[o] ++;
#endif

       return e;
    }

    DoublyLinkedEntryWrap* PopFirst() {
       DoublyLinkedEntryWrap* e;
       WRITE_OP_BEGIN
         // write operation begin

         if (SNAPSHOT(count)>0)
           {
              SNAPSHOT(count) = SNAPSHOT(count)-1;
              e=SNAPSHOT(head);
              if (SNAPSHOT(head)==SNAPSHOT(end))
                {
                   SNAPSHOT_WRITE(head,0);
                   SNAPSHOT_WRITE(end,0);
                }
              else
                {
                   DoublyLinkedEntryWrap* tmp_var_4=newstate->head;
                   DoublyLinkedEntryWrap* tmp_var_5;
                   MOD_READ(tmp_var_4->next,tmp_var_5);
                   SNAPSHOT_WRITE(head,tmp_var_5);;
                }
               FREE_NODE(e);
           }

         // write operation end
       WRITE_OP_END

#ifdef CHECK_CORRECTNESS
       elem_counter[e->o] --;
#endif
       return e;
    }

    DoublyLinkedEntryWrap* PopLast() {
       DoublyLinkedEntryWrap* e;
       WRITE_OP_BEGIN
         // write operation begin

         if (SNAPSHOT(count)>0)
           {
              SNAPSHOT(count) = SNAPSHOT(count)-1;
              e=SNAPSHOT(end);
              if (SNAPSHOT(head)==SNAPSHOT(end))
                {
                   SNAPSHOT_WRITE(head,0);
                   SNAPSHOT_WRITE(end,0);
                }
              else
                {
                   DoublyLinkedEntryWrap* tmp_var_6=newstate->end;
                   DoublyLinkedEntryWrap* tmp_var_7;
                   MOD_READ(tmp_var_6->prev,tmp_var_7);
                   SNAPSHOT_WRITE(end,tmp_var_7);;
                }
               FREE_NODE(e);
           }

         // write operation end
       WRITE_OP_END

#ifdef CHECK_CORRECTNESS
       elem_counter[e->o] --;
#endif

       return e;
    }
    unsigned size() const{
       unsigned __ret__29;
       // used for performance optimization
       // will be removed if it's useless
        READ_OP_BEGIN
         __ret__29 = newstate->count;
        READ_OP_END
       return __ret__29;
    }
  };

/*************************************************
    Adapter for benchmark
**************************************************/
template <class T>
class lightweight_struct {
    DoublyLinkedListWrap<T> queue;
public:
    lightweight_struct(int _size): queue() {}
    void push(T send_v, int percent_v) {
        if (percent_v < 50) {
            queue.AppendLast(send_v);
        } else {
            queue.PushFirst(send_v);
        }
    }
    T pop(int percent_v) {
        if (percent_v < 50) {
            queue.PopFirst();
        } else {
            queue.PopLast();
        }
    }
};

#endif // NONBLOCKING_DLIST
