// noah rodgers, sydney petrehn, and james turne
// code using linked list and insertion sort

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include “pq.h”


/* Allocates and initializes a new pq */
pq* pq_create();

/* Adds value to pq based on numerical order of key */
void pq_push(pq *head, double key, void *value);

/* Returns value from pq having the minimum key */
void* pq_pop(pq *head);

/* Deallocates (frees) pq. Shallow destruction,
meaning nodes in the pq are not recursively freed. */
void pq_destroy();


