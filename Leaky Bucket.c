#include<stdio.h>
#include<stdlib.h>

struct packet
{
    int time;
    int size;
} p[50];

void main()
{
    int i,n,m,k=0;
    int bsize,bfilled,outrate;
    printf("Enter the number of packets\n");
    scanf("%d",&n);
    printf("Enter arrival time and size of each packet in the order of arrival time\n");

    for(i=0;i<n;i++)
        scanf("%d%d",&p[i].time,&p[i].size);

    printf("Enter bucket size\n");
    scanf("%d",&bsize);
    printf("Enter output rate\n");
    scanf("%d",&outrate);

    m=p[n-1].time;
    i=1;
    k=0;
    bfilled=0;

    while(i<=m || bfilled!=0)
    {
        printf("\n\nAt time %d\n\n",i);
        while(p[k].time<=i && k<n)
        {
            if(bsize>=bfilled+p[k].size)
            {
                bfilled=bfilled + p[k].size;
                printf("%d byte packet inserted\n",p[k].size);
                k=k+1;
            }
            else
            {
                printf("%d byte packet discarded\n",p[k].size);
                k=k+1;
            }
        }
        if(bfilled==0)
            printf("No packet to transmit\n");
        else if(bfilled>=outrate)
        {
            bfilled=bfilled-outrate;
            printf("%d bytes transfered\n",outrate);
        }
        else
        {
            printf("%d bytes transferred\n",bfilled);
            bfilled=0;
        }
        printf("Packet in the bucket - %d byte\n",bfilled);
        i++;
    }
}
