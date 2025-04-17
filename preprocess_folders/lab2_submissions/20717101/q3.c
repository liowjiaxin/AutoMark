#include <stdio.h>

int main() {
    int N, i;
    float highestBid = 0;

    // Prompt user for the number of bids
    printf("Enter the number of bids (minimum 2): ");
    scanf("%d", &N);

    // Validate that N is at least 2
    if (N < 2) {
        printf("Error: At least two bids are required to determine the highest bid.\n");
        return 1; // Exit program
    }

    float bids[N];

    // Input bids with validation
    for (i = 0; i < N; i++) {
        printf("Enter bid %d (minimum $100,000): ", i + 1);
        scanf("%f", &bids[i]);

        // Validate bid amount
        while (bids[i] < 100000) {
            printf("Invalid bid! Each bid must be at least $100,000.\n");
            printf("Enter bid %d again: ", i + 1);
            scanf("%f", &bids[i]);
        }

        // Track the highest bid
        if (bids[i] > highestBid) {
            highestBid = bids[i];
        }
    }

    // Output the highest bid
    printf("\nThe highest bid is: $%.2f\n", highestBid);

    return 0;
}

