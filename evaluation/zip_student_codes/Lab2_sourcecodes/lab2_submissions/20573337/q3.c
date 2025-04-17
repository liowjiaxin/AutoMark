//libraries 
#include <stdio.h>
#include <stdlib.h>

// Function to find the highest bidder
//Pretty self-explanatory
float findHighestBid(const float bids[], int count) {
    float highest = bids[0];
    for (int increment = 1; increment < count; increment++) { // for loop to add bidders
        if (bids[increment] > highest) {
            highest = bids[increment];
        }
    }
    return highest;
}
// the main function to actually execute the code :)
int main() {
    int numBids;

    // Input number of bids
    printf("Enter the number of bids (minimum 2): ");
    scanf("%d", &numBids);

    // Validate number of bids
    if (numBids < 2) {
        printf("Error: At least two bids are required.\n");
        return 1;
    }

    // Allocate memory for bids
    float *bids = (float *)malloc(numBids * sizeof(float));
    if (bids == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    // Input bids and validate each one
    printf("Enter the bids (minimum $100,000 each):\n");
    for (int increment = 0; increment < numBids; increment++) {
        do {
            printf("Bid %d: ", increment + 1);
            scanf("%f", &bids[increment]);
            if (bids[increment] < 100000) {
                printf("Error: Bid must be at least $100,000.\n");
            }
        } while (bids[increment] < 100000);
    }

    // Find and display the highest bid
    float highestBid = findHighestBid(bids, numBids);
    printf("The highest bid is: $%.2f\n", highestBid);

    // Free allocated memory
    free(bids);
    return EXIT_SUCCESS;
}
