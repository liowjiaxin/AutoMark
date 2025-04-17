//Question 3
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    int *bids;

    //Prompts the user to enter the number of bids
    do {
        printf("Enter the number of bids: ");
        scanf("%d", &N);
        if (N < 2) {
            printf("Error: Number of bids must be at least 2. Please try again.\n");
        }
    } while (N < 2);

    //Dynamically allocates memory for the bids array
    bids = (int *)malloc(N * sizeof(int));
    if (bids == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    //Prompts the user to input the values of the bids
    for (int i = 0; i < N; i++) {
        do {
            printf("Bid %d: ", i + 1);
            scanf("%d", &bids[i]);
            if (bids[i] < 100000) {
                printf("Error: Bid must be at least $100000. Please try again.\n");
            }
        } while (bids[i] < 100000);
    }

    //Determines the highest bid
    int highestBid = bids[0];
    for (int i = 1; i < N; i++) {
        if (bids[i] > highestBid) {
            highestBid = bids[i];
        }
    }

    //Outputs the value of the highest bid
    printf("The highest bid is $%d\n", highestBid);

    //Frees the allocated memory
    free(bids);

    return 0;
}
