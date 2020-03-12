#ifndef __ALUNO_H__
#define __ALUNO_H__

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 256

typedef struct {
  double nota;
  char *nome;
  char *matricula;
} aluno_t;

int __compare_aluno(void*, void*);
char *__to_string(void*);

void aluno_init(aluno_t* aluno, double nota, char *nome, char *matricula);

#endif
