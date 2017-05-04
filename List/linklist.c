#include <stdio.h>
#include "linklist.h"
#include "merge_list.h"
#include "reverse_list.h"

int main()
{
  LinkList L1, L2, L3;
  CreateListR_L(L1, 5);
  CreateListR_L(L2, 3);

  MergeList_L(L1, L2, L3);

  ListTraverse_L(L3);
  //ReverseList_L(L1);
  ListTraverse_L(L1);
  ListTraverse_L(L2);

  return 1;
}
