#include <stdio.h>
#include <stdio_ext.h>
#include "./lib/bs-tree.h"
#include "./lib/aluno.h"

int main() {
  bs_tree_t bst;
  aluno_t aluno;
  Node node;

  bst_init(&bst);
  
  int op = 1;

  char nome[255], matricula[255];
  double nota;

  do {
    printf("(1)Inserir na árvore\n(2)Imprimir Ordem Decrescente\n(3)Imprimir numero de alunos na disciplina\n(4)Imprimir menor nota obtida\n(5)Imprimir maior nota obtida\n(6)Imprimir numero de alunos com media na primeira prova\n(0)Sair\n" );
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
        node_init(&node, &aluno);
        bst_insert(&bst.head, &node, __compare_aluno);
        break;
      case 2:
        printf("\n");
        break;
      case 3:
        printf("\n");
        break;
      case 4:
        printf("\n");
        break;
      case 5:
        printf("\n");
        break;
     default:
        break;
    }

  } while(op != 0);
 
  return 0;
}


