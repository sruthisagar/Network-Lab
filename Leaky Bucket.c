#include <stdio.h>
int main()
{
    int b, o, n;
    printf("Enter the bucket size\n");
    scanf("%i", &b);
    printf("Enter the output rate\n");
    scanf("%i", &o);
    printf("Enter the number of packets\n");
    scanf("%i", &n);
    int size[1000] = {0};
    int i = 0, loop = n;
    while (loop--)
    {
        printf("Enter the packet size at time %d", i + 1);
        scanf("%d", &size[i]);
        i++;
    }
    printf("Time\tReceived\tSent\tDropped\tRemaining\n");
    int rem = 0;
    for (int i = 0; i < n; i++)
    {
        if (rem + size[i] <= b)
        {
            rem = rem - o + size[i];
            printf("%d\t%d\t%d\t%d\t%d\n", i + 1, size[i], o, 0, rem);
        }
        else if (i == 0)
        {
            rem = rem;
            printf("%d\t%d\t%d\t%d\t%d\n", i + 1, size[i], 0, size[i], rem);
        }
        else
        {
            rem = rem - o;
            printf("%d\t%d\t%d\t%d\t%d\n", i + 1, size[i], o, size[i], rem);
        }
    }
    while (rem > 0)
    {
        rem -= o;
        int sent = o;
        if (rem < 0)
        {
            sent = rem + o;
            rem = 0;
        }
        printf("%d\t%d\t%d\t%d\t%d\n", i + 1, size[i], sent, size[i], rem);
    }
}
