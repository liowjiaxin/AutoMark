#include <stdio.h>

int main() {
    int N;

    // Prompt the user to enter the number of bids
    printf("Enter the number of bids: ");
    scanf("%d", &N);

    // Checks that the number of bids is at least 2
    while (N < 2) {
        printf("Error: Number of bids must be at least 2. Please try again: ");
        scanf("%d", &N);
    }

    int numbids[N]; // Array to store the number of bids
    int highestBid = 0;

    // Prompt the user to enter each bid
    printf("Enter the bids (must be at least $100000):\n");
    for (int i = 0; i < N; i++) {
        printf("Bid %d: ", i + 1);
        scanf("%d", &numbids[i]);

        // Checks whether each bid is at least $100,000
        while (numbids[i] < 100000) {
            printf("Error: Bid must be at least $100000. Please try again: ");
            scanf("%d", &numbids[i]);
        }

        // Determine the highest bid provided 
        if (numbids[i] > highestBid) {
            highestBid = numbids[i];
        }
    }
    
    // Outputs the highest bid
    printf("The highest bid is: $%d\n", highestBid);

    return 0;
}
