// noah rodgers, sydney petrehn, and james turne
// code using linked list and insertion sort

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include “pq.h”

 int main(int argc, char *argv[])
 {
    int i;
    const int n = 1000;
    double *v = malloc(sizeof(double)*n);
    pq *mypq;

    // create stack to hold the linked list 
    struct Node *head = (struct Node*) malloc(sizeof(struct Node));
    head->num = 2;
    head->Previous = NULL;
    head->Next = NULL;

    /* init */
    srand(time(NULL));
    mypq = pq_create();
    for (i = 0; i < n; i++) v[i] = drand48();
    /* begin sort */
    for (i = 0; i < n; i++) pq_push(mypq, v[i], (void*)v[i]);
    for (i = 0; i < n; i++) v[i] = pq_pop(mypq);
    /* end sort */

    for (i = 0; i < n; i++) printf(“%g\n”, v[i]);
    free(v);
    return 0;
 }
