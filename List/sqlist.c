#include <stdio.h>
#include "sqlist.h"
#include "merge_sqlist.h"

int main()
{
  SqList L1, L2, L3;
  InitList_Sq(&L1);
  InitList_Sq(&L2);
  InitList_Sq(&L3);

  ListInsert_Sq(&L1, 1, 5);
  ListInsert_Sq(&L1, 1, 4);
  ListInsert_Sq(&L1, 1, 2);
  ListInsert_Sq(&L2, 1, 7);
  ListInsert_Sq(&L2, 1, 5);
  ListInsert_Sq(&L2, 1, 2);
  
  MergeList_Sq(L1, L2, &L3);

  ListTraverse_Sq(L1);
  ListTraverse_Sq(L2);
  ListTraverse_Sq(L3);

  return 1;
}

