// unable to partition data

#define ENABLE_REVALIDATION // safe to revalidate

#include "nonblocking_header.h"
#ifndef MDLIST_H
#define MDLIST_H
#include <cstdint>
#include <string>
class MDList  
  {
    struct GarbageCollector;
    struct MDList_synobj;
    typedef struct MDList_synobj synobj_t;
    struct Node;
    typedef Node gc_node_t;
    #define ENABLE_GC_NODE_ALLOCATOR
    typedef struct {
        Node* value;
        int version;
    } wrapper_t;
    typedef Node* value_t;
    
    #include "nonblocking_sync.h"
    static const int DIMENSION=16;
    struct Node{
      wrapper_t* m_child[DIMENSION];
      uint8_t m_coord[DIMENSION];
      int m_key;
    };
    struct MDList_synobj{
      ;
       
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
      MDList_synobj& operator =(MDList_synobj& that)
      {
          
          synobj=that.synobj;
          return *this;
      }
      
    };
    
    ;
    public:
    MDList ()  ;
    ~MDList() ;
    void Insert(int key) ;
    bool Delete(int key) ;
    bool Find(int key) ;
    private:
    template <int D>
    void KeyToCoord(int key,uint8_t coord[]) ;
    void LocatePred(uint8_t coord[],Node*& pred,Node*& curr,int& dim,int& pred_dim) ;
    void FillNewNode(Node* new_node,Node* pred,Node* curr,int dim,int pred_dim) ;
    void FinishInserting(Node* n,Node* curr,int dim,int pred_dim) ;
    void Traverse_read(Node* n,Node* parent,int dim,std::string & prefix) ;
    void Traverse_write(Node* n,Node* parent,int dim,std::string & prefix) ;
    private:
    wrapper_t* m_head;
  };
