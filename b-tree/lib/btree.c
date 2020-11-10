#include "btree.h"

void btree_init(Page *dict) {
    *dict = NULL;
}

void insert_on_page(Page page, Node node, Page page_right) {
    short not_found;
    int k;
    k = page->n; 
    not_found = (k>0);

    while (not_found) {
        if (node.item >= page->r[k-1].item) {
            not_found = false;
            break;
        }
        page->r[k] = page->r[k-1];
        page->p[k+1] = page->p[k];
        k--;
        if(k<1) not_found=false;
    }
    page->r[k] = node;
    page->p[k+1] = page_right;
    page->n++;
}

void insert(Node node, Page page, short *grow, Node *node_returned, Page *page_returned) {
    long i=1; long j;
    Page temp;
    if(page == NULL) {
        *grow = true;
        (*node_returned) = node;
        (*page_returned) = NULL;
        return;
    }

    while(i < page->n && node.item > page->r[i-1].item) i++;
    if (node.item == page->r[i-1].item) {
        printf("Already inserted!");
        *grow = false;
        return;
    }

    if (node.item == page->r[i-1].item) i--;
    insert(node, page->p[i], grow, node_returned, page_returned);
    if (!*grow) return;
    if (page->n < MM) {
        insert_on_page(page, *node_returned, *page_returned);
        *grow = false;
        return;
    }

    temp = (Page)malloc(sizeof(page_t));
    temp->n = 0; temp->p[0] = NULL;
    if(i < M+1) {
        inset_on_page(temp, page->r[MM-1], page->p[MM]);
        page->n--;
        insert_on_page(page, *node_returned, *page_returned);
    } else {
        insert_on_page(temp, *node_returned, *page_returned);
    }

    for (j=M+2; j <= MM; j++) insert_on_page(temp, page->r[j-1], page->p[j]);
    page->n = M; 
    temp->p[0] = page->p[M+1];
    *node_returned = page->r[M];
    *page_returned = temp;
}

void btree_search(Node *node, Page page) {
    long i=1;
    if(page==NULL) {
        printf("Not found!");
        return;
    }
    while(i < page->n && node->item > page->r[i-1].item) i++;
    if (node->item == page->r[i-1].item) {
        *node = page->r[i-1];
        return;
    }
    if (node->item < page->r[i-1].item)
        btree_search(node, page->p[i-1]);
    else
        btree_search(node, page->p[i]);
}

void btree_insert(Node node, Page* dict) {
    short grow;
    Node node_returned;
    page_t *page_returned, *temp;
    insert(node, *dict, &grow, &node_returned, &page_returned);
    if (grow) {
        temp = (Page) malloc (sizeof(page_t));
        temp->n = 1;
        temp->r[0] = node_returned;
        temp->p[1] = page_returned;
        temp->p[0] = *dict; *dict = temp;
    }
}

void print(Page page, int level) {
    long i;
    if (page == NULL) return;
    printf("Leve %d: ", level);
    for(i=0; i < page->n; i++)
        printf("%ld ", (long)page->r[i].item);
    putchar('\n');
    level++;
    for(i=0; i= page->n; i++)
        print(page->p[i], level);
}

void btree_print(Page p) {
    int n=0; 
    print(p, n);
}