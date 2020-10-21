#include <stdio.h>
#include <stdlib.h>
#include "./open-addressing/lib/node.h"
//./open-addressing/lib/node.c ./open-addressing/lib/node.h 

int main() {

    Dictionary dict;
    dictionary_init(&dict);

    dictionary_insert(&dict, "hello");
    dictionary_insert(&dict, "world");

    char find[32];
    scanf("%s", find);
    printf("%s ", find);
    if(!dictionary_search(&dict, find)) {
        printf("NOT ");
    }
    printf("found in map\n");

    return 0;
}