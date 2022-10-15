
//Distance Victor Routing
//Author :Sruthi Sagar V K
#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    int cost[n][n];
    printf("Enter the cost matrix\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    int next_hop[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            next_hop[i][j] = -1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (cost[i][j] + cost[j][k] < cost[i][k])
                {
                    cost[i][k] = cost[i][j] + cost[j][k];
                    next_hop[i][k] = j + 1;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("For router %d\n", i + 1);
        printf("Dest\tnext_hop\tdist\n");
        for (int j = 0; j < n; j++)
        {
            if (next_hop[i][j] == -1)
            {
                printf("%d\t-\t\t%d\n", j + 1, cost[i][j]);
            }
            else
            {
                printf("%d\t%d\t\t%d\n", j + 1, next_hop[i][j], cost[i][j]);
            }
        }
        printf("\n");
    }
}

// 0 5 2 3 999
// 5 0 4 999 3
// 2 4 0 999 4
// 3 999 999 0 999
// 999 3 4 999 0
