#include <stdio.h>
#include <stdlib.h>

int main() {
    int *bids = NULL;       // Pointer for dynamic array
    int Bids;            // Number of bids
    int highestBid = 0;     // Variable to store the highest bid

    // User inputs number of bids
    do {
        printf("Enter the number of bids (N ≥ 2): ");
        scanf("%d", &Bids);
        if (Bids < 2) {
            printf("Invalid input. You must have at least two bids.\n");
        }
    } while (Bids < 2);

    // Allocate size dynamically according to user input 
    bids = (int *)malloc(Bids * sizeof(int));
    if (bids == NULL) {
        printf("Memory allocation failed. Exiting program.\n");
        return 1;
    }

    // User inputs each bid and validate bid ≥ 100,000
    printf("Enter the bids (must be at least $100,000):\n");
    for (int i = 0; i < Bids; i++) {
        do {
            printf("Bid %d: ", i + 1);
            scanf("%d", &bids[i]);
            if (bids[i] < 100000) {
                printf("Error: Bid must be at least $100,000.\n");
            }
        } while (bids[i] < 100000);
    }

    // Determine highest bid
    highestBid = bids[0]; 
    for (int *ptr = bids; ptr < bids + Bids; ptr++) {
        if (*ptr > highestBid) {
            highestBid = *ptr; 
        }
    }

    // Print the highest bid
    printf("The highest bid is: $%d\n", highestBid);

    return 0;
}
