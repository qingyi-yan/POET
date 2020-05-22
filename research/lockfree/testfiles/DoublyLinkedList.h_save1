// unable to partition data

// unsafe revalidation

#include "nonblocking_header.h"
#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H
template <class T>
class DoublyLinkedListWrap  
  ;
template <class T>
class DoublyLinkedEntryWrap  
  {
    T o;
    wrapper_t* prev;
    wrapper_t* next;
    public:
    DoublyLinkedEntryWrap (const T& _o) : o(_o),next(0),prev(0) {
       
    }
    ~DoublyLinkedEntryWrap() {
       
    }
    T& GetEntry() {
       return o;
    }
    friend class DoublyLinkedListWrap<T>;
  };
template <class T>
class DoublyLinkedListWrap  
  {
    struct GarbageCollector;
    struct DoublyLinkedListWrap_synobj;
    typedef struct DoublyLinkedListWrap_synobj synobj_t;
    struct DoublyLinkedEntryWrap<T>;
    typedef DoublyLinkedEntryWrap<T> gc_node_t;
    #define ENABLE_GC_NODE_ALLOCATOR
    typedef struct {
        DoublyLinkedEntryWrap<T>* value;
        int version;
    } wrapper_t;
    typedef DoublyLinkedEntryWrap<T>* value_t;
    
    #include "nonblocking_sync.h"
    ;;
    unsigned count;
    void operator =(const DoublyLinkedListWrap<T>& that) {
       
    }
    struct DoublyLinkedListWrap_synobj{
      DoublyLinkedEntryWrap<T>* end;DoublyLinkedEntryWrap<T>* head;
       
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
      DoublyLinkedListWrap_synobj& operator =(DoublyLinkedListWrap_synobj& that)
      {
          end=that.end;
          head=that.head;
          synobj=that.synobj;
          return *this;
      }
      
    };
    
    ;
    public:
    DoublyLinkedListWrap () : count(0) {
       gc = new GarbageCollector ();
       struct DoublyLinkedListWrap_synobj* state_tmp=new DoublyLinkedListWrap_synobj ();
       state_tmp->synobj.parent_gc = gc;
       state_tmp->synobj.version_number = 1;
       state = state_tmp;
       state_tmp->head = 0;
       state_tmp->end = 0;
    }
    DoublyLinkedListWrap (const DoublyLinkedListWrap<T>& that)  {
       gc = new GarbageCollector ();
       struct DoublyLinkedListWrap_synobj* state_tmp=new DoublyLinkedListWrap_synobj ();
       state_tmp->synobj.parent_gc = gc;
       state_tmp->synobj.version_number = 1;
       state = state_tmp;
       state_tmp->head = state_tmp->end = 0;
       count = 0;
       *this+=that;
    }
    ~DoublyLinkedListWrap() {
       DeleteAll();
    }
    void operator +=(const DoublyLinkedListWrap<T>& that) {
       for (Iterator iter(that) ; !iter.ReachEnd(); iter++)
         {
            T& c=iter.Current();
            {
               ++count;
               DoublyLinkedEntryWrap<T>* e=new DoublyLinkedEntryWrap<T> (c);
               if (state->end==0) 
                 {
                    state->head = state->end = e;
                 }
               else 
                 {
                    e->prev = state->end;
                    state->end->next = e;
                    state->end = e;
                 }
               
            }
         }
    }
    void Reverse() {
        
       int __ret__3;
       WRITE_OP_BEGIN
         // write operation begin
         
         DoublyLinkedEntryWrap<T>* tmp_next_copy=0;
         DoublyLinkedEntryWrap<T>* newstate_head_next_copy=0;
         __ret__3 = 0;
         if (count==0) 
           {
              __ret__3 = 1;
           }
         if (__ret__3!=1) 
           {
              DoublyLinkedEntryWrap<T>* tmp=SNAPSHOT(head);
              DoublyLinkedEntryWrap<T>* tmp_var_0;
              MOD_READ(tmp->next,tmp_var_0);
              DoublyLinkedEntryWrap<T>* tmp1=tmp_var_0;
              while (tmp!=SNAPSHOT(end))
                {
                   DoublyLinkedEntryWrap<T>* tmp2=tmp;
                   tmp = tmp1;
                   DoublyLinkedEntryWrap<T>* tmp_var_1;
                   MOD_READ(tmp->next,tmp_var_1);
                   tmp1 = tmp_var_1;
                   tmp_next_copy = tmp2;
                   MOD_WRITE(tmp->next,tmp_next_copy);
                }
              newstate_head_next_copy = 0;
              DoublyLinkedEntryWrap<T>* tmp_var_2=newstate->head;
              MOD_WRITE(tmp_var_2->next,newstate_head_next_copy);
              SNAPSHOT_WRITE(end,SNAPSHOT(head));;
              SNAPSHOT_WRITE(head,tmp);;
           }
         
         // write operation end
       WRITE_OP_END
       return ;
    }
    DoublyLinkedEntryWrap<T>* AppendLast(const T& o) {
        
       DoublyLinkedEntryWrap<T>* e=allocate_node(o);
       WRITE_OP_BEGIN
         // write operation begin
         
         DoublyLinkedEntryWrap<T>* newstate_end_next_copy=0;
         ++count;
         if (SNAPSHOT(end)==0) 
           {
              SNAPSHOT_WRITE(head,SNAPSHOT_WRITE(end,e););;
           }
         else 
           {
              WRP_WRITE(e->prev) = SNAPSHOT(end);
              newstate_end_next_copy = e;
              DoublyLinkedEntryWrap<T>* tmp_var_3=newstate->end;
              MOD_WRITE(tmp_var_3->next,newstate_end_next_copy);
              SNAPSHOT_WRITE(end,e);;
           }
         
         // write operation end
       WRITE_OP_END
       return e;
    }
    DoublyLinkedEntryWrap<T>* PushFirst(const T& o) {
        
       DoublyLinkedEntryWrap<T>* e=allocate_node(o);
       WRITE_OP_BEGIN
         // write operation begin
         
         DoublyLinkedEntryWrap<T>* newstate_head_prev_copy=0;
         ++count;
         if (SNAPSHOT(head)==0) 
           {
              SNAPSHOT_WRITE(head,SNAPSHOT_WRITE(end,e););;
           }
         else 
           {
              WRP_WRITE(e->next) = SNAPSHOT(head);
              newstate_head_prev_copy = e;
              DoublyLinkedEntryWrap<T>* tmp_var_4=newstate->head;
              MOD_WRITE(tmp_var_4->prev,newstate_head_prev_copy);
              SNAPSHOT_WRITE(head,e);;
           }
         
         // write operation end
       WRITE_OP_END
       return e;
    }
    void PopFirst() {
        
       WRITE_OP_BEGIN
         // write operation begin
         
         if (count>0) 
           {
              --count;
              DoublyLinkedEntryWrap<T>* e=SNAPSHOT(head);
              if (SNAPSHOT(head)==SNAPSHOT(end)) 
                {
                   SNAPSHOT_WRITE(head,SNAPSHOT_WRITE(end,0););;
                }
              else 
                {
                   DoublyLinkedEntryWrap<T>* tmp_var_5=newstate->head;
                   DoublyLinkedEntryWrap<T>* tmp_var_6;
                   MOD_READ(tmp_var_5->next,tmp_var_6);
                   SNAPSHOT_WRITE(head,tmp_var_6);;
                }
           }
         
         // write operation end
       WRITE_OP_END
    }
    void PopLast() {
        
       WRITE_OP_BEGIN
         // write operation begin
         
         if (count>0) 
           {
              --count;
              DoublyLinkedEntryWrap<T>* e=SNAPSHOT(end);
              if (SNAPSHOT(head)==SNAPSHOT(end)) 
                {
                   SNAPSHOT_WRITE(head,SNAPSHOT_WRITE(end,0););;
                }
              else 
                {
                   DoublyLinkedEntryWrap<T>* tmp_var_7=newstate->end;
                   DoublyLinkedEntryWrap<T>* tmp_var_8;
                   MOD_READ(tmp_var_7->prev,tmp_var_8);
                   SNAPSHOT_WRITE(end,tmp_var_8);;
                }
           }
         
         // write operation end
       WRITE_OP_END
    }
    bool Find(const T& o) {
        
       bool res;
       DoublyLinkedEntryWrap<T>* e;
       READ_OP_BEGIN
         // read operation begin
         
         e = SNAPSHOT(head);
         while (e!=0&&e->o!=o)
           {
              DoublyLinkedEntryWrap<T>* tmp_var_9;
              MOD_READ_R(e->next,tmp_var_9);
              e = tmp_var_9;
           }
         res = e!=0;
         // read operation end
       READ_OP_END
    }
    void DeleteAll() {
        
       WRITE_OP_BEGIN
         // write operation begin
         
         while (SNAPSHOT(head)!=0)
           {
              if (count>0) 
                {
                   --count;
                   DoublyLinkedEntryWrap<T>* e=SNAPSHOT(head);
                   if (SNAPSHOT(head)==SNAPSHOT(end)) 
                     {
                        SNAPSHOT_WRITE(head,SNAPSHOT_WRITE(end,0););;
                     }
                   else 
                     {
                        DoublyLinkedEntryWrap<T>* tmp_var_10=newstate->head;
                        DoublyLinkedEntryWrap<T>* tmp_var_11;
                        MOD_READ(tmp_var_10->next,tmp_var_11);
                        SNAPSHOT_WRITE(head,tmp_var_11);;
                     }
                }
           }
         
         // write operation end
       WRITE_OP_END
    }
    unsigned size() const{
       return count;
    }
    
    
    DoublyLinkedEntryWrap<T>* Next(DoublyLinkedEntryWrap<T>* cur) const{
       return WRP_READ(cur->next);
    }
    class Iterator  
      {
        const DoublyLinkedListWrap<T>* list;
        DoublyLinkedEntryWrap<T>* cur;
        public:
        Iterator (const DoublyLinkedListWrap<T>& l) : list(&l) {
           cur = l.First();
        }
        Iterator (const Iterator& that) : list(that.list),cur(that.cur) {
           
        }
        Iterator& operator =(const Iterator& that) {
           list = that.list;
           cur = that.cur;
        }
        Iterator () : list(0),cur(0) {
           
        }
        T& Current() const{
           return (cur->GetEntry)();
        }
        T& operator *() const{
           return Current();
        }
        bool ReachEnd() const{
           return cur==0;
        }
        void Reset() {
           if (list!=0) 
             {
                cur = (list->First)();
             }
        }
        void Advance() {
           if (cur!=0) 
             {
                cur = (list->Next)(cur);
             }
        }
        void operator ++() {
           Advance();
        }
        void operator ++(int) {
           Advance();
        }
      };
    Iterator GetIterator() const{
       return Iterator(*this);
    }
  };
#endif
