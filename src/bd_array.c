#include <bd_array.h>
#include <stdio.h>
#include <strings.h>
#include <errno.h>

bd_array bd_array_init(int32_t initial_capacity) {
  bd_array arr;// = (bd_array*)malloc(sizeof(bd_array));
  arr.items = (int32_t*)calloc(initial_capacity, sizeof(int32_t));
  arr.size = 0;
  arr.cap = initial_capacity;
  return arr;
}

int32_t bd_array_free(bd_array* arr) {
  free(arr->items);
  return 0;
}

int bd_array_expand(bd_array* arr) {
  void* mem = realloc((void*)arr->items, arr->cap * 2 * sizeof(int32_t));
  if (mem != NULL && errno == 0) {
    arr->items = mem;
    arr->cap = arr->cap * 2;
    bzero(((void *)arr->items + arr->size*4), arr->cap - arr->size);
  }
  else {
    return -1;
  }
  return 0;
}

int32_t bd_array_push(bd_array* arr, int32_t n) {
  if (arr->size >= arr->cap - 1) {
    int res = bd_array_expand(arr);
    if (res != 0) {
      return res;
    }
  }
  arr->items[arr->size] = n;
  arr->size++;
  return 0;
}

int32_t bd_array_write(bd_array* arr, int32_t index, int32_t n) {
  while (index >= arr->cap) {
    bd_array_expand(arr);
  }
  arr->items[index] = n;
  if (index >= arr->size) {
    arr->size = index+1;
  }
  return 0;
}

int32_t bd_array_read(bd_array* arr, int32_t index) {
  return arr->items[index];
}

void bd_array_print(bd_array* arr) {
  printf("Items:\n[");
  for (int i = 0; i < arr->size - 1; i++) {
    printf("%i,\t", arr->items[i]);
    if (i%10 == 9) {
      printf("\n");
    }
  }
  if (arr->size != 0) {
    printf("%i", arr->items[arr->size - 1]);
  }
  printf("]\n");
  printf("Size: %i\n", arr->size);
  printf("Capacity: %i\n", arr->cap);
}


int32_t bd_array_bsearch(bd_array* arr, int32_t target) {
  int32_t left = 0;
  int32_t right = arr->size - 1;
  int32_t mid;
  while (left < right) {
    mid = (right + left)/2;
    int32_t v = bd_array_read(arr, mid);
    if (v == target) {
      return mid;
    } else if (v > target) {
      right = mid;
    } else {
      left = mid+1;
    }
  }
  return -1;
}
