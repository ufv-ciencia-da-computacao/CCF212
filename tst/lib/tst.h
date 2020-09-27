#ifndef __TRIE_H__
#define __TRIE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_t *TST;

struct node_t {
  struct node_t *left;
  struct node_t *right;
  struct node_t *middle;
  char character;
  int end_word;
};

void tst_node_init(TST *root, char ch);
void tst_insert(TST *root, char *str);
int tst_search(TST *root, char *str);
#endif