#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIST_INIT_SIZE 100 
#define LISTINCREMENT 10
#define TRUE 1
#define FALSE 0 

typedef struct{
  int * elem;
  int length;
  int listsize;
}SqList;

int InitList_Sq(SqList *L) {
  L->elem = (int *)malloc(LIST_INIT_SIZE * sizeof(int));
  if(!L->elem) {
    printf("malloc failed.\n");
    exit(-1);
  }
  memset(L->elem, 0, LIST_INIT_SIZE * sizeof(int));
  L->length = 0;
  L->listsize = LIST_INIT_SIZE;
  return 1;
}

int DestoryList_Sq(SqList *L) {
  if(!L->elem) {
    printf("The SqList L not exist.\n");
    exit(0);
  }
  free(L->elem);
  L->length = 0;
  L->listsize = 0;
  return 1;
}

int ClearList_Sq(SqList *L) {
  if(!L->elem) {
    printf("The SqList L not exist.\n");
    exit(0);;
  }
  memset(L->elem, 0, sizeof(L->elem));
  L->length = 0;
  L->listsize = LIST_INIT_SIZE;
  return 1;
}

int ListEmpty_Sq(SqList L) {
  return L.length == 0 ? TRUE : FALSE;
}

int ListLength_Sq(SqList L) {
  return L.length;
}

int GetElem_Sq(SqList L, int i, int e) {
  if(!L.elem) {
    printf("The SqList L not exist.\n");
    exit(0);
  }
  if(i >= 1 && i <= L.length) {
    printf("The GetElem i is out of range. 1 <= %d <= %d\n", i, L.length);
    exit(0);;
  }
  e = L.elem[i-1];
  return e; 
}

int LocateElem_Sq(SqList L, int e) {
  int locate_e = 0;
  int i = 0;
  if(!L.elem) {
    printf("The SqList L not exist.\n");
    exit(0);
  }
  while(i < (L.length-1)) {
    if(L.elem[i] == e)  locate_e = i + 1;
    i++;
  }
  if(i == L.length) {
    printf("The value e is not in L.\n");
    exit(0);
  }
  printf("The location of e is %d\n", locate_e);
  return locate_e;
}

int PriorElem(SqList L, int e, int pre_e) {
  if(!L.elem) {
    printf("The SqList L not exist.\n");
    exit(0);
  }
  int locate_e = LocateElem_Sq(L, e);
  if(locate_e == 0) {
    printf("The value e is not in L.\n");
    exit(0);
  }
  else if(locate_e == 0) {
    printf("The value e is the first one.\n");
    exit(0);
  }
  pre_e = locate_e - 1;
  return pre_e;
}

int NextElem(SqList L, int e, int next_e) {
  if(!L.elem) {
    printf("The SqList L not exist.\n");
    exit(0);
  }
  int locate_e = LocateElem_Sq(L, e);
  if(locate_e == 0) {
    printf("The value e is not in L.\n");
    exit(0);
  }
  else if(locate_e == L.length) {
    printf("The value e is the last one.\n");
    next_e = 0;
  }
  next_e= locate_e + 1;
  return next_e;
}

int ListInsert_Sq(SqList *L, int i, int e) {
  int k = 0;
  if(i < 1 || i > (L->length + 1)) exit(0);
  int *newbase = (int *)realloc(L->elem, (LIST_INIT_SIZE + LISTINCREMENT) * sizeof(int));   
  if(!newbase) {
    printf("realloc failed.\n");
    exit(-1);
  }
  L->elem = newbase;
  L->listsize += LISTINCREMENT;
  L->length++;
  for(k=L->length-1; k>=(i-1); k--) L->elem[k+1] = L->elem[k];
  L->elem[i-1] = e;
  return 1;
}

int ListDelete_Sq(SqList *L, int i, int e) {
  if(i < 1 || i > (L->length + 1)) exit(0);
  e = L->elem[i-1];
  for(int k=i; k<L->length; k++) L->elem[k-1] = L->elem[k];
  L->length -= 1;
  return 1;
}

int ListTraverse_Sq(SqList L) {
  if(!L.elem) {
    printf("The L.elem is null.\n");
    exit(0);
  }
  for(int i=0; i<L.length; i++) printf("%d ", L.elem[i]);
  printf("\n");
  return 1;
}

