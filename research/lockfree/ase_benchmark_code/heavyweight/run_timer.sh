
#assert(argc==8);
#MAX_VAL = atoi(argv[1]);
#NUM_OF_THREADS = atoi(argv[3]);
#DATA_SIZE_PER_THREAD = atoi(argv[2])/NUM_OF_THREADS;
#MAX_LOOP = atoi(argv[4]);
#FIND_THRESHOLD = atoi(argv[5]);
#INSERT_THRESHOLD = atoi(argv[6]);
#N_SNAPSHOT = atoi(argv[7]);

max_val=6000000
input_size=2560000
max_loop=128

# test generated lock-free code

echo "Write Only"
for n_threads in 1 2 4 8 16 32 64 128 256
do
    for ((i=1;i<=1;i++)) ; do
        #./NONBLOCKING_HASHSET_timer.o $max_val $input_size $n_threads $max_loop 0 50 0 #>> NONBLOCKING_HASHSET.txt.${n_threads}.write_only
        #./NONBLOCKING_HASHSET_ARRAYBASED_timer.o $max_val $input_size $n_threads $max_loop 0 50 $max_val #>> NONBLOCKING_HASHSET_ARRAYBASED.txt.${n_threads}.write_only
        #./NONBLOCKING_BST_timer.o $max_val $input_size $n_threads $max_loop 0 50 0 #>> NONBLOCKING_BST.txt.${n_threads}.write_only
        #./NONBLOCKING_BST_ARRAYBASED_timer.o $max_val $input_size $n_threads $max_loop 0 50 16 #>> NONBLOCKING_BST_ARRAYBASED.txt.${n_threads}.write_only
        ./NONBLOCKING_MDLIST_timer.o $max_val $input_size $n_threads $max_loop 0 50 0 #>> NONBLOCKING_MDLIST.txt.${n_threads}.write_only
        #./NONBLOCKING_MDLIST_ARRAYBASED_timer.o $max_val $input_size $n_threads $max_loop 0 50 16 #>> NONBLOCKING_MDLIST_ARRAYBASED.txt.${n_threads}.write_only
    done
done


echo "Mostly Read"
for n_threads in 1 2 4 8 16 32 64 128 256
do
    for ((i=1;i<=1;i++)) ; do
        #./NONBLOCKING_HASHSET_timer.o $max_val $input_size $n_threads $max_loop 90 95 0 #>> NONBLOCKING_HASHSET.txt.${n_threads}.mostly_read
        #./NONBLOCKING_HASHSET_ARRAYBASED_timer.o $max_val $input_size $n_threads $max_loop 90 95 $max_val #>> NONBLOCKING_HASHSET_ARRAYBASED.txt.${n_threads}.mostly_read
        #./NONBLOCKING_BST_timer.o $max_val $input_size $n_threads $max_loop 90 95 0 #>> NONBLOCKING_BST.txt.${n_threads}.mostly_read
        #./NONBLOCKING_BST_ARRAYBASED_timer.o $max_val $input_size $n_threads $max_loop 90 95 16 #>> NONBLOCKING_BST_ARRAYBASED.txt.${n_threads}.mostly_read
        ./NONBLOCKING_MDLIST_timer.o $max_val $input_size $n_threads $max_loop 90 95 0 #>> NONBLOCKING_MDLIST.txt.${n_threads}.mostly_read
        #./NONBLOCKING_MDLIST_ARRAYBASED_timer.o $max_val $input_size $n_threads $max_loop 90 95 16 #>> NONBLOCKING_MDLIST_ARRAYBASED.txt.${n_threads}.mostly_read
    done
done

