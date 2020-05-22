#define ENABLE_DATA_PARTITION // data partitioned

#define ENABLE_REVALIDATION // safe to revalidate

#include "nonblocking_header.h"
template <typename T>
class BST  
  ;
template <typename T>
class BST  
  {
    struct GarbageCollector;
    struct BST_synobj;
    typedef struct BST_synobj synobj_t;
    struct Node;
    typedef Node gc_node_t;
    #define ENABLE_GC_NODE_ALLOCATOR
    typedef struct {
        Node* value;
        int version;
    } wrapper_t;
    typedef Node* value_t;
    
    #include "nonblocking_sync.h"
    struct BST_synobj{
      ;
      Node* root_entry;
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
      BST_synobj& operator =(BST_synobj& that)
      {
          
          synobj=that.synobj;
          return *this;
      }
      
    };
    
    ;
    public:
    struct Node{
      wrapper_t* left;
      wrapper_t* right;
      wrapper_t* parent;
      T value;
    };
    BST ()  {
       gc = new GarbageCollector ();
       struct BST_synobj* state_tmp=new BST_synobj ();
       state_tmp->synobj.parent_gc = gc;
       state_tmp->synobj.version_number = 1;
       state = state_tmp;
       root = (Node**)calloc(50,sizeof (Node*));
       num_subtree = 16;
       size_subtree = 10000;
    }
    ;
    bool insert(int newItem) {
        
       Node* newNode=allocate_node(newItem);
       Node* newNodeParent=(Node*)(-1);
       Node* root_node=(Node*)(-1);
       Node* curr=(Node*)(-1);
       bool ret=-1;
       WRITE_OP_BEGIN(newItem/size_subtree)
         // write operation begin
         
         Node* root__right_copy=0;
         Node* newNodeParent_left_copy=0;
         Node* newNodeParent_right_copy=0;
         newNodeParent = 0;
         Node* tmp_var_0;
         SNAPSHOT_READ(root_entry,tmp_var_0);
         root_node = tmp_var_0;
         Node* tmp_var_1;
         MOD_READ(root_node->right,tmp_var_1);
         curr = tmp_var_1;
         ret = true;
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
                   root__right_copy = newNode;
                   MOD_WRITE(tmp_var_0->right,root__right_copy);
                }
              else 
                {
                   if (newItem<newNodeParent->value) 
                     {
                        newNodeParent_left_copy = newNode;
                        MOD_WRITE(newNodeParent->left,newNodeParent_left_copy);
                     }
                   else 
                     {
                        newNodeParent_right_copy = newNode;
                        MOD_WRITE(newNodeParent->right,newNodeParent_right_copy);
                     }
                }
           }
         
         // write operation end
       WRITE_OP_END
       return ret;
    }
    bool remove(int t) {
        
       bool ret=-1;
       Node* nodeToRemove=(Node*)(-1);
       Node* root_node=(Node*)(-1);
       WRITE_OP_BEGIN(t/size_subtree)
         // write operation begin
         
         Node* root__right_copy=0;
         Node* successor_right_copy=0;
         Node* successor_right_parent_copy=0;
         Node* root_node_right_copy=0;
         Node* u_parent_left_copy=0;
         Node* u_parent_right_copy=0;
         Node* v_parent_copy=0;
         Node* successor_left_copy=0;
         Node* successor_left_parent_copy=0;
         ret = false;
         nodeToRemove = 0;
         Node* tmp_var_4;
         SNAPSHOT_READ(root_entry,tmp_var_4);
         root_node = tmp_var_4;
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
                        root__right_copy = v;
                        MOD_WRITE(tmp_var_4->right,root__right_copy);
                     }
                   else 
                     {
                        Node* tmp_var_11;
                        MOD_READ(tmp_var_10->left,tmp_var_11);
                        if (u==tmp_var_11) 
                          {
                             u_parent_left_copy = v;
                             MOD_WRITE(tmp_var_10->left,u_parent_left_copy);
                          }
                        else 
                          {
                             u_parent_right_copy = v;
                             MOD_WRITE(tmp_var_10->right,u_parent_right_copy);
                          }
                     }
                   if (v!=0) 
                     {
                        Node* tmp_var_12;
                        MOD_READ(u->parent,tmp_var_12);
                        v_parent_copy = tmp_var_12;
                        MOD_WRITE(v->parent,v_parent_copy);
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
                             root_node_right_copy = v;
                             MOD_WRITE(root_node->right,root_node_right_copy);
                          }
                        else 
                          {
                             Node* tmp_var_16;
                             MOD_READ(tmp_var_15->left,tmp_var_16);
                             if (u==tmp_var_16) 
                               {
                                  u_parent_left_copy = v;
                                  MOD_WRITE(tmp_var_15->left,u_parent_left_copy);
                               }
                             else 
                               {
                                  u_parent_right_copy = v;
                                  MOD_WRITE(tmp_var_15->right,u_parent_right_copy);
                               }
                          }
                        if (v!=0) 
                          {
                             Node* tmp_var_17;
                             MOD_READ(u->parent,tmp_var_17);
                             v_parent_copy = tmp_var_17;
                             MOD_WRITE(v->parent,v_parent_copy);
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
                                     root_node_right_copy = v;
                                     MOD_WRITE(root_node->right,root_node_right_copy);
                                  }
                                else 
                                  {
                                     Node* tmp_var_24;
                                     MOD_READ(tmp_var_23->left,tmp_var_24);
                                     if (u==tmp_var_24) 
                                       {
                                          u_parent_left_copy = v;
                                          MOD_WRITE(tmp_var_23->left,u_parent_left_copy);
                                       }
                                     else 
                                       {
                                          u_parent_right_copy = v;
                                          MOD_WRITE(tmp_var_23->right,u_parent_right_copy);
                                       }
                                  }
                                if (v!=0) 
                                  {
                                     Node* tmp_var_25;
                                     MOD_READ(u->parent,tmp_var_25);
                                     v_parent_copy = tmp_var_25;
                                     MOD_WRITE(v->parent,v_parent_copy);
                                  }
                             }
                             Node* tmp_var_26;
                             MOD_READ(nodeToRemove->right,tmp_var_26);
                             successor_right_copy = tmp_var_26;
                             MOD_WRITE(successor->right,successor_right_copy);
                             successor_right_parent_copy = successor;
                             Node* tmp_var_27;
                             MOD_READ(successor->right,tmp_var_27);
                             MOD_WRITE(tmp_var_27->parent,successor_right_parent_copy);
                          }
                        {
                           Node* u=nodeToRemove;
                           Node* v=successor;
                           Node* tmp_var_28;
                           MOD_READ(u->parent,tmp_var_28);
                           if (tmp_var_28==0) 
                             {
                                root_node_right_copy = v;
                                MOD_WRITE(root_node->right,root_node_right_copy);
                             }
                           else 
                             {
                                Node* tmp_var_29;
                                MOD_READ(tmp_var_28->left,tmp_var_29);
                                if (u==tmp_var_29) 
                                  {
                                     u_parent_left_copy = v;
                                     MOD_WRITE(tmp_var_28->left,u_parent_left_copy);
                                  }
                                else 
                                  {
                                     u_parent_right_copy = v;
                                     MOD_WRITE(tmp_var_28->right,u_parent_right_copy);
                                  }
                             }
                           if (v!=0) 
                             {
                                Node* tmp_var_30;
                                MOD_READ(u->parent,tmp_var_30);
                                v_parent_copy = tmp_var_30;
                                MOD_WRITE(v->parent,v_parent_copy);
                             }
                        }
                        Node* tmp_var_31;
                        MOD_READ(nodeToRemove->left,tmp_var_31);
                        successor_left_copy = tmp_var_31;
                        MOD_WRITE(successor->left,successor_left_copy);
                        successor_left_parent_copy = successor;
                        Node* tmp_var_32;
                        MOD_READ(successor->left,tmp_var_32);
                        MOD_WRITE(tmp_var_32->parent,successor_left_parent_copy);
                     }
                }
           }
         
         // write operation end
       WRITE_OP_END
       return ret;
    }
    bool contains(int v) {
        
       Node* curr;
       Node* root_node;
       bool ret;
       READ_OP_BEGIN(v/size_subtree)
         // read operation begin
         
         curr = 0;
         root_node = 0;
         ret = false;
         Node* tmp_var_33;
         SNAPSHOT_READ(root_entry,tmp_var_33);
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
    private:
    wrapper_t** root;
    int num_subtree;
    int size_subtree;
  };
