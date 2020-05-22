#include "mdlist.h"

MDList* hashmap = 0;

void new_map() {
    hashmap = new MDList();
}

bool insert_entry(int i)
{
    hashmap->Insert(i);
}

bool erase_entry(int i)
{
   return hashmap->Delete(i);
}
bool is_empty() {
    return true;
}
