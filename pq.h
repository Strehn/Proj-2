#include <limits.h>
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct pq {
    int num;
    struct pq* Previous;
    struct pq* Next;
};

typedef struct pq pq;

/* Allocates and initializes a new pq */
struct pq* pq_create();

/* Adds value to pq based on numerical order of key */
void pq_push( pq *head, double key, pq *value);

/* Returns value from pq having the minimum key */
double pq_pop(pq *head);

/* Deallocates (frees) pq. Shallow destruction,
meaning nodes in the pq are not recursively freed. */
void pq_destroy();
