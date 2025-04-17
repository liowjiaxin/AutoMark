#include <stdio.h>

int main() {
    int N;

    // Input and validate the number of bids
    do {
        printf("Enter the number of bids: ");
        scanf("%d", &N);
        if (N < 2) {
            printf("Error: Number of bids must be at least 2. Please try again:\n");
        }
    } while (N < 2);

    // Array to store bids
    float bids[N];

    // Input bids and validate each one
    for (int i = 0; i < N; i++) {
        do {
            printf("Enter bid %d (must be at least $100,000): ", i + 1);
            scanf("%f", &bids[i]);
            if (bids[i] < 100000) {
                printf("Error: Bid must be at least $100,000. Please try again:\n");
            }
        } while (bids[i] < 100000);
    }

    // Determine the highest bid
    float highestBid = bids[0];
    for (int i = 1; i < N; i++) {
        if (bids[i] > highestBid) {
            highestBid = bids[i];
        }
    }

    // Output the highest bid
    printf("\nThe highest bid is: $%.0f\n", highestBid);

    return 0;
}
