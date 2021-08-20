#include <stdio.h>
#include <time.h>

void main()
{
    double clk;
    clock_t starttime, endtime;
    int i, n, key;
    printf("enter the number of elements:\n");
    scanf("%d", &n);
    int a[100000];
    for (i = 0; i < n; i++)
        a[i] = 100 + rand() % 1000;
    printf("the elements are:\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);

    printf("\nenter the key:\n");
    scanf("%d", &key);

    starttime = clock();

    for (i = 0; i < n; i++)
    {
        if (a[i] == key)
            printf("\nthe element %d is found in %d position\n", a[i], i);
    }

    endtime = clock();

    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;

    printf("the time taken is:%f", clk);
}