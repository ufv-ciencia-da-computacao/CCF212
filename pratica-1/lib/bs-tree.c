#include "bs-tree.h"

struct node_t {
  Item data;
  struct node_t *left;
  struct node_t *right;
};

static void __bst_pre_order(Tree *node, void (*to_string)(Item)) {  
  if ((*node) == NULL) return;
  Item key = ((*node)->data);
  (*to_string)(key);
  __bst_pre_order(&((*node)->left), to_string);
  __bst_pre_order(&((*node)->right), to_string);
}

static void __bst_post_order(Tree *node, void (*to_string)(Item)) {
  if ((*node) == NULL) return;
  
  Item key = ((*node)->data);
  __bst_post_order(&((*node)->left), to_string);
  __bst_post_order(&((*node)->right), to_string);
  (*to_string)(key);
}

static void __bst_in_order(Tree *node, void (*to_string)(Item)) {
  if ((*node) == NULL) return;
  
  Item key = ((*node)->data);
  __bst_in_order(&((*node)->left), to_string);
  (*to_string)(key);
  __bst_in_order(&((*node)->right), to_string);
}

Item bst_get_item(Tree *tree) {
  return (*tree)->data;
}

Tree bst_get_node_left(Tree *tree) {
  return ((*tree)->left);
}

Tree bst_get_node_right(Tree *tree) {
  return ((*tree)->right);
}

int node_init(Tree *node, Item data) {
  (*node) = (Tree) malloc(sizeof(struct node_t));
  (*node)->data = data;
  (*node)->left = NULL;
  (*node)->right = NULL;
  return 0;
}

int bst_init(Tree *tree) {
  *tree = NULL;
  return 0;
}

int bst_insert(Tree *node, Item data, int (*compare_data)(Item, Item)) {
  if ((*node) == NULL) {
    node_init(node, data);
    return 0;
  } 
 
  int comparator = (*compare_data)(data, (((*node)->data)));
  if(comparator > 0)  { // greater than father node, node_right
    bst_insert(&((*node)->right), data, compare_data);
  } else if (comparator < 0) { // lower than father node, node_left
    bst_insert(&((*node)->left), data, compare_data);
  }

  return 0;
}

int bst_print(Tree *tree, void (*to_string)(Item), Order_print_t order_print) {
  switch (order_print) {
    case pre_order:
      __bst_pre_order((tree), to_string);
      break;
    case post_order:
      __bst_post_order((tree), to_string);
      break;
    case in_order:
      __bst_in_order((tree), to_string);
      break;
    default:
      return -1;
  }
  return 0;
}
