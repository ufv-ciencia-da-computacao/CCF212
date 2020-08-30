#include "queue.h"

int node_queue_init(Node_queue *node_queue, Item_queue *node_tree) {
  (*node_queue) = (Node_queue) malloc(sizeof(struct node_queue_t));
  (*node_queue)->key = *node_tree;
  (*node_queue)->next = NULL;

  return 0;
}

int queue_init(Queue *queue) {
  queue->front = NULL;
  queue->rear = NULL;
  return 0;
}

int queue_empty(Queue *queue) {
  return (queue->rear == NULL) ? 0 : 1;
}

int enqueue(Queue *queue, Node_queue *node) {

  if(queue_empty(queue)==0) {
    queue->front = (*node); 
    queue->rear = (*node);
    return 0;
  }

  queue->rear->next = (*node);
  queue->rear = (*node);
  
  return 0;
}

Item_queue dequeue(Queue *queue) {
  if (queue->front == NULL) {
    return NULL;
  }

  Item_queue node = queue->front->key;
  queue->front = queue->front->next;

  if (queue->front == NULL) {
    queue->rear = NULL;
  }

  return node;
}

