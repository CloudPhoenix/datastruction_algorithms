#include <stdio.h>

int partition(int a[], int low, int high) {
  int key = a[low];

  while(low < high) {
    while((low < high) && a[high] >= key) high--;
    a[low] = a[high];
    while((low < high) && a[low] <= key) low++;
    a[high] = a[low];
  }
  a[low] = key;

  return low;
}

void quick_sort(int a[], int low, int high) {
  if(low < high) {
    int tmp = partition(a, low, high);
    quick_sort(a, low, tmp - 1);
    quick_sort(a, tmp + 1, high);
  }
}

int main() 
{
  int a[7] = {49, 38, 65, 97, 76, 13, 27};
  int len = 7;

  quick_sort(a, 0, 6);

  for(int i; i<len; i++)
    printf("%d ", a[i]);
}

