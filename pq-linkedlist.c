// noah rodgers, sydney petrehn, and james turner
// code using a doubly linked list and insertion sort

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
//#include "pq.h"

// function declaration
void InsertionSort(pq *head);
void sInsert(pq** head, pq* newNode);

/* Allocates and initializes a new pq */
pq* pq_create()
{
  return (pq*)malloc(sizeof(pq));
}

/* Adds value to pq based on numerical order of key */
void pq_push(pq *head, double key, void *value)
{
  if (head && !(head->ptr)) head->ptr = value;
}

/* Returns value from pq having the minimum key */
void* pq_pop(pq *head)
{
  void *p = head->ptr;
  head->ptr = NULL;
  return p;
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

// doubly linked list sorted using insertion sort
// inserts every node into a new sorted list (sl)
// ----- This function can be deleted we didnt end up using it -----
void InsertionSort(pq *head){
    pq *sl = pq_create();
    pq *current = pq_create();
    current = *head;
    pq *next = pq_create();
    // go through list and insert each into a new sorted list
    while (current != NULL) {
        next = current->Next;
        current->prev = current->Next = NULL;
        sInsert(&sl, current); // put node in sorted list
        current = next;
    }
    *head = sl; // new head pointer points to head of sl
}

void sInsert(pq* head, pq* newNode){// head = sl, new = current
    pq *current = pq_create();
    // if list null head becomes node to be sorted
    if (*head == NULL){
        *head = newNode;
    }
    else if ((*head)->num >= newNode->num) { // if the newNode's is first
        newNode->Next = *head;
        newNode->Next->prev = newNode;
        *head = newNode;
    }
    else { // find where to insert new node
        current = *head;
        while (current->Next != NULL && 
              current->Next->num < newNode->num)
            current = current->Next;
        // insert node here
        newNode->Next = current->Next;
        // if at end of list next = null 
        if (current->Next != NULL)
            newNode->Next->prev = newNode;
        current->Next = newNode;
        newNode->prev = current;
    }
}
