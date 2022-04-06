#include <stdlib.h>

#include "amem.h"
void _qsort(void *v[], int left, int right, int (*comp)(char *, char *));
int astrcmp(char *s, char *t);
void qqsort(void *v[], int left, int right) { _qsort(v, left, right, astrcmp); }
void _qsort(void *v[], int left, int right, int (*comp)(char *, char *)) {
  int i, last;
  if (left >= right) /* do nothing if array contains */

    return; /* fewer than two elements */

  swap(v, left, (left + right) / 2);

  last = left;

  for (i = left + 1; i <= right; i++)

    if ((*comp)(v[i], v[left]) < 0) swap(v, ++last, i);

  swap(v, left, last);

  _qsort(v, left, last - 1, comp);

  _qsort(v, last + 1, right, comp);
}

void swap(void *v[], int i, int j) {
  char *temp;

  temp = v[i];

  v[i] = v[j];

  v[j] = temp;
}

/* numcmp:  compare s1 and s2 numerically */

int numcmp(char *s1, char *s2) {
  double v1, v2;

  v1 = atof(s1);

  v2 = atof(s2);

  if (v1 < v2)

    return -1;

  else if (v1 > v2)

    return 1;

  else

    return 0;
}

int astrcmp(char *s, char *t) {
  int i;

  for (i = 0; s[i] == t[i]; i++)

    if (s[i] == '\0') return 0;

  return s[i] - t[i];
}