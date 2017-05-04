/**
 * Quick_Sort in C
 *
 * @Author: Phoenix
 */

#include <stdio.h>

#define LENGTH(array) ( (sizeof(array)) / (sizeof(array[0])) )

void quick_sort(int a[], int low, int high)
{
    if (low < high)
    {
        int ilow, jhigh, key;
        ilow = low;
        jhigh = high;
        key = a[ilow];
        while (ilow < jhigh)
        {
            while(ilow < jhigh && a[jhigh] > key) jhigh--;    
            if(ilow < jhigh)    a[ilow++] = a[jhigh];
            while(ilow < jhigh && a[ilow] < key) ilow++; 
            if(ilow < jhigh)    a[jhigh--] = a[ilow];
        }
        a[ilow] = key;
        quick_sort(a, low, ilow-1);    
        quick_sort(a, ilow+1, high);   
    }
}

void main()
{
    int i;
    int a[] = {30,40,60,10,20,50};
    int len = LENGTH(a);

    printf("before sort:\n");
    for (i=0; i<len; i++)
        printf("%d ", a[i]);

    quick_sort(a, 0, len-1);

    printf("\nafter  sort:\n");
    for (i=0; i<len; i++)
        printf("%d ", a[i]);
    printf("\n");
}
