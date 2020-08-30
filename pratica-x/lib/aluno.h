#ifndef __ALUNO_H__
#define __ALUNO_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct aluno_t {
  double nota;
  char nome[255];
  char matricula[255];
} aluno_t;

int __compare_aluno(aluno_t* aluno1, aluno_t* aluno2);
void __to_string_aluno(aluno_t* aluno);

void aluno_init(aluno_t* aluno, double nota, char *nome, char *matricula);

#endif
