#include <string>
#include "containerAPI.h"
#include "bst-seq.h"
#include <iostream>

BST<int>  *container=0;

void p_init(int size, int nThreads) 
{
  container = new BST<int>();

  for (int i = 0; i < size; i++) {
    container->insert(i+1);
  }
}
void p_destroy() 
{
  delete container;
  container = 0;
}
void p_print() 
{
}
void p_attachThread()
{
}

void p_dettachThread()
{
}

void p_push(void* e1)
{
  int e2 = (long) e1;
  container->insert(e2);
}

void* p_pop()
{
  int res;
  container->remove(res);
  return (void*)res;
}

int p_getSize()
{
  return 0;
}

bool p_insertAt(int pos,void* e)
{
 return false; 
}
void p_eraseAt(int pos,void* e)
{
 return;
}
void* p_readAt(int)
{
}

bool p_casAt(int pos,void* e1,void* e2)
{
}
