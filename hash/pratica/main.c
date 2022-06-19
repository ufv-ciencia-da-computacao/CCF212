#include "node.h"
#include <stdio.h>
#include <stdio_ext.h>

void read_file(Dictionary *hash_table) {
    FILE *f;

    f = fopen("tripulantes.txt", "r");

    if (f==NULL) {
        exit(0);
    }

    char nome[MAX_NOME];
    int cod;

    tripulante_t t;
    
    while (!feof(f)) {
        fscanf(f, "%d ", &cod);
        fgets(nome, MAX_NOME, f);
        nome[strcspn(nome, "\n")] = '\0'; // Troca a primeira ocorrência do '\n' para '\0'.
        
        strcpy(t.nome, nome);
        t.cod = cod;
        dictionary_insert(hash_table, t);
    }
}


int main () {
    Dictionary hash_table;

    dictionary_init(&hash_table);
    read_file(&hash_table);

    char nome[MAX_NOME];

    int op;
    printf("0-Sair\n1-Pesquisar\n");
    while (scanf("%d", &op), op) {
        __fpurge(stdin);
        fgets(nome, MAX_NOME, stdin);
        nome[strcspn(nome, "\n")] = '\0'; // Troca a primeira ocorrência do '\n' para '\0'.

        tuple_t tup = dictionary_search(&hash_table, nome);
        if (tup.t == NULL) {
            printf("Não Encontrado!\n");
            printf("Seekings: %d\n\n", tup.seekings);
        } else { 
            printf("Nome: "); puts(tup.t->nome);
            printf("Código: %d\n", tup.t->cod);
            printf("Seekings: %d\n\n", tup.seekings);
        }

        printf("0-Sair\n1-Pesquisar\n");
    }
}