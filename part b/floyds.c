#include <stdio.h>
#include <time.h>

int i, j, k, n, a[1000][1000];
int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}
void floyds(int a[1000][1000])
{
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }
}
void main()
{
    double clk;
    clock_t starttime, endtime;
    printf("enter the order the matrix:\n");
    scanf("%d", &n);
    printf("enter the elements of the matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("a[%d][%d]:", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    printf("the entered elements are:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    starttime = clock();
    floyds(a);
    endtime = clock();
    printf("the single source shortest path is:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;
    printf("\nthe time taken is %f seconds", clk);
}
