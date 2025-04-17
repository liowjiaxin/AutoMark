#include <stdio.h>

#define MIN_BID 100000 // Minimum bid value

int main(void) {
    int num_bid;

    // Input number of bids with validation
    do {
        printf("Enter the number of bids: ");
        scanf("%d", &num_bid);
        if (num_bid < 2) {
            printf("Error: Number of bids must be at least 2. Please try again. \n");
        }
    } while (num_bid < 2);

    int bids[num_bid]; // Array to store the bids

    // Input bids  to the array with validation
    printf("Enter the bids (must be at least $100000): \n");
    for (int i = 0; i < num_bid; i++) {
        int bid;
        do {
            printf("Bid %d: ", i + 1);
            scanf("%d", &bid);
            if (bid < MIN_BID) {
                printf("Error: Bid must be at least $100,000. Please try again: \n");
            }
        } while (bid < MIN_BID);
        
        bids[i] = bid; // Store valid bid
    }

    // Determine the highest bid
    int highestBid = bids[0];
    for (int i = 1; i < num_bid; i++) {
        if (bids[i] > highestBid) {
            highestBid = bids[i];
        }
    }

    // Output the highest bid
    printf("The highest bid is: $%d\n", highestBid);

    return 0;
}




