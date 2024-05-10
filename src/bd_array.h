#ifndef _bd_array_h_
#define _bd_array_h_

#include <stdint.h>
#include <stdlib.h>

typedef struct bd_array{
  int* items;
  int32_t size;
  int32_t cap;
} bd_array;

bd_array bd_array_init();
int32_t bd_array_free(bd_array arr);
int32_t bd_array_push(bd_array arr, int32_t n);
// int bdpush(bd_array* arr, int32_t i);


#endif
