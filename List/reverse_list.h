#include <stdio.h>
#include "linklist.h"

int ReverseList_L(LinkList &L) {
  if(!L) return 0;
  LNode *prior = L->next;
  LNode *pcur = prior->next;
  prior->next = NULL;
  while(pcur) {
    LNode *ptmp = pcur->next;
    L->next = pcur;
    pcur->next = prior;
    prior = pcur;
    pcur = ptmp;
  }
  return 1;
}

