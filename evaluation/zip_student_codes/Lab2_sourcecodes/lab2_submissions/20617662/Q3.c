#include <stdio.h>

#define MINIMUM_BID 100000  // Minimum bid amount

int main() {
    int n; // Initialise the number of bids.

    // Enter the number of bids 
    do {
        printf("Enter the number of bids (minimum 2): ");
        scanf("%d", &n);
        if (n < 2) {
            printf("Number of bids must be at least 2. Please try again.\n");
        }
    } while (n < 2);

    //Array is allocated to store bids.
    float bids[n];
    
    // Validate input bids 
    for (int i = 0; i < n; i++) {
        do {
            printf("Enter bid %d (must be at least $%d): ", i + 1, MINIMUM_BID);
            scanf("%f", &bids[i]);
            if (bids[i] < MINIMUM_BID) {
                printf("Error. Each bid must be at least $%d.Please try again.\n", MINIMUM_BID);
            }
        } while (bids[i] < MINIMUM_BID);
    }

    // The highest bid is determined
    float highestBid = bids[0];  // Initialize highest bid with the first bid
    for (int i = 1; i < n; i++) {
        if (bids[i] > highestBid) {
            highestBid = bids[i];
        }
    }

    // Highest bid output
    printf("The highest bid is: $%.2f\n", highestBid);

    return 0;
}