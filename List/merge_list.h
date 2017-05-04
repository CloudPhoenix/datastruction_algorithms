#include <stdio.h>
#include "linklist.h"

int MergeList_L(LinkList La, LinkList Lb, LinkList &Lc) {
  if(!La) Lc = Lb;
  if(!Lb) Lc = La;

  LNode *pa = La->next;
  LNode *pb = Lb->next;
  LNode *pc = Lc = La;

  while(pa && pb) {
    if(pa->data <= pb->data) {
      pc->next = pa;
      pc = pa;
      pa = pa->next;
    } 
    else {
      pc->next = pb;
      pc = pb;
      pb = pb->next;
    }
  }
  pc->next = pa ? pa : pb;

  //free(Lb);
  return 1;
}

  while(pcur) {
    LNode *ptmp = pcur->next;
    L->next = pcur;
    pcur->next = prior;
    prior = pcur;
    pcur = ptmp;
  }
  return 1;
}
