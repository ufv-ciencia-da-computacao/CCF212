#ifndef __PATRICIA_H__
#define __PATRICIA_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define D 8 // Depends on type of Item

typedef char Item;
typedef int index_amp;

typedef enum {
  internal, external
} node_type;

typedef struct pat_node_str* Patricia;
typedef struct pat_node_str {
  node_type type;
  union {
    struct {
      index_amp index;
      Patricia left;
      Patricia right;
    }node_internal;
    Item key;
  }node;
} pat_node;

typedef int bit_digit;

bit_digit bit(index_amp i, Item key);
int type_node(Patricia p);
void pat_init(Patricia* patricia);
void pat_node_init(Patricia* patricia, Item key, Item key_a, int i, int *h);
int pat_search(Patricia patricia, Item key);
void pat_insert(Patricia* patricia, Item key);
#endif