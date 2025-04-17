#include <stdio.h>
#include <stdlib.h>

int main() {
    int B;                 // Number of bids
    int *bids = NULL;      // Array to store bid values
    int highestBid = 0;    // Variable to track the highest bid

    //User input
    do {
        printf("Enter the number of bids: ");
        scanf("%d", &B);
        if (B < 2) {
            printf("Error: Number of bids must be greater or equal to 2. Please try again: ");
            scanf("%d", &B);
        }
    } while (B < 2);

    //Allocate memory to store bids
    bids = (int *)malloc(B * sizeof(int));
    if (bids == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Exit the program if memory allocation fails
    }

    //User input
    printf("Enter the bids (must be at least $100000):\n");
    for (int i = 0; i < B; i++) {
        do {
            printf("Bid %d: ", i + 1);
            scanf("%d", &bids[i]);
            if (bids[i] < 100000) {
                printf("Error: Bid must be at least $100000. Please try again: ");
                scanf("%d", &bids[i]);
            }
        } while (bids[i] < 100000);
    }

    //Choose the highest bid
    highestBid = bids[0];
    for (int i = 1; i < B; i++) {
        if (bids[i] > highestBid) {
            highestBid = bids[i];
        }
    }

    //Print the highest bid
    printf("The highest bid is: $%d\n", highestBid);

    //Release allocated memory
    free(bids);

    return 0;
}