#include <bd_array.h>
#include <stdio.h>

int main(void) {
  printf("bandit\n");
/*
  bd_array* arr = bd_array_init();

  printf("%i\n", arr->size);
  printf("%i\n", arr->cap);
*/
  bd_array arr = bd_array_init(10);
  bd_array_print(&arr);
  for (int i = 0; i < 64; i++) {
    bd_array_push(&arr, (i + 1) * (i + 1));
  }

  bd_array_print(&arr);
  printf("Index of 16: %d\n", bd_array_bsearch(&arr, 16));
  printf("Index of 17: %d\n", bd_array_bsearch(&arr, 17));


  bd_array_free(&arr);
  return 0;
}

