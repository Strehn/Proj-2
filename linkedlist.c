#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "pq.h"
#include "pq-linkedlist.c"

/* Allocates and initializes a new pq */
pq* pq_create()
{
  return (pq*)malloc(sizeof(pq));
}

/* Deallocates (frees) pq. Shallow destruction,
meaning nodes in the pq are not recursively freed. */
void pq_destroy(pq *head)
{
  free(head);
}

void PrintLL(pq *head){
    struct pq * temp;
    if(head == NULL){
        printf(" Empty List.");
    }
    else {
        temp = head;
        printf("\n Data in list :\n");
        while(temp != NULL){
            printf("%d ", temp->num);
            temp = temp->Next; // move to next node down list
        }
    }
}

void sInsert(pq* head, pq* newNode){// head = sl, new = current
    pq *current = pq_create();
    // if list null head becomes node to be sorted
    if (head == NULL){
        head = newNode;
    }
    else if ((head)->num >= newNode->num) { // if the newNode's is first
        newNode->Next = head;
        newNode->Next->Previous = newNode;
        head = newNode;
    }
    else { // find where to insert new node
        current = head;
        while (current->Next != NULL && 
              current->Next->num < newNode->num)
            current = current->Next;
        // insert node here
        newNode->Next = current->Next;
        // if at end of list next = null 
        if (current->Next != NULL)
            newNode->Next->Previous = newNode;
        current->Next = newNode;
        newNode->Previous = current;
    }
}


int main(int argc, char *argv[])
{
  int i = 0;
  const int n = 1000;
  double *v = malloc(sizeof(double)*n);
  struct pq *mypq;
  mypq = pq_create();
    /* init */
    srand(time(NULL));
    for (i = 0; i < n; i++) {
      v[i] = drand48();
    }

    for (i = 0; i < n; i++){
      struct pq *newNode = pq_create();
      newNode->num = v[i];
      newNode->Next = NULL;
      newNode->Previous = NULL;        // INSERTION SORT
      sInsert(mypq, newNode);
    } 
    
    PrintLL(mypq); // print the data in the list

    free(v);
    free(mypq);
    return 0;
}
