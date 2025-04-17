#include <stdio.h>

#define MIN_BID 100000 

int main() {
    int N;  
    float highestBid = 0;
    float bids[N];

    printf("Enter the number of bids (N >= 2): ");
    scanf("%d", &N);
    while(N < 2){
        if (N < 2) {
            printf("Error: Number of bids must be at least 2. Please try again:");
            scanf("%d", &N);
        }
        else{
            break;
        }
    }

    printf("Enter the bids (must be at least $100,000):\n");
    for(int i = 0; i < N; i++) {
        while (bids[i] < MIN_BID) {
            printf("Bid %d:", i + 1);
            scanf("%f", &bids[i]);
            if (bids[i] < MIN_BID) {
                printf("Error: Bid must be at least $100,000. Please try again:");
                scanf("%f", &bids[i]);
            }
        } 
    }

    for (int i = 0; i < N; i++) {
        if (bids[i] > highestBid) {
            highestBid = bids[i];
        }
    }

    printf("The highest bid is: $%.2f\n", highestBid);

    return 0;
}