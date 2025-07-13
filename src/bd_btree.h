#ifndef BD_BTREE_H
#define BD_BTREE_H
#include <stdint.h>
typedef struct bd_btree_node {
  int32_t val;
  struct bd_btree_node* left;
  struct bd_btree_node* right;
} bd_btree_node;

void bd_btree_printNode


#endif /*BD_BTREE_H*/
