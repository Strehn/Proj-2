#include <limits.h>
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// A structure to represent a linked list of nodes
struct Node {
    int num;
    struct Node* Previous;
    struct Node* Next;
};

// Function to add an item to stack.  It increases top by 1
// -------

// Change this to implement insertion sort

// -------
void push(int num, struct Node *head){
    // we know head will never be 0 in this function
    struct Node* temp = head; 
    int last = 0;
    // step through list and add num
    while(temp->num <= num){ // as soon as temp->num > num stop
        if(temp->num == num){
            return; // do nothing
        }
        if(temp->Next == NULL){ // last node in list
            last = 1;
            break;
        }
        temp = temp->Next;
    }

    struct Node *node = (struct Node*) malloc(sizeof(struct Node));
    node->num = num;
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

// Function to remove an item from stack.  It decreases top by 1
// -------

// Change this to implement insertion sort

// -------
void pop(int num, struct Node *head)
{
    if(head == NULL){
        // do nothing
        return;
    }
    // temp nodes to step through list and remove num
    struct Node* temp = head;
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

