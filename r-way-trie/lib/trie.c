#include "trie.h"

void trie_node_init(Trie *node) {
  (*node) = (Trie) malloc(sizeof(struct node_t));

  (*node)->end_word = 0;

  int i=0;
  for (i=0; i<R_WAY; i++) {
    (*node)->children[i] = NULL;
  }
}

void trie_insert(Trie *node, char *str) {
  Trie node_aux = (*node);

  int i=0;
  for (i=0; i < strlen(str); i++) {
    int index = str[i] - 'a';

    if (!node_aux->children[index]) {
      trie_node_init(&(node_aux)->children[index]);
    }     
    
    node_aux = node_aux->children[index];
  }

  node_aux->end_word = 1;
}

int trie_search(Trie *node, char *str) {
  Trie node_aux = (*node);
  int i=0;
  for (i=0; i < strlen(str); i++) {
    int index = str[i] - 'a';

    if(!node_aux->children[index]) return 0;
    node_aux = node_aux->children[index];
  }

  return (node_aux != NULL && node_aux->end_word);
}
