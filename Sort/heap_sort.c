/**
 * Heap_Sort in C
 *
 * @Author: Phoenix
 */

#include <stdio.h>

#define LENGTH(array) ( (sizeof(array)) / (sizeof(array[0])) )
#define swap(a,b) (a^=b,b^=a,a^=b)

void maxheap_adjustdown(int a[], int start, int end)
{
  int i = start;            
  int j = 2*i + 1;        
  int tmp = a[i];           
  while (j <= end)
  {
    if ( j + 1 < end && a[j] < a[j+1])
      j++;        
    if (tmp >= a[j])
      break;        

    a[i] = a[j];
    a[j]= tmp;
    i = j;
    j = 2 * i + 1;
  }
}

void heap_sort_asc(int a[], int n)
{
  int i;

  for (i = n / 2 - 1; i >= 0; i--)
    maxheap_adjustdown(a, i, n-1);

  for (i = n - 1; i > 0; i--)
  {
    swap(a[0], a[i]);
    maxheap_adjustdown(a, 0, i-1);
  }
}

void minheap_adjustdown(int a[], int start, int end)
{
  int i = start;            
  int j = 2*i + 1;        
  int tmp = a[i];           
  while (j <= end)
  {
    if ( j + 1 < end && a[j] > a[j+1])
      j++;        
    if (tmp <= a[j])
      break;        

    a[i] = a[j];
    a[j]= tmp;
    i = j;
    j = 2 * i + 1;
  }
}

void heap_sort_desc(int a[], int n)
{
  int i;

  for (i = n / 2 - 1; i >= 0; i--)
    minheap_adjustdown(a, i, n-1);

  for (i = n - 1; i > 0; i--)
  {
    swap(a[0], a[i]);
    minheap_adjustdown(a, 0, i-1);
  }
}

int main()
{
  int i;
  int a[] = {20,30,90,40,70,110,60,10,100,50,80};
  int len = LENGTH(a);

  printf("before sort: \n");
  for (i=0; i<len; i++)
    printf("%d ", a[i]);

  heap_sort_asc(a, len);            

  printf("\nafter asc sort:\n");
  for (i=0; i<len; i++)
    printf("%d ", a[i]);

  heap_sort_desc(a, len);        
  printf("\nafter desc sort:\n");
  for (i=0; i<len; i++)
    printf("%d ", a[i]);

  return 1;
}
