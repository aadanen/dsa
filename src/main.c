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
  /*
  for (int i = 63; i > 0; i--) {
    bd_array_push(&arr, (i + 1) * (i + 1));
  }
  */
  int32_t err = bd_array_gen_random(&arr, 37, 0, 1);
  printf("%d\n", err);

  bd_array_print(&arr);
  bd_array_msort(&arr, BD_ASCENDING);
  bd_array_print(&arr);


  bd_array_free(&arr);
  return 0;
}

