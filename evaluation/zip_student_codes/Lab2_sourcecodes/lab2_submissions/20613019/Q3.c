#include <stdio.h>

#define MIN_BID 100000

int main() {
    int N;
    
    //Enter number of bids
    do{
        printf("Enter the number of bids (minimum 2):");
        scanf("%d",&N);
        if (N < 2) {
        printf("Error! The number of bids must be at least 2. Please try again.\n");
        }
    } while (N < 2);

    int bids[N];
    int highestBid = 0;

    // Input bids and validate each bid
    for (int i = 0; i < N; i++) {
        int bid;
        do {
            printf("Enter bid %d (minimum $%d): ", i + 1, MIN_BID);
            scanf("%d", &bid);
            if (bid < MIN_BID) {
                printf("Invalid bid. Please enter a bid of at least $%d.\n", MIN_BID);
            }
        } while (bid < MIN_BID);

        // Store the valid bid
        bids[i] = bid;

        // Update the highest
        if (bid > highestBid) {
            highestBid = bid;
        }
    }

    // Display the highest
    printf("The highest bid is: $%d\n", highestBid);

    return 0;
}
