#if 0 

#include "list.hpp"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
size_t sum = 0;

void add(size_t _, size_t data) {
   sum += data; 
}

int main(int argc, char** argv) {

   list* items = nullptr;

   for (size_t index = 0; index < argc; index ++) {
       push(&items, atoi(argv[index]));
   }

   foreach(items,add);

   return sum;
}

#else

#include "vector.hpp"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
size_t sum = 0;

void add(size_t _, size_t data) {
   sum += data; 
}

int main(int argc, char** argv) {

   vector items = {nullptr, 0};

   for (size_t index = 0; index < argc; index ++) {
       push(&items, atoi(argv[index]));
   }

   foreach(&items,add);

   return sum;
}

#endif