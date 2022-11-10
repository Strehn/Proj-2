// noah rodgers, sydney petrehn, and james turne
// code using a doubly linked list and insertion sort

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include “pq.h”

// function declaration
void InsertionSort(pq *head);
void sInsert(pq** head, pq* newNode);

// doubly linked list sorted using insertion sort
// inserts every node into a new sorted list (sl)
void InsertionSort(pq *head){
    pq *sl = pq_create();
    pq *current = pq_create();
    current = *head;
    pq *next = pq_create();
    // go through list and insert each into a new sorted list
    while (current != NULL) {
        next = current->next;
        current->prev = current->next = NULL;
        sInsert(&sl, current); // put node in sorted list
        current = next;
    }
    *head = sl; // new head pointer points to head of sl
}

void sInsert(pq** head, pq* newNode){
    pq *current = pq_create();
    // if list null head becomes node to be sorted
    if (*head == NULL){
        *head = newNode;
    }
    else if ((*head)->data >= newNode->data) { // if the newNode's is first
        newNode->next = *head;
        newNode->next->prev = newNode;
        *head = newNode;
    }
    else { // find where to insert new node
        current = *head;
        while (current->next != NULL && 
              current->next->data < newNode->data)
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