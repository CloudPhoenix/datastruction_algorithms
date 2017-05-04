/**
 * Bubble_Sort in C
 *
 * @Author: Phoenix
 */

#include <stdio.h>

#define LENGTH(array) ( (sizeof(array)) / (sizeof(array[0])) )
#define swap(a,b)    (a^=b,b^=a,a^=b)

void bubble_sort(int a[], int n)
{
  int i,j;

  for (i=n-1; i>0; i--)
  {
    for (j=0; j<i; j++)
    {
      if (a[j] > a[j+1])
        swap(a[j], a[j+1]);
    }
  }
}

void bubble_sort_improved(int a[], int n)
{
  int i,j;
  int flag;                 

  for (i=n-1; i>0; i--)
  {
    flag = 0;            

    for (j=0; j<i; j++)
    {
      if (a[j] > a[j+1])
      {
        swap(a[j], a[j+1]);
        flag = 1;    
      }
    }

    if (flag==0)
      break;            
  }
}

int main()
{
  int i;
  int a[] = {20,40,30,10,60,50};
  int len = LENGTH(a);

  printf("before sort:\n");
  for (i=0; i<len; i++)
    printf("%d ", a[i]);

  //bubble_sort(a, len);
  bubble_sort_improved(a, len);

  printf("\nafter  sort:\n");
  for (i=0; i<len; i++)
    printf("%d ", a[i]);

  return 1;
}
