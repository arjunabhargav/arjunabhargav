#include <stdio.h>
#include <time.h>

int min(int a, int b)

{

    return ((a < b) ? a : b);
}

void prims(int n, int cost[10][10])

{

    int i, j, k, u, v, min, source;

    int sum, t[20][20], p[10], d[10], visited[10];

    min = 9999;

    source = 0;

    for (i = 0; i < n; i++)

        for (j = 0; j < n; j++)

            if (cost[i][j] != 0 && cost[i][j] <= min)

            {

                min = cost[i][j];

                source = i;
            }

    for (i = 0; i < n; i++)

    {

        d[i] = cost[source][i];

        visited[i] = 0;

        p[i] = source;
    }

    visited[source] = 1;

    sum = 0;

    k = 0;

    for (i = 1; i < n; i++)

    {

        min = 9999;

        u = -1;

        for (j = 0; j < n; j++)

        {

            if (visited[j] == 0)

            {

                if (d[j] <= min)

                {

                    min = d[j];

                    u = j;
                }
            }
        }

        t[k][0] = u;

        t[k][1] = p[u];

        k++;

        sum = sum + cost[u][p[u]];

        visited[u] = 1;

        for (v = 0; v < n; v++)

        {

            if (visited[v] == 0 && cost[u][v] < d[v])

            {

                d[v] = cost[u][v];

                p[v] = u;
            }
        }
    }

    if (sum >= 9999)

        printf("\n Spanning tree does not exist");

    else

    {

        printf("Spanning tree exists and minimum spanning tree is\n");

        for (i = 0; i < n - 1; i++)

        {

            printf("%d %d\n", t[i][0], t[i][1]);
        }

        printf("\n The cost of spanning tree is %d ", sum);
    }
}

int main()

{

    int cost[10][10], n, i, j;

    double clk;

    clock_t starttime, endtime;

    printf("Enter the number of vertices :");

    scanf("%d", &n);

    printf("Enter the cost adjacency matrix :\n");

    for (i = 0; i < n; i++)

        for (j = 0; j < n; j++)

            scanf("%d", &cost[i][j]);

    starttime = clock();

    prims(n, cost);

    endtime = clock();

    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;

    printf("\nThe time taken is %f\n", clk);
}
