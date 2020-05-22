#include "TATAS.h"
#include <vector>

template <typename T>
class BST  
  ;
template <typename T>
class Node  
  {
    public:
    friend class BST<T>;
    Node (T v)  {
       value = v;
       left = nullptr;
       right = nullptr;
       parent = nullptr;
    }
    private:
    Node* left;
    Node* right;
    Node* parent;
    T value;
  };
template <typename T>
class BST  
  {
    public:
    public:
    BST () : idx_(0) {
       root = nullptr;
    }
    ;
    void insert(T t) ;
    void remove(T& t) ;
    bool contains(T& v) ;
    bool isEmpty() ;
    std::string toString() {
       
       { 
         AcquireLock acq(lock1);
       
       return "Elements: "+std::to_string(idx_);
        }
    }
    private:
    size_t idx_;
    Node<T>* root;
    Node<T>* search(Node<T>* rootNode,T& value) ;
    Node<T>* findMin() ;
    void transplant(Node<T>* u,Node<T>* v) ;
    private:
    mutable TATAS lock1;
  };
template <typename T>
void BST<T>::insert(T newItem) {
   int __ret__9=0;
   T& _b4_v=newItem;
   int __ret__1=-1;
   T& _b6_value=_b4_v;
   Node<T>* __ret__3=(Node<T>*)(-1);
   if (__ret__1!=true)  
     {
        __ret__1 = false;
     }
   if (__ret__1)  
     {
        __ret__9 = 1;
     }
   Node<T>* _b4_rootNode=(Node<T>*)(-1);
   Node<T>* _b6_current=(Node<T>*)(-1);
   { 
     AcquireLock acq(lock1);
   
   _b4_rootNode = root;
   _b6_current = _b4_rootNode;
   if (_b6_current==nullptr||_b6_current->value==_b6_value)  
     {
        __ret__3 = _b6_current;
     }
   else if (_b6_value<_b6_current->value)  
     {
        __ret__3 = search(_b6_current->left,_b6_value);
     }
   else  
     {
        __ret__3 = search(_b6_current->right,_b6_value);
     }
   if (__ret__3!=nullptr)  
     {
        __ret__1 = true;
     }
   if (__ret__9!=1)  
     {
        Node<T>* newNode=new Node<T> (newItem);
        if (root==nullptr)  
          {
             root = newNode;
             __ret__9 = 1;
          }
        if (__ret__9!=1)  
          {
             Node<T>* newNodeParent=nullptr;
             Node<T>* current=root;
             while (current!=nullptr)  
               {
                  newNodeParent = current;
                  if (newNode->value<current->value)  
                    {
                       current = current->left;
                    }
                  else  
                    {
                       current = current->right;
                    }
               }
             newNode->parent = newNodeParent;
             if (newNode->value<newNodeParent->value)  
               {
                  newNodeParent->left = newNode;
               }
             else  
               {
                  newNodeParent->right = newNode;
               }
             idx_++;
          }
     }
    }
   return ;
}
template <typename T>
void BST<T>::remove(T& t) {
   int __ret__10=0;
   int __ret__2=-1;
   
   { 
     AcquireLock acq(lock1);
   
   __ret__2 = idx_<=0;
   if (__ret__2)  
     {
        __ret__10 = 1;
     }
   if (__ret__10!=1)  
     {
        Node<T>* nodeToRemove=root;
        while (nodeToRemove!=nullptr)  
          {
             if (t==nodeToRemove->value)  
               {
                  break;
               }
             else if (t<nodeToRemove->value)  
               {
                  nodeToRemove = nodeToRemove->left;
               }
             else  
               {
                  nodeToRemove = nodeToRemove->right;
               }
          }
        if (nodeToRemove==nullptr)  
          {
             __ret__10 = 1;
          }
        if (__ret__10!=1)  
          {
             if (nodeToRemove->left==nullptr)  
               {
                  Node<T>* u=nodeToRemove;
                  Node<T>* v=nodeToRemove->right;
                  if (u->parent==nullptr)  
                    {
                       root = v;
                    }
                  else if (u==u->parent->left)  
                    {
                       u->parent->left = v;
                    }
                  else  
                    {
                       u->parent->right = v;
                    }
                  if (v!=nullptr)  
                    {
                       v->parent = u->parent;
                    }
               }
             else if (nodeToRemove->right==nullptr)  
               {
                  Node<T>* u=nodeToRemove;
                  Node<T>* v=nodeToRemove->left;
                  if (u->parent==nullptr)  
                    {
                       root = v;
                    }
                  else if (u==u->parent->left)  
                    {
                       u->parent->left = v;
                    }
                  else  
                    {
                       u->parent->right = v;
                    }
                  if (v!=nullptr)  
                    {
                       v->parent = u->parent;
                    }
               }
             else  
               {
                  Node<T>* successor=(Node<T>*)(-1);
                  {
                     Node<T>* current=root;
                     while (current->left!=nullptr)  
                       {
                          current = current->left;
                       }
                     successor = current;
                  }
                  if (successor->parent!=nodeToRemove)  
                    {
                       {
                          Node<T>* u=successor;
                          Node<T>* v=successor->right;
                          if (u->parent==nullptr)  
                            {
                               root = v;
                            }
                          else if (u==u->parent->left)  
                            {
                               u->parent->left = v;
                            }
                          else  
                            {
                               u->parent->right = v;
                            }
                          if (v!=nullptr)  
                            {
                               v->parent = u->parent;
                            }
                       }
                       successor->right = nodeToRemove->right;
                       successor->right->parent = successor;
                    }
                  {
                     Node<T>* u=nodeToRemove;
                     Node<T>* v=successor;
                     if (u->parent==nullptr)  
                       {
                          root = v;
                       }
                     else if (u==u->parent->left)  
                       {
                          u->parent->left = v;
                       }
                     else  
                       {
                          u->parent->right = v;
                       }
                     if (v!=nullptr)  
                       {
                          v->parent = u->parent;
                       }
                  }
                  successor->left = nodeToRemove->left;
                  successor->left->parent = successor;
               }
             idx_--;
          }
     }
    }
   return ;
}
template <typename T>
void BST<T>::transplant(Node<T>* u,Node<T>* v) {
   if (u->parent==nullptr)  
     {
        root = v;
     }
   else if (u==u->parent->left)  
     {
        u->parent->left = v;
     }
   else  
     {
        u->parent->right = v;
     }
   if (v!=nullptr)  
     {
        v->parent = u->parent;
     }
}
template <typename T>
bool BST<T>::contains(T& v) {
   int __ret__11=-1;
   T& _b50_value=v;
   Node<T>* __ret__4=(Node<T>*)(-1);
   if (__ret__11!=true)  
     {
        __ret__11 = false;
     }
   Node<T>* _b50_rootNode=(Node<T>*)(-1);
   Node<T>* current=(Node<T>*)(-1);
   { 
     AcquireLock acq(lock1);
   
   _b50_rootNode = root;
   current = _b50_rootNode;
   if (current==nullptr||current->value==_b50_value)  
     {
        __ret__4 = current;
     }
   else if (_b50_value<current->value)  
     {
        __ret__4 = search(current->left,_b50_value);
     }
   else  
     {
        __ret__4 = search(current->right,_b50_value);
     }
   if (__ret__4!=nullptr)  
     {
        __ret__11 = true;
     }
    }
   return __ret__11;
}
template <typename T>
Node<T>* BST<T>::search(Node<T>* rootNode,T& value) {
   Node<T>* current=rootNode;
   if (current==nullptr||current->value==value)  
     {
        return current;
     }
   else if (value<current->value)  
     {
        return search(current->left,value);
     }
   else  
     {
        return search(current->right,value);
     }
}
template <typename T>
Node<T>* BST<T>::findMin() {
   Node<T>* current=root;
   while (current->left!=nullptr)  
     {
        current = current->left;
     }
   return current;
}
template <typename T>
bool BST<T>::isEmpty() {
   
   { 
     AcquireLock acq(lock1);
   
   return idx_<=0;
    }
}
