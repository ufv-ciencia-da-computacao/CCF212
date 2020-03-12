#include <stdio.h>
#include "./lib/bs-tree.h"

typedef struct {
  int key;
} Int;

char *__int_to_string(void *arg) {
  Int data = *(Int*)arg;
  char *print = (char*) malloc (sizeof(Int) + STRING_MAX);
  char buffer[BUFFER_SIZE];
  
  sprintf(buffer, "%d ", data.key);
  strcat(print, buffer);

  return print;
}

int __compare_int(void *arg1, void *arg2) {
  Int data1, data2;
  
  data1 = *(Int*)arg1;
  data2 = *(Int*)arg2;

  if (data1.key > data2.key) {
    return 1;
  } else if (data1.key < data2.key) {
    return -1;
  } else {
    return 0;
  }
}

int main() {
  bs_tree_t bst;
  Data data;
  Int number;
  Node node;

  bst_init(&bst);
  createData(&data);
  setToStringFunction(&data, __int_to_string);
  
  int op = 1;

  do {
    printf("(1)Inserir na árvore\n(2)Imprimir Ordem\n(3)Imprimir Pre Ordem\n(4)Imprimir Pos Ordem\n(5)Imprimir em Largura\n(6)Retirar da Árvore\n(0)Sair\n" );
    scanf("%d", &op);

    switch(op) {
      case 1:
        printf("Digite um numero: ");
        scanf("%d", &number.key);
 
        setData(&data, &number, sizeof(Int));
        node_init(&node, &data);
        bst_insert(&bst.head, &node, __compare_int);
        break;
      case 2:
        bst_print(&bst, 2);
        printf("\n");
        break;
      case 3:
        bst_print(&bst, 0);
        printf("\n");
        break;
      case 4:
        bst_print(&bst, 1);
        printf("\n");
        break;
      case 5:
        bst_bfs(&(bst.head));
        printf("\n");
        break;
      case 6:
        printf("Digite o numero que queira retirar: ");
        scanf("%d", &number.key);
        setData(&data, &number, sizeof(Int));

        bst_remove(&(bst.head), &data, __compare_int);
        bst_bfs(&(bst.head));
        printf("\n");
        break;
      default:
        break;
    }

  } while(op != 0);
 
  return 0;
}


