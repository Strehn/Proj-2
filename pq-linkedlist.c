// noah rodgers, sydney petrehn, and james turne
// code using linked list and insertion sort

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include “pq.h”

/* Allocates and initializes a new pq */
pq* pq_create();

/* Adds value to pq based on numerical order of key */
// Change this to implement insertion sort
void pq_push(pq *head, double key, void *value){
    pq* temp = head;
    double s_num = key; // number to look for
    int last = 0;

    // insertion sort
    // step through list and add num
    while(temp->num <= s_num){ // as soon as temp->num > num stop
        if(temp->num == s_num){
            return; // do nothing
        }
        if(temp->Next == NULL){ // last node in list
            last = 1;
            break;
        }
        temp = temp->Next;
    }

    // insert the node
    pq *node = (struct Node*) malloc(sizeof(struct Node));
    node->num = value;
    if(last = 1){ // add to end of list
        node->Next = NULL;
        node->Previous = temp;
        temp->Next = node;
    }
    else{
        // inset between two nodes
        node->Next = temp->Next;
        node->Previous = temp;
        temp->Next = node;
    }
}

/* Returns value from pq having the minimum key */
void* pq_pop(pq *head)
{
    if(head == NULL){
        // do nothing
        return;
    }
    // temp nodes to step through list and remove num
    s* temp = head;
    struct Node* previous = NULL;
    // step through LL
    while(temp->num != num){
        // no match
        if(temp->Next == NULL){
            return;
        }
        else{
            previous = temp;
            temp = temp->Next;
        }
    }
    // first node in list so head becomes next
    if(temp == head){
        head = head->Next;
    }
    else{
        previous->Next = temp->Next;
        // remove current node
    }
}

/* Deallocates (frees) pq. Shallow destruction,
meaning nodes in the pq are not recursively freed. */
void pq_destroy();
