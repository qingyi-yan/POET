#include "containerAPI.h"
#include "DoublyLinkedList.h"
#include <iostream>

DoublyLinkedListWrap<int>  *container=0;

void p_init(int size, int nThreads) 
{
  container = new DoublyLinkedListWrap<int>();

  for (int i = 0; i < size; i++) {
    container->AppendLast(i+1);
//std::cerr << "after initiating: " << ":" << container->First()->GetEntry() << "\n";
  }
}
void p_destroy() 
{
std::cout << "in destroy\n";
//  delete container;
  container = 0;
std::cout << "done destroy\n";
}
void p_print() 
{
  int res = 0;
  for (DoublyLinkedEntryWrap<int> *p = container->First();
       p!=0; p = container->Next(p)) {
     res = res + p->GetEntry();
  }
  std::cout << "result:" << res << "\n";   
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
//std::cerr << "after pushing " << e2 << ":" << container->First()->GetEntry() << "\n";
}

void* p_pop()
{
  long e2 = (long) container->PopFirst();
  //std::cerr << "popping " << e2 << "\n";
  return (void*)e2;
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
  return 0;
}

bool p_casAt(int pos,void* e1,void* e2)
{
  return false;
}
