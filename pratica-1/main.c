#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "./lib/bs-tree.h"

int main () {
  Tree tree;
  bst_init(&tree);

  int op=1;
  
  int number;
  
  do {
    printf("(1)Inserir na árvore\n(2)Imprimir Pré-Ordem\n(3)Imprimir Pós-Ordem\n(4)Imprimir em Ordem\n");
    scanf("%d", &op);

    switch(op) {
      case 1:
        __fpurge(stdin);
        scanf("%d", &number);
        bst_insert(&tree, number, compare_data);
        break;
      case 2:
        bst_print(&tree, to_string_int, 0);
        printf("\n");
        break;
      case 3:
        bst_print(&tree, to_string_int, 1);
        printf("\n");
        break;
      case 4:
        bst_print(&tree, to_string_int, 2);
        printf("\n");
        break;
      default:
        break;
    }

  } while(op!=0);
  
  return 0;
}
