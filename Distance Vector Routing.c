#include<stdlib.h>
#include<stdio.h>

struct node
{
    int dist[20];
    int from[20];
} route[10];

int main()
{
    int dm[20][20], no;
    printf("Enter number of nodes\n");
    scanf("%d",&no);
    printf("\nEnter distance matrix\n");
    for (int i = 0; i < no; i++)
    {
        for (int j = 0; j < no; j++)
        {
            scanf("%d",&dm[i][j]);
            dm[i][i] = 0;
            route[i].dist[j] = dm[i][j];
            route[i].from[j] = j;
        }
    }

    int flag;
    do
    {
        flag = 0;
        for (int i = 0; i < no; i++)
        {
            for (int j = 0; j < no; j++)
            {
                for (int k = 0; k < no; k++)
                {
                    if ((route[i].dist[j]) > (dm[i][k] + route[k].dist[j]))
                    {
                        route[i].dist[j] = route[i].dist[k] + route[k].dist[j];
                        route[i].from[j] = k;
                        flag = 1;
                    }
                }
            }
        }
    } while (flag);

    for (int i = 0; i < no; i++)
    {
        printf("\nRouter %d:\n",i+1);
        printf("Node\t\tNext Hop\t\tDistance\n");
        for (int j = 0; j < no; j++)
        {
            if((j+1)!=(route[i].from[j]+1))
                printf("%d\t\t%d\t\t%d\n", j+1, route[i].from[j]+1, route[i].dist[j]);
            else 
                printf("%d\t\t-\t\t%d\n", j+1, route[i].dist[j]);
        }
    }
    return 0;
}

// 0 5 2 3 1000
// 5 0 4 1000 3
// 2 4 0 1000 4
// 3 1000 1000 0 1000
// 1000 3 4 1000 0
