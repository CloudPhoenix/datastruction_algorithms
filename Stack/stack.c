#include <stdio.h>
#include "stack.h"

int main()
{
  SqStack_i S1;
  SqStack_c Sc;

  InitStack_i(S1);
  InitStack_c(Sc);
  Push_i(S1, 1);
  Push_i(S1, 2);
  Push_i(S1, 3);
  Push_c(Sc, 'a');
  Push_c(Sc, 'b');
  Push_c(Sc, 'c');

  int tmp = GetTop_i(S1);
  printf("%d\n", tmp);

  tmp = Pop_i(S1);
  printf("%d\n", tmp);

  TraverseStack_i(S1);
  TraverseStack_c(Sc);

  return 1;
}
