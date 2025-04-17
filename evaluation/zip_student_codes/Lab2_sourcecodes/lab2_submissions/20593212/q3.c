#include <stdio.h>

#define MIN_BID 100000  // Minimum bid value

int main() {
    int N;

    // Input the number of bids
    do {
        printf("Enter the number of bids (N ≥ 2): ");
        scanf("%d", &N);

        if (N < 2) {
            printf("Invalid input. The number of bids must be at least 2.\n");
        }
    } while (N < 2);

    // Array to store the bids
    float bids[N];

    // Input the bids with validation
    for (int i = 0; i < N; i++) {
        do {
            printf("Enter bid %d (must be at least $%d): ", i + 1, MIN_BID);
            scanf("%f", &bids[i]);

            if (bids[i] < MIN_BID) {
                printf("Bid must be at least $%d. Please try again.\n", MIN_BID);
            }
        } while (bids[i] < MIN_BID);
    }

    // Find the highest bid
    float highestBid = bids[0];
    for (int i = 1; i < N; i++) {
        if (bids[i] > highestBid) {
            highestBid = bids[i];
        }
    }

    // Output the highest bid
    printf("\nThe highest bid is: $%.2f\n", highestBid);

    return 0;
}
