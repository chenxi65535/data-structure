#include <stdio.h>
#include "hash_table/simple_hash_table.h"

void test_simple_hash_table() {
    struct table* t = create_table(11);
    int i;
    for (i = 0;i <= 10; i++) {
        insert(t, i, 10-i);
    }

    for (i = 0; i <= 10; i++) {
        printf("%d -> %d\n", i, lookup(t, i));
    }
}

int main() {
    printf("Hello, World!\n");

    printf("\n\n\nTesting simple hash function :\n\n\n");
    test_simple_hash_table();

    return 0;
}
