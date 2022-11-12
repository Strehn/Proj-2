#include <limits.h>
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct pq {
    int num;
    struct Node* Previous;
    struct Node* Next;
};

/* Allocates and initializes a new pq */
struct pq* pq_create();  //tried this with and with out "struct" -- didn't like either - main problem is it doesn't recognize the pq type across files

/* Adds value to pq based on numerical order of key */
void pq_push(pq *head, double key, void *value);

/* Returns value from pq having the minimum key */
void* pq_pop(pq *head);

/* Deallocates (frees) pq. Shallow destruction,
meaning nodes in the pq are not recursively freed. */
void pq_destroy();

