#include <stdio.h>

int Search_Lost(int ST[], int len) {
  int low = 0;
  int high = len - 1;

  while(low <= high) {
    int mid = (low + high)/2;
    if(ST[mid] == (mid + 1)) low = mid + 1;
    if(ST[mid] > (mid + 1)) high = mid - 1;
  }
  if(low >= high) return (low + 1); 
  return 0;
}

int main()
{
  int ST[10] = {1,2,3,4,5,6,7,8,10,11};
  int ST1[10] = {1,3,4,5,6,7,8,9,10,11};
  int ST2[10] = {2,3,4,5,6,7,8,9,10,11};
  int ST3[10] = {1,2,3,4,5,6,7,8,9,10};

  int len = 10;
  int lost = Search_Lost(ST1, len);
  printf("The lost is %d.\n", lost);

  return 1;
}
