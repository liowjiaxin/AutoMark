#include <stdio.h>
//QUESTION 3

int main() {
    int numBids, i;               // Declaration for the number of bids and loop counter
    float bid, highestBid = 0.0;  // Variables to store each bid and the highest bid

    // Prompt the user to enter the number of bids
    printf("Enter the number of bids: ");
    scanf("%d", &numBids);

    // Ensure the number of bids is at least 2
    while (numBids < 2) {
        printf("Error: Number of bids must be at least 2. Please try again: ");
        scanf("%d", &numBids);
    }

    // Prompt the user to input bids
    printf("Enter the bids (must be at least $100,000):\n");
    for (i = 1; i <= numBids; i++) {
        printf("Bid %d: ", i);
        scanf("%f", &bid);

        // Ensure each bid is at least $100,000
        while (bid < 100000) {
            printf("Error: Bid must be at least $100,000. Please try again: ");
            scanf("%f", &bid);
        }

        // Update the highest bid if the current bid is greater
        if (bid > highestBid) {
            highestBid = bid;
        }
    }

    // Display the highest bid
    printf("The highest bid is: $%.2f\n", highestBid);

    return 0;
}
