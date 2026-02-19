#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "amem.h"

int astrcmp(char *s, char *t);

int main(void) {
  /* astrcmp */
  assert(astrcmp("abc", "abc") == 0);
  assert(astrcmp("abc", "abd") < 0);
  assert(astrcmp("abd", "abc") > 0);
  assert(astrcmp("", "") == 0);
  assert(astrcmp("a", "") > 0);
  assert(astrcmp("", "a") < 0);

  /* swap */
  char *v[] = {"first", "second", "third"};
  swap((void **)v, 0, 2);
  assert(astrcmp(v[0], "third") == 0);
  assert(astrcmp(v[2], "first") == 0);

  /* qqsort */
  char *lines[] = {"banana", "apple", "cherry", "apricot"};
  qqsort((void **)lines, 0, 3);
  assert(astrcmp(lines[0], "apple") == 0);
  assert(astrcmp(lines[1], "apricot") == 0);
  assert(astrcmp(lines[2], "banana") == 0);
  assert(astrcmp(lines[3], "cherry") == 0);

  /* qqsort single element */
  char *single[] = {"only"};
  qqsort((void **)single, 0, 0);
  assert(astrcmp(single[0], "only") == 0);

  printf("all sort tests passed\n");
  return 0;
}
