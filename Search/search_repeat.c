#include <stdio.h>

int Search_Bin(int ST[], int len) {
  int low = 0;
  int high = len - 1;

  while(low <= high) {
    int mid = (low + high)/2;
    if(ST[mid] == (mid + 1)) low = mid + 1;
    if(ST[mid] < (mid + 1)) high = mid - 1;
  }
  if(low >= high) return ST[low];
  return 0;
}

int main()
{
  int ST[11] = {1,1,2,3,4,5,6,7,8,9,10};

  int len = 11;
  int repeat = Search_Bin(ST, len);
  printf("The repeat is %d.\n", repeat);

  return 1;
}
