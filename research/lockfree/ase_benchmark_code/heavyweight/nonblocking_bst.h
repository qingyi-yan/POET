
#ifdef NONBLOCKING_BST

#define ENABLE_REVALIDATION

#include "bst_header.h"

template <typename T>
class BST
{
#ifdef CHECK_CORRECTNESS
int elem_min;
int final_count;
#endif
    struct GarbageCollector;
    struct BST_synobj;
    typedef struct BST_synobj synobj_t;
    struct Node;
    typedef Node gc_node_t;
    #define ENABLE_GC_NODE_ALLOCATOR
    typedef struct wrapper_s {
        wrapper_s* gc_next;
        Node* value;
        int version;
    } wrapper_t;
    typedef Node* value_t;

    struct Node {
        T value;
        wrapper_t* left;
        wrapper_t* right;
        wrapper_t* parent;
        Node() {
            left = right = parent = 0;
        }
        Node(T v) : value(v) {
            left = right = parent = 0;
        }
        Node* gc_next;
    };

    #include "nonblocking_sync.h"
    struct BST_synobj{
      BST_synobj* gc_next;

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
      BST_synobj& operator =(BST_synobj& that)
      {
          synobj=that.synobj;
          return *this;
      }

      BST_synobj& reload(BST_synobj& that)
      {
        synobj.reload(that.synobj);
        return *this;
      }

    };

    public:
    public:
    BST ()  {
       gc = new GarbageCollector ();
       struct BST_synobj* state_tmp=new BST_synobj ();
       state_tmp->synobj.parent_gc = gc;
       state_tmp->synobj.version_number = 1;
       // WRP_WRITE(root) = new Node(-1);
       root = new wrapper_t;
       root->value = new Node(-1);
       state = state_tmp;
    }
    void correctness_verification(Node *curr) {
#ifdef CHECK_CORRECTNESS
        if (curr == 0) return;
        // printf("left tree begin\n");
        if (read_wrapper(curr->left) != 0) {
            if (read_wrapper(read_wrapper(curr->left)->parent) != curr) {
                printf("curr->left->parent != curr\n");
            }
        }
        correctness_verification(read_wrapper(curr->left));
        // printf("left tree done\n");
        while (elem_counter[elem_min].load() == 0) {
            elem_min ++;
            // printf("%d\n", elem_min);
        }
        if (elem_counter[elem_min].load()!=1) {
            printf("error: elem_counter[%d] should be 1 (%d)\n", elem_min, elem_counter[elem_min].load());
        }
        if (curr->value !=elem_min) {
            // if (elem_min < 2000000) {
                printf("error: %u != %d elem_counter(%d)\n", curr->value, elem_min, elem_counter[curr->value].load());
            // }
        } else {
            elem_counter[elem_min] = 0;
        }
        final_count ++;
        // printf("right tree begin\n");
        if (read_wrapper(curr->right) != 0) {
            if (read_wrapper(read_wrapper(curr->right)->parent) != curr) {
                printf("root->right->parent != curr\n");
            }
        }
        correctness_verification(read_wrapper(curr->right));
        // printf("right tree done\n");
        // printf("subtree finished\n");
#endif
    }

    ~BST() {
#ifdef CHECK_CORRECTNESS
        printf("correctness_verification begin\n");
        elem_min = 0;
        final_count = 0;
        correctness_verification(read_wrapper(read_wrapper(root)->right));
        for (int i = 0; i < MAX_VAL; i++) {
            if (elem_counter[i].load() != 0) {
                printf("error: elem_counter[%d] should be 0\n", i);
            }
        }
        printf("correctness_verification done %d\n", final_count);
#endif
    }

    ;
    bool insert(T t) ;
    bool remove(T& t) ;
    bool contains(T v) ;
private:
    wrapper_t* root;

  };

template <typename T>
bool BST<T>::insert(T newItem) {
       Node* newNode=allocate_node();
       Node* tmp_var_0;
       Node* curr=(Node*)(-1);
       Node* newNodeParent=(Node*)(-1);
       Node* root_node=(Node*)(-1);
       bool ret=-1;
       WRITE_OP_BEGIN
         // write operation begin

         newNode->value = newItem;
         WRP_WRITE(newNode->parent) = 0;
         WRP_WRITE(newNode->left) = 0;
         WRP_WRITE(newNode->right) = 0;

         curr = 0;
         newNodeParent = 0;
         root_node = 0;
         ret = true;
         Node* tmp_var_0;
         // MOD_READ(root,tmp_var_0);
         // root_node = tmp_var_0;
         root_node = root->value;
         Node* tmp_var_1;
         MOD_READ(root_node->right,tmp_var_1);
         curr = tmp_var_1;
         while (curr)
           {
              newNodeParent = curr;
              if (curr->value==newItem)
                {
                   ret = false;
                   break;
                }
              else if (newItem<curr->value)
                {
                   Node* tmp_var_2;
                   MOD_READ(curr->left,tmp_var_2);
                   curr = tmp_var_2;
                }
              else
                {
                   Node* tmp_var_3;
                   MOD_READ(curr->right,tmp_var_3);
                   curr = tmp_var_3;
                }
           }
         if (ret)
           {
              WRP_WRITE(newNode->parent) = newNodeParent;
              if (newNodeParent==0)
                {
                   MOD_WRITE(root_node->right, newNode);
                }
              else
                {
                   if (newItem<newNodeParent->value)
                     {
                        MOD_WRITE(newNodeParent->left, newNode);
                     }
                   else
                     {
                        MOD_WRITE(newNodeParent->right, newNode);
                     }
                }
           }

         // write operation end
       WRITE_OP_END

#ifdef CHECK_CORRECTNESS
   if (ret) elem_counter[newItem] ++;
#endif
   return ret;
}

