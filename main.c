//edited to remain as project 2 described - apparently no changes are needed to this file
//i still have copies of last edits in case we need to revert

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "pq.h"

int main(int argc, char *argv[])
{
  int i;
  const int n = 1000;
  double *v = malloc(sizeof(double)*n);
  double **p = malloc(sizeof(double*)*n);
  struct pq *mypq;

  /* init */
  srand(time(NULL));
  mypq = pq_create();
  for (i = 0; i < n; i++) {
    v[i] = drand48();
  }

  /* begin sort */
  for (i = 0; i < n; i++) pq_push(mypq, v[i], (void*)v[i]);
  for (i = 0; i < n; i++) v[i] = pq_pop(mypq);
  /* end sort */

  for (i = 0; i < n; i++) {
    if (p[i]) printf("%g\n", v[i]);
  }

  free(v);
  return 0;
}
