#ifndef __BS_TREE_H__
#define __BS_TREE_H__

#include "data.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node_t *Node;
typedef struct node_queue_t *Node_queue;
struct node_t {
  Data data;
  struct node_t *left;
  struct node_t *right;
};

struct node_queue_t {
  struct node_t *key;
  struct node_queue_t *next;
};

typedef struct {
  struct node_queue_t* front;
  struct node_queue_t* rear; 
} Queue;

typedef struct {
  Node head;
} bs_tree_t;

typedef enum {pre_order, post_order, in_order} Order_print_t;

int node_init(Node *node, Data *data);
int node_queue_init(Node_queue *node_queue, Node *node_tree); 

int queue_init(Queue *queue);
int enqueue(Queue *queue, Node_queue *node);
Node dequeue(Queue *queue);
int queue_empty(Queue *queue);

int bst_init(bs_tree_t *tree);
int bst_insert(Node *node, Node *node_insert, int (*compare_data)(void*, void*));
void bst_predecessor(Node q, Node *r);
Node* bst_search(Node *node, Data key, int (*compare_data)(void*, void*));
int bst_remove(Node *node, Data *key, int (*compare_data)(void*, void*));
int bst_print(bs_tree_t *tree, Order_print_t order_print);
int bst_height(Node *node);
void bst_bfs(Node *node);
#endif
