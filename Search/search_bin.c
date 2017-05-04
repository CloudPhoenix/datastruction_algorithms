#include <stdio.h>

int Search_Bin(int ST[], int len, int key) {
  int low = 0;
  int high = len - 1;

  while(low <= high) {
    int mid = (low + high)/2;
    if(ST[mid] == key) return (mid + 1);
    else if(ST[mid] < key) low = mid + 1;
    else high = mid - 1;
  }
  return 0;
}

int main()
{
  int ST[10] = {1,2,3,4,5,6,7,8,9,10};

  int key = 9;
  int index = Search_Bin(ST, 10, key);
  if(key == 0) printf("The key %d not found.\n", key);
  else printf("The key %d is the %dth value.\n", key, index);

  return 1;
}
