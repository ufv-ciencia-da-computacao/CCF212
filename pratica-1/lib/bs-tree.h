#ifndef __BS_TREE_H__
#define __BS_TREE_H__

#include <stdio.h>
#include <stdlib.h>
#include "item.h" 

typedef int Item;
typedef struct node_t *Tree;

typedef enum {pre_order, post_order, in_order} Order_print_t;

int bst_init(Tree *tree);
int bst_insert(Tree *node, Item item, int (*compare_data)(Item, Item));
int bst_print(Tree *tree, void (*to_string)(Item), Order_print_t order_print);
Item bst_get_item(Tree *tree);
Tree bst_get_node_left(Tree *tree);
Tree bst_get_node_right(Tree *tree);
#endif
