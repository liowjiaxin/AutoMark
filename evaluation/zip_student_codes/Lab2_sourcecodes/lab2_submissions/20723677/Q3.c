#include <stdio.h>

#define MIN_BID 100000  // Minimum bid is $100000

int main() {
    int N;

    // Prompt user for the number of bids and validate
        printf("Enter the number of bids: ");
        scanf("%d", &N);

        // If the number of bids is less than 2
        while (N < 2) {
            printf("Error: Number of bids must be at least 2. Please try again: ");
            scanf("%d", &N); // Prompt user to enter a valid number of bids
        }

    // Declare an array to store the bids
    int bids[N];

    // Prompt user to enter each bid and validate
    printf("Enter the bids (must be at least $100000):\n");
    for (int i = 0; i < N; i++) {
            printf("Bid %d: ", i + 1);
            scanf("%d", &bids[i]);

            // If the bid is below the minimum ($100000)
            while (bids[i] < MIN_BID) {
                printf("Error: Bid must be at least $100000. Please try again: ");
                scanf("%d", &bids[i]); // Prompt user for a valid bid
            }
    }

    // Determine the highest bid
    int highestBid = bids[0];  // Initialize the highest bid as the first bid
    for (int i = 1; i < N; i++) {
        if (bids[i] > highestBid) {
            highestBid = bids[i];  // Update the highest bid
        }
    }

    // Print the highest bid
    printf("The highest bid is: $%d\n", highestBid);

    return 0;
}
