
#ifdef NONBLOCKING_MDLIST_ARRAYBASED

#define ENABLE_DATA_PARTITION
#define ENABLE_REVALIDATION

#include "mdlist_arraybased_header.h"

template <class T>
class MDList
{
#ifdef CHECK_CORRECTNESS
    int final_count;
#endif
    struct GarbageCollector;
    struct MDList_synobj;
    typedef struct MDList_synobj synobj_t;
    struct Node;
    typedef Node gc_node_t;
    #define ENABLE_GC_NODE_ALLOCATOR
    typedef struct wrapper_s {
        wrapper_s* gc_next;
        Node* value;
        int version;
    } wrapper_t;
    typedef Node* value_t;

    #include "nonblocking_sync.h"
    static const uint32_t DIMENSION=16;
    struct Node{
      wrapper_t* m_child[DIMENSION];
      uint8_t m_coord[DIMENSION];
      uint32_t m_key;
      struct Node* gc_next;
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
      MDList_synobj& reload(MDList_synobj& that)
      {
          synobj.reload(that.synobj);
          return *this;
      }

    };

    public:
    public:
    MDList (int)  ;
    ~MDList() ;
    bool Insert(uint32_t key) ;
    bool Delete(uint32_t key) ;
    bool Find(uint32_t key) ;
    void Traverse(Node* n,Node* parent,int dim);
    inline uint32_t hash_func (uint32_t key) {
        return (key/partition_size);
    }
    private:
    private:
    Node** m_head;
    int partition_num;
    int partition_size;
  };
#include <cstdio>
#include <cstring>
#include <cmath>
#include <immintrin.h>
#define CLR_ADPINV(_p)    ((Node *)(((uintptr_t)(_p)) & ~1))
#define IS_ADPINV(_p)     (((uintptr_t)(_p)) & 1)
template<class T>
MDList<T>::MDList (int _partition_num)  {
   partition_num = _partition_num;
   partition_size = (MAX_VAL+1)/partition_num;
   m_head = new Node* [partition_num];
   printf("begin init\n");
   for (int i = 0; i <partition_num; i++) {
    gc_array[i] = new GarbageCollector ();
    struct MDList_synobj* state_tmp=new MDList_synobj ();
    state_tmp->synobj.parent_gc = gc_array[i];
    state_tmp->synobj.version_number = 1;
    m_head[i] = new Node ();
    std::memset(m_head[i],0,sizeof(Node));
    // write_wrapper(m_head[i]->m_child[0]) = new Node();
    m_head[i]->m_child[0] = new wrapper_t;
    m_head[i]->m_child[0]->value = new Node();
    // std::memset((write_wrapper(m_head[i]->m_child[0])),0,sizeof(Node));
    std::memset(m_head[i]->m_child[0]->value,0,sizeof(Node));
    // write_wrapper(m_head[i]->m_child[0])->m_key = -1;
    m_head[i]->m_child[0]->value->m_key = -1;
    state_array[i] = state_tmp;
   }
   printf("end init\n");
}

template<class T>
void MDList<T>::Traverse(Node* n,Node* parent,int dim) {
#ifdef CHECK_CORRECTNESS
    if (n->m_key != -1) {
        elem_counter[n->m_key] --;
        final_count ++;
    }
   for (int i=DIMENSION-1; i>-1+dim; i-=1)
     {
        Node* child=read_wrapper(n->m_child[i]);
        if (child!=NULL)
          {
             Traverse(child,n,i);
          }
     }
#endif
}

template<class T>
MDList<T> :: ~MDList() {
#ifdef CHECK_CORRECTNESS
    final_count = 0;
    for (int i = 0; i < partition_num; i++) {
    Traverse(read_wrapper(m_head[i]->m_child[0]),NULL,0);
    }

    for (int i = 0; i < MAX_VAL; i++) {
        if (elem_counter[i].load() != 0) {
            printf("error: elem_counter[%d] should be 0 (%d)\n", i, elem_counter[i].load());
        }
    }
    printf("final_count %d\n", final_count);
#endif
}

