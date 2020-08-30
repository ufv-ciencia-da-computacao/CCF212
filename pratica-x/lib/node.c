#include "node.h"

int node_init(Node *node, Item *data) {
  (*node) = (Node) malloc(sizeof(struct node_t));
  (*node)->data = *data;
  (*node)->left = NULL;
  (*node)->right = NULL;
  return 0;
}
