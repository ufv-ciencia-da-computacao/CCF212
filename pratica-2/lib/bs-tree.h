#ifndef __BS_TREE_H__
#define __BS_TREE_H__

#include <stdio.h>
#include <stdlib.h>
#include "node.h" 
#include "queue.h"

typedef struct {
  Node root;
} bs_tree_t;

typedef enum {pre_order, post_order, in_order, decreasing_order} Order_print_t;


int bst_init(bs_tree_t *tree);
int bst_insert(Node *node, Item item, int (*compare_data)(Item, Item));
void bst_predecessor(Node q, Node *r);
int bst_search(Node *node, Item *key, int (*compare_data)(Item, Item));
int bst_remove(Node *node, Item key, int (*compare_data)(Item, Item));
int bst_print(bs_tree_t tree, void (*to_string)(Item), Order_print_t order_print); 
int bst_height(Node node);
void bst_bfs(Node node, void (*to_string)(Item));
int greatest_value(Node node, Item *item);
int lowest_value(Node node, Item *item);
int count_nodes(Node node);
int count_average_students(Node node, int average); 
#endif
