#include <stdio.h>  // For standard input-output

int main() {
    int numBids;
    float bids[100]; // this assumes a max number of 100 bids, can be adjusted if need be.
    float highestBid = 0.0;

    // This will 'get' and validate the number of bids
    do {
        printf("You may enter the number of bids: ");
        scanf("%d", &numBids);
        if (numBids < 2) {
            printf("Error: The number of bids must at least be 2. Please try again: ");
            scanf("%d", &numBids); // 'get' the input again.
        }
    } while (numBids < 2);

    // 'get' and validate the bids
    printf("Please enter the bids (must be at least $100000):\n");
    for (int i = 0; i < numBids; i++) {
        do {
            printf("Bid %d: ", i + 1);
            scanf("%f", &bids[i]);
            if (bids[i] < 100000.0) {
                printf("Error: The bid must be at least $100000. Please try again: ");
                scanf("%f", &bids[i]); // 'get' the input again.
            }
        } while (bids[i] < 100000.0);

        // This shall update highestBid if the current bid is higher
        if (i == 0 || bids[i] > highestBid) {
            highestBid = bids[i];
        }
    }

    // This will output the highest bid.
    printf("The highest bid is: $%.0f\n", highestBid);

    return 0;
}