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
  int input = 0; 

    /* init */
    srand(time(NULL));
    mypq = pq_create();
    for (i = 0; i < n; i++) {
      v[i] = drand48();
    }

    printf("%s", "Choose an option, 0 is the base main.c implementation. \n (1) linked list \n (2) heap. \n");
    scanf("&d", &input);

    if(input = 1){ // linked list
      for (i = 0; i < n; i++){
        struct pq *newNode = pq_create();
        newNode->value = i;
        newNode->next = NULL;
        newNode->Previous = NULL;
        
        // INSERTION SORT
        sInsert(mypq, newNode);
      } 
    }
    else if(input = 2){ // heap

    }
    else{ //base / given main.c sort
      /* begin sort */
      for (i = 0; i < n; i++){
        pq_push(mypq, v[i], (void*)v[i]);
      } 
      for (i = 0; i < n; i++){
        v[i] = pq_pop(mypq);
      } 
      /* end sort */
    }

    for (i = 0; i < n; i++) {
    printf("%g\n", v[i]);
    }
    free(v);
    return 0;

}
