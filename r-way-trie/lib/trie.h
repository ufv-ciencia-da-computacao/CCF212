#ifndef __TRIE_H__
#define __TRIE_H__
#define R_WAY 26

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Item;
typedef struct node_t *Trie;

struct node_t {
  struct node_t *children[R_WAY];
  int end_word;
};

void trie_node_init(Trie *node);
void trie_insert(Trie *node, char *str);
int trie_search(Trie *node, char *str);
#endif