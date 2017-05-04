/**
 * Merge_Sort in C
 *
 * @Author: Phoenix
 */

#include <stdio.h>
#include <stdlib.h>

#define LENGTH(array) ( (sizeof(array)) / (sizeof(array[0])) )

void merge_array(int a[], int start, int mid, int end)
{
    int *tmp = (int *)malloc((end-start+1)*sizeof(int));    
    int i = start;            
    int j = mid + 1;        
    int k = 0;                

    while(i <= mid && j <= end)
    {
        if (a[i] <= a[j])
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];
    }

    while(i <= mid)
        tmp[k++] = a[i++];

    while(j <= end)
        tmp[k++] = a[j++];

    for (i = 0; i < k; i++)
        a[start + i] = tmp[i];

    free(tmp);
}

void merge_sort_up2down(int a[], int start, int end)
{
    if(a==NULL || start >= end)
        return ;

    int mid = (end + start)/2;
    merge_sort_up2down(a, start, mid); 
    merge_sort_up2down(a, mid+1, end); 

    merge_array(a, start, mid, end);
}


void merge_groups(int a[], int len, int slen)
{
    int i;
    int twolen = 2 * slen;    

    for(i = 0; i + 2 * slen - 1 < len; i += (2 * slen))
    {
        merge_array(a, i, i + slen - 1, i + 2 * slen - 1);
    }

    if ( i + slen - 1 < len - 1)
    {
        merge_array(a, i, i + slen - 1, len - 1);
    }
}

void merge_sort_down2up(int a[], int len)
{
    int n;

    if (a==NULL || len<=0)
        return ;

    for(n = 1; n < len; n*=2)
        merge_groups(a, len, n);
}

void main()
{
    int i;
    int a[] = {80,30,60,40,20,10,50,70};
    int ilen = LENGTH(a);

    printf("before sort:\n");
    for (i=0; i<ilen; i++)
        printf("%d ", a[i]);

    merge_sort_up2down(a, 0, ilen-1);        
    //merge_sort_down2up(a, ilen);            

    printf("\nafter  sort:\n");
    for (i=0; i<ilen; i++)
        printf("%d ", a[i]);
    printf("\n");
}
