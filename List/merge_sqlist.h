#include <stdio.h>
#include "sqlist.h"

int MergeList_Sq(SqList La, SqList Lb, SqList *Lc) {
  if(ListEmpty_Sq(La) && ListEmpty_Sq(Lb)) exit(0);
  int i, j, k;
  i = j = k = 0;
  Lc->length = La.length + Lb.length;
  while(i < La.length && j < Lb.length) {
    if(La.elem[i] <= Lb.elem[j]) Lc->elem[k++] = La.elem[i++];
    else Lc->elem[k++] = Lb.elem[j++];
  }
  while(i < La.length) Lc->elem[k++] = La.elem[i++];
  while(j < Lb.length) Lc->elem[k++] = Lb.elem[j++];

  return 1;
}

