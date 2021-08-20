#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int partition(int[], int, int);
int main()
{
    int n = 100, i;
    double clk;
    clock_t starttime, endtime;
    srand(time(0));
    printf("Enter the number of students\n");
    scanf("%d", &n);
    int a[n];
    printf("All available ID numbers are\n");
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 1000 + 1000;
        printf("%d\t", a[i]);
    }
    printf("\nStudent IDs available in ascending order is\n");
    printf("\n");
    quick_sort(a, 0, n - 1);
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    starttime = clock();
    quick_sort(a, 0, n - 1);
    endtime = clock();
    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;
    printf("\nThe run time is %f\n", clk);
}

void quick_sort(int a[], int low, int high)
{
    int j;
    if (low < high)
    {
        j = partition(a, low, high);
        quick_sort(a, low, j - 1);
        quick_sort(a, j + 1, high);
    }
}

int partition(int a[], int low, int high)
{
    int i, j, temp, pivot;
    pivot = a[low];
    i = low + 1;
    j = high;
    while (1)
    {
        while ((i < high) && a[i] <= pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        else
        {
            temp = a[j];
            a[j] = a[low];
            a[low] = temp;
            return j;
        }
    }
}
