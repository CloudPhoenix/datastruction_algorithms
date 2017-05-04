#include <stdio.h>
#include "stack.h"

int conversion(int num, int base) {
  SqStack_i S;
  InitStack_i(S);

  while(num) {
    Push_i(S, num % base);
    num = num / base;
  }
  while(S.top != S.base) printf("%d ", Pop_i(S));

  return 1;
}

int main()
{
  conversion(5, 2);

  return 1;
}
