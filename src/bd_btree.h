#ifndef BD_BTREE_H
#define BD_BTREE_H
#include <stdlib.h>
typedef struct bd_btree_node {
  int val;
  struct bd_btree_node* left;
  struct bd_btree_node* right;
} bd_btree_node;

bd_btree_node* bd_btree_node_new(int val);
int bd_bst_insert(bd_btree_node* root, bd_btree_node* node);
void bd_btree_preorder(bd_btree_node* root);
void bd_btree_inorder(bd_btree_node* root);
void bd_btree_postorder(bd_btree_node* root);

#endif /*BD_BTREE_H*/
