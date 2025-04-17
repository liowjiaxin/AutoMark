#include <stdio.h>
#include <stdlib.h>

// Function to find the highest bid
float findHighestBid(const float bids[], int count) {
    float highest = bids[0];
    for (int i = 1; i < count; i++) {
        if (bids[i] > highest) {
            highest = bids[i];
        }
    }
    return highest;
}

int main() {
    int N;
    float *bids;

    // Prompt the user for the number of bids
    printf("How many bids are there? (Minimum 2): ");
    scanf("%d", &N);

    // Ensure at least 2 bids are entered
    while (N < 2) {
        printf("Error: You need at least two bids to proceed.\n");
        printf("Enter a valid number of bids: ");
        scanf("%d", &N);
    }

    // Allocate memory for the bids
    bids = (float *)malloc(N * sizeof(float));
    if (bids == NULL) {
        printf("Error: Unable to allocate memory for bids.\n");
        return 1;
    }

    // Enter the bids
    printf("Enter your bids (minimum $100,000):\n");
    for (int i = 0; i < N; i++) {
        printf("Bid %d: ", i + 1);
        scanf("%f", &bids[i]);

        // Validate each bid
        while (bids[i] < 100000) {
            printf("Invalid bid! Please enter a bid of at least $100,000: ");
            scanf("%f", &bids[i]);
        }
    }

    // Find the highest bid
    float highest = findHighestBid(bids, N);

    // Display the highest bid
    printf("The highest bid is: $%.2f\n", highest);

    // Free the allocated memory
    free(bids);

    return 0;
}
