#include <stdio.h>
#include <time.h>
int i;
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void bubble_sort(int a[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
}

void main()
{
    double clk;
    clock_t starttime, endtime;
    int i, j, n, a[1000];
    printf("enter the number of elements:\n");
    scanf("%d", &n);
    printf("the elements are:\n");
    for (i = 0; i < n; i++)
    {
        a[i] = 100 + rand() % 1000;
        printf("%d\t", a[i]);
    }

    starttime = clock();
    bubble_sort(a, n);
    endtime = clock();
    printf("\nthe elements after sorting in bubble sort is:\n");
    for (i = 0; i < n; i++)
    {
        printf("\n%d\t", a[i]);
    }
    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;

    printf("\nthe time taken is %f", clk);
}