#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

void printArray(int arr[],int lb ,int ub)
{
    for (int i = lb; i < ub; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int low, int high, int size)
{
    int pivot = arr[low];
    int i = low, j = high;
    while (i < j)
    {
        while (arr[i] <= pivot && i < high)
        {
            i++;
        }
        while (arr[j] > pivot && j > low)
        {
            j--;
        }
        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void qs(int arr[], int lower, int upper, int size)
{
    if (lower < upper)
    {
        int n = partition(arr, lower, upper, size);
        printf("Sorting %d: ", arr[n]);
        printArray(arr, lower, upper+1);
        printf("\n");
        qs(arr, lower, n - 1, size);
        qs(arr, n + 1, upper, size);
    }
}

int main()
{
    int arr[] = {19, 17, 15, 12, 16, 18}; // 4, 11, 13
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, 0, n-1);

    qs(arr, 0, n - 1, n);

    printf("Sorted array: ");
    printArray(arr, 0, n-1);

    return 0;
}