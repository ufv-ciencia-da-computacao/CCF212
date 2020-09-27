#include <stdio.h>
#include <stdlib.h>
#include "./lib/trie.h"

int main () {
  char strings[8][20] = {"agreement", "cat", "visible", "bean", "charter", "continuation", "charm", "ground"};
  Trie trie;
  trie_node_init(&trie);

  int i=0;
  for (i=0; i<8; i++) {
    trie_insert(&trie, strings[i]);
  }

  printf(trie_search(&trie, "visible") ? "YES\n":"NO\n");
  printf(trie_search(&trie, "charm") ? "YES\n":"NO\n");
  printf(trie_search(&trie, "germano") ? "YES\n":"NO\n");

  return 0;
}
