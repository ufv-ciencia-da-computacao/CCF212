#include "bs-tree.h"

static void __bst_pre_order(Node *node, void (*to_string)(Item*)) {  
  if ((*node) == NULL) return;
  
  Item *key = &((*node)->data);
  (*to_string)(key);
  __bst_pre_order(&((*node)->left), to_string);
  __bst_pre_order(&((*node)->right), to_string);
}

static void __bst_post_order(Node *node, void (*to_string)(Item*)) {
  if ((*node) == NULL) return;
  
  Item *key = &((*node)->data);
  __bst_post_order(&((*node)->left), to_string);
  __bst_post_order(&((*node)->right), to_string);
  (*to_string)(key);
}

static void __bst_in_order(Node *node, void (*to_string)(Item*)) {
  if ((*node) == NULL) return;
  
  Item *key = &((*node)->data);
  __bst_in_order(&((*node)->left), to_string);
  (*to_string)(key);
  __bst_in_order(&((*node)->right), to_string);
}

int bst_init(bs_tree_t *tree) {
  tree->head = NULL;
  return 0;
}

int bst_insert(Node *node, Node *node_insert, int (*compare_data)(Item*, Item*)) {
  if ((*node) == NULL) {
    node_init(node, &((*node_insert)->data));
    return 0;
  } 
 
  int comparator = (*compare_data)((&((*node_insert)->data)),(&((*node)->data)));
  if(comparator > 0)  { // greater than father node, node_right
    bst_insert(&((*node)->right), node_insert, compare_data);
  } else if (comparator < 0) { // lower than father node, node_left
    bst_insert(&((*node)->left), node_insert, compare_data);
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

Node* bst_search(Node *node, Item key, int (*compare_data)(Item*, Item*)) {
  if((*node) == NULL) {
    return NULL;
  } 
  
  int comparator = (*compare_data)((&key), (&((*node)->data)));

  if(comparator > 0) {
    return bst_search(&((*node)->right), key, compare_data);
  } else if (comparator < 0) {
    return bst_search(&((*node)->left), key, compare_data);
  } else {
    return node;
  }
  
  return NULL;
}

int bst_remove(Node *node, Item *key, int(*compare_data)(Item*, Item*)) {
  if ((*node) == NULL) return -2; // empty tree

  Node* node_searched = bst_search(node, *key, compare_data);
  if ((*node_searched) != NULL) {
    if ((*node_searched)->left == NULL && (*node_searched)->right == NULL) {
      Node aux = *node_searched;
      (*node_searched) = (*node_searched)->right;
      free(aux);
    } else if ((*node_searched)->left == NULL && (*node_searched)->right != NULL) {
      (*node_searched) = (*node_searched)->right;
      free((*node_searched)->right);
    } else if ((*node_searched)->right == NULL && (*node_searched)->left != NULL) {
      (*node_searched) = (*node_searched)->left;
      free((*node_searched)->left);
    } else if ((*node_searched)->left != NULL && (*node_searched)->right != NULL) {
      bst_predecessor((*node_searched), &((*node_searched)->left));
    }
  } else {
    return -1; // not_found
  }

  return 0;
}

int bst_print(bs_tree_t *tree, void (*to_string)(Item*), Order_print_t order_print) {
  switch (order_print) {
    case pre_order:
      __bst_pre_order(&(tree->head), to_string);
      break;
    case post_order:
      __bst_post_order(&(tree->head), to_string);
      break;
    case in_order:
      __bst_in_order(&(tree->head), to_string);
      break;
    default:
      return -1;
  }
  return 0;
}

int bst_height(Node *node) {
  if ((*node) == NULL) {
    return -1;
  } else {
    int h_left = bst_height(&((*node)->left));
    int h_right = bst_height(&((*node)->right));
    if(h_left < h_right) {
      return h_right;
    } else {
      return h_left;
    }
  }
}

void bst_bfs(Node *node, void (*to_string)(Item*)) {
  Queue queue;
  queue_init(&queue);
  Node aux_node = (*node);

  while (aux_node != NULL) {
    Item *key = &(aux_node->data);
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
