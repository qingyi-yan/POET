#include <stdlib.h>

int foo() {
 int* a = (int*) malloc (sizeof(int)*10);
 *a = 0;
 for (int i = 0; i < 10; ++i) {
   if (a[i] < 0) {
      return 1;
   }
 }
 free(a);
 return 0;
}

int main() {
return foo();
}