template<class T>
bool MDList<T>::Insert(uint32_t key) {
   if (key == 0) key = 1;
   // Node* new_node=new Node ();
   Node* new_node=allocate_node();
   bool ret;
   const static uint32_t _b10_basis[32]= { 0xffffffff,0x10000,0x800,0x100,0x80,0x40,0x20,0x10,0xC,0xA,0x8,0x7,0x6,0x5,0x5,0x4,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x2 };
   uint8_t* _b10_coord=(uint8_t*)(-1);
   uint32_t _b10_quotient;
   Node* pred=(Node*)(-1);
   Node* curr=(Node*)(-1);
   uint32_t dim;
   uint32_t pred_dim;
   uint8_t* _b9_coord=(uint8_t*)(-1);

     _b10_coord = new_node->m_coord;
     _b10_quotient = key;
     for (int i=DIMENSION-1; i>-1; i-=1)
       {
          _b10_coord[i] = _b10_quotient%_b10_basis[DIMENSION-1];
          _b10_quotient = _b10_quotient/_b10_basis[DIMENSION-1];
       }
  WRITE_OP_BEGIN(hash_func(key))
     new_node->m_key = key;
     ret = false;
     pred = NULL;
     Node* tmp_var_0;
     // MOD_READ(m_head[hash_func(key)]->m_child[0],tmp_var_0);
     tmp_var_0 = m_head[hash_func(key)]->m_child[0]->value;
     curr = tmp_var_0;
     dim = 0;
     pred_dim = 0;
     _b9_coord = new_node->m_coord;
     while (dim<DIMENSION)
       {
          while (curr&&_b9_coord[dim]>curr->m_coord[dim])
            {
               pred_dim = dim;
               pred = curr;
               Node* tmp_var_1;
               MOD_READ(curr->m_child[dim],tmp_var_1);
               curr = tmp_var_1;
            }
          if (curr==NULL||_b9_coord[dim]<curr->m_coord[dim])
            {
               break;
            }
          else
            {
               ++dim;
            }
       }
     if (dim!=DIMENSION)
       {
          ret = true;
          {
             for (uint32_t i=0; i<pred_dim; ++i)
               {
                  WRP_WRITE(new_node->m_child[i]) = 0;
               }
             for (int i=0; i<DIMENSION-pred_dim; i+=1)
               {
                  // std::memset(&write_wrapper((new_node->m_child+pred_dim)[i]),0,sizeof(Node*));
                  WRP_WRITE((new_node->m_child+pred_dim)[i]) = 0;
               }
             if (dim<DIMENSION)
               {
                  WRP_WRITE(new_node->m_child[dim]) = curr;
               }
          }
          // write_wrapper(pred->m_child[pred_dim]) = new_node;
          MOD_WRITE(pred->m_child[pred_dim], new_node);
          {
             Node* n=new_node;
             for (uint32_t i=pred_dim; i<dim; ++i)
               {
                  Node* tmp_var_2;
                  MOD_READ(curr->m_child[i],tmp_var_2);
                  Node* child=tmp_var_2;
                  // write_wrapper(curr->m_child[i]) = 0;
                  MOD_WRITE(curr->m_child[i],0);
                  WRP_WRITE(n->m_child[i]) = child;
               }
          }
       }
    WRITE_OP_END
#ifdef CHECK_CORRECTNESS
       if (ret) elem_counter[key] ++;
#endif
       return ret;
}

