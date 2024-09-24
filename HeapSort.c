#include <stdio.h>
void heapify(int arr[], int i, int n)
{
    int largest = i;
    int j = 2 * i + 1;
    int k = 2 * i + 2;
    if (j < n && arr[largest] < arr[j])
    {
        largest = j;
    }
    if (k < n && arr[largest] < arr[k])
    {
        largest = k;
    }
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, largest, n);
    }
}
void heap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, i, n);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, 0, i);
    }
}
int main()
{
    int arr[] = {2, 4, 6, 8, 2, 9};
    heap(arr, 6);
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", arr[i]);
    }
}
