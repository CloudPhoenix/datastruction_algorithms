#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define FAIL 0

typedef struct LNode{
  int data;
  struct LNode *next;
}LNode, *LinkList;

int CreateListR_L(LinkList &L, int n) {
  L = (LinkList)malloc(sizeof(LNode));
  if(!L) exit(-1);
  L->next = NULL;
  LNode *q = L; 
  int tmp = 0;
  for(int i=0; i<n; i++) {
    LNode *p = (LinkList)malloc(sizeof(LNode));
    if(!p) exit(-1);
    scanf("%d", &tmp);
    p->data = tmp;
    q->next = p;
    q = p;
    p->next = NULL;
  }
}

int CreateListF_L(LinkList &L, int n) {
  L = (LinkList)malloc(sizeof(LNode));
  if(!L) exit(-1);
  L->next = NULL;
  L->data = 0;
  int tmp = 0;
  for(int i=0; i<n; i++) {
    LNode *p = (LinkList)malloc(sizeof(LNode));
    if(!p) exit(-1);
    scanf("%d", &tmp);
    p->data = tmp;
    p->next = L->next;
    L->next = p;
  }
  return 1; 
}

int GetElem_L(LinkList L, int i) {
  LNode *p = L->next;
  if(!p) return 0;
  int k = 1;
  while(p && k < i) {
    p = p->next;
    k++;
  }
  return p->data;
}

int ListInsert_L(LinkList &L, int i, int e) {
  if(i < 1) return 0;
  LNode *p = L;
  LNode *q = (LinkList)malloc(sizeof(LNode));
  if(!q) exit(-1);
  q->data = e;
  int k = 1;
  while((p->next) && (k < i)) {
    p = p->next;
    k++;
  }
  if(!(p->next)) {
    p->next = q;
    q->next = NULL;
  } 
  else {
    q->next = p->next;
    p->next = q;
  }
  return 1;
}

int ListDelete_L(LinkList &L, int i) {
  if(i < 1) return 0;
  LNode *p = L;
  int k = 1;
  while((p->next) && (k < i)) {
    p = p->next;
    k++;
  }
  if(!(p->next)) {
    printf(" INPUT i is out of range.\n");
    return 0;
  }
  LNode *q = p->next;
  if(!(q->next)) {
    p->next = NULL;
    free(q);
  }
  else {
    q = p->next;
    p->next = q->next;
    free(q);
  }
  return 1; 
}

int ListTraverse_L(LinkList L) {
  if(!L) return 0;
  LNode *p = L->next;
  while(p) {
    printf("%d ", p->data);
    p = p->next;
  }
  printf("\n");
}

