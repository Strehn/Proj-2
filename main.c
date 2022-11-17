#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "pq.h"

int main(int argc, char *argv[])
{
  int i = 0;
  const int n = 1000;
  double *v = malloc(sizeof(double)*n);
  struct pq *mypq;
  mypq = pq_create();

    /* init */
    srand(time(NULL));
    mypq = pq_create();
    for (i = 0; i < n; i++) {
      v[i] = drand48();
    }
//base /  ----- given main.c sort -----
      /* begin sort */
      
      for (i = 0; i < n; i++){
        pq_push(mypq, v[i], (void*)v[i]); //gave error in compilation so added (void*) to match argument from push_pq in header file
      } 
      for (i = 0; i < n; i++){
        v[i] = pq_pop(mypq);
      } 
      for (i = 0; i < n; i++) {
      printf("%g\n", v[i]);
      }
      free(v);
      /* end sort */
      
    
    return 0;
}
