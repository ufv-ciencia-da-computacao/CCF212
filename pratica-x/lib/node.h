#ifndef __NODE_H__
#define __NODE_H__

#include <stdio.h>
#include <stdlib.h>
#include "aluno.h" 

typedef aluno_t Item;
typedef struct node_t *Node;

struct node_t {
  Item data;
  struct node_t *left;
  struct node_t *right;
};

int node_init(Node *node, Item *data);

#endif
