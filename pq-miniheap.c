// noah rodgers, sydney petrehn, and james turner
// code implementing a mini heap

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include “pq.h”

//min heap
struct Mheap{
    int *arr; // array to hold the binary tree
    int size;
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
int leftc(int i){
    return (2*i + 1);
}
int rightc(int i){
    return (2*i + 2);
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

int main(int argc, char *argv[])
{
  int i;
  const int n = 1000;
  double *v = malloc(sizeof(double)*n);
  double **p = malloc(sizeof(double*)*n);
  pq *mypq;
  Mheap *heap;

  /* init */
  srand48(time(NULL));
  mypq = pq_create();
  for (i = 0; i < n; i++) {
    v[i] = drand48();
    p[i] = &v[i];
  }

  /* begin sort */
  for (i = 0; i < n; i++) {
    pq_push(mypq, v[i], (void*)p[i]);
    insertHeap(heap, i);
  }
   
  // insert miniheap conversion here

  /* end sort */

  for (i = 0; i < n; i++) {
    if (p[i]) printf("%g\n", *p[i]);
  }

  pq_destroy(mypq);

  free(v);
  free(p);
  return 0;
}


