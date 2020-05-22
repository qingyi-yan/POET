#include "containerAPI.h"
#include "ringbuffer_seq.h"
#include <iostream>

RingBuffer<int>  *container=0;

void p_init(int size, int nThreads) 
{
  container = new RingBuffer<int>(size);

  for (int i = 0; i < size; i++) {
    container->push(i+1);
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
  container->push(e2);
}

void* p_pop()
{
  int res;
  container->pop(res);
  return (void*)res;
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
