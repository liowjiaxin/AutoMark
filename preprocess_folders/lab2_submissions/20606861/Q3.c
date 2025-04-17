#include <stdio.h>

int main() {
    int N, i, b, hb, vb = 0;

    // Get the number of bids (N)
    printf("Enter the number of bids: ");
    scanf("%d", &N);

    // Ensure at least 2 bids
    while (N < 2) {
        printf("Error: Number of bids must be at least 2. Please try again.\n");
        printf("Enter the number of bids: ");
        scanf("%d", &N);
    }

    // Initialize highestbid to 0 (lowest possible value)
    hb = 0;

    //  Get the bids and validate each one
    printf("Enter the bids (must be at least $100000):\n");
    for (i = 0; i < N; i++) {
        printf("Bid %d: ", i + 1);
        scanf("%d", &b);

        // If bid is less than 100000, prompt again
        while (b < 100000) {
            printf("Error: Bid must be at least $100000. Please try again: ");
            scanf("%d", &b);
        }

        // Update highest bid if current bid is higher
        if (b > hb) {
            hb = b;
        }

        vb++;  // Count valid bids
    }

    // If there are fewer than two valid bids, display an error
    if (vb < 2) {
        printf("Error: A highest bid cannot be determined.\n");
    } else {
        // Output the highest bid
        printf("The highest bid is: $%d\n", hb);
    }

    return 0;
}

