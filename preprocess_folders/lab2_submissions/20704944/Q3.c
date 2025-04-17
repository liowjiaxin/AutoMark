#include <stdio.h>
int cmp(int array[4]);
int main(){
    int c,d;
    int array[4];
    printf("Enter the number of bids: ");
    scanf("%d",&c);
    while (c<2) {
    printf("Error: Number of bids must be at least 2. Please try again: ");
    scanf("%d",&c);
    }
    printf("Enter the bids (must be at least $100000):\n");
    printf("Bid 1: ");
    scanf("%d",&array[0]);
    while (array[0]<100000) {
        printf("Error: Bid must be at least $100000. Please try again:");
        scanf("%d",&array[0]);
        
    }

    printf("Bid 2: ");
    scanf("%d",&array[1]);
    while (array[1]<100000) {
        printf("Error: Bid must be at least $100000. Please try again:");
        scanf("%d",&array[1]);
    }

    printf("Bid 3: ");
    scanf("%d",&array[2]);
    while (array[2]<100000) {
        printf("Error: Bid must be at least $100000. Please try again:");
        scanf("%d",&array[2]);
    }
    int i=cmp(array);
    printf("The higest bid is: %d",i);

    return 0;
}


int cmp(int array[4]){
    int a;
    if(array[0]>array[1]&&array[0]>array[2]){
        a=array[0];
        return a;
    }
    if(array[1]>array[0]&&array[1]>array[2]){
        a=array[1];
        return a;
    }
    if(array[2]>array[1]&&array[2]>array[0]){
        a=array[2];
        return a;
    }    
}