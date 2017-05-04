#include <stdio.h>
#include "stack.h"

int bracketmatch(char *str) {
  SqStack_c S;
  InitStack_c(S);

  printf("%s", *str);
  char ch = *str;
  char tmp;
  while(ch != '\0') {
    switch(ch) {
      case '(':
        Push_c(S, ch);
        str++;
        break;
      case '[':
        Push_c(S, ch);
        str++;
        break;
      case ')':
        Pop_c(S, tmp);
        while(tmp != '(') Pop_c(S, tmp);
        if(S.base == S.top) { printf("Format error.\n"); return FAIL; }
        str++;
        break;
      case ']':
        Pop_c(S, tmp);
        while(tmp != '[') Pop_c(S, tmp);
        if(S.base == S.top) { printf("Format error.\n"); return FAIL; }
        str++;
        break;
      default:
        str++;
    }
  }
  if(S.base != S.top) { printf("Format error.\n"); return FAIL; }
  printf("All brackets match.\n");

  DestroyStack_c(S);
  return 1;
}

int main()
{
  char str[10] = "[(";
  bracketmatch(str);
  printf("test\n");

  return 1;
}