template<class T>
bool MDList<T>::Delete(uint32_t key) {
   if (key == 0) key = 1;
   bool ret;
   uint8_t coord[DIMENSION];
   const static uint32_t _b14_basis[32]= { 0xffffffff,0x10000,0x800,0x100,0x80,0x40,0x20,0x10,0xC,0xA,0x8,0x7,0x6,0x5,0x5,0x4,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x2 };
   uint32_t _b14_quotient;
   Node* pred=(Node*)(-1);
   Node* curr=(Node*)(-1);
   uint32_t dim;
   uint32_t pred_dim;
   Node* nextChild=(Node*)(-1);
   uint32_t child_dim;
     _b14_quotient = key;
     for (int i=DIMENSION-1; i>-1; i-=1)
       {
          coord[i] = _b14_quotient%_b14_basis[DIMENSION-1];
          _b14_quotient = _b14_quotient/_b14_basis[DIMENSION-1];
       }

  WRITE_OP_BEGIN(hash_func(key))
     ret = false;
     pred = NULL;
     Node* tmp_var_3;
     // MOD_READ(m_head[hash_func(key)]->m_child[0],tmp_var_3);
     tmp_var_3 = m_head[hash_func(key)]->m_child[0]->value;
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
          ret = true;
          for (int i=DIMENSION-1; i>-1; i-=1)
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
            }
          // write_wrapper(pred->m_child[pred_dim]) = nextChild;
          MOD_WRITE(pred->m_child[pred_dim],nextChild);
          if (nextChild!=NULL)
            {
               for (uint32_t i=pred_dim; i<child_dim; i++)
                 {
                    Node* tmp_var_7;
                    MOD_READ(curr->m_child[i],tmp_var_7);
                    // write_wrapper(nextChild->m_child[i]) = tmp_var_7;
                    MOD_WRITE(nextChild->m_child[i],tmp_var_7);
                 }
            }
          FREE_NODE(curr);
       }
    WRITE_OP_END
#ifdef CHECK_CORRECTNESS
       if (ret) elem_counter[key] --;
#endif
       return ret;
}
template<class T>
bool MDList<T>::Find(uint32_t key) {
   if (key == 0) key = 1;
   uint8_t coord[DIMENSION];
   const static uint32_t _b18_basis[32]= { 0xffffffff,0x10000,0x800,0x100,0x80,0x40,0x20,0x10,0xC,0xA,0x8,0x7,0x6,0x5,0x5,0x4,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x2 };
   uint32_t _b18_quotient;
   Node* pred=(Node*)(-1);
   Node* curr=(Node*)(-1);
   uint32_t dim;
   uint32_t pred_dim;
     _b18_quotient = key;
     for (int i=DIMENSION-1; i>-1; i-=1)
       {
          coord[i] = _b18_quotient%_b18_basis[DIMENSION-1];
          _b18_quotient = _b18_quotient/_b18_basis[DIMENSION-1];
       }


   READ_OP_BEGIN(hash_func(key))
     pred = NULL;
     Node* tmp_var_8;
     // MOD_READ_R(m_head[hash_func(key)]->m_child[0],tmp_var_8);
     tmp_var_8 = m_head[hash_func(key)]->m_child[0]->value;
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
  READ_OP_END
   return dim==DIMENSION;
}

/*
template<class T> std::atomic<int> MDList<T>::GarbageCollector::thread_count(0);
template<class T> GC_Queue<typename MDList<T>::synobj_t>* MDList<T>::GarbageCollector::synobj_queue[GC_MAX_THREADS];
template<class T> GC_Queue<typename MDList<T>::wrapper_t>* MDList<T>::GarbageCollector::wrapper_queue[GC_MAX_THREADS];
template<class T> GC_Queue<typename MDList<T>::gc_node_t>* MDList<T>::GarbageCollector::node_queue[GC_MAX_THREADS];

template<class T> typename MDList<T>::synobj_t *MDList<T>::GarbageCollector::read_obj[GC_MAX_THREADS];

template<class T> unsigned MDList<T>::ConflictArray::shift = 0;
template<class T> unsigned MDList<T>::ConflictArray::mask = 0;
template<class T> GC_Array_Allocator<volatile int> MDList<T>::ActivityArray::allocator;
template<class T> GC_Array_Allocator<volatile void*> MDList<T>::ConflictArray::allocator;
template<class T> GC_Array_Allocator<typename MDList<T>::GC_Retired_SynObj> MDList<T>::RetiredSynObjArray::allocator;
*/

GC_STATIC_SETUP(template<class T>, MDList<T>);


/*************************************************
    Adapter for benchmark
**************************************************/

template <class T>
class heavyweight_struct {
    MDList<T> set;
public:
    heavyweight_struct(): set(N_SNAPSHOT) {}
    bool insert(T send_v) {
        return set.Insert(send_v);
    }
    void erase(T send_v) {
        set.Delete(send_v);
    }
    bool find(T send_v) {
        return set.Find(send_v);
    }
};

#endif // NONBLOCKING_MDLIST_ARRAYBASED
