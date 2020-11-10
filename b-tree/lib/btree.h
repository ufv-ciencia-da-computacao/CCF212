#ifndef __BTREE_H__
#define __BTREE_H__

#include <stdio.h>
#include <stdlib.h>

#define M 2
#define MM (M*2)
#define false 0
#define true 1

typedef long Item;
typedef struct node_t {
    Item item;
} Node;

typedef page_t * Page; 
typedef struct page_t {
    short n;
    Node r[MM];
    Page p[MM+1];
} page_t;

#endif