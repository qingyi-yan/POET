#include "containerAPI.h"
#include "SinglyLinkedList.h"
#include <iostream>

SinglyLinkedListWrap<int>  *container=0;

void p_init(int size, int nThreads) 
{
  container = new SinglyLinkedListWrap<int>();

  for (int i = 0; i < size; i++) {
    container->AppendLast(i+1);
  }

}
void p_destroy() 
{
  delete container;
  container = 0;
}
void p_print() 
{
/*
  int res = 0;
  for (SinglyLinkedListWrap<int>::Iterator p = container->GetIterator();
       !p.ReachEnd(); p.Advance()) {
     res = res + *p;
  }
  std::cout << "result:" << res << "\n";   
*/
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
  container->AppendLast(e2);
}

void* p_pop()
{
  container->PopFirst();
}

int p_getSize()
{
  return container->size();
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
