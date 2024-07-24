#include <stdio.h>

// Function to partition the array
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        do
        {
            i++;
        } while (i <= high && arr[i] <= pivot); // Ensure i does not go out of bounds

        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

// QuickSort function
void Quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int j = partition(arr, low, high);
        Quicksort(arr, low, j);
        Quicksort(arr, j + 1, high);
    }
}

int main()
{
    int arr[] = {1, 7, 2, 9, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    Quicksort(arr, 0, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
