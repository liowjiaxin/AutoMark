#include <stdio.h>

int main() {
    int n;
    int i;
    
    //Get the number of bids
    printf("Enter the number of bids: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("Error: Number of bids must be at least 2. Please try again.\n");
        return 0;
    }

    int bids[n];
    printf("Enter the bids(must be at least $100000):\n");
    for (i = 0; i < n; i++) {
        printf("Bid %d: ", i + 1);
        scanf("%d", &bids[i]);

        // Validate each bid to ensure it is >= $100 000
        while (bids[i] < 100000) {
            printf("Error: Bid must be at least $100000. Please try again: ");
            scanf("%d", &bids[i]);
        }
    }

    // To find the highest bid
    int highestBid = bids[0];
    for (i = 1; i < n; i++) {
        if (bids[i] > highestBid) {
            highestBid = bids[i];
        }
    }

    // Print  the highest bid
    printf("The highest bid is: $%d\n", highestBid);

    return 0;
}
