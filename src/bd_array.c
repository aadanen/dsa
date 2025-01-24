#include <bd_array.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <stdlib.h>

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

int32_t bd_array_expand(bd_array* arr) {
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

int32_t bd_array_expandto(bd_array* arr, int32_t n) {
  void* mem = realloc((void*)arr->items, n * sizeof(int32_t));
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

int32_t bd_array_gen_random(bd_array* arr, int32_t n, int32_t lb, int32_t ub) {
  if (arr->cap < n) {
    if (bd_array_expandto(arr, n) < 0) {
      return -1;
    }
  }
  arr->size = 0;
  srand(time(NULL));
  if (ub > lb) {
    for (int32_t i = 0; i < n; i++) {
      bd_array_push(arr, (rand() % (ub - lb)) + lb);
    }
  } else {
    for (int32_t i = 0; i < n; i++) {
      bd_array_push(arr, lb);
    }
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

int32_t bd_array_msort(bd_array* arr, uint8_t ascending) {
  int32_t* A = arr->items;
  int n = arr->size;
  int32_t* B = (int32_t*)calloc(n, sizeof(int32_t));
  memcpy(B, A, n*sizeof(int32_t));
  bd_array_msort_split(B, A, 0, n, ascending);

  return 0; 
}

void bd_array_msort_split(int32_t* A, int32_t* B, 
    int32_t start, int32_t end, uint8_t ascending) {
  if (end - start <= 1) {
    return;
  }
  int32_t middle = (start+end)/2;
  bd_array_msort_split(B, A, start, middle, ascending);
  bd_array_msort_split(B, A, middle, end, ascending);
  bd_array_msort_merge(A, B, start, middle, end, ascending);
}

int32_t* bd_array_msort_merge(int32_t* A, int32_t* B, 
    int32_t start, int32_t middle, int32_t end, uint8_t ascending) {
  int32_t i = start;
  int32_t j = middle;

  for (int32_t k = start; k < end; k++) {
    uint8_t b;
    if (ascending) {
      b = A[i] <= A[j];
    } else {
      b = A[i] >= A[j];
    }
    
    if (i < middle && (j >= end || b)) {
      B[k] = A[i];
      i = i + 1;
    } else {
      B[k] = A[j];
      j = j + 1;
    }
  }
  return 0;
}
