#include "node.h"

int hash(char* item) {
    int h=0, a=31415, b=27183;
    for (int i = 0; item[i] != '\0'; i++, a=a*b % (M-1)) {
        h=(a*h + item[i]) % M;
    }

    return h;
}

int hashing_linear(int hash, int j) {
    return (hash + j) % (M);
}

void dictionary_init(Dictionary* dict) {
    for (int i = 0; i < M; i++) {
        dict[i]->word = NULL; 
    }
}

int dictionary_search(Dictionary* dict, char* item) {
    int h = hash(item);
    for (int i=0; i<M; i++) {
        int h_lin = hashing_linear(h, i);
        printf("%d\n", h_lin);
        if (dict[h_lin]->word==NULL) {
            return 0;
        } else if (strcmp(dict[h_lin]->word, item)==0) {
            return 1;
        }
    }  
    return 0;  
}

void dictionary_insert(Dictionary* dict, char *item) {
    int h = hash(item);
    if (!dictionary_search(dict, item)) {
        int j=0;
        while (dict[hashing_linear(h, j)]->word != NULL && j < M) j++;

        if (j < M) {
            h = hashing_linear(h,j);
            dict[h]->word = (char*) malloc(n*sizeof(char));
            strcpy(dict[h]->word, item);
        }
        else return;
    } else {
        printf("Already inserted!\n");
    }
}