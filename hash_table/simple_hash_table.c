//
// Created by Souris on 9/21/2020.
//

#include "simple_hash_table.h"
#include <stdio.h>
#include <stdlib.h>

struct table *create_table(int size) {
    struct table *t = (struct table*) malloc(sizeof(struct table));
    t->size = size;
    t->list = (struct node**) malloc(sizeof(struct node*)*size);
    int i;
    for (i = 0; i <= size; i++) {
        t->list[i] = NULL;
    }
    return t;
}

int hashcode(struct table *t, int key) {
    if ( key < 0 ) {
        return -(key % t->size);
    }
    return key % t->size;
}

void insert(struct table *t, int key, int val) {
    int pos = hashcode(t, key);
    struct node *list = t->list[pos];
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    struct node *temp = list;
    while (temp) {
        if (temp->key == key) {
            temp->val = val;
            return;
        }
        temp = temp->next;
    }
    new_node->key = key;
    new_node->val = val;
    // new_node will be inserted at the 1st pos
    new_node->next = list;
    t->list[pos] = new_node;
}

/**
 * -1 will be used as error_code, value must NOT be -1
 * @param t
 * @param key
 * @return
 */
int lookup(struct table *t, int key) {
    int pos = hashcode(t, key);
    struct node* list = t->list[pos];
    struct node* temp = list;
    while (temp) {
        if (temp->key == key) {
            return temp->val;
        }
        temp = temp->next;
    }
    return -1;
}
