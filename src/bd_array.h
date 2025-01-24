#ifndef _bd_array_h_
#define _bd_array_h_

#include <stdint.h>
#include <stdlib.h>

#define BD_ASCENDING 1
#define BD_DESCENDING 0
typedef struct bd_array{
  int* items;
  int32_t size;
  int32_t cap;
} bd_array;

bd_array bd_array_init(int32_t initial_capacity);
int32_t bd_array_free(bd_array* arr);
int32_t bd_array_push(bd_array* arr, int32_t n);
int32_t bd_array_write(bd_array* arr, int32_t index, int32_t n);
int32_t bd_array_expand(bd_array* arr);
int32_t bd_array_expandto(bd_array* arr, int32_t n);
int32_t bd_array_gen_random(bd_array* arr, int32_t n, int32_t lb, int32_t ub);
void bd_array_print(bd_array* arr);
int32_t bd_array_bsearch(bd_array* arr, int32_t target);
int32_t bd_array_msort(bd_array* arr, uint8_t ascending);

void bd_array_msort_split(int32_t* a, int32_t* b,
    int32_t start, int32_t end, uint8_t ascending);
int32_t* bd_array_msort_merge(int32_t* a, int32_t* b, 
    int32_t start, int32_t middle, int32_t end, uint8_t ascending);
// int bdpush(bd_array* arr, int32_t i);


#endif
