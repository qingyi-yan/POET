// unable to partition data

// unsafe revalidation

#include "nonblocking_header.h"
#include <stdio.h>
#include <iostream>
template <class T>
class list_seq  
  ;
template <class T>
class list_node  
  {
    private:
    T value;
    wrapper_t* prev;
    wrapper_t* next;
    friend class list_seq<T>;
  };
template <class T>
class list_seq  
  {
    struct GarbageCollector;
    struct list_seq_synobj;
    typedef struct list_seq_synobj synobj_t;
    struct list_node<T>;
    typedef list_node<T> gc_node_t;
    #define ENABLE_GC_NODE_ALLOCATOR
    typedef struct {
        list_node<T>* value;
        int version;
    } wrapper_t;
    typedef list_node<T>* value_t;
    
    #include "nonblocking_sync.h"
    struct list_seq_synobj{
      std::size_t  counter;list_node<T>* tailp;list_node<T>* headp;
       
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
      list_seq_synobj& operator =(list_seq_synobj& that)
      {
          counter=that.counter;
          tailp=that.tailp;
          headp=that.headp;
          synobj=that.synobj;
          return *this;
      }
      
    };
    
    ;
    public:
    ;
    ;
    wrapper_t* nil;
    ;
    typedef T value_type;
    typedef T& reference;
    typedef std::size_t  size_type;
    list_seq ()  {
       gc = new GarbageCollector ();
       struct list_seq_synobj* state_tmp=new list_seq_synobj ();
       state_tmp->synobj.parent_gc = gc;
       state_tmp->synobj.version_number = 1;
       state = state_tmp;
       WRP_WRITE(nil) = allocate_node();
       list_node<T>* tmp_var_19;
       tmp_var_19 = WRP_READ(nil);
       list_node<T>* tmp_var_20;
       tmp_var_20 = WRP_READ(nil);
       list_node<T>* tmp_var_21;
       tmp_var_21 = WRP_READ(nil);
       WRP_WRITE(tmp_var_21->prev) = WRP_WRITE(tmp_var_21->next) = tmp_var_21;
       list_node<T>* tmp_var_22;
       tmp_var_22 = WRP_READ(nil);
       state_tmp->headp = state_tmp->tailp = tmp_var_22;
       state_tmp->counter = 0;
    }
    ~list_seq() {
       struct list_seq_synobj* state_tmp=state;
       list_node<T>* p=state_tmp->headp;list_node<T>* q;
       list_node<T>* tmp_var_23;
       tmp_var_23 = WRP_READ(nil);
       while (p!=tmp_var_23)
         {
            q = p;
            list_node<T>* tmp_var_24;
            tmp_var_24 = WRP_READ(p->next);
            p = tmp_var_24;
            delete q;
            tmp_var_23 = WRP_READ(nil);
         }
       delete p;
    }
    std::size_t  size() {
        
       std::size_t  __ret__2;
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
    reference operator [](std::size_t  n) {
        
       int i;
       list_node<T>* p;
       list_node<T>* tmp_var_0;
       MOD_READ(nil,tmp_var_0);
       list_node<T>* tmp_var_1;
       MOD_READ(p->next,tmp_var_1);
       for (; i<n&&p!=tmp_var_0; i++,p = tmp_var_1)
         {
            
         }
       T __ret__6;
       READ_OP_BEGIN
         // read operation begin
         
         __ret__6 = p->value;
         // read operation end
       READ_OP_END
       return __ret__6;
    }
    reference front() {
        
       T __ret__8;
       READ_OP_BEGIN
         // read operation begin
         
         list_node<T>* tmp_var_2=newstate->headp;
         __ret__8 = tmp_var_2->value;
         // read operation end
       READ_OP_END
       return __ret__8;
    }
    reference back() {
        
       T __ret__10;
       READ_OP_BEGIN
         // read operation begin
         
         list_node<T>* tmp_var_3=newstate->tailp;
         __ret__10 = tmp_var_3->value;
         // read operation end
       READ_OP_END
       return __ret__10;
    }
    void push_front(T x) {
        
       list_node<T>* new_node=allocate_node();
       WRITE_OP_BEGIN
         // write operation begin
         
         list_node<T>* newstate_headp_prev_copy=0;
         new_node->value = x;
         WRP_WRITE(new_node->next) = SNAPSHOT(headp);
         WRP_WRITE(new_node->prev) = new_node;
         newstate_headp_prev_copy = new_node;
         list_node<T>* tmp_var_4=newstate->headp;
         MOD_WRITE(tmp_var_4->prev,newstate_headp_prev_copy);
         SNAPSHOT_WRITE(headp,new_node);;
         if (SNAPSHOT(counter)==0) 
           {
              SNAPSHOT_WRITE(tailp,new_node);;
           }
         newstate->counter++;
         
         // write operation end
       WRITE_OP_END
    }
    void push_back(T x) {
        
       list_node<T>* new_node=allocate_node();
       WRITE_OP_BEGIN
         // write operation begin
         
         list_node<T>* nil_prev_copy=0;
         list_node<T>* newstate_tailp_next_copy=0;
         new_node->value = x;
         if (SNAPSHOT(counter)==0) 
           {
              SNAPSHOT_WRITE(headp,SNAPSHOT_WRITE(tailp,new_node););;
              WRP_WRITE(new_node->prev) = new_node;
              list_node<T>* tmp_var_5;
              MOD_READ(nil,tmp_var_5);
              WRP_WRITE(new_node->next) = tmp_var_5;
              nil_prev_copy = new_node;
              MOD_WRITE(tmp_var_5->prev,nil_prev_copy);
           }
         else 
           {
              list_node<T>* tmp_var_6;
              MOD_READ(nil,tmp_var_6);
              WRP_WRITE(new_node->next) = tmp_var_6;
              WRP_WRITE(new_node->prev) = SNAPSHOT(tailp);
              nil_prev_copy = new_node;
              MOD_WRITE(tmp_var_6->prev,nil_prev_copy);
              newstate_tailp_next_copy = new_node;
              list_node<T>* tmp_var_7=newstate->tailp;
              MOD_WRITE(tmp_var_7->next,newstate_tailp_next_copy);
              SNAPSHOT_WRITE(tailp,new_node);;
           }
         newstate->counter++;
         
         // write operation end
       WRITE_OP_END
    }
    T pop_front() {
        
       T res;
       T __ret__15;
       WRITE_OP_BEGIN
         // write operation begin
         
         list_node<T>* newstate_headp_prev_copy=0;
         list_node<T>* nil_prev_copy=0;
         if (SNAPSHOT(counter)>1) 
           {
              list_node<T>* tmp_var_8=newstate->headp;
              res = tmp_var_8->value;
              list_node<T>* tmp_headp=SNAPSHOT(headp);
              list_node<T>* tmp_var_9;
              MOD_READ(tmp_var_8->next,tmp_var_9);
              SNAPSHOT_WRITE(headp,tmp_var_9);;
              newstate_headp_prev_copy = SNAPSHOT(headp);
              MOD_WRITE(tmp_var_8->prev,newstate_headp_prev_copy);
              newstate->counter--;
           }
         else if (SNAPSHOT(counter)==1) 
           {
              list_node<T>* tmp_headp=SNAPSHOT(headp);
              list_node<T>* tmp_var_10;
              MOD_READ(nil,tmp_var_10);
              SNAPSHOT_WRITE(headp,SNAPSHOT_WRITE(tailp,tmp_var_10););;
              list_node<T>* tmp_var_11;
              MOD_READ(nil,tmp_var_11);
              nil_prev_copy = tmp_var_11;
              MOD_WRITE(tmp_var_11->prev,nil_prev_copy);
              res = tmp_headp->value;
              newstate->counter--;
           }
         __ret__15 = res;
         
         // write operation end
       WRITE_OP_END
       return __ret__15;
    }
    T pop_back() {
        
       T res;
       T __ret__18;
       WRITE_OP_BEGIN
         // write operation begin
         
         list_node<T>* newstate_tailp_next_copy=0;
         list_node<T>* nil_prev_copy=0;
         if (SNAPSHOT(counter)>1) 
           {
              list_node<T>* tmp_var_12=newstate->tailp;
              res = tmp_var_12->value;
              list_node<T>* tmp_tailp=SNAPSHOT(tailp);
              list_node<T>* tmp_var_13;
              MOD_READ(tmp_var_12->prev,tmp_var_13);
              SNAPSHOT_WRITE(tailp,tmp_var_13);;
              list_node<T>* tmp_var_14;
              MOD_READ(nil,tmp_var_14);
              newstate_tailp_next_copy = tmp_var_14;
              MOD_WRITE(tmp_var_12->next,newstate_tailp_next_copy);
              nil_prev_copy = SNAPSHOT(tailp);
              MOD_WRITE(tmp_var_14->prev,nil_prev_copy);
              newstate->counter--;
           }
         else if (SNAPSHOT(counter)==1) 
           {
              list_node<T>* tmp_var_15=newstate->tailp;
              res = tmp_var_15->value;
              list_node<T>* tmp_tailp=SNAPSHOT(tailp);
              list_node<T>* tmp_var_16;
              MOD_READ(nil,tmp_var_16);
              SNAPSHOT_WRITE(headp,SNAPSHOT_WRITE(tailp,tmp_var_16););;
              list_node<T>* tmp_var_17;
              MOD_READ(nil,tmp_var_17);
              nil_prev_copy = tmp_var_17;
              MOD_WRITE(tmp_var_17->prev,nil_prev_copy);
              newstate->counter--;
           }
         __ret__18 = res;
         
         // write operation end
       WRITE_OP_END
       return __ret__18;
    }
    bool find(T x) {
        
       bool res;
       list_node<T>* e=(list_node<T>*)(-1);
       READ_OP_BEGIN
         // read operation begin
         
         e = SNAPSHOT(headp);
         while (e!=SNAPSHOT(tailp)&&e->value!=x)
           {
              list_node<T>* tmp_var_18;
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
