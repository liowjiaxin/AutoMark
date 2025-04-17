#include <stdio.h>
#include <stdlib.h>

int main() {
    int bidNum;
    float *bids;

    //input amount of bids
    printf("Enter the number of bids: ");
    scanf("%d", &bidNum);

    //loop to validate bids input
    while (1) {
        if (bidNum < 2) {
            printf("Error: Number of bids must be at least 2. Please try again: ");
        }
        else {
            break;
        }
    }

    //allocate memory
    bids = (float *)malloc(bidNum * sizeof(float));

    //input bids amount
    printf("Enter the bids (must be at least $100000):\n");
    for (int i = 0; i < bidNum; i++) {
        //validate bids
        while (bids[i] < 100000) {
            printf("Bid %d: ", i + 1);
            scanf("%f", &bids[i]);
            if (bids[i] < 100000) {
                printf("Bid must be at least $100000. Please try again: ");
            }
        }
    }

    //compare bids (find highest input)
    float highestBid = bids[0];
    for (int i = 1; i < bidNum; i++) {
        if (bids[i] > highestBid) {
            highestBid = bids[i];
        }
    }

    //output
    printf("The highest bid is: $%.2f\n", highestBid);

    //free memory
    free(bids);

    return 0;
}
