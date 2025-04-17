

int main() {
    int numBids;
    float bids[100]; 
    float highestBid = 0.0;

    // Prompt the user to enter the number of bids
    do {
        printf("Enter the number of bids: ");
        scanf("%d", &numBids);
        if (numBids < 2) {
            printf("Error: Number of bids must be at least 2. Please try again.\n");
        }
    } while (numBids < 2);

    //  ensuring each bid is at least $100,000
    for (int i = 0; i < numBids; i++) {
        do {
            printf("Enter bid %d (must be at least $100,000): ", i + 1);
            scanf("%f", &bids[i]);
            if (bids[i] < 100000) {
                printf("Error: Bid must be at least $100,000. Please try again.\n");
            }
        } while (bids[i] < 100000);
    }

    // Determine the highest bid
    highestBid = bids[0];
    for (int i = 1; i < numBids; i++) {
        if (bids[i] > highestBid) {
            highestBid = bids[i];
        }
    }

    // Output the highest bid
    printf("The highest bid is: $%.2f\n", highestBid);

    return 0;
}

