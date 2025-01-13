#ifndef _BD_HASH_H_
#define _BD_HASH_H_

#include <stdint.h>
#include <stdlib.h>

#define BD_HASH_CAPACITY 40

/* 
 * to add an element, we pass a (key, value) pair
 * we hash(key) -> hashed key, and then put value in
 * the value table at index hashed key
 * we also store the original key in the key table
 */
typedef struct bd_hash {
  uint32_t key_arr[BD_HAS_CAPACITY];
  
} bd_hash;


#endif

