#include <stdio.h>

int main() {
    int N;

    // Step 1: Input number of bids and validate
    do {
        printf("Enter the number of bids (N >= 2): ");
        scanf("%d", &N);
        if (N < 2) {
            printf("Invalid input. There must be at least two bids.\n");
        }
    } while (N < 2);

    float bids[N];  // Array to store bid values

    // Step 2: Input bids and validate each bid
    for (int i = 0; i < N; i++) {
        do {
            printf("Enter bid %d (at least $100,000): ", i + 1);
            scanf("%f", &bids[i]);
            if (bids[i] < 100000) {
                printf("Invalid bid. It must be at least $100,000.\n");
            }
        } while (bids[i] < 100000);
    }

    // Step 3: Determine the highest bid
    float highestBid = bids[0];
    for (int i = 1; i < N; i++) {
        if (bids[i] > highestBid) {
            highestBid = bids[i];
        }
    }

    // Step 4: Output the highest bid
    printf("The highest bid is: $%.2f\n", highestBid);

    return 0;
}
