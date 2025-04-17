#include <stdio.h>
int main(){
int N,bid[]={0};

    printf("Enter the number of bids: ", N);
    scanf("%d", &N);
    while (N<2){
        printf("Error: Number of bids must be at least 2. Please try again: ", N);
        scanf("%d", &N);

    }
    printf("Enter the bids (must be at least $100000): \n");
    for(int i=0;i<=N;++i){
        printf("Bid %d: ",i,bid[i]);
        scanf("%d", &bid[i]);
        if (bid[i]<100000){
            printf("Error: Bid must be at least $100000. Please try again: ",bid[i]);
            scanf("%d", &bid[i]);
        }
    }
    int max = bid[0];
    for(int j = 1; j < N; j++) {
        if(bid[j] > max) {
            max = bid[j];
        }
    }
    printf("The highest bid is: %d", max);
    
}