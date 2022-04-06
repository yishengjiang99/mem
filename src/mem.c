#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "amem.h"

#define MEMSIZE (1 << 23)
static char allocbuf[MEMSIZE];
static char *allocp = &allocbuf[0];
char *alloc(int n) {
  ptrdiff_t diff = allocp - allocbuf;
  if (MEMSIZE - diff < n) {
    return 0;
  }
  allocp += n;
  return allocp - n;
}

int astrlen(char *str) {
  int len;
  for (len = 0; *str != '\0'; str++, len++)
    ;
  return len;
}

void astrcp(char *s, char *t) {
  int i;
  i = 0;
  while ((s[i] = t[i]) != '\0') i++;
}
int agetline(char *line, int max) {
  int c, i;
  for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    line[i] = c;
  }
  if (c == '\n') {
    line[i] = '\0';
    ++i;
  }
  line[i] = '\0';
  return i;
}
void swapp(int *px, int *py) /* interchange *px and *py */
{
  int temp;

  temp = *px;

  *px = *py;

  *py = temp;
}