template <typename T>
bool BST<T>::remove(T& t) {
       bool ret=-1;
       Node* nodeToRemove=(Node*)(-1);
       Node* root_node=(Node*)(-1);
       WRITE_OP_BEGIN
         // write operation begin

         ret = false;
         nodeToRemove = 0;
         Node* tmp_var_4;
         // MOD_READ(root,tmp_var_4);
         // root_node = tmp_var_4;
         root_node = root->value;
         Node* tmp_var_5;
         MOD_READ(root_node->right,tmp_var_5);
         nodeToRemove = tmp_var_5;
         while (nodeToRemove!=0)
           {
              if (t==nodeToRemove->value)
                {
                   ret = true;
                   break;
                }
              else
                {
                   if (t<nodeToRemove->value)
                     {
                        Node* tmp_var_6;
                        MOD_READ(nodeToRemove->left,tmp_var_6);
                        nodeToRemove = tmp_var_6;
                     }
                   else
                     {
                        Node* tmp_var_7;
                        MOD_READ(nodeToRemove->right,tmp_var_7);
                        nodeToRemove = tmp_var_7;
                     }
                }
           }
         if (ret)
           {
              Node* tmp_var_8;
              MOD_READ(nodeToRemove->left,tmp_var_8);
              if (tmp_var_8==0)
                {
                   Node* u=nodeToRemove;
                   Node* tmp_var_9;
                   MOD_READ(nodeToRemove->right,tmp_var_9);
                   Node* v=tmp_var_9;
                   Node* tmp_var_10;
                   MOD_READ(u->parent,tmp_var_10);
                   if (tmp_var_10==0)
                     {
                        MOD_WRITE(root_node->right, v);
                     }
                   else
                     {
                        Node* tmp_var_11;
                        MOD_READ(tmp_var_10->left,tmp_var_11);
                        if (u==tmp_var_11)
                          {
                             MOD_WRITE(tmp_var_10->left, v);
                          }
                        else
                          {
                             MOD_WRITE(tmp_var_10->right, v);
                          }
                     }
                   if (v!=0)
                     {
                        Node* tmp_var_12;
                        // MOD_READ(u->parent,tmp_var_12);
                        tmp_var_12 = tmp_var_10;
                        MOD_WRITE(v->parent, tmp_var_12);
                     }
                }
              else
                {
                   Node* tmp_var_13;
                   MOD_READ(nodeToRemove->right,tmp_var_13);
                   if (tmp_var_13==0)
                     {
                        Node* u=nodeToRemove;
                        Node* tmp_var_14;
                        MOD_READ(nodeToRemove->left,tmp_var_14);
                        Node* v=tmp_var_14;
                        Node* tmp_var_15;
                        MOD_READ(u->parent,tmp_var_15);
                        if (tmp_var_15==0)
                          {
                             MOD_WRITE(root_node->right, v);
                          }
                        else
                          {
                             Node* tmp_var_16;
                             MOD_READ(tmp_var_15->left,tmp_var_16);
                             if (u==tmp_var_16)
                               {
                                  MOD_WRITE(tmp_var_15->left, v);
                               }
                             else
                               {
                                  MOD_WRITE(tmp_var_15->right, v);
                               }
                          }
                        if (v!=0)
                          {
                             Node* tmp_var_17;
                             // MOD_READ(u->parent,tmp_var_17);
                             tmp_var_17 = tmp_var_15;
                             MOD_WRITE(v->parent, tmp_var_17);
                          }
                     }
                   else
                     {
                        Node* successor=0;
                        {
                           Node* tmp_var_18;
                           MOD_READ(nodeToRemove->right,tmp_var_18);
                           Node* rootNode=tmp_var_18;
                           Node* current=rootNode;
                           Node* tmp_var_19;
                           MOD_READ(current->left,tmp_var_19);
                           while (tmp_var_19!=0)
                             {
                                Node* tmp_var_20;
                                MOD_READ(current->left,tmp_var_20);
                                current = tmp_var_20;
                                MOD_READ(current->left,tmp_var_19);
                             }
                           successor = current;
                        }
                        Node* tmp_var_21;
                        MOD_READ(successor->parent,tmp_var_21);
                        if (tmp_var_21!=nodeToRemove)
                          {
                             {
                                Node* u=successor;
                                Node* tmp_var_22;
                                MOD_READ(successor->right,tmp_var_22);
                                Node* v=tmp_var_22;
                                Node* tmp_var_23;
                                MOD_READ(u->parent,tmp_var_23);
                                if (tmp_var_23==0)
                                  {
                                     MOD_WRITE(root_node->right, v);
                                  }
                                else
                                  {
                                     Node* tmp_var_24;
                                     MOD_READ(tmp_var_23->left,tmp_var_24);
                                     if (u==tmp_var_24)
                                       {
                                          MOD_WRITE(tmp_var_23->left, v);
                                       }
                                     else
                                       {
                                          MOD_WRITE(tmp_var_23->right, v);
                                       }
                                  }
                                if (v!=0)
                                  {
                                     Node* tmp_var_25;
                                     // MOD_READ(u->parent,tmp_var_25);
                                     tmp_var_25 = tmp_var_23;
                                     MOD_WRITE(v->parent, tmp_var_25);
                                  }
                             }
                             Node* tmp_var_26;
                             MOD_READ(nodeToRemove->right,tmp_var_26);
                             MOD_WRITE(successor->right, tmp_var_26);
                             // Node* tmp_var_27=WRP_READ(successor->right);
                             Node* tmp_var_27;
                             MOD_READ(successor->right, tmp_var_27);
                             MOD_WRITE(tmp_var_27->parent, successor);
                          }
                        {
                           Node* u=nodeToRemove;
                           Node* v=successor;
                           Node* tmp_var_28;
                           MOD_READ(u->parent,tmp_var_28);
                           if (tmp_var_28==0)
                             {
                                MOD_WRITE(root_node->right, v);
                             }
                           else
                             {
                                Node* tmp_var_29;
                                MOD_READ(tmp_var_28->left,tmp_var_29);
                                if (u==tmp_var_29)
                                  {
                                     MOD_WRITE(tmp_var_28->left, v);
                                  }
                                else
                                  {
                                     MOD_WRITE(tmp_var_28->right, v);
                                  }
                             }
                           if (v!=0)
                             {
                                Node* tmp_var_30;
                                // MOD_READ(u->parent,tmp_var_30);
                                tmp_var_30 = tmp_var_28;
                                MOD_WRITE(v->parent, tmp_var_30);
                             }
                        }
                        Node* tmp_var_31;
                        MOD_READ(nodeToRemove->left,tmp_var_31);
                        MOD_WRITE(successor->left, tmp_var_31);
                        // Node* tmp_var_32=WRP_READ(successor->left);
                        Node* tmp_var_32;
                        MOD_READ(successor->left, tmp_var_32);
                        MOD_WRITE(tmp_var_32->parent, successor);
                     }
                }
                FREE_NODE(nodeToRemove);
           }

         // write operation end
       WRITE_OP_END
#ifdef CHECK_CORRECTNESS
   if (ret) elem_counter[t] --;
#endif
   return ret;
}
template <typename T>
bool BST<T>::contains(T v) {
       Node* curr;
       Node* root_node;
       bool ret;
       READ_OP_BEGIN
         // read operation begin

         curr = 0;
         root_node = 0;
         ret = false;
         Node* tmp_var_33;
         MOD_READ_R(root,tmp_var_33);
         root_node = tmp_var_33;
         Node* tmp_var_34;
         MOD_READ_R(root_node->right,tmp_var_34);
         curr = tmp_var_34;
         while (curr)
           {
              if (curr->value==v)
                {
                   ret = true;
                   break;
                }
              else if (v<curr->value)
                {
                   Node* tmp_var_35;
                   MOD_READ_R(curr->left,tmp_var_35);
                   curr = tmp_var_35;
                }
              else
                {
                   Node* tmp_var_36;
                   MOD_READ_R(curr->right,tmp_var_36);
                   curr = tmp_var_36;
                }
           }
         // read operation end
       READ_OP_END
       return ret;
}

/*************************************************
    Adapter for benchmark
**************************************************/

template <class T>
class heavyweight_struct {
    BST<T> set;
public:
    heavyweight_struct(): set() {}
    bool insert(T send_v) {
        return set.insert(send_v);
    }
    void erase(T send_v) {
        set.remove(send_v);
    }
    bool find(T send_v) {
        return set.contains(send_v);
    }
};


#endif // NONBLOCKING_HASHSET


