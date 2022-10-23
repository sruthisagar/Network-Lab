#include<stdio.h>
#include<stdlib.h>

#define min(x, y) (x<y)?x:y
void hello(){
printf("hello");
}
void main(){
    int n, i, j, source, k = 999, count = 0, ind, dist = 0;

    printf("Enter the number of routers : \n");
    scanf("%i", &n);

    int arr[n][n];
    printf("Enter the routing distance\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%i", &arr[i][j]);
        }
    }

    printf("Enter the source : ");
    scanf("%i", &source);

    int src[n];
    int flag[500] = {0};
    for(i=0;i<n;i++){
        src[i] = arr[source][i];
        // k = min(src[i], k);
    }
    int abcd,bcde;
    flag[source] = 1;

    while(count < n){
        k = 999;
        for(i=0;i<n;i++){
            if(flag[i] == 0 && k>src[i]){
                ind = i;
                k = src[i];
            }
        }
        // dist+=k;
        flag[ind] = 1;
        for(i=0;i<n;i++){
            if(flag[i] == 0){
                src[i] = min(src[i], k+arr[ind][i]);
            }
        }
        count++;
    }
    abcd=0;
    for(i=0;i<n;i++){
        printf("%i ", src[i]);
    }
    printf("\n");
}
