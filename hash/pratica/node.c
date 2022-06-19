#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Weight w;

static tuple_t tuple_init(tripulante_t *t, int seekings) {
    tuple_t tuple;
    tuple.t = t;
    tuple.seekings = seekings;
    return tuple;
}

static void define_weight() {
    srand(time(NULL));
    for (int i=0; i<MAX_NOME; i++) {
        w[i] = rand()%MAX_NOME+1;  // o peso pode ser calculado de diversas formas. Utilizei aqui o método randômico seguindo os slides.
    }
}

int hash(char* item) {
    int h=0;
    for (int i = 0; item[i] != '\0'; i++) {
        h += item[i]*w[i];
    }
    return h;
}

int hashing_linear(int hash, int j) {
    return (hash + j) % (M);
}

void dictionary_init(Dictionary* dict) {
    for (int i = 0; i < M; i++) {
        dict[i]->t = NULL; 
    }
    define_weight();
}

tuple_t dictionary_search(Dictionary* dict, char *nome) {
    int h = hash(nome);
    for (int i=0; i<M; i++) {
        int h_lin = hashing_linear(h, i);
        if (dict[h_lin]->t==NULL) {
            return tuple_init(NULL, i);
        } else if (strcmp(dict[h_lin]->t->nome, nome)==0) {
            return tuple_init(dict[h_lin]->t, i);
        }
    }

    return tuple_init(NULL, 0);  
}

void dictionary_insert(Dictionary* dict, tripulante_t t) {
    int h = hash(t.nome);
    tuple_t tup = dictionary_search(dict, t.nome);
    if (tup.t == NULL) {
        int j=0;
        while (dict[hashing_linear(h, j)]->t != NULL && j < M) j++;

        if (j < M) {
            h = hashing_linear(h,j);
            dict[h]->t = (tripulante_t*) malloc(sizeof(tripulante_t));
            strcpy(dict[h]->t->nome, t.nome);
            dict[h]->t->cod = t.cod;
        }
        else return;
    }
}