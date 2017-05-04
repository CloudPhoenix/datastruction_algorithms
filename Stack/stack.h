#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define OK 1
#define FAIL 0

typedef struct {
  int *top;
  int *base;
  int stacksize;
}SqStack_i;

typedef struct {
  char *top;
  char *base;
  int stacksize;
}SqStack_c;

int InitStack_i(SqStack_i &S) {
  S.top = S.base = (int *)malloc(STACK_INIT_SIZE * sizeof(int));
  if(!S.top) exit(-1);
  memset(S.base, 0, STACK_INIT_SIZE * sizeof(int));
  S.stacksize = STACK_INIT_SIZE;
  return OK;
}

int InitStack_c(SqStack_c &S) {
  S.top = S.base = (char *)malloc(STACK_INIT_SIZE * sizeof(char));
  if(!S.top) exit(-1);
  memset(S.base, 0, STACK_INIT_SIZE * sizeof(char));
  S.stacksize = STACK_INIT_SIZE;
  return OK;
}

int DestroyStack_i(SqStack_i &S) {
  free(S.base);

  return 1;
}

int DestroyStack_c(SqStack_c &S) {
  free(S.base);

  return 1;
}

int GetTop_i(SqStack_i S) {
  if(S.top == S.base) {
    printf("The Stack is empty.\n");
    return 0;
  }
  int tmp = *(S.top - 1);

  return tmp;
}

char GetTop_c(SqStack_c S) {
  if(S.top == S.base) {
    printf("The Stack is empty.\n");
    return 0;
  }
  char tmp = *(S.top - 1);

  return tmp;
}

int Push_i(SqStack_i &S, int e) {
  if((S.top - S.base) >= S.stacksize) {
    S.base = (int *)realloc(S.base, (STACK_INIT_SIZE + STACKINCREMENT) * sizeof(int));
    if(!S.base) exit(-1);
    memset(S.base, 0, (STACK_INIT_SIZE + STACKINCREMENT) * sizeof(int));
    S.top = S.base + S.stacksize;
    S.stacksize += STACKINCREMENT;
  }
  *S.top++ = e;

  return OK;
}

int Push_c(SqStack_c &S, char e) {
  if((S.top - S.base) >= S.stacksize) {
    S.base = (char *)realloc(S.base, (STACK_INIT_SIZE + STACKINCREMENT) * sizeof(char));
    if(!S.base) exit(-1);
    memset(S.base, 0, (STACK_INIT_SIZE + STACKINCREMENT) * sizeof(char));
    S.top = S.base + S.stacksize;
    S.stacksize += STACKINCREMENT;
  }
  *S.top++ = e;

  return OK;
}

int Pop_i(SqStack_i &S) {
  if(S.top == S.base) {
    printf("The Stack is empty.\n");
    return 0;
  }
  int tmp = *(--S.top);

  return tmp;
}

int Pop_c(SqStack_c &S, char &ch) {
  if(S.top == S.base) {
    printf("The Stack is empty.\n");
    return 0;
  }
  ch = *(--S.top);

  return OK;
}

int TraverseStack_i(SqStack_i S) {
  if(S.top == S.base) {
    printf("The Stack is empty.\n");
    return 0;
  }
  int *tmp = S.top;
  while(tmp != S.base) {
    tmp--;
    printf("%d ", *tmp);
  }

  return OK;
} 

int TraverseStack_c(SqStack_c S) {
  if(S.top == S.base) {
    printf("The Stack is empty.\n");
    return 0;
  }
  char *tmp = S.top;
  while(tmp != S.base) {
    tmp--;
    printf("%c ", *tmp);
  }

  return OK;
} 

