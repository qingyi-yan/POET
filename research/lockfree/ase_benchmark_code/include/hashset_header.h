
#include <vector>
#include <queue>
#include <cstring>

// #define ENABLE_SLEEP_TUNING

#define GC_MAX_THREADS  260
#define CONFLICT_ARRAY_SHIFT 14
#define GC_BLOCK_SIZE       (131072)
#define LOG_NUM             1
#define READ_NUM        5
#define NODE_NUM        1

#ifdef ENABLE_SLEEP_TUNING
#define SLEEP_NANOSEC   10000
struct timespec req = {
    .tv_sec = 0,
    .tv_nsec = SLEEP_NANOSEC
};
void inline nanosleep_invoke() {
    struct timespec rem;
    nanosleep(&req, &rem);
}
#else
void inline nanosleep_invoke() {;}
#endif

thread_local int local_gc_idx = -1;
#include <pthread.h>
#include <stdlib.h>
#include <utility>

#include "gc_util.h"



