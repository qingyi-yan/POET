#include <limits>
//#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <unistd.h>
#include <assert.h>
#include "hash_map.h"

hash_map<int, int> *hashmap = 0;

void new_map() {
    hashmap = new hash_map<int, int>(1024);
}

bool insert_entry(int i)
{
    std::pair<int,int> v = std::make_pair(i, 0);
    return hashmap->insert(v);
}

bool erase_entry(int i)
{
   return hashmap->erase(i);
}
bool is_empty() {
    return hashmap->empty();
}
