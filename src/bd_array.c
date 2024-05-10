#include <bd_array.h>

bd_array bd_array_init() {
  bd_array arr;// = (bd_array*)malloc(sizeof(bd_array));
  arr.items = (int32_t*)malloc(sizeof(int32_t) * 10);
  arr.size = 0;
  arr.cap = 10;
  return arr;
}

int32_t bd_array_free(bd_array arr) {
  free(arr.items);
  return 0;
}

int32_t bd_array_push(bd_array arr, int32_t n) {
  if (arr.size >= arr.cap - 1) {
    // make it bigger
  }
  arr.items[arr.size] = n;
  arr.size++;
  return 0;
}
