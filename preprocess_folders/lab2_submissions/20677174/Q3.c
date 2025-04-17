#include <stdio.h>

int main (void) {
    int noOfBids;
    int highestBid;
    
    // Prompt user input for number of bids
    // Asks user to input again if invalid
    printf("Enter the number of bids: ");
    while (1) {
        scanf("%d", &noOfBids);
        if (noOfBids >= 2) {
            break;
        }
        printf("Error: Number of bids must be at least 2. Please try again: ");
    }

    // Initialise array to store bids based on number of bids input by user
    int bids[noOfBids];

    // Prompt user input for bids
    // Asks user to input again if invalid
    printf("Enter the bids (must be at least $100000)\n");
    for (int i = 0; i < noOfBids; ++i) {
        printf("Bid %d: ", i + 1);
        while (1) {
            scanf("%d", bids + i);
            if (bids[i] >= 100000) {
                break;
            }
            printf("Error: Bids must be at least $100000. Please try again: ");
        }
    }

    // Loop through all bids to get highest bid
    // Initialise highest bid by default to first bid and start comparing from second bid onwards
    highestBid = bids[0];
    for (int i = 1; i < noOfBids; ++i) {
        if (bids[i] > highestBid) {
            highestBid = bids[i];
        }
    }

    // Output the highest bid
    printf("The highest bid is: $%d", highestBid);

    return 0;
}