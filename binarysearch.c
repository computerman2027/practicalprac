#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarysearch(int *arr, int low, int high, int val)
{
    if (low > high)
        return -1;
    int mid = low + ((high - low) / 2);
    if (arr[mid] == val)
    {
        return mid;
    }
    else if (arr[mid] < val)
    {
        return binarysearch(arr, mid + 1, high, val);
    }
    else
    {
        return binarysearch(arr, low, mid-1, val);
    }
}

int main()
{
    int n, i,val;
    printf("Enter size of array : ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter values : ");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter value to be searched : ");
    scanf("%d",&val);

    clock_t start =clock();
    int ans=binarysearch(arr,0,n-1,val);
    clock_t end =clock();

    double timetaken=((double)(end-start))/CLOCKS_PER_SEC;

    printf("Index found = %d\n",ans);
    printf("Time = %lf s\n",timetaken);
    return 0;
}