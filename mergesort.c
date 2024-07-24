#include <stdio.h>

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int arr[], int lb, int ub, int mid, int size)
{
    int i = lb, j = mid + 1, b[size], k = lb;
    if (lb < ub)
    {
        while (i <= mid && j <= ub)
        {
            if (arr[i] <= arr[j])
            {
                b[k] = arr[i];
                i++;
            }
            else
            {
                b[k] = arr[j];
                j++;
            }
            k++;
        }
        if (i > mid && j <= ub)
        {
            while (j <= ub)
            {
                b[k] = arr[j];
                k++;
                j++;
            }
        }
        else
        {
            while (i <= mid)
            {
                b[k] = arr[i];
                i++;
                k++;
            }
        }
    }
    for (k = lb; k <= ub; k++)
    {
        arr[k] = b[k];
    }

    printf("\nAfter merging: ");
    printArray(arr, size);
}

void mergesort(int arr[], int lb, int ub, int size)
{
    if (lb < ub)
    {
        int mid = lb + (ub-lb)/2;
        mergesort(arr, mid + 1, ub, size);
        mergesort(arr, lb, mid, size);
        merge(arr, lb, ub, mid, size);
    }
}

int main()
{
    int arr[] = {19, 17, 15, 12, 16, 18}; // , 4, 11, 13, 10
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    mergesort(arr, 0, n - 1, n);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}