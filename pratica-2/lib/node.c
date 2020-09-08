#include "node.h"

int node_init(Node *node, Item *data) {
  (*node) = (Node) malloc(sizeof(struct node_t));
  (*node)->data = *data;
  (*node)->left = NULL;
  (*node)->right = NULL;
  return 0;
}

Item node_get_item(Node node) {
  return node->data;
}

Node node_get_right(Node node) {
  return node->right;
}

Node node_get_left(Node node) {
  return node->left;
}
