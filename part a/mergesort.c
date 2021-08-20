#include <stdio.h>
#include <time.h>
int A[100000];
void merge(int, int, int);
void merge_sort(int, int);
void main()
{
    double clk;
    clock_t starttime, endtime;
    int n, i;
    printf("enter the number of elements:\n");
    scanf("%d", &n);
    printf("the elements are:\n");
    for (i = 0; i < n; i++)
    {
        A[i] = rand() % 1000;
        printf("%d\t", A[i]);
    }
    printf("\n the elements in ascending order is:\n");

    starttime = clock();
    merge_sort(0, n - 1);
    endtime = clock();
    for (i = 0; i < n; i++)
    {
        printf("%d\t", A[i]);
    }
    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;
    printf("the time taken is %f seconds", clk);
}

void merge_sort(int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        merge_sort(low, mid);
        merge_sort(mid + 1, high);
        merge(low, mid, high);
    }
}

void merge(int low, int mid, int high)
{
    int h, l, i, j, b[500000], k;
    h = low;
    i = low;
    j = mid + 1;
    //the left half is h, r8 half is j and the final set is i;
    while ((h <= mid) && (j <= high))
    {
        if (A[h] <= A[j])
        {
            b[i] = A[h]; //b is the final set
            h++;
        }
        else
        {
            b[i] = A[j];
            j++;
        }
        i++;
    }
    if (h > mid)
    {
        for (k = j; k <= high; k++)
        {
            b[i] = A[k];
            i++;
        }
    }
    else
    {
        for (k = h; k <= mid; k++)
        {
            b[i] = A[k];
            i++;
        }
    }
    for (k = low; k <= high; k++)
        A[k] = b[k];
}