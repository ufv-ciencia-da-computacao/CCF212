#include "aluno.h"

int __compare_aluno(void *arg1, void *arg2) {
  aluno_t data1, data2;
  data1 = *(aluno_t*) arg1;
  data2 = *(aluno_t*) arg2;

  if (data1.nota > data2.nota) {
    return 1;
  } else if (data1.nota < data2.nota) {
    return -1;
  } else {
    return 0;
  }
}

char *__to_string(void *arg1) {
  aluno_t data = *(aluno_t*) arg1;

  char *print = (char*) malloc(sizeof(aluno_t) + BUFFER_SIZE);

  sprintf(print, "Nome: %s\nMatricula: %s\nNota: %lf\n", data.nome, data.matricula, data.nota);

  return print;
}

void aluno_init(aluno_t* aluno, double nota, char *nome, char *matricula) {
  aluno->nota = nota;
  aluno->nome = nome;
  aluno->matricula = matricula;
}
