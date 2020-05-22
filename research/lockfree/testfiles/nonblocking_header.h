
// #define ENABLE_SLEEP_TUNING 1
// #define ENABLE_MEM_REUSE    1
// #define ENABLE_REVALIDATION 1
// #define ENABLE_MULTISNAPSHOT 1

#define GC_MAX_THREADS  1000
#define CONFLICT_ARRAY_SIZE  10000000
#define GC_BLOCK_NUM        1000
#define GC_BLOCK_SIZE       (800000/PRODUCER_NUM)
#define LOG_NUM             1
#define READ_NUM            20

#ifdef ENABLE_MULTISNAPSHOT
#define NUM_OF_SNAPSHOTS    16
thread_local int snapshot_idx = -1;
#endif

#ifdef ENABLE_SLEEP_TUNING
#define SLEEP_NANOSEC   80000
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

