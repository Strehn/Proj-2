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

void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void insertHeap(Mheap *heap, int num){
    int i = heap->size - 1;
    heap->arr[i] = num;

    while( i != 0 && heap->arr[parent(i)] > heap->arr[i]){
      swap(&heap->arr[i], &heap->arr[parent(i)]);
      i = parent(i);
    }
    heap->size++;
}

void PrintHeap(Mheap *heap){
  int i = 0; 
  printf("\n Data in heap :\n");
  for(i = 0; i < 1000; i++){
    printf("%d ", heap->arr[i]);
  }
}
