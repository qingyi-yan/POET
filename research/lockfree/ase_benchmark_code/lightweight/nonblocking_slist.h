
#ifdef NONBLOCKING_SLIST

#include "slist_header.h"

template <class T>
class SinglyLinkedListWrap
  {
    struct GarbageCollector;
    struct SinglyLinkedListWrap_synobj;
    typedef struct SinglyLinkedListWrap_synobj synobj_t;
    struct SinglyLinkedEntryWrap;
    typedef SinglyLinkedEntryWrap gc_node_t;
    #define ENABLE_GC_NODE_ALLOCATOR
    typedef struct wrapper_s {
        wrapper_s* gc_next;
        SinglyLinkedEntryWrap* value;
        int version;
    } wrapper_t;
    typedef SinglyLinkedEntryWrap* value_t;

    #include "nonblocking_sync.h"

    struct SinglyLinkedEntryWrap
      {
        gc_node_t* gc_next;
        T o;
        wrapper_t* next;
        public:
        SinglyLinkedEntryWrap (const T& _o) : o(_o),next(0) {

        }
        SinglyLinkedEntryWrap () : next(0) {

        }
        ~SinglyLinkedEntryWrap() {

        }
        T& GetEntry() {
           return o;
        }
      };

    void operator =(const SinglyLinkedListWrap<T>& that) {
    }

    struct SinglyLinkedListWrap_synobj{
      synobj_t* gc_next;

      unsigned count;SinglyLinkedEntryWrap* end;SinglyLinkedEntryWrap* head;

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

      SinglyLinkedListWrap_synobj& operator =(SinglyLinkedListWrap_synobj& that)
      {
          count=that.count;
          end=that.end;
          head=that.head;
          synobj=that.synobj;
          return *this;
      }

    };

    public:
    SinglyLinkedListWrap ()  {
       gc = new GarbageCollector ();
       struct SinglyLinkedListWrap_synobj* state_tmp=new SinglyLinkedListWrap_synobj ();
       state_tmp->synobj.parent_gc = gc;
       state_tmp->synobj.version_number = 1;
       state_tmp->head = 0;
       state_tmp->end = 0;
       state_tmp->count = 0;
       state = state_tmp;
    }
    ~SinglyLinkedListWrap() {
#ifdef CHECK_CORRECTNESS
       printf("%d\n", state.load()->count);
       SinglyLinkedEntryWrap* e = state.load()->head;
       for (int i = 0; i < state.load()->count; i++) {
            elem_counter[e->o] --;
            e = read_wrapper(e->next);
       }

        bool succ = true;
       if (e!=0) {
            succ = false;
            printf("error 1\n");
        }
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
    }

    void AppendLast(const T& o) {
       SinglyLinkedEntryWrap* e=allocate_node();

       WRITE_OP_BEGIN
         // write operation begin

         e->o = o;
         WRP_WRITE(e->next) = 0;
         SinglyLinkedEntryWrap* newstate_end_next_copy=0;
         SNAPSHOT_WRITE(count,(SNAPSHOT(count)+1));;
         if (SNAPSHOT(end)==0)
           {
              SNAPSHOT_WRITE(head, e);
              SNAPSHOT_WRITE(end,e);
           }
         else
           {
              newstate_end_next_copy = e;
              SinglyLinkedEntryWrap* tmp_var_2=newstate->end;
              MOD_WRITE(tmp_var_2->next,newstate_end_next_copy);
              SNAPSHOT_WRITE(end,e);;
           }

         // write operation end
       WRITE_OP_END
#ifdef CHECK_CORRECTNESS
       elem_counter[o] ++;
#endif
       // return e;
    }
    void PushFirst(const T& o) {
       SinglyLinkedEntryWrap* e=allocate_node();

       WRITE_OP_BEGIN
         // write operation begin

         e->o = o;
         WRP_WRITE(e->next) = 0;
         SNAPSHOT_WRITE(count,SNAPSHOT(count)+1);;
         if (SNAPSHOT(head)==0)
           {
              SNAPSHOT_WRITE(head,e);
              SNAPSHOT_WRITE(end,e);
           }
         else
           {
              WRP_WRITE(e->next) = SNAPSHOT(head);
              SNAPSHOT_WRITE(head,e);;
           }

         // write operation end
       WRITE_OP_END

#ifdef CHECK_CORRECTNESS
          elem_counter[o] ++;
#endif
       // return e;
    }
    void PopFirst() {
         T res;
         bool ret = false;
         WRITE_OP_BEGIN
         // write operation begin

         ret = false;
         if (SNAPSHOT(count)>0)
           {
              ret = true;
              SNAPSHOT_WRITE(count,SNAPSHOT(count)-1);;
              SinglyLinkedEntryWrap* e=SNAPSHOT(head);
              if (SNAPSHOT(head)==SNAPSHOT(end))
                {
                   SNAPSHOT_WRITE(head, 0);
                   SNAPSHOT_WRITE(end, 0);
                }
              else
                {
                   SinglyLinkedEntryWrap* tmp_var_3=newstate->head;
                   SinglyLinkedEntryWrap* tmp_var_4;
                   MOD_READ(tmp_var_3->next,tmp_var_4);
                   SNAPSHOT_WRITE(head,tmp_var_4);;
                }
                res = e->o;
                FREE_NODE(e);
           }

         // write operation end
       WRITE_OP_END

#ifdef CHECK_CORRECTNESS
       if(ret) elem_counter[res] --;
#endif
    }
};


/*************************************************
    Adapter for benchmark
**************************************************/
template <class T>
class lightweight_struct {
    SinglyLinkedListWrap<T> queue;
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
        queue.PopFirst();
    }
};

#endif // NONBLOCKING_SLIST

