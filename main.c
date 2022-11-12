#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "pq.h"
#include "pq-null.c"

int main(int argc, char *argv[])
{
  int i;
  const int n = 1000;
  double *v = malloc(sizeof(double)*n);
  double **p = malloc(sizeof(double*)*n);
  struct pq * mypq;

  /* init */
  srand48(time(NULL));
  mypq = pq_create();
  for (i = 0; i < n; i++) {
    v[i] = drand48();
    p[i] = &v[i];
  }

  /* begin sort */
  for (i = 0; i < n; i++) pq_push(mypq, v[i], (void*)p[i]);
  for (i = 0; i < n; i++) p[i] = pq_pop(mypq);
  /* end sort */

  for (i = 0; i < n; i++) {
    if (p[i]) printf("%g\n", *p[i]);
  }

  pq_destroy(mypq);

  free(v);
  free(p);
  return 0;
}
