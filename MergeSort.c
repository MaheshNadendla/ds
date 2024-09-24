/*merge sort*/
#include <stdio.h>
int a[7] = {28, 32, 45, 12, 13, 43, 98};
void merge(int lb, int mid, int ub)
{
    int i = lb;
    int j = mid + 1;
    int k = lb;
    int b[7];
    while (i <= mid && j <= ub)
    {

        if (a[i] < a[j])
        {
            b[k] = a[i];
            k++;
            i++;
        }
        else
        {
            b[k] = a[j];
            k++;
            j++;
        }
    }
    if (i > mid)
    {
        while (j <= ub)
        {
            b[k] = a[j];
            k++;
            j++;
        }
    }
    else
    {
        while (i <= mid)
        {
            b[k] = a[i];
            k++;
            i++;
        }
    }
    for (int i = lb; i <= ub; i++)
    {
        a[i] = b[i];
    }
}
void mergesort(int lb, int ub)
{
    int mid;
    if (lb < ub)
    {
        mid = (lb + ub) / 2;
        mergesort(lb, mid);
        mergesort(mid + 1, ub);
        merge(lb, mid, ub);
    }
}
int main()
{

    mergesort(0, 6);
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", a[i]);
    }
}
