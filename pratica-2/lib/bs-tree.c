#include "bs-tree.h"

static void __bst_pre_order(Node node, void (*to_string)(Item)) {  
  if (node == NULL) return;
  
  Item key = node->data;
  (*to_string)(key);
  __bst_pre_order(node->left, to_string);
  __bst_pre_order(node->right, to_string);
}

static void __bst_post_order(Node node, void (*to_string)(Item)) {
  if (node == NULL) return;
  
  Item key = node->data;
  __bst_post_order(node->left, to_string);
  __bst_post_order(node->right, to_string);
  (*to_string)(key);
}

static void __bst_in_order(Node node, void (*to_string)(Item)) {
  if (node == NULL) return;
  
  Item key = node->data;
  __bst_in_order(node->left, to_string);
  (*to_string)(key);
  __bst_in_order(node->right, to_string);
}

static void __bst_decreasing_order(Node node, void (*to_string)(Item)) {
  if (node == NULL) return;
  
  Item key = node->data; 
  __bst_decreasing_order(node->right, to_string);
  (*to_string)(key);
  __bst_decreasing_order(node->left, to_string);
}

int bst_init(bs_tree_t *tree) {
  tree->root = NULL;
  return 0;
}

int bst_insert(Node *node, Item item, int (*compare_data)(Item, Item)) {
  if ((*node) == NULL) {
    node_init(node, &item);
    return 0;
  } 
 
  int comparator = (*compare_data)(item, (*node)->data);
  if(comparator > 0)  { // greater than father node, node_right
    bst_insert(&((*node)->right), item, compare_data);
  } else if (comparator < 0) { // lower than father node, node_left
    bst_insert(&((*node)->left), item, compare_data);
  } else {
    return 11; //not implemented
  }

  return 0;
}

void bst_predecessor(Node q, Node *r) {
  Node aux;
  
  if ((*r)->right != NULL) {
    bst_predecessor(q, &((*r)->right));
    return;
  }

  q->data = (*r)->data;
  aux = *r;
  *r = (*r)->left;

  free(aux);
}

int bst_search(Node *node, Item *key, int (*compare_data)(Item, Item)) {
  if(node == NULL) {
    return 0;
  } 
  
  int comparator = (*compare_data)(*key, (*node)->data);

  if(comparator > 0) {
    return bst_search(&((*node)->right), key, compare_data);
  } else if (comparator < 0) {
    return bst_search(&((*node)->left), key, compare_data);
  } else {
    *key = (*node)->data;
    return 1;
  }
  
  return 0;
}

int bst_remove(Node *node, Item key, int(*compare_data)(Item, Item)) {
  if ((*node) == NULL) return -2; // empty tree

  int comparator = compare_data(key, node_get_item(*node));
  if (comparator > 0) {
    return bst_remove(&(*node)->right, key, compare_data);
  } else if (comparator < 0) {
    return bst_remove(&(*node)->left, key, compare_data);
  } else {
    if ((*node)->right == NULL) {
      Node aux = *node;
      aux = (*node)->left;
      free(aux);
    }

    if ((*node)->left != NULL) {
      bst_predecessor(*node, &(*node)->left);
      return 1;
    }

    Node aux = *node;
    *node = (*node)->right;
    free(aux);
  }

  return 1;
}

int bst_print(bs_tree_t tree, void (*to_string)(Item), Order_print_t order_print) {
  switch (order_print) {
    case pre_order:
      __bst_pre_order(tree.root, to_string);
      break;
    case post_order:
      __bst_post_order(tree.root, to_string);
      break;
    case in_order:
      __bst_in_order(tree.root, to_string);
      break;
    case decreasing_order:
      __bst_decreasing_order(tree.root, to_string);
      break;
    default:
      return -1;
  }
  return 0;
}

int bst_height(Node node) {
  if (node == NULL) {
    return -1;
  } else {
    int h_left = bst_height(node->left);
    int h_right = bst_height(node->right);
    if(h_left < h_right) {
      return h_right;
    } else {
      return h_left;
    }
  }
}

void bst_bfs(Node node, void (*to_string)(Item)) {
  Queue queue;
  queue_init(&queue);
  Node aux_node = node;

  while (aux_node != NULL) {
    Item key = aux_node->data;
    (*to_string)(key);
   
    if ((aux_node->left) != NULL) {
      Node_queue node_queue;
      node_queue_init(&node_queue, &(aux_node->left)); 
      enqueue(&queue, &node_queue);
    } 

    if((aux_node->right) != NULL)  {
      Node_queue node_queue;
      node_queue_init(&node_queue, &(aux_node->right));
      enqueue(&queue, &node_queue);
    }

    aux_node = dequeue(&queue);
    
  }
}

int greatest_value(Node node, Item *item) {
  Node current = node;

  while(current->right != NULL) current = current->right;

  *item = current->data;

  return 1;
}

int lowest_value(Node node, Item *item) {
  Node current = node;

  while(current->left != NULL) current = current->left;

  *item = current->data;

  return 1;
}

int count_nodes(Node node) {
  if (node == NULL) return 0;
  return 1 + count_nodes(node->right) + count_nodes(node->left);
}
