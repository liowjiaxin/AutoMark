#include <stdio.h>

#define MIN_BID 100000 // Minimum bid amount for validation

int main() {
    int numBids; // Number of bids
    float bids[15]; // Array to store the bids (assuming a max of 15 bids)
    float highestBid; // Variable to track the highest bid

    // Input and validate number of bids
    while (1) {
        printf("Enter the number of bids: ");
        scanf("%d", &numBids);

        if (numBids >= 2) {
            break; // Valid input
        } else {
            printf("Number of bids must be at least 2. Please try again.\n");
        }
    }

    // Input and validate bid amount $
    for (int i = 0; i < numBids; i++) {
        while (1) {
            printf("Bid %d: ", i + 1);
            scanf("%f", &bids[i]);

            if (bids[i] >= MIN_BID) {
                break; // Valid bid
            } else {
                printf("Bid must be at least $%d. Please try again:\n", MIN_BID);
            }
        }
    }

    // Determine the highest bid
    highestBid = bids[0]; // Assume the first bid is the highest initially
    for (int i = 1; i < numBids; i++) { 
        if (bids[i] > highestBid) { //Rearrangement
            highestBid = bids[i];
        }
    }

    // Display the highest bid
    printf("The highest bid is: $%.2f\n", highestBid);

    return 0;
}

