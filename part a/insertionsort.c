#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int n = 100, i;
    double clk;
    clock_t starttime, endtime;
    srand(time(0));
    printf("Enter the number of contact numbers\n");
    scanf("%d", &n);
    long long A[n];
    printf("All available numbers are\n");
    for (i = 0; i < n; i++)
    {
        A[i] = 900000000 + rand() % 100000000;
        printf("%lld\t", A[i]);
    }
    printf("\nNumbers available in ascending order is\n");
    printf("\n");
    insertsort(A, n);
    for (i = 0; i < n; i++)
    {
        printf("%lld\t", A[i]);
    }
    starttime = clock();
    insertsort(A, n);
    endtime = clock();
    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;
    printf("\nThe run time is %f\n", clk);
}

void insertsort(long long A[], int n)
{
    int i, t, j, flag = 0;
    for (i = 0; i < n; i++)
    {
        t = A[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (A[j] > t)
            {
                A[j + 1] = A[j];
                flag = 1;
            }
            else
                break;
        }
        if (flag)
            A[j + 1] = t;
    }
}
