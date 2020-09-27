#include "tst.h"

void tst_node_init(TST *root, char ch) {
  (*root) = (TST) malloc(sizeof(struct node_t));

  (*root)->left = NULL;
  (*root)->middle = NULL;
  (*root)->right = NULL;
  (*root)->end_word = 0;
  (*root)->character = ch;
}

static void insert(TST *root, char* str, int pos, int len) {
  if ((*root) == NULL) tst_node_init(root, str[pos]);

  if (pos == len-1) {
    (*root)->end_word = 1;
    return;
  }

  if (str[pos] == (*root)->character) insert(&(*root)->middle, str, pos+1, len);
  else if (str[pos] > (*root)->character) insert(&(*root)->right, str, pos, len);
  else insert(&(*root)->left, str, pos, len);
  
}

void tst_insert(TST *root, char *str) {
  insert(root, str, 0, strlen(str));
}


static int search(TST *root, char *str, int pos, int len) {
  if ((*root) == NULL) return 0;
  if (pos == len-1) return 1;

  if (str[pos] == (*root)->character) return search(&(*root)->middle, str, pos+1, len);
  else if (str[pos] > (*root)->character) return search(&(*root)->right, str, pos, len);
  else return search(&(*root)->left, str, pos, len);
}

int tst_search(TST *root, char *str) {
  return search(root, str, 0, strlen(str));
}