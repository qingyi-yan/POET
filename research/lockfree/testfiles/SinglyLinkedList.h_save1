// unable to partition data

// unsafe revalidation

#include "nonblocking_header.h"
#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H
template <class T>
class SinglyLinkedListWrap  
  ;
template <class T>
class SinglyLinkedEntryWrap  
  {
    T o;
    wrapper_t* next;
    public:
    SinglyLinkedEntryWrap (const T& _o) : o(_o),next(0) {
       
    }
    ~SinglyLinkedEntryWrap() {
       
    }
    T& GetEntry() {
       return o;
    }
    friend class SinglyLinkedListWrap<T>;
  };
template <class T>
class SinglyLinkedListWrap  
  {
    struct GarbageCollector;
    struct SinglyLinkedListWrap_synobj;
    typedef struct SinglyLinkedListWrap_synobj synobj_t;
    struct SinglyLinkedEntryWrap<T>;
    typedef SinglyLinkedEntryWrap<T> gc_node_t;
    #define ENABLE_GC_NODE_ALLOCATOR
    typedef struct {
        SinglyLinkedEntryWrap<T>* value;
        int version;
    } wrapper_t;
    typedef SinglyLinkedEntryWrap<T>* value_t;
    
    #include "nonblocking_sync.h"
    ;;
    ;
    void operator =(const SinglyLinkedListWrap<T>& that) {
       
    }
    struct SinglyLinkedListWrap_synobj{
      unsigned count;SinglyLinkedEntryWrap<T>* end;SinglyLinkedEntryWrap<T>* head;
       
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
      SinglyLinkedListWrap_synobj& operator =(SinglyLinkedListWrap_synobj& that)
      {
          count=that.count;
          end=that.end;
          head=that.head;
          synobj=that.synobj;
          return *this;
      }
      
    };
    
    ;
    public:
    SinglyLinkedListWrap ()  {
       gc = new GarbageCollector ();
       struct SinglyLinkedListWrap_synobj* state_tmp=new SinglyLinkedListWrap_synobj ();
       state_tmp->synobj.parent_gc = gc;
       state_tmp->synobj.version_number = 1;
       state = state_tmp;
       state_tmp->head = 0;
       state_tmp->end = 0;
       state_tmp->count = 0;
    }
    SinglyLinkedListWrap (const SinglyLinkedListWrap<T>& that)  {
       gc = new GarbageCollector ();
       struct SinglyLinkedListWrap_synobj* state_tmp=new SinglyLinkedListWrap_synobj ();
       state_tmp->synobj.parent_gc = gc;
       state_tmp->synobj.version_number = 1;
       state = state_tmp;
       state_tmp->head = 0;
       state_tmp->end = 0;
       state_tmp->count = 0;
       *this+=that;
    }
    ~SinglyLinkedListWrap() {
       DeleteAll();
    }
    void operator +=(const SinglyLinkedListWrap<T>& that) {
       for (Iterator iter(that) ; !iter.ReachEnd(); iter++)
         {
            T& c=iter.Current();
            {
               state->count = state->count+1;
               SinglyLinkedEntryWrap<T>* e=new SinglyLinkedEntryWrap<T> (c);
               if (state->end==0) 
                 {
                    state->head = e;
                    state->end = e;
                 }
               else 
                 {
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
         
         SinglyLinkedEntryWrap<T>* tmp_next_copy=0;
         SinglyLinkedEntryWrap<T>* newstate_head_next_copy=0;
         __ret__3 = 0;
         if (SNAPSHOT(count)==0) 
           {
              __ret__3 = 1;
           }
         if (__ret__3!=1) 
           {
              SinglyLinkedEntryWrap<T>* tmp=SNAPSHOT(head);
              SinglyLinkedEntryWrap<T>* tmp_var_0;
              MOD_READ(tmp->next,tmp_var_0);
              SinglyLinkedEntryWrap<T>* tmp1=tmp_var_0;
              while (tmp!=SNAPSHOT(end))
                {
                   SinglyLinkedEntryWrap<T>* tmp2=tmp;
                   tmp = tmp1;
                   SinglyLinkedEntryWrap<T>* tmp_var_1;
                   MOD_READ(tmp->next,tmp_var_1);
                   tmp1 = tmp_var_1;
                   tmp_next_copy = tmp2;
                   MOD_WRITE(tmp->next,tmp_next_copy);
                }
              newstate_head_next_copy = 0;
              SinglyLinkedEntryWrap<T>* tmp_var_2=newstate->head;
              MOD_WRITE(tmp_var_2->next,newstate_head_next_copy);
              SNAPSHOT_WRITE(end,SNAPSHOT(head));;
              SNAPSHOT_WRITE(head,tmp);;
           }
         
         // write operation end
       WRITE_OP_END
       return ;
    }
    SinglyLinkedEntryWrap<T>* AppendLast(const T& o) {
        
       SinglyLinkedEntryWrap<T>* e=allocate_node(o);
       WRITE_OP_BEGIN
         // write operation begin
         
         SinglyLinkedEntryWrap<T>* newstate_end_next_copy=0;
         SNAPSHOT_WRITE(count,SNAPSHOT(count)+1);;
         if (SNAPSHOT(end)==0) 
           {
              SNAPSHOT_WRITE(head,e);;
              SNAPSHOT_WRITE(end,e);;
           }
         else 
           {
              newstate_end_next_copy = e;
              SinglyLinkedEntryWrap<T>* tmp_var_3=newstate->end;
              MOD_WRITE(tmp_var_3->next,newstate_end_next_copy);
              SNAPSHOT_WRITE(end,e);;
           }
         
         // write operation end
       WRITE_OP_END
       return e;
    }
    SinglyLinkedEntryWrap<T>* PushFirst(const T& o) {
        
       SinglyLinkedEntryWrap<T>* e=allocate_node(o);
       WRITE_OP_BEGIN
         // write operation begin
         
         SNAPSHOT_WRITE(count,SNAPSHOT(count)+1);;
         if (SNAPSHOT(head)==0) 
           {
              SNAPSHOT_WRITE(head,e);;
           }
         SNAPSHOT_WRITE(end,e);;
         else 
           {
              WRP_WRITE(e->next) = SNAPSHOT(head);
              SNAPSHOT_WRITE(head,e);;
           }
         
         // write operation end
       WRITE_OP_END
       return e;
    }
    void PopFirst() {
        
       WRITE_OP_BEGIN
         // write operation begin
         
         if (SNAPSHOT(count)>0) 
           {
              SNAPSHOT_WRITE(count,SNAPSHOT(count)-1);;
              SinglyLinkedEntryWrap<T>* e=SNAPSHOT(head);
              if (SNAPSHOT(head)==SNAPSHOT(end)) 
                {
                   SNAPSHOT_WRITE(head,0);;
                   SNAPSHOT_WRITE(end,0);;
                }
              else 
                {
                   SinglyLinkedEntryWrap<T>* tmp_var_4=newstate->head;
                   SinglyLinkedEntryWrap<T>* tmp_var_5;
                   MOD_READ(tmp_var_4->next,tmp_var_5);
                   SNAPSHOT_WRITE(head,tmp_var_5);;
                }
           }
         
         // write operation end
       WRITE_OP_END
    }
    bool Find(const T& o) {
        
       bool res;
       SinglyLinkedEntryWrap<T>* e;
       READ_OP_BEGIN
         // read operation begin
         
         e = SNAPSHOT(head);
         while (e!=0&&e->o!=o)
           {
              SinglyLinkedEntryWrap<T>* tmp_var_6;
              MOD_READ_R(e->next,tmp_var_6);
              e = tmp_var_6;
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
              if (SNAPSHOT(count)>0) 
                {
                   SNAPSHOT_WRITE(count,SNAPSHOT(count)-1);;
                   SinglyLinkedEntryWrap<T>* e=SNAPSHOT(head);
                   if (SNAPSHOT(head)==SNAPSHOT(end)) 
                     {
                        SNAPSHOT_WRITE(head,0);;
                        SNAPSHOT_WRITE(end,0);;
                     }
                   else 
                     {
                        SinglyLinkedEntryWrap<T>* tmp_var_7=newstate->head;
                        SinglyLinkedEntryWrap<T>* tmp_var_8;
                        MOD_READ(tmp_var_7->next,tmp_var_8);
                        SNAPSHOT_WRITE(head,tmp_var_8);;
                     }
                }
           }
         
         // write operation end
       WRITE_OP_END
    }
    unsigned size() const{
        
       unsigned __ret__10;
       READ_OP_BEGIN
         // read operation begin
         
         __ret__10 = SNAPSHOT(count);
         // read operation end
       READ_OP_END
       return __ret__10;
    }
    
    
    SinglyLinkedEntryWrap<T>* Next(SinglyLinkedEntryWrap<T>* cur) const{
       return WRP_READ(cur->next);
    }
    class Iterator  
      {
        const SinglyLinkedListWrap<T>* list;
        SinglyLinkedEntryWrap<T>* cur;
        public:
        Iterator (const SinglyLinkedListWrap<T>& l) : list(&l) {
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
