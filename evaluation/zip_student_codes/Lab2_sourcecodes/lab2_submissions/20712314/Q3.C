#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;

    // Prompt the user to enter the number of bids
    printf("Enter the number of bids (N >= 2): ");
    scanf("%d", &N);

    // Validate that N is at least 2
    while (N < 2) {
        printf("\nError: Number of bids must be at least 2. Please try again: ");
        scanf("%d", &N);
    }

    // Dynamically allocate memory for the bids array
    int *bids = (int *)malloc(N * sizeof(int));
    if (bids == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Get the bids from the user
    for (int i = 0; i < N; i++) {
        printf("\nEnter bid %d (must be at least $100,000): ", i + 1);
        scanf("%d", &bids[i]);
        // Validate that each bid is at least $100,000
        while (bids[i] < 100000) {
            printf("\nError: Bid must be at least $100,000. Please try again: ");
            scanf("%d", &bids[i]);
        }
    }

    // Find the highest bid
    int highestBid = bids[0];
    for (int i = 1; i < N; i++) {
        if (bids[i] > highestBid) {
            highestBid = bids[i];
        }
    }

    // Output the highest bid
    printf("The highest bid is: $%d\n", highestBid);


    return 0;
}
