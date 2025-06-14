#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comp(const void* a, const void* b)
{
    int* x = *(int**)a;
    int* y = *(int**)b;

    if(x[1]<y[1])
    return -1;
    else if(x[1]>y[1])
    return 1;
    else if(x[1]=y[1] && x[0]>y[0])
    return 1;
    else if(x[1]=y[1] && x[0]<y[0])
    return 0;
    else
    return 0;

}

int* actsel(int** arr, int n)
{
    qsort(arr,n,sizeof(arr[0]),comp);

    int* ans=(int*)calloc(n,sizeof(int));
    int k =1,i;
    ans[arr[0][2]]=1;
    int endtime=arr[0][1];
    k++;

    for(i=1;i<n;i++)
    {
        if(arr[i][0]>endtime)
        {
            ans[arr[i][2]]=k;
            k++;
            endtime=arr[i][1];
        }
    }
    return ans;
}

// 0 - start time
// 1 - end time
// 2 - index
int main()
{
    int n, i;
    printf("Enter number of activity : ");
    scanf("%d", &n);

    int **arr = (int **)malloc(n * sizeof(int));
    printf("Enter Data : ");

    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(3 * sizeof(int));
        arr[i][2] = i;
        printf("Enter start time : ");
        scanf("%d", &arr[i][0]);
        printf("Enter end time : ");
        scanf("%d", &arr[i][1]);
    }


    clock_t start = clock();
    int *ans = actsel(arr,n);
    clock_t end = clock();

    double timetaken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Answer vector : ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", ans[i]);
    }
    printf("\n");

    printf("Time = %lf s\n", timetaken);
    return 0;
}