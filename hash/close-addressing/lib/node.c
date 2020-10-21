#include "node.h"

// static Node node_init(keys item) {
//     Node node;
//     (node) = (Node) malloc(sizeof(struct node_t)); 
//     item_init(&((node)->item), item);
//     (node)->next = NULL;

//     return node;
// }

void linked_list_init(List *list) {
    list->head = (Node) malloc(sizeof(struct node_t));
    list->tail = list->head;
    list->head->next=NULL;
}

void linked_list_insert(List *list, char *item) {
    list->tail = (Node) malloc(sizeof(struct node_t));
    list->tail = list->tail->next;
    puts(list->tail->item);
    strcpy(list->tail->item, item);
    list->tail->next = NULL;
}

int hash(keys item) {
    int h=0, a=31415, b=27183;
    for (int i = 0; item[i] != '\0'; i++, a=a*b % (M-1)) {
        h=(a*h + item[i]) % M;
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

    if (dict[h]->head->next == NULL) {
        return 0;
    } 

    Node aux = dict[h]->head;

    while (aux->next != NULL) {
        puts(aux->item);
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