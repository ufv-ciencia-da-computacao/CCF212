#ifndef __NODE_H__
#define __NODE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define n 128
#define M 7

#define MAX_NOME 255

typedef struct {
    char nome[MAX_NOME];
    int cod;
} tripulante_t;

typedef struct {
    tripulante_t* t;
    int seekings;
} tuple_t; // estrutura para retornar duas variáveis em uma função

typedef struct {
    tripulante_t* t;
}Item;

typedef Item Dictionary[M];
typedef int Weight[MAX_NOME];

void dictionary_init(Dictionary* dict);
tuple_t dictionary_search(Dictionary* dict, char* nome);
void dictionary_insert(Dictionary* dict, tripulante_t t);

#endif