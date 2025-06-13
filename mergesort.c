#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void merge(int *arr, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int *left = (int *)malloc((n1 + 1) * sizeof(int));
    int *right = (int *)malloc((n2 + 1) * sizeof(int));
    int i, j;
    for (i = 0; i < n1; i++)
    {
        left[i] = arr[i + p];
    }
    for (i = 0; i < n2; i++)
    {
        right[i] = arr[i + q + 1];
    }
    left[n1] = (int)INFINITY;
    right[n2] = (int)INFINITY;

    int k1 = 0, k2 = 0;
    for (i = p; i <= r; i++)
    {
        if (left[k1] <= right[k2])
        {
            arr[i] = left[k1];
            k1++;
        }
        else
        {
            arr[i] = right[k2];
            k2++;
        }
    }
}

void mergesort(int *arr, int p, int r)
{
    if (p < r)
    {
        int mid = p + ((r - p) / 2);
        mergesort(arr, p, mid);
        mergesort(arr, mid + 1, r);
        merge(arr, p, mid, r);
    }
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

    printf("unsorted array : ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    clock_t start = clock();
    mergesort(arr, 0, n - 1);
    clock_t end = clock();

    double timetaken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("sorted array : ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("Time = %lf s\n", timetaken);
    return 0;
}