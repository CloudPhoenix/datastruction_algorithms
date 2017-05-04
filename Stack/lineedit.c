#include <stdio.h>
#include "stack.h"

int LineEdit() {
  SqStack_c S;
  InitStack_c(S);

  char ch = getchar();
  char tmp;
  while(ch != EOF) {
    while(ch != EOF && ch != '\n') {
      switch(ch) {
        case '#':
          Pop_c(S, tmp);
          break;
        case '@':
          while(S.top != S.base) Pop_c(S, tmp);
          break;
        default:
          Push_c(S, ch);
      }
      ch = getchar();
    }
    TraverseStack_c(S);
  }
  DestroyStack_c(S);

  return 1;
}

int main()
{
  LineEdit();

  return 1;
}
