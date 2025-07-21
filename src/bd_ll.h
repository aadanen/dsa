#ifndef BD_LL_H
#define BD_LL_H

#include <stdlib.h>
#include <bd_btree.h>
typedef struct bd_ll {
  int size;
  bd_btree_node* head;
  bd_btree_node* tail;
} bd_ll;

bd_ll* bd_ll_new() {
  bd_ll* ll = (bd_ll*)malloc(sizeof(bd_ll));
  ll->size= 0;
  ll->head = NULL;
  ll->tail = NULL;
  return ll;
}
void bd_ll_push_back(bd_ll* ll, bd_btree_node* node) {
  if (ll->tail == NULL || ll->head == NULL) {
    ll->head = node;
    ll->tail = node;
    return;
  }
  ll->tail->right = node;
  node->left = ll->tail;
  node->right = NULL;
  ll->tail = node;
  ll->size++;
}
void bd_ll_push_front(bd_ll* ll, bd_btree_node* node) {
  if (ll->tail == NULL || ll->head == NULL) {
    ll->head = node;
    ll->tail = node;
    return;
  }
  ll->head->left = node;
  node->right = ll->head;
  node->left = NULL;
  ll->head = node;
  ll->size++;
}
bd_btree_node* bd_ll_back(bd_ll* ll) {
  return ll->tail;
}
bd_btree_node* bd_ll_front(bd_ll* ll) {
  return ll->head;
}
bd_btree_node* bd_ll_pop_back(bd_ll* ll) {
  bd_btree_node* temp = ll->tail;
  if (temp == NULL) {
    return NULL;
  }
  ll->tail = temp->left;
  ll->tail->right = NULL;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}
bd_btree_node* bd_ll_pop_front(bd_ll* ll) {
  bd_btree_node* temp = ll->head;
  if (temp == NULL) {
    return NULL;
  }
  ll->head = temp->right;
  ll->head->left = NULL;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

#endif /* BD_LL_H */
