#ifndef __NODE_H__
#define __NODE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define n 128
#define M 7

typedef struct {
    char* word;
}Item;

typedef Item Dictionary[M];

void dictionary_init(Dictionary* dict);
int dictionary_search(Dictionary* dict, char* item);
void dictionary_insert(Dictionary* dict, char* item);

#endif