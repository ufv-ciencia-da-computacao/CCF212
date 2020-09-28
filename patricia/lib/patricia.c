#include "patricia.h"

bit_digit bit(index_amp i, Item key) {
  if(i==0) return 0;
  else return ((key >> (D-i-1)) & 1);
}

int type_node(Patricia p) {
  return (p->type == external);
}

void pat_init(Patricia* patricia) {
  (*patricia) = (Patricia) malloc(sizeof(pat_node));

  (*patricia)->node.node_internal.index = 0;
  (*patricia)->node.node_internal.left = NULL;
  (*patricia)->node.node_internal.right = NULL;
}

void pat_node_init(Patricia* patricia, Item key, Item key_a, int i, int *h) {
  Patricia aux1, aux2;
  int b = 1;

  while (b && i <= D) {
    if (bit(i, key) == bit(i, key_a)) i++;
    else b = 0;
  }

  if (i > D) {
    *h=1;
    return;
  }

  *h=0;

  aux1 = (Patricia) malloc(sizeof(pat_node));
  aux2 = (Patricia) malloc(sizeof(pat_node));

  aux1->type = internal;
  aux1->node.node_internal.index = i;

  if(bit(i, key) == 0) aux1->node.node_internal.left = aux2;
  else aux1->node.node_internal.right = aux2;
  
  aux2->type = external;
  aux2->node.key = key;
  (*patricia) = aux1;
}

int pat_search(Patricia patricia, Item key) {
  if (type_node(patricia) == external) {
    if (key == patricia->node.key) return 1;
    else return 0;
  } 

  if (bit(patricia->node.node_internal.index, key) == 0) return pat_search(patricia->node.node_internal.left, key);
  else return pat_search(patricia->node.node_internal.right, key);
}

static void insert_pat(Patricia* patricia, Patricia *node2insert, int i, int *h, Item key) {
  if((*patricia) == NULL) {
    *h = 1;
    (*patricia) = (Patricia) malloc(sizeof(pat_node));
    (*patricia)->type = external;
    (*patricia)->node.key = key;
    return;
  } else if(type_node(*patricia) == external) {
    pat_node_init(node2insert, key, (*patricia)->node.key, i+1, h);
  } else {
    if((*patricia)->node.node_internal.index == i+1) i++;
    if(bit((*patricia)->node.node_internal.index, key) == 0) {
      insert_pat(&(*patricia)->node.node_internal.left, node2insert, i, h, key);
      if (*h) return;
      if((*patricia)->node.node_internal.index >= (*node2insert)->node.node_internal.index) return;
      *h=1;
      if (bit((*node2insert)->node.node_internal.index, key) == 0) 
        (*node2insert)->node.node_internal.right = (*patricia)->node.node_internal.left;
      else
        (*node2insert)->node.node_internal.left = (*patricia)->node.node_internal.left;
      (*patricia)->node.node_internal.left = (*node2insert);
      return;
    }

    insert_pat(&(*patricia)->node.node_internal.right, node2insert, i, h, key);
    if(*h) return;
    *h=1;
    if (bit((*node2insert)->node.node_internal.index, key) == 0) 
      (*node2insert)->node.node_internal.right = (*patricia)->node.node_internal.right;
    else
      (*node2insert)->node.node_internal.left = (*patricia)->node.node_internal.right;
    (*patricia)->node.node_internal.right = (*node2insert);
  }
}

void pat_insert(Patricia* patricia, Item key) {
  int h = 0;
  Patricia node2insert;
  insert_pat(patricia, &node2insert, 0, &h, key);
}