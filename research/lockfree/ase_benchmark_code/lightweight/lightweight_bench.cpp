
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h>
#include <sched.h>
#include <unistd.h>
#include <ctime>
#include <cmath>
#include <limits.h>
#include <iostream>
#include <fstream>
#include <atomic>
#include <assert.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>

int MAX_VAL;        // maximum element value
int NUM_OF_THREADS;
int DATA_SIZE_PER_THREAD;
int MAX_LOOP;

#ifdef CHECK_CORRECTNESS
std::atomic<int>* elem_counter;
#endif

#include "nonblocking_ringbuffer.h"
#include "nonblocking_stack.h"
#include "nonblocking_slist.h"
#include "nonblocking_dlist.h"
#include "nonblocking_deque.h"

typedef int elem_type, *elem_type_t;
typedef lightweight_struct<elem_type> taskq_s, *taskq_t;

typedef struct thread_args {
    elem_type_t send_buf;
    taskq_t     taskq;
    int*        percent_buf;
    unsigned*   loop_buf;

    int         idx;
    int         elem_num;
} thread_args_s, *thread_args_t;

pthread_barrier_t init_barrier;

int bind_to_core(int core_id)
{
    int core_num = sysconf(_SC_NPROCESSORS_ONLN);
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(core_id%core_num, &cpuset);
    pthread_t curr = pthread_self();
    return pthread_setaffinity_np(curr, sizeof(cpu_set_t), &cpuset);
}

#define RAND_SEED           time(NULL)
#define GEN_RAND_PERCENT    (rand()%100+1)
#define GEN_RAND_ELEMENT    (rand()%MAX_VAL)
#define GEN_RAND_LOOP       (rand()%MAX_LOOP)

inline void idle_loop (unsigned rand_loop) {
    volatile unsigned int i = 0;
    while (i < rand_loop) i++;
}

void *thread_exec (void *t_args_p) {
    thread_args_t t_args = (thread_args_t) t_args_p;
    bind_to_core(t_args->idx);

    int elem_num = t_args->elem_num;
    int *send_buf = t_args->send_buf;
    int *percent_buf = t_args->percent_buf;
    unsigned *loop_buf = t_args->loop_buf;
    taskq_t taskq = t_args->taskq;
    for (int i = 0; i < 25600/NUM_OF_THREADS; i++) {
        taskq->push(send_buf[i], percent_buf[i]);
    }
    pthread_barrier_wait(&init_barrier);
    pthread_barrier_wait(&init_barrier);
    for (int i = 0; i < elem_num; i++) {
        int percent = percent_buf[i];
        taskq->push(send_buf[i], percent);
        idle_loop(loop_buf[i]);
        i++;
        percent = percent_buf[i];
        taskq->pop(percent);
        idle_loop(loop_buf[i]);
    }
    pthread_barrier_wait(&init_barrier);
}

int main(int argc, char *argv[])
{
    assert(argc==5);
    MAX_VAL = atoi(argv[1]);
    NUM_OF_THREADS = atoi(argv[3]);
    DATA_SIZE_PER_THREAD = atoi(argv[2])/NUM_OF_THREADS;
    MAX_LOOP = atoi(argv[4]);

    int total_data_size = DATA_SIZE_PER_THREAD*NUM_OF_THREADS;

    thread_args_t t_args = new thread_args_s [NUM_OF_THREADS];
    memset (t_args, 0, NUM_OF_THREADS*sizeof(thread_args_s));

    // taskq_t taskq = new taskq_s(2*total_data_size);
    taskq_t taskq = new taskq_s(total_data_size);

    int i, j;

    elem_type_t send_buf = new elem_type [total_data_size];
    int* percent_buf = new int [total_data_size];
    unsigned* loop_buf = new unsigned [total_data_size];

    for (i = 0; i < NUM_OF_THREADS; i++) {
        t_args[i].idx = i;
        t_args[i].taskq = taskq;
        t_args[i].elem_num = DATA_SIZE_PER_THREAD;
        t_args[i].send_buf = send_buf + i*DATA_SIZE_PER_THREAD;
        t_args[i].percent_buf = percent_buf + i*DATA_SIZE_PER_THREAD;
        t_args[i].loop_buf = loop_buf + i*DATA_SIZE_PER_THREAD;
        for (j = 0; j < DATA_SIZE_PER_THREAD; j++) {
            t_args[i].send_buf[j] = GEN_RAND_ELEMENT; //%26;
            t_args[i].percent_buf[j] = GEN_RAND_PERCENT;
            t_args[i].loop_buf[j] = GEN_RAND_LOOP;
        }
    }

#ifdef CHECK_CORRECTNESS
    elem_counter = new std::atomic<int> [MAX_VAL];
    for (int i = 0; i < MAX_VAL; i++) {
        elem_counter[i] = 0;
    }
    printf("%d,%d, %d,%d\n", MAX_VAL, total_data_size, DATA_SIZE_PER_THREAD, NUM_OF_THREADS);
#endif

    pthread_t thread_tids[NUM_OF_THREADS];
    pthread_barrier_init(&init_barrier, NULL, NUM_OF_THREADS+1);

    for (i = 0; i < NUM_OF_THREADS; i++) {
        pthread_create(&thread_tids[i], NULL, thread_exec, &t_args[i]);
    }
    struct timespec start, end;
    double diff;

    pthread_barrier_wait(&init_barrier);
    clock_gettime(CLOCK_MONOTONIC, &start);
    pthread_barrier_wait(&init_barrier);
    pthread_barrier_wait(&init_barrier);
    clock_gettime(CLOCK_MONOTONIC, &end);

    diff = (end.tv_sec - start.tv_sec);
    diff += (end.tv_nsec - start.tv_nsec)/1000000000.0;

    printf("Elapsed time\t%.3f\n", diff);
    printf("Throughput\t%.3f\n", total_data_size/diff);

    for (i = 0; i < NUM_OF_THREADS; i++) {
        pthread_join(thread_tids[i], NULL);
    }
    delete taskq;
    return 0;
}











