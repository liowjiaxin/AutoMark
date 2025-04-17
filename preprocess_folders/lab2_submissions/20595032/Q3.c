#include <stdio.h>

#define minimum 100000  // Minimum bid value

// Getting a valid bid
int BidValue() {
    int bid;
    while (1) {
        printf("Enter a bid (minimum $100,000): ");
        scanf("%d", &bid);
        if (bid >= minimum) {
            return bid;
        } else {
            printf("Error: Bid must be at least $100000. Please try again:\n");
        }
    }
}

int main() {
    int N;

    // Getting number of bids
    do {
        printf("Enter the number of bids (N >= 2): ");
        scanf("%d", &N);
        if (N < 2) {
            printf("Error: Number of bids must be at least 2.\n");
        }
    } while (N < 2);

    // Storage for bids
    int bids[N];
    
    // Prompt to input bids
    for (int i = 0; i < N; i++) {
        printf("Enter bid #%d: ", i + 1);
        bids[i] = BidValue();
    }

    // Find highest bid
    int highest = bids[0];
    for (int i = 1; i < N; i++) {
        if (bids[i] > highest) {
            highest = bids[i];
        }
    }

    // Output highest bid
    printf("The highest bid is: $%d\n", highest);

    return 0;
}
