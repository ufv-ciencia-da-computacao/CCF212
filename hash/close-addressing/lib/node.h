#ifndef __NODE_H__
#define __NODE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define n 128
#define M 7

typedef char keys[n+1];

typedef struct node_t *Node;

struct node_t {
    char item[n+1];
    struct node_t *next;
};

typedef struct List {
    Node head;
    Node tail; 
}List;

typedef List Dictionary[M+1]; 

void linked_list_init(List *list);
void linked_list_insert(List *list, keys item);
void dictionary_init(Dictionary* dict);
int dictionary_search(Dictionary* dict, keys item);
void dictionary_insert(Dictionary* dict, keys item);

#endif