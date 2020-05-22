
#ifdef NONBLOCKING_DEQUE

#include "deque_header.h"
template <class T>
class list_seq
  {
    struct GarbageCollector;
    struct list_seq_synobj;
    typedef struct list_seq_synobj synobj_t;
    struct list_node;
    typedef list_node gc_node_t;
    #define ENABLE_GC_NODE_ALLOCATOR
    typedef struct wrapper_s {
        wrapper_s* gc_next;
        list_node* value;
        int version;
    } wrapper_t;
    typedef list_node* value_t;
    struct list_node
      {
        list_node* gc_next;
        T value;
        wrapper_t* prev;
        wrapper_t* next;
      };


    #include "nonblocking_sync.h"
    struct list_seq_synobj{
      synobj_t* gc_next;
      std::size_t counter;list_node* tailp;list_node* headp;

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
      list_seq_synobj& operator =(list_seq_synobj& that)
      {
          counter=that.counter;
          tailp=that.tailp;
          headp=that.headp;
          synobj=that.synobj;
          return *this;
      }

    };


    public:
    ;
    ;
    wrapper_t* nil;
    ;
    typedef T value_type;
    typedef T& reference;
    typedef std::size_t size_type;
    public:
    list_seq ()  {
       gc = new GarbageCollector ();
       struct list_seq_synobj* state_tmp=new list_seq_synobj ();
       state_tmp->synobj.parent_gc = gc;
       state_tmp->synobj.version_number = 0;
       nil = NULL;
       // write_wrapper(nil) = new list_node ();
       nil = new wrapper_t;
       nil->value = new list_node();
       list_node* tmp_var_19;
       tmp_var_19 = read_wrapper(nil);
       list_node* tmp_var_20;
       tmp_var_20 = read_wrapper(nil);
       list_node* tmp_var_21;
       tmp_var_21 = read_wrapper(nil);
       // write_wrapper(tmp_var_21->prev) = write_wrapper(tmp_var_21->next) = tmp_var_21;
       tmp_var_21->prev = new wrapper_t;
       tmp_var_21->next = new wrapper_t;
       tmp_var_21->prev->value = tmp_var_21;
       tmp_var_21->next->value = tmp_var_21;
       list_node* tmp_var_22;
       tmp_var_22 = read_wrapper(nil);
       state_tmp->headp = state_tmp->tailp = tmp_var_22;
       state_tmp->counter = 0;
       state = state_tmp;
    }
    ~list_seq() {
#ifdef CHECK_CORRECTNESS
        printf("%d\n", state.load()->counter);
        list_node* e = state.load()->headp;
        for (int i = 0; i < state.load()->counter; i++) {
            elem_counter[e->value] --;
            e = read_wrapper(e->next);
        }
        if (e != read_wrapper(nil)) printf("error 1 %d, %d, %d, %d, %d\n", e->value, read_wrapper(nil)->value, state.load()->headp->value, state.load()->tailp->value, read_wrapper(state.load()->tailp->next)->value);
        for (int i = 0; i < MAX_VAL; i++) {
            if (elem_counter[i]!=0) printf("error 2 %d\n", elem_counter[i].load());
        }
        printf("verified \n");
#endif
    }

    std::size_t size() {
       std::size_t __ret__2;
       READ_OP_BEGIN
         // read operation begin

         __ret__2 = SNAPSHOT(counter);
         // read operation end
       READ_OP_END
       return __ret__2;
    }

    bool empty() {
       bool __ret__4;
       READ_OP_BEGIN
         // read operation begin

         __ret__4 = SNAPSHOT(counter)<1;
         // read operation end
       READ_OP_END
       return __ret__4;
    }

    void push_front(T x) {
       list_node* new_node=allocate_node();
       WRITE_OP_BEGIN
         // write operation begin
         list_node* newstate_headp_prev_copy=0;
         new_node->value = x;
         WRP_WRITE(new_node->next) = SNAPSHOT(headp);
         WRP_WRITE(new_node->prev) = new_node;
         newstate_headp_prev_copy = new_node;
         list_node* tmp_var_4=newstate->headp;
         MOD_WRITE(tmp_var_4->prev,newstate_headp_prev_copy);
         SNAPSHOT_WRITE(headp,new_node);;
         if (SNAPSHOT(counter)==0)
           {
              SNAPSHOT_WRITE(tailp,new_node);;
           }
         SNAPSHOT_WRITE(counter, SNAPSHOT(counter)+1);

         // write operation end
       WRITE_OP_END
#ifdef CHECK_CORRECTNESS
        elem_counter[x] ++;
#endif
    }
    void push_back(T x) {
       list_node* new_node=allocate_node();
       WRITE_OP_BEGIN
         // write operation begin

         list_node* nil_prev_copy=0;
         list_node* newstate_tailp_next_copy=0;
         new_node->value = x;
         if (SNAPSHOT(counter)==0)
           {
              SNAPSHOT_WRITE(headp,new_node);
              SNAPSHOT_WRITE(tailp,new_node);
              WRP_WRITE(new_node->prev) = new_node;
              list_node* tmp_var_5;
              MOD_READ(nil,tmp_var_5);
              WRP_WRITE(new_node->next) = tmp_var_5;
              nil_prev_copy = new_node;
              MOD_WRITE(tmp_var_5->prev,nil_prev_copy);
           }
         else
           {
              list_node* tmp_var_6;
              MOD_READ(nil,tmp_var_6);
              WRP_WRITE(new_node->next) = tmp_var_6;
              WRP_WRITE(new_node->prev) = SNAPSHOT(tailp);
              nil_prev_copy = new_node;
              MOD_WRITE(tmp_var_6->prev,nil_prev_copy);
              newstate_tailp_next_copy = new_node;
              list_node* tmp_var_7=newstate->tailp;
              MOD_WRITE(tmp_var_7->next,newstate_tailp_next_copy);
              SNAPSHOT_WRITE(tailp,new_node);;
           }
         SNAPSHOT_WRITE(counter, SNAPSHOT(counter)+1);

         // write operation end
       WRITE_OP_END

#ifdef CHECK_CORRECTNESS
       elem_counter[x] ++;
#endif
    }
    T pop_front() {
       T res;
       T __ret__15;
       bool ret = false;
       WRITE_OP_BEGIN
         // write operation begin

         ret = false;
         list_node* newstate_headp_prev_copy=0;
         list_node* nil_prev_copy=0;
         if (SNAPSHOT(counter)>1)
           {
              ret = true;
              list_node* tmp_var_8=newstate->headp;
              res = tmp_var_8->value;
              FREE_NODE(tmp_var_8);
              list_node* tmp_headp=SNAPSHOT(headp);
              list_node* tmp_var_9;
              MOD_READ(tmp_var_8->next,tmp_var_9);
              SNAPSHOT_WRITE(headp,tmp_var_9);;
              newstate_headp_prev_copy = SNAPSHOT(headp);
              MOD_WRITE(tmp_var_9->prev,newstate_headp_prev_copy);
              SNAPSHOT_WRITE(counter, SNAPSHOT(counter)-1);
           }
         else if (SNAPSHOT(counter)==1)
           {
              ret = true;
              list_node* tmp_headp=SNAPSHOT(headp);
              list_node* tmp_var_10;
              MOD_READ(nil,tmp_var_10);
              SNAPSHOT_WRITE(headp,tmp_var_10);
              SNAPSHOT_WRITE(tailp,tmp_var_10);
              list_node* tmp_var_11;
              MOD_READ(nil,tmp_var_11);
              nil_prev_copy = tmp_var_11;
              MOD_WRITE(tmp_var_11->prev,nil_prev_copy);
              res = tmp_headp->value;
              FREE_NODE(tmp_headp);
              SNAPSHOT_WRITE(counter, SNAPSHOT(counter)-1);
           }
         __ret__15 = res;

         // write operation end
       WRITE_OP_END
#ifdef CHECK_CORRECTNESS
       if(ret) elem_counter[__ret__15] --;
#endif
       return __ret__15;
    }
    T pop_back() {
       T res;
       T __ret__18;
       bool ret = false;
       WRITE_OP_BEGIN
         // write operation begin

         ret = false;
         list_node* newstate_tailp_next_copy=0;
         list_node* nil_prev_copy=0;
         if (SNAPSHOT(counter)>1)
           {
              ret = true;
              list_node* tmp_var_12=newstate->tailp;
              res = tmp_var_12->value;
              FREE_NODE(tmp_var_12);
              list_node* tmp_tailp=SNAPSHOT(tailp);
              list_node* tmp_var_13;
              MOD_READ(tmp_var_12->prev,tmp_var_13);
              SNAPSHOT_WRITE(tailp,tmp_var_13);;
              list_node* tmp_var_14;
              MOD_READ(nil,tmp_var_14);
              newstate_tailp_next_copy = tmp_var_14;
              MOD_WRITE(tmp_var_13->next,newstate_tailp_next_copy);
              nil_prev_copy = SNAPSHOT(tailp);
              MOD_WRITE(tmp_var_14->prev,nil_prev_copy);
              SNAPSHOT_WRITE(counter, SNAPSHOT(counter)-1);
           }
         else if (SNAPSHOT(counter)==1)
           {
              ret = true;
              list_node* tmp_var_15=newstate->tailp;
              res = tmp_var_15->value;
              FREE_NODE(tmp_var_15);
              list_node* tmp_tailp=SNAPSHOT(tailp);
              list_node* tmp_var_16;
              MOD_READ(nil,tmp_var_16);
              SNAPSHOT_WRITE(headp,tmp_var_16);
              SNAPSHOT_WRITE(tailp,tmp_var_16);
              list_node* tmp_var_17;
              MOD_READ(nil,tmp_var_17);
              nil_prev_copy = tmp_var_17;
              MOD_WRITE(tmp_var_17->prev,nil_prev_copy);
              SNAPSHOT_WRITE(counter, SNAPSHOT(counter)-1);
           }
         __ret__18 = res;

         // write operation end
       WRITE_OP_END
#ifdef CHECK_CORRECTNESS
       if(ret) elem_counter[__ret__18] --;
#endif
       return __ret__18;
    }
    bool find(T x) {
       bool res;
       list_node* e=(list_node*)(-1);
       READ_OP_BEGIN
         // read operation begin

         e = SNAPSHOT(headp);
         while (e!=SNAPSHOT(tailp)&&e->value!=x)
           {
              list_node* tmp_var_18;
              MOD_READ_R(e->next,tmp_var_18);
              e = tmp_var_18;
           }
         if (e->value==x)
           {
              res = true;
           }
         else
           {
              res = false;
           }
         // read operation end
       READ_OP_END
       return res;
    }
  };

/*************************************************
    Adapter for benchmark
**************************************************/
template <class T>
class lightweight_struct {
    list_seq<T> queue;
public:
    lightweight_struct(int _size): queue() {}
    void push(T send_v, int percent_v) {
        if (percent_v < 50) {
            queue.push_front(send_v);
        } else {
            queue.push_back(send_v);
        }
    }
    T pop(int percent_v) {
        if (percent_v < 50) {
            queue.pop_front();
        } else {
            queue.pop_back();
        }
    }
};


#endif // NONBLOCKING_DEQUE

