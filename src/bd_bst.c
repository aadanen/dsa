#include <bd_btree.h>
#include <stdlib.h>
#include <stdio.h>

bd_btree_node* bd_btree_node_new(int val) {
  bd_btree_node* n = (bd_btree_node*)malloc(sizeof(bd_btree_node));
  n->val = val;
  n->left = NULL;
  n->right = NULL;
  return n;
}

void bd_btree_preorder(bd_btree_node* root) {
  if (root == NULL) {
    return;
  }
  printf("%d ", root->val);
  bd_btree_preorder(root->left);
  bd_btree_preorder(root->right);
}
void bd_btree_inorder(bd_btree_node* root) {
  if (root == NULL) {
    return;
  }
  bd_btree_inorder(root->left);
  printf("%d ", root->val);
  bd_btree_inorder(root->right);

}
void bd_btree_postorder(bd_btree_node* root) {
  if (root == NULL) {
    return;
  }
  bd_btree_postorder(root->left);
  bd_btree_postorder(root->right);
  printf("%d ", root->val);
}

void bd_btree_levelorder(bd_btree_node* root) {
  printf("%d ", root->val);
}

int bd_bst_insert(bd_btree_node* root, bd_btree_node* node) {
  if (node->val == root->val) {
    // no duplicates allowed
    return 1;
  }
  int ret = 0;
  if (node->val > root->val) {
    if (root->right == NULL) {
      root->right = node;
    } else {
      ret = bd_bst_insert(root->right, node);
    }
  } else {
    if (root->left == NULL) {
      root->left = node;
    } else {
      ret = bd_bst_insert(root->left, node);
    }
  }
  return ret;

}

/* Minimal Tree: Given a sorted (increasing order) array with unique integer 
 * elements, write an algorithm to create a binary search tree with minimal 
 * height.
 *
 * idea: an inorder traversal of a bst provides a sorted array
 * idea: root node will be the median item. root->left would be the median
 * of the left half, root->right would be the median of the right half
 * 
*/
bd_btree_node* bd_min_btree_from_sorted(int arr[], int size) {
  if (size == 0) {
    return NULL;
  }  

  bd_btree_node* node = bd_btree_node_new(arr[size/2]);
  if (size == 1) {
    return node;
  }

  node->left = bd_min_btree_from_sorted(arr, size/2);
  node->right = bd_min_btree_from_sorted(&(arr[size/2 + 1]), size - size/2 - 1);
  return node;
}


