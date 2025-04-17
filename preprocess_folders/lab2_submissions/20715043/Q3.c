#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    float *bids;

    //input the number of bid
    do {
        printf("Enter the number of bids: ");
        scanf("%d", &N);
        if (N < 2) {
            printf("Error: Number of bids must be at least 2. Please try again.\n");
        }
    } while (N < 2);

    //memory allocation
    bids = (float *)malloc(N * sizeof(float));
    if (bids == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    //input the bidding amount
    printf("Enter the bids (must be at least $100000):\n");
    for (int i = 0; i < N; i++) {
        do {
            printf("Bid %d: ", i + 1);
            scanf("%f", &bids[i]);
            if (bids[i] < 100000.0) {
                printf("Error: Bid must be at least $100000. Please try again\n");
            }
        } while (bids[i] < 100000.0);
    }

    //find the max bid
    float highestBid = bids[0];
    for (int i = 1; i < N; i++) {
        if (bids[i] > highestBid) {
            highestBid = bids[i];
        }
    }

    //print the max bid
    printf("\nThe highest bid is: $%.2f\n", highestBid);


    return 0;
}
