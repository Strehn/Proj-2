#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "pq.h"
#include "pq-linkedlist.c"
#include "pq-miniheap.c"

int main(int argc, char *argv[])
{
  int i = 0;
  const int n = 1000;
  double *v = malloc(sizeof(double)*n);
  struct pq *mypq;
  mypq = pq_create();
  struct Mheap *heap;
  heap = heap_create();
  int input = 0; 

    /* init */
    srand(time(NULL));
    mypq = pq_create();
    for (i = 0; i < n; i++) {
      v[i] = drand48();
    }

    printf("%s", "Choose an option, 0 is the base main.c implementation. \n (1) linked list \n (2) heap. \n");
    scanf("%d", &input);

    if(input == 1){ // ----- linked list -----
      for (i = 0; i < n; i++){
        struct pq *newNode = pq_create();
        newNode->num = i;
        newNode->Next = NULL;
        newNode->Previous = NULL;
        // INSERTION SORT
        sInsert(mypq, newNode);
      } 
      PrintLL(mypq); // print the data in the list
    }
    else if(input == 2){ // ----- heap -----
      heap->size = 1;
      heap->arr = new int[n];
      for (i = 0; i < n; i++){
        insertHeap(heap, i);
      }
      // print the data in the heap
      PrintHeap(heap);
    }
    else{ //base /  ----- given main.c sort -----
      /* begin sort */
      /*
      for (i = 0; i < n; i++){
        pq_push(mypq, v[i], v[i]);
      } 
      for (i = 0; i < n; i++){
        v[i] = pq_pop(mypq);
      } 
      for (i = 0; i < n; i++) {
      printf("%g\n", v[i]);
      }
      free(v);
      /* end sort */
      
    }
    return 0;
}
