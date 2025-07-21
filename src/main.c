#include <bd_array.h>
#include <bd_btree.h>
#include <bd_ll.h>
#include <stdio.h>

#define NUM_NODES 16
int main(void) {
  int arr[NUM_NODES] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
  bd_btree_node* root = bd_min_btree_from_sorted(arr, NUM_NODES);

  bd_ll* ll = bd_ll_new();
  // 1
  bd_ll_push_back(ll, root->left->left->left);
  // 3
  bd_ll_push_back(ll, root->left->left->right);
  // 2
  bd_ll_push_back(ll, root->left->left);

  bd_btree_node* c;
  c = bd_ll_pop_front(ll);
  printf("%d\n", c->val);
  c = bd_ll_pop_front(ll);
  printf("%d\n", c->val);
  c = bd_ll_pop_front(ll);
  printf("%d\n", c->val);

  

  return 0;
}

