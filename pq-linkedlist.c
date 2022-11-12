// noah rodgers, sydney petrehn, and james turner
// code using a doubly linked list and insertion sort

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include “pq.h”
#include "pq-null.c"

// function declaration
void InsertionSort(pq *head);
void sInsert(pq** head, pq* newNode);

// doubly linked list sorted using insertion sort
// inserts every node into a new sorted list (sl)
void InsertionSort(pq *head){
    struct pq *sl = pq_create();
    struct pq *current = pq_create();
    current = *head;
    struct pq *next = pq_create();
    // go through list and insert each into a new sorted list
    while (current != NULL) {
        next = current->next;
        current->prev = current->next = NULL;
        sInsert(&sl, current); // put node in sorted list
        current = next;
    }
    *head = sl; // new head pointer points to head of sl
}

void sInsert(pq** head, pq* newNode){// head = sl, new = current
    struct pq *current = pq_create();
    // if list null head becomes node to be sorted
    if (*head == NULL){
        *head = newNode;
    }
    else if ((*head)->num >= newNode->num) { // if the newNode's is first
        newNode->next = *head;
        newNode->next->prev = newNode;
        *head = newNode;
    }
    else { // find where to insert new node
        current = *head;
        while (current->next != NULL && 
              current->next->num < newNode->num)
            current = current->next;
        // insert node here
        newNode->next = current->next;
        // if at end of list next = null 
        if (current->next != NULL)
            newNode->next->prev = newNode;
        current->next = newNode;
        newNode->prev = current;
    }
}

int main(int argc, char *argv[])
{
  int i;
  const int n = 1000;
  double *v = malloc(sizeof(double)*n);
  double **p = malloc(sizeof(double*)*n);
  struct pq *mypq;

  /* init */
  srand48(time(NULL));
  mypq = pq_create();
  for (i = 0; i < n; i++) {
    v[i] = drand48();
    p[i] = &v[i];
  }

  /* begin sort */
  for (i = 0; i < n; i++) pq_push(mypq, v[i], (void*)p[i]);
  InsertionSort(mypq);
  /* end sort */

  for (i = 0; i < n; i++) {
    if (p[i]) printf("%g\n", *p[i]);
  }

  pq_destroy(mypq);

  free(v);
  free(p);
  return 0;
}
