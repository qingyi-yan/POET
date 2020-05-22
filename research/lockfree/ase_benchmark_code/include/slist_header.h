
#define ENABLE_SLEEP_TUNING
// #define ENABLE_GC_REUSE

#define GC_MAX_THREADS  260
#define CONFLICT_ARRAY_SHIFT  14
#define GC_BLOCK_SIZE       (131072)
#define LOG_NUM             1
#define NODE_NUM            1

#ifdef ENABLE_SLEEP_TUNING
#define SLEEP_NANOSEC   1000000
thread_local struct timespec req = {
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

#include <string>
#include <vector>

thread_local int local_gc_idx = -1;

#include "gc_util.h"



