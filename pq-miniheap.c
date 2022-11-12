// noah rodgers, sydney petrehn, and james turner
// code implementing a min-heap
// removed #include pq-null and main function

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "pq.h"

//min heap
struct Mheap{
    int *arr; // array to hold the binary tree
    int size; // array size
}

/*       root   <- minimum num
   parent    parent
 node node  node node <- largest num\
represented as an array
[min/root   parent parent node node node node]
root     = arr [0]
current  = arr[i]
parent   = arr[(i-1)/2]
left c   = arr[(2*i)+1]
right c  = arr[(2*i)+2]
*/

int parent(int i){
    return (i-1)/2;
}

void insertHeap(Mheap *heap, int num){
    heap->arr[heap->size - 1] = num;
    int current = heap->size - 1;
    int temp = 0;
    while(current > 0 && 
    heap->arr[parent(current)] > heap->arr[current]){
        temp = heap->arr[parent(current)];
        heap->arr[parent(current)] = heap->arr[current];
        heap->arr[current] = temp;
        current = parent(current);
    }
}

