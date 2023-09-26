#include <stdlib.h>

#include "memory.h"

// uses realloc() to resize the block of memory pointed to by pointer to newSize
void* reallocate(void* pointer, size_t oldSize, size_t newSize) {
  if (newSize == 0) {
    free(pointer);
    return NULL;
  }

  void* result = realloc(pointer, newSize);
  if (result == NULL) exit(1);
  return result;
}
