#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int median(int arr[], int low, int high)
{
    int mid = low + (high - low) / 2;
    if (arr[low] > arr[mid])
    {
        swap(&arr[low], &arr[mid]);
    }
    if (arr[low] > arr[high])
    {
        swap(&arr[low], &arr[high]);
    }
    if (arr[mid] > arr[high])
    {
        swap(&arr[mid], &arr[high]);
    }
    swap(&arr[mid], &arr[high - 1]);
    return arr[high - 1];
}

int partition(int arr[], int low, int high)
{
    int pivot = median(arr, low, high);
    int i = low, j = high - 1;

    while (1)
    {
        while (arr[++i] < pivot)
        {
        }
        while (arr[--j] > pivot)
        {
        }
        if (i >= j)
        {
            break;
        }
        swap(&arr[i], &arr[j]);
    }

    swap(&arr[i], &arr[high - 1]);
    return i;
}

void qs(int arr[], int lower, int upper)
{
    if (lower < upper)
    {
        int n = partition(arr, lower, upper);
        qs(arr, lower, n - 1);
        qs(arr, n + 1, upper);
    }
}

int main()
{
    int arr[] = {19, 17, 15, 12, 16, 18, 4, 11, 13};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    qs(arr, 0, n - 1);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
