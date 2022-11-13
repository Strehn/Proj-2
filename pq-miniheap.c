// noah rodgers, sydney petrehn, and james turner
// code implementing a min-heap

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
//#include "pq.h"

//min heap
struct Mheap{
    int *arr; // array to hold the binary tree
    int size;
};

/*       root   <- minimum num
   parent    parent
 node node  node node <- largest nums
represented as an array
[root, parent, parent, node, node, node, node,]
root     = arr [0]
current  = arr[i]
parent   = arr[(i-1)/2]
left c   = arr[(2*i)+1]
right c  = arr[(2*i)+2]
*/

typedef struct Mheap Mheap;

int parent(int i){
    return (i-1)/2;
}

Mheap* heap_create()
{
  return (Mheap*)malloc(sizeof(Mheap));
}

void insertHeap(Mheap *heap, int num){
    heap->arr[heap->size - 1] = num;
    int current = heap->size - 1;
    int temp = 0;
    while(current > 0 && heap->arr[parent(current)] > heap->arr[current]){
        temp = heap->arr[parent(current)];
        heap->arr[parent(current)] = heap->arr[current];
        heap->arr[current] = temp;
        current = parent(current);
    }
}

void PrintHeap(Mheap *heap){
  int i = 0; 
  printf("\n Data in heap :\n");
  for(i = 0; i < 1000; i++){
    printf("%d ", heap->arr[i]);
  }
}
