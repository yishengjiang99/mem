#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "amem.h"
char *alloc(int n);
int astrlen(char *str);
void astrcp(char *from, char *to);

int main(int argc, char *argv[]) {
  char *pt = alloc(1);
  float *pt2 = (float *)alloc(4);
  ptrdiff_t diff = (char *)pt2 - pt;
  assert(diff == 1);
  int a = 2, b = 3;
  swapp(&a, &b);
  assert(a == 3);
  assert(astrlen("1234") == 4);
  assert(astrlen("") == 0);
  char *aaa = "abc";
  char bbb[3];
  astrcp(aaa, bbb);
  assert(bbb[0] == 'a');
  char *linebig = alloc(5555);
  agetline(linebig, argc > 1 ? atoi(argv[1]) : 5);
  printf("getline %5s\n", linebig);
  return 0;
}