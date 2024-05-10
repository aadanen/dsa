#include <bd_array.h>
#include <stdio.h>

int main(void) {
  printf("bandit\n");
/*
  bd_array* arr = bd_array_init();

  printf("%i\n", arr->size);
  printf("%i\n", arr->cap);
*/
  bd_array arr = bd_array_init();
  printf("%i\n", arr.size);
  printf("%i\n", arr.cap);

  bd_array_push(arr, 1);
  printf("%i\n", arr.items[0]);

  bd_array_free(arr);
  //free(arr);
  return 0;
}

