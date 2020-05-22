#include <limits>
//#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <unistd.h>
#include <assert.h>

void new_map();
bool insert_entry(int v);
bool erase_entry(int v);
bool is_empty();

#define RANDSEED    time(NULL)

#define ITEM_NUM 200

int main(int argc, char **argv) {
	int item_num=ITEM_NUM;

    int *item_buf = (int *)calloc(item_num, sizeof(int));
    int *unique_buf = (int *)calloc(1024, sizeof(int));
    int i, res;
    bool is_correct = true;
    for (i = 0; i < item_num; i++) {
        item_buf[i] = rand()%1024;
        unique_buf[item_buf[i]] = 1;
    }

    new_map();
    for (i = 0; i < item_num; i++) {
        insert_entry(item_buf[i]);
    }

    for (i = 0; i < 1024; i++) {
        if (unique_buf[i] <= 0)
            continue;
        res = erase_entry(i);
        if (res == 0) {
            printf("%d doesn't exist \n", i);
            is_correct = false;
        } else if (res > 1) {
            printf("%d not unique \n", i);
            is_correct = false;
        }
    }

    if (!is_empty()) {
        printf("hashmap not empty \n");
        is_correct = false;
    }

    if (is_correct)
        printf("identical output \n");
    else
        printf("incorrent output \n");
	return 0;

};
