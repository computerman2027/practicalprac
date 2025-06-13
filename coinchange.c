#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int comp(const void *a, const void *b)
{
    int *arr1 = *(int **)a;
    int *arr2 = *(int **)b;
    if (arr1[0] > arr2[0])
        return -1;
    else if (arr1[0] < arr2[0])
        return 1;
    else
        return 0;
}

int *cchange(int **arr, int n, int target)
{
    qsort(arr, n, sizeof(arr[0]), comp);
    int i;
    int *ans = (int *)calloc(n, sizeof(int));
    for (i =0;i<n;i++)
    {
        ans[arr[i][1]]=target/arr[i][0];
        target=target%arr[i][0];
    }
    return ans;
}

int main()
{
    int n, i, target;
    printf("Enter no of denomination : ");
    scanf("%d", &n);

    int **arr = (int **)malloc(n * sizeof(int*));
    printf("Enter the denominations : ");
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(2 * sizeof(int));
        scanf("%d", &arr[i][0]);
        arr[i][1] = i;
    }

    printf("Enter target amount : ");
    scanf("%d", &target);

    clock_t start = clock();
    int *ans = cchange(arr, n, target);
    clock_t end = clock();

    double timetaken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Answer vector : ");
    for(i=0;i<n;i++)
    {
        printf("%d ",ans[i]);
    }
    printf("\n");

    printf("Time = %lf s\n", timetaken);
    return 0;
}