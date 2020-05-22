
#assert(argc==5);
#MAX_VAL = atoi(argv[1]);
#NUM_OF_THREADS = atoi(argv[3]);
#DATA_SIZE_PER_THREAD = atoi(argv[2])/NUM_OF_THREADS;
#MAX_LOOP = atoi(argv[4]);

max_val=3000
data_size_per_thread=2560000
max_loop=128

for n_threads in 1 2 4 8 16 32 64 128 256
do
    echo $n_threads
    for((i=1;i<=1;i++)) ; do
    #./NONBLOCKING_RINGBUFFER_timer.o $max_val $data_size_per_thread $n_threads $max_loop #>> NONBLOCKING_RINGBUFFER.txt.$n_threads
    #./NONBLOCKING_STACK_timer.o $max_val $data_size_per_thread $n_threads $max_loop #>> NONBLOCKING_STACK.txt.$n_threads
    #./NONBLOCKING_SLIST_timer.o $max_val $data_size_per_thread $n_threads $max_loop #>> NONBLOCKING_SLIST.txt.${n_threads}
    #./NONBLOCKING_DLIST_timer.o $max_val $data_size_per_thread $n_threads $max_loop #>> NONBLOCKING_DLIST.txt.$n_threads
    ./NONBLOCKING_DEQUE_timer.o $max_val $data_size_per_thread $n_threads $max_loop #>> NONBLOCKING_DEQUE.txt.$n_threads
    done
done

