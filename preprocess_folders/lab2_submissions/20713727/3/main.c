#include <stdio.h>

int main() {
    int N; // Number of bids
    float highestBid = 0; 

    // Prompt the user to enter the number of bids and validate
    printf("Enter the number of bids: ");
    scanf("%d", &N);

    if (N < 2) {
        printf("Error: Number of bids must be at least 2. Please try again: ");
        scanf("%d", &N);
    }

    float bids[N]; // Array to store the bids

    // Input bid values with validation
    printf("Enter the bids (must be at least $100000):\n");
    for (int i = 0; i < N; i++) {
        while (1) {
            printf("Bid %d: ", i + 1);
            scanf("%f", &bids[i]);

            if (bids[i] >= 100000.0) {
                break; 
            } else {
                printf("Error: Bid must be at least $100000. Plese try again: ");
                scanf("%f", &bids[i]);
            }
        }
    }

    // Determine the highest bid
    for (int i = 0; i < N; i++) {
        if (bids[i] > highestBid) {
            highestBid = bids[i];
        }
    }

    printf("The highest bid is: $%.2f\n", highestBid);

    return 0;
}
