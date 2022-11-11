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

typedef struct pq pq;

/* Allocates and initializes a new pq */
pq* pq_create();

/* Adds value to pq based on numerical order of key */
void pq_push(pq *head, double key, void *value);

/* Returns value from pq having the minimum key */
void* pq_pop(pq *head);

/* Deallocates (frees) pq. Shallow destruction,
meaning nodes in the pq are not recursively freed. */
void pq_destroy();

