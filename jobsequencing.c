#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int comp(const void* a, const void* b)
{
    int* x = *(int**)a;
    int* y = *(int**)b;

    // if(x[0]<y[0])
    // return 1;
    // return 0;
    return y[0] - x[0]; // descending order

}

int* jobscq(int** arr, int n)
{
    qsort(arr,n,sizeof(arr[0]),comp);
    int max=arr[0][1];

    int* ans=(int*)malloc((max+2)*sizeof(int));
    ans[0]=max;
    int i,totalprofit=0;
    for(i=1;i<=max;i++)
    {
        ans[i]=-1;
    }

    for(i=0;i<n;i++)
    {
        int d=arr[i][1];
        while(d>=1)
        {
            if(ans[d]==-1)
            {
                ans[d]=arr[i][2]+1;
                totalprofit+=arr[i][0];
                break;
            }
            else
            d--;
        }
    }
    ans[max+1]=totalprofit;
    return ans;

}
// 0 - profit
// 1 - deadline
// 2 - index
int main()
{
    int n, i;
    printf("Enter number of activity : ");
    scanf("%d", &n);

    int **arr = (int **)malloc(n * sizeof(int*));
    printf("Enter Data : ");

    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(3 * sizeof(int));
        arr[i][2] = i;
        printf("Enter profit : ");
        scanf("%d", &arr[i][0]);
        printf("Enter deadline : ");
        scanf("%d", &arr[i][1]);
    }


    clock_t start = clock();
    int *ans = jobscq(arr,n);
    clock_t end = clock();

    double timetaken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Answer vector : ");
    for (i = 1; i <= ans[0]; i++)
    {
        printf("%d ", ans[i]);
    }
    printf("\n");
    printf("Total profit = %d\n",ans[ans[0]+1]);
    printf("Time = %lf s\n", timetaken);
    return 0;
}