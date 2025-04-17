#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    float* bids; 
    float highest_bid = 0.0;

    // Prompt the user to enter the number of bids
    do {
        printf("Enter the number of bids: ");
        scanf_s("%d", &N);
        if (N < 2) {
            printf("Error: Number of bids must be at least 2. Please try again.\n");
        }
    } while (N < 2);

    // Memory allocates dynamically using malloc()
    bids = (float*)malloc(N * sizeof(float));

    // checking for memory allocation
    if (bids == NULL) {
        printf("Memory not allocated.\n");
    }

    else {
        // Prompt the user to enter the values of the bids
        printf("Enter the bids (must be at least $100000):\n");
        for (int i = 0; i < N; i++) {
            do {
                printf("Bid %d: ", i + 1);
                scanf_s("%f", &bids[i]);
                if (bids[i] < 100000) { // check if value of bit is more than $100000
                    printf("Error: Each bid must be at least $100000. Please try again:\n");
                    scanf_s("%f", &bids[i]);
                }
            } while (bids[i] < 100000);
        }

        // Determine the highest bid
        highest_bid = bids[0];
        for (int i = 1; i < N; i++) {
            if (bids[i] > highest_bid) {
                highest_bid = bids[i];
            }
        }

        // print the highest bid
        printf("\nThe highest bid is: $%.0f\n", highest_bid);
    }

    free(bids);

    return 0;
}
