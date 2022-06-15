#include "node.h"
#include <stdio.h>

void linked_list_init(List *list) {
    list->head = NULL;
    list->tail = NULL;
}

void linked_list_insert(List *list, char *item) {
    Node node = (Node) malloc(sizeof(struct node_t));
    strcpy(node->item, item);
    node->next = NULL;

    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = list->tail->next;
    }
}

int hash(keys item) {
    int h=0, a=31415, b=27183;
    for (int i = 0; item[i] != '\0'; i++, a=a*b % (M-1)) {
        h = (a*h + item[i]) % M;
    }

    return h;
}

void dictionary_init(Dictionary* dict) {
    for (int i = 0; i < M; i++) {
        linked_list_init(dict[i]);
    }
}

int dictionary_search(Dictionary* dict, keys item) {
    int h = hash(item);

    if (dict[h]->head == NULL) {
        return 0;
    } 
    Node aux = dict[h]->head;

    while (aux != NULL) {

        if (strcmp(aux->item, item) == 0) return 1;
        aux = aux->next;
    }

    return 0;
}

void dictionary_insert(Dictionary* dict, keys item) {
    int h = hash(item);

    if (!dictionary_search(dict, item)) {
        linked_list_insert(dict[h], item);
    } else {
        printf("Already inserted!\n");
    }
}