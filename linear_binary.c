#include <stdio.h>
#include <stdlib.h>

void linear(int arr[], int key)
{
    int flag = 0;
    for (int i = 0; i < 10; i++)
    {
        if (key == arr[i])
        {
            printf("Element found at position %d", i + 1);
            flag = 1;
        }
    }
    if (!flag)
    {
        printf("Element not found in the array");
    }
}

void linearReccursive(int arr[], int key, int index, int size)
{
    if (index >= size)
    {
        printf("Element not found");
        return;
    }
    if (arr[index] == key)
    {
        printf("Element found at position %d", index + 1);
        return;
    }
    else
    {
        linearReccursive(arr, key, index + 1, size);
    }
}

void binary(int arr[], int key, int size)
{

    int lb = 0, ub = size - 1, found = 0;

    while (lb <= ub)
    {
        int mid = (lb + ub) / 2;
        if (arr[mid] == key)
        {
            printf("Element found at position %d", mid + 1);
            found = 1;
            return;
        }
        if (arr[mid] > key)
        {
            ub = mid - 1;
        }
        else
        {
            lb = mid + 1;
        }
    }
    if (!found)
    {
        printf("Element not found");
    }
}

void binaryReccursive(int arr[], int key, int size, int lb, int ub)
{
    if (lb <= ub)
    {
        int mid = (lb + ub) / 2;
        if (arr[mid] == key)
        {
            printf("Element found at position %d", mid + 1);
            return;
        }
        if (arr[mid] > key)
        {
            binaryReccursive(arr, key, size, lb, mid - 1);
        }
        else
        {
            binaryReccursive(arr, key, size, mid + 1, ub);
        }
    }
    else
    {
        printf("Element not found");
    }
}

int main()
{
    int arr[10] = {1, 2, 23, 24, 35, 57, 78, 79, 80, 90};
    printf("Given array: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nEnter the number you want to search: ");
    int key;
    scanf("%d", &key);
    linear(arr, key);
    linearReccursive(arr, key, 0, 10);
    binary(arr, key, 10);
    binaryReccursive(arr, key, 10, 0, 9);
    return 0;
}