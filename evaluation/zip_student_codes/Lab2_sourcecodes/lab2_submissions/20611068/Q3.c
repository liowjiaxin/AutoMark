#include <stdio.h>

int main() {
    int N;
    float bids[100]; 
    float highestBid;

    printf("Enter the number of bids (N, N >= 2): ");
    scanf("%d", &N);


    if (N < 2) {
        printf("Error: Number of bits must be at least 2.\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        printf("Enter bid %d: ", i + 1);
        scanf("%f", &bids[i]);
        if (bids[i] < 100000) {
            printf("Error: Bid must be at least $100000. Please try again.\n");
            i--; 
        }
    }

    
    highestBid = bids[0];
    for (int i = 1; i < N; i++) {
        if (bids[i] > highestBid) {
            highestBid = bids[i];
        }
    }

    printf("The highest bid is: $%.2f\n", highestBid);

    return 0;
}