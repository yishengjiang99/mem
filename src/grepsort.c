#include <stdio.h>

#include "amem.h"
#define MAXLINE 10000
#define MAX_LINE_LENGTH 82

char *lineptr[MAXLINE];
void astrcp(char *from, char *to);

int main(int argc, char *argv[]) {
  int len, nlines = 0;
  char line[MAX_LINE_LENGTH];
  char *p;
  while ((len = agetline(line, MAX_LINE_LENGTH)) > 0) {
    p = alloc(len + 1);
    if (p == NULL) return -1;
    p[len] = '\0';
    astrcp(p, line);
    lineptr[nlines++] = p;
  }
  if (nlines < 0) {
    perror("oom");
    return 1;
  }
  qqsort((void **)lineptr, 0, nlines - 1);
  for (int i = 0; i < nlines; i++) printf("%s\n", lineptr[i]);
  return 0;
}