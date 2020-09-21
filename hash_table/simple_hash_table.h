//
// Created by Souris on 9/21/2020.
// just for practicing
// origin: http://www.kaushikbaruah.com/posts/data-structure-in-c-hashmap/
//

#ifndef DATA_STRUCTURE_SIMPLE_HASH_TABLE_H
#define DATA_STRUCTURE_SIMPLE_HASH_TABLE_H

struct node {
    int key;
    int val;
    struct node *next;
};

struct table {
    int size;
    struct node **list;
};

struct table *create_table(int size);

int hashcode(struct table *t, int key);

void insert(struct table *t, int key, int val);

int lookup(struct table *t, int key);

#endif //DATA_STRUCTURE_SIMPLE_HASH_TABLE_H
