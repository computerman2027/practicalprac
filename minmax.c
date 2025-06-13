#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int *maxmin(int *arr, int x, int y)
{
    int *ans = (int *)malloc(2 * sizeof(int));
    if (y - x <= 1)
    {
        ans[0] = max(arr[x], arr[y]);
        ans[1] = min(arr[x], arr[y]);
        return ans;
    }

    int m = (x + y) / 2;
    int *ans1 = maxmin(arr, x, m);
    int *ans2 = maxmin(arr, m + 1, y);
    ans[0] = max(ans1[0], ans2[0]);
    ans[1] = min(ans1[1], ans2[1]);
    return ans;
}

int main()
{
    int n, i;
    printf("Enter size of array : ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter values : ");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    clock_t start = clock();
    int* ans = maxmin(arr,0,n-1);
    clock_t end = clock();

    double timetaken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("max = %d\n", ans[0]);
    printf("min = %d\n", ans[1]);
    printf("Time = %lf s\n", timetaken);
    return 0;
}