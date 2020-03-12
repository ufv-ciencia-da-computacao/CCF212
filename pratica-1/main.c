#include <stdio.h>
#include <stdio_ext.h>
#include "./lib/bs-tree.h"
#include "./lib/aluno.h"

int main() {
  bs_tree_t bst;
  Data data;
  aluno_t aluno;
  Node node;

  bst_init(&bst);
  createData(&data);
  setToStringFunction(&data, __to_string);
  
  int op = 1;

  char *nome, *matricula;
  double nota;

  do {
    printf("(1)Inserir na árvore\n(2)Imprimir Ordem Decrescente\n(3)Imprimir numero de alunos na disciplina\n(4)Imprimir menor nota obtida\n(5)Imprimir maior nota obtida\n(6)Imprimir numero de alunoscom media na primeira prova\n(0)Sair\n" );
    scanf("%d", &op);

    switch(op) {
      case 1:
        __fpurge(stdin);
        printf("Digite o nome: ");
        fgets(nome, 80, stdin);
        
        __fpurge(stdin);
        printf("Digite a matricula: ");
        fgets(matricula, 80, stdin);
        
        __fpurge(stdin);
        printf("Digite a nota: ");
        scanf("%lf", &nota);
        
        aluno_init(&aluno, nota, nome, matricula);
        setData(&data, &aluno, sizeof(aluno_t));
        node_init(&node, &data);
        bst_insert(&bst.head, &node, __compare_aluno);
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
     default:
        break;
    }

  } while(op != 0);
 
  return 0;
}


