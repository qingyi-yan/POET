
template <class U>
struct GC_Array_Allocator {
    unsigned array_num_per_block;
    unsigned array_size;
    U* allocate_start;
    U* allocate_ptr;
    unsigned block_idx;
    std::vector<U*> blocks;
    GC_Array_Allocator() {
        array_size = 0;
        array_num_per_block = 0;
        allocate_start = 0;
        allocate_ptr = 0;
        block_idx = 0;
    }

    U* allocate() {
        assert(array_size > 0);
        if ((allocate_start == 0) || (block_idx == array_num_per_block)) {
printf("hello 1 %d %d\n", array_size, array_num_per_block);
            allocate_start = new U [array_size*array_num_per_block];
printf("hello 2\n");
            std::memset((void*) allocate_start, 0, array_size*array_num_per_block*sizeof(U));
            allocate_ptr = allocate_start;
            block_idx = 0;
            blocks.push_back(allocate_start);
        }
        U* ret = allocate_ptr;
        block_idx ++;
        allocate_ptr += array_size;
        return ret;
    }
};

template <class U>
struct GC_Queue {
    std::vector<U*> block_list;
    U* curr_block;
    int block_idx;
    int block_size;

    U* free_list;

    GC_Queue() {
        block_size = GC_BLOCK_SIZE;
        curr_block = new U [block_size];
        block_idx = 0;
        block_list.push_back(curr_block);
        free_list = 0;
    }

    ~GC_Queue() {
        while (!block_list.empty()) {
            U* b = block_list.pop_back();
            delete[] b;
        }
    }

    inline void push(U* free_obj) {
        free_obj->gc_next = free_list;
        free_list = free_obj;
    }

    inline void push_list (U* head, U* tail) {
        if (head == 0) return;
        tail->gc_next = free_list;
        free_list = head;
    }

    inline U* front() {
        U* ret = 0;
        if (free_list == 0) {
            if (block_idx == block_size) {
                curr_block = new U [block_size];
                block_idx = 0;
                block_list.push_back(curr_block);
            }
            ret = &(curr_block[block_idx++]);
            push(ret);
        } else {
            ret = free_list;
        }
        return ret;
    }

    inline void pop() {
        free_list = free_list->gc_next;
    }

    inline U* pop_front() {
        U* ret = front();
        pop();
        return ret;
    }
};

#ifdef ENABLE_DATA_PARTITION
#define GC_STATIC_SETUP(_classtemplate, _classname)   \
_classtemplate GC_Queue<typename _classname::synobj_t>* _classname::GarbageCollector::synobj_queue[GC_MAX_THREADS]; \
_classtemplate GC_Queue<typename _classname::wrapper_t>* _classname::GarbageCollector::wrapper_queue[GC_MAX_THREADS]; \
_classtemplate GC_Queue<typename _classname::gc_node_t>* _classname::GarbageCollector::node_queue[GC_MAX_THREADS]; \
_classtemplate typename _classname::synobj_t* _classname::GarbageCollector::read_obj[GC_MAX_THREADS]; \
_classtemplate std::atomic<int> _classname::GarbageCollector::thread_count(0); \
_classtemplate unsigned _classname::ConflictArray::shift = 0; \
_classtemplate unsigned _classname::ConflictArray::mask = 0; \
_classtemplate GC_Array_Allocator<volatile int> _classname::ActivityArray::allocator; \
_classtemplate GC_Array_Allocator<volatile void*> _classname::ConflictArray::allocator; \
_classtemplate GC_Array_Allocator<typename _classname::GC_Retired_SynObj> _classname::RetiredSynObjArray::allocator;

#endif


