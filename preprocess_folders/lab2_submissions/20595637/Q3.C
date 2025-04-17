#include <stdio.h>

// defining the minimum amt of bid
#define MIN_BID 100000

int main() {
    // variable to store the number of bids
    int numberOfBids;

    // Ask the user to enter the number of bids
    printf("Enter the number of bids: ");
    scanf("%d", &numberOfBids);

    // Check the number of bids to ensure it's at least 2
    while (numberOfBids < 2) {
        // Display an error message to tell the user to try again
        printf("Error: Number of bids must be at least 2. Please try again: ");
        scanf("%d", &numberOfBids);
    }

    // Declaring an array
    int bids[numberOfBids];

    for (int i = 0; i < numberOfBids; i++) {
        int bid;
        
        do {
            // Display and ask user to enter the bid amt
            printf("Enter bid %d (must be at least $%d): ", i + 1, MIN_BID);
            scanf("%d", &bid);
            // Check if the bid amount is less than the minimum bid
            if (bid < MIN_BID) {
                // Display an error message and ask the user to try again
                printf("Error: Bid must be at least $%d. Please try again: ", MIN_BID);
            }
        } while (bid < MIN_BID);
        // Store the valid bid amount in the array
        bids[i] = bid;
    }

    // Initialize the highest bid to the first bid in the array
    int highestBid = bids[0];
    // Loop through the remaining bids to find the highest one
    for (int i = 1; i < numberOfBids; i++) {
        // Check if the current bid is higher than the highest bid found so far
        if (bids[i] > highestBid) {
            // Update the highest bid
            highestBid = bids[i];
        }
    }

    // Display the highest bid
    printf("\nThe highest bid is: $%d\n", highestBid);

    return 0;
}