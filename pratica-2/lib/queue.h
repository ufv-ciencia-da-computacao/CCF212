#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

typedef struct node_queue_t *Node_queue;
typedef Node Item_queue;

struct node_queue_t {
  Item_queue key;
  struct node_queue_t *next;
};

typedef struct {
  struct node_queue_t* front;
  struct node_queue_t* rear; 
} Queue;

int node_queue_init(Node_queue *node_queue, Item_queue *node_tree); 
int queue_init(Queue *queue);
int enqueue(Queue *queue, Node_queue *node);
Item_queue dequeue(Queue *queue);
int queue_empty(Queue *queue);

#endif
