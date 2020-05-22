#ifndef CONTAINER_API_H
#define CONTAINER_API_H

#include <atomic>
void p_init(int size, int nThreads);
void p_destroy();
void p_print();
void p_attachThread();
void p_dettachThread();
void p_push(void*);
void* p_pop();
int p_getSize();
bool p_insertAt(int,void*);
void p_eraseAt(int,void*);
void* p_readAt(int);
bool p_casAt(int,void*,void*);

#endif
