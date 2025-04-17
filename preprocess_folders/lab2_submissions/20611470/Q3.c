#include <stdio.h>

int main() {
    int N, i;
    int highestBid = 0;

    // Prompt the user to enter the number of bids
    printf("Enter the number of bids: ");
    scanf("%d", &N);

    // Validate the number of bids
    while (N < 2) {
        printf("Error: Number of bids must be at least 2. Please try again: ");
        scanf("%d", &N);
    }

    int bids[N];

    // Prompt the user to enter the bids
    printf("Enter the bids (must be at least $100000):\n");
    for (i = 0; i < N; i++) {
        printf("Bid %d: ", i + 1);
        scanf("%d", &bids[i]);

        // Validate each bid
        while (bids[i] < 100000) {
            printf("Error: Bid must be at least $100000. Please try again: ");
            scanf("%d", &bids[i]);
        }

        // Determine the highest bid
        if (bids[i] > highestBid) {
            highestBid = bids[i];
        }
    }

    // Output the highest bid
    printf("The highest bid is: $%d\n", highestBid);

    return 0;
}
