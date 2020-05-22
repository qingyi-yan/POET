
#include <vector>
#include <queue>
#include <cstring>

// #define ENABLE_SLEEP_TUNING
// #define ENABLE_GC_REUSE

#define MAX_N_SNAPSHOT  20

#define GC_MAX_THREADS  260
#define CONFLICT_ARRAY_SHIFT  14
#define GC_BLOCK_SIZE       (131072)
#define LOG_NUM             8
#define READ_NUM            80
#define NODE_NUM            1

#ifdef ENABLE_SLEEP_TUNING
#define SLEEP_NANOSEC   1000
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


thread_local int local_gc_idx = -1;
thread_local int snapshot_idx = -1;

#include "gc_util.h"


