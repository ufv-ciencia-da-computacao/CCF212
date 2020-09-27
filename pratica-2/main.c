#include <stdio.h>
#include <stdio_ext.h>
#include "./lib/bs-tree.h"
#include "./lib/aluno.h"

int main() {
  bs_tree_t bst;
  aluno_t aluno;

  bst_init(&bst);
  
  int op = 1;
  int success;
  char nome[255], matricula[255];
  double nota;
  int grupo;

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

        __fpurge(stdin);
        printf("Digite o grupo: ");
        scanf("%d", &grupo);
        
        aluno_init(&aluno, nota, nome, matricula, grupo);
        bst_insert(&bst.root, aluno, __compare_aluno);
        break;
      case 2:
        bst_print(bst, __to_string_aluno, 3);
        printf("\n");
        break;
      case 3:
        printf("Número de alunos na disciplina: %d\n", count_nodes(bst.root)); 
        break;
      case 4:
        success = lowest_value(bst.root, &aluno);
        if (success) __to_string_aluno(aluno);

        break;
      case 5:
        success = greatest_value(bst.root, &aluno);
        if (success) __to_string_aluno(aluno);
        break;
      case 6:
        printf("Número de alunos com média: %d\n", count_average_students(bst.root, 6));
        break;
     default:
        break;
    }

  } while(op != 0);
 
  return 0;
}


