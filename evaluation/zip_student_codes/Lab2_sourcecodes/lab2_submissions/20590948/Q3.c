#include <stdio.h>

int main() {
    int N; // Number of bids
    float bids[100]; // Array to ensure that the bids are stored (a max of 100 bids for simplicity)
    float highestBid = 0.0; // The highest bid is to be stored

    // Step 1: Ask user to enter the number of bids and ensure that is valid 
    printf("Enter the number of bids: ");
    scanf("%d", &N);

    while (N < 2) {
        printf("Error: Number of bids must be at least 2. Please try again: ");
        scanf("%d", &N);
    }

    // Step 2: Input the bids and make sure each bid is valid
    printf("Enter the bids (must be at least $100000):\n");
    for (int i = 0; i < N; i++) {
        printf("Bid %d: ", i + 1);
        scanf("%f", &bids[i]);

        while (bids[i] < 100000) {
            printf("Error: Bid must be at least $100000. Please try again: ");
            printf("Bid %d: ", i + 1); // Ask user to reprompt for the same bid
            scanf("%f", &bids[i]);
        }
    }

    // Step 3: Decide the highest bid
    highestBid = bids[0];
    for (int i = 1; i < N; i++) {
        if (bids[i] > highestBid) {
            highestBid = bids[i];
        }
    }

    // Step 4: Display output of the highest bid
    printf("The highest bid is: $%.0f\n", highestBid);

    return 0;
}