#include <cstdio>
#include <cstring>
#include <cmath>
#include <immintrin.h>
#define CLR_ADPINV(_p)    ((Node *)(((uintptr_t)(_p)) & ~1))
#define IS_ADPINV(_p)     (((uintptr_t)(_p)) & 1)
template <int D>
void MDList::KeyToCoord (int key,uint8_t coord[]) {
   const static int basis[32]= { 0xffffffff,0x10000,0x800,0x100,0x80,0x40,0x20,0x10,0xC,0xA,0x8,0x7,0x6,0x5,0x5,0x4,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x2 };
   int quotient=key;
   int i=D-1;
   while (i>=0)
     {
        coord[i] = quotient%basis[D-1];
        quotient = quotient/basis[D-1];
        i--;
     }
}
MDList::MDList ()  {
   gc = new GarbageCollector ();
   struct MDList_synobj* state_tmp=new MDList_synobj ();
   state_tmp->synobj.parent_gc = gc;
   state_tmp->synobj.version_number = 1;
   state = state_tmp;
   WRP_WRITE(m_head) = allocate_node();
   std::memset (WRP_WRITE(m_head),0,sizeof (Node));
}
MDList :: ~MDList() {
   
}
void MDList::Insert (int key) {
    
   int __ret__9;
   Node* new_node=allocate_node();
   const static int _b10_basis[32]= { 0xffffffff,0x10000,0x800,0x100,0x80,0x40,0x20,0x10,0xC,0xA,0x8,0x7,0x6,0x5,0x5,0x4,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x2 };
   int _b10_quotient=0;
   int _b10_i=0;
   Node* pred=(Node*)(-1);
   Node* curr=(Node*)(-1);
   int dim=0;
   int pred_dim=0;
   WRITE_OP_BEGIN
     // write operation begin
     
     __ret__9 = 0;
     new_node->m_key = key;
     _b10_quotient = key;
     _b10_i = DIMENSION-1;
     while (_b10_i>=0)
       {
          new_node->m_coord[i] = _b10_quotient%_b10_basis[DIMENSION-1];
          _b10_quotient = _b10_quotient/_b10_basis[DIMENSION-1];
          _b10_i--;
       }
     pred = NULL;
     Node* tmp_var_0;
     MOD_READ(m_head,tmp_var_0);
     curr = tmp_var_0;
     dim = 0;
     pred_dim = 0;
     while (dim<DIMENSION)
       {
          while (curr&&new_node->m_coord[dim]>curr->m_coord[dim])
            {
               pred_dim = dim;
               pred = curr;
               Node* tmp_var_1;
               MOD_READ(curr->m_child[dim],tmp_var_1);
               curr = tmp_var_1;
            }
          if (curr==NULL||new_node->m_coord[dim]<curr->m_coord[dim]) 
            {
               break;
            }
          else 
            {
               ++dim;
            }
       }
     if (dim==DIMENSION) 
       {
          __ret__9 = 1;
       }
     if (__ret__9!=1) 
       {
          {
             for (int i=0; i<pred_dim; i+=1)
               {
                  WRP_WRITE(new_node->m_child[i]) = 0;
               }
             std::memset (new_node->m_child+pred_dim,0,sizeof (Node*)*(DIMENSION-pred_dim));
             if (dim<DIMENSION) 
               {
                  WRP_WRITE(new_node->m_child[dim]) = curr;
               }
          }
          WRP_WRITE(pred->m_child[pred_dim]) = new_node;
          {
             for (int i=pred_dim; i<dim; i+=1)
               {
                  Node* tmp_var_2;
                  MOD_READ(curr->m_child[i],tmp_var_2);
                  Node* child=tmp_var_2;
                  WRP_WRITE(curr->m_child[i]) = 0;
                  WRP_WRITE(new_node->m_child[i]) = child;
               }
          }
       }
     
     // write operation end
   WRITE_OP_END
   return ;
}
void MDList::LocatePred (uint8_t coord[],Node*& pred,Node*& curr,int& dim,int& pred_dim) {
   while (dim<DIMENSION)
     {
        while (curr&&coord[dim]>curr->m_coord[dim])
          {
             pred_dim = dim;
             pred = curr;
             curr = curr->m_child[dim];
          }
        if (curr==NULL||coord[dim]<curr->m_coord[dim]) 
          {
             break;
          }
        else 
          {
             ++dim;
          }
     }
}
void MDList::FillNewNode (Node* new_node,Node* pred,Node* curr,int dim,int pred_dim) {
   for (int i=0; i<pred_dim; i+=1)
     {
        new_node->m_child[i] = 0;
     }
   memset(new_node->m_child+pred_dim,0,sizeof (Node*)*(DIMENSION-pred_dim));
   if (dim<DIMENSION) 
     {
        new_node->m_child[dim] = curr;
     }
}
void MDList::FinishInserting (Node* n,Node* curr,int dim,int pred_dim) {
   for (int i=pred_dim; i<dim; i+=1)
     {
        Node* child=curr->m_child[i];
        curr->m_child[i] = 0;
        n->m_child[i] = child;
     }
}
bool MDList::Delete (int key) {
    
   int __ret__10;
   uint8_t coord[DIMENSION];
   const static int _b14_basis[32]= { 0xffffffff,0x10000,0x800,0x100,0x80,0x40,0x20,0x10,0xC,0xA,0x8,0x7,0x6,0x5,0x5,0x4,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x2 };
   int _b14_quotient=0;
   int _b14_i=0;
   Node* pred=(Node*)(-1);
   Node* curr=(Node*)(-1);
   int dim=0;
   int pred_dim=0;
   Node* nextChild=(Node*)(-1);
   int child_dim=0;
   WRITE_OP_BEGIN
     // write operation begin
     
     __ret__10 = -1;
     _b14_quotient = key;
     _b14_i = DIMENSION-1;
     while (_b14_i>=0)
       {
          coord[i] = _b14_quotient%_b14_basis[DIMENSION-1];
          _b14_quotient = _b14_quotient/_b14_basis[DIMENSION-1];
          _b14_i--;
       }
     pred = NULL;
     Node* tmp_var_3;
     MOD_READ(m_head,tmp_var_3);
     curr = tmp_var_3;
     dim = 0;
     pred_dim = 0;
     while (dim<DIMENSION)
       {
          while (curr&&coord[dim]>curr->m_coord[dim])
            {
               pred_dim = dim;
               pred = curr;
               Node* tmp_var_4;
               MOD_READ(curr->m_child[dim],tmp_var_4);
               curr = tmp_var_4;
            }
          if (curr==NULL||coord[dim]<curr->m_coord[dim]) 
            {
               break;
            }
          else 
            {
               ++dim;
            }
       }
     nextChild = NULL;
     child_dim = 0;
     if (dim==DIMENSION) 
       {
          int i=DIMENSION-1;
          while (i>=0)
            {
               Node* tmp_var_5;
               MOD_READ(curr->m_child[i],tmp_var_5);
               if (tmp_var_5!=NULL) 
                 {
                    Node* tmp_var_6;
                    MOD_READ(curr->m_child[i],tmp_var_6);
                    nextChild = tmp_var_6;
                    child_dim = i;
                    break;
                 }
               i--;
            }
          WRP_WRITE(pred->m_child[pred_dim]) = nextChild;
          if (nextChild!=NULL) 
            {
               for (int i=pred_dim; i<child_dim; i+=1)
                 {
                    Node* tmp_var_7;
                    MOD_READ(curr->m_child[i],tmp_var_7);
                    WRP_WRITE(nextChild->m_child[i]) = tmp_var_7;
                 }
            }
          __ret__10 = true;
       }
     else 
       {
          __ret__10 = false;
       }
     
     // write operation end
   WRITE_OP_END
   return __ret__10;
}
bool MDList::Find (int key) {
    
   uint8_t coord[DIMENSION];
   const static int _b18_basis[32]= { 0xffffffff,0x10000,0x800,0x100,0x80,0x40,0x20,0x10,0xC,0xA,0x8,0x7,0x6,0x5,0x5,0x4,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x2 };
   int _b18_quotient=0;
   int _b18_i=0;
   Node* pred=(Node*)(-1);
   Node* curr=(Node*)(-1);
   int dim=0;
   int pred_dim=0;
   READ_OP_BEGIN
     // read operation begin
     
     _b18_quotient = key;
     _b18_i = DIMENSION-1;
     while (_b18_i>=0)
       {
          coord[i] = _b18_quotient%_b18_basis[DIMENSION-1];
          _b18_quotient = _b18_quotient/_b18_basis[DIMENSION-1];
          _b18_i--;
       }
     pred = NULL;
     Node* tmp_var_8;
     MOD_READ_R(m_head,tmp_var_8);
     curr = tmp_var_8;
     dim = 0;
     pred_dim = 0;
     while (dim<DIMENSION)
       {
          while (curr&&coord[dim]>curr->m_coord[dim])
            {
               pred_dim = dim;
               pred = curr;
               Node* tmp_var_9;
               MOD_READ_R(curr->m_child[dim],tmp_var_9);
               curr = tmp_var_9;
            }
          if (curr==NULL||coord[dim]<curr->m_coord[dim]) 
            {
               break;
            }
          else 
            {
               ++dim;
            }
       }
     // read operation end
   READ_OP_END
   return dim==DIMENSION;
}
void MDList::Traverse_read (Node* n,Node* parent,int dim,std::string & prefix) {
   struct MDList_synobj *oldstate = get_old_synobj();
   
   int i=DIMENSION-1;
   while (i>=dim)
     {
        Node* tmp_var_10;
        if(!check_conflict(oldstate,n->m_child[i],tmp_var_10)) throw "conflict";
        Node* child=tmp_var_10;
        if (child!=NULL) 
          {
             Traverse_read(child,n,i,prefix);
          }
        i--;
     }
}
void MDList::Traverse_write (Node* n,Node* parent,int dim,std::string & prefix) {
   struct MDList_synobj *oldstate = get_old_synobj();
   struct MDList_synobj *newstate = get_new_synobj();
   
   int i=DIMENSION-1;
   while (i>=dim)
     {
        Node* tmp_var_10;
        if(!check_conflict(oldstate,newstate,n->m_child[i],tmp_var_10)) throw "conflict";
        Node* child=tmp_var_10;
        if (child!=NULL) 
          {
             Traverse_write(child,n,i,prefix);
          }
        i--;
     }
}
#endif 
