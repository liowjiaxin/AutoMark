#include <stdio.h>

#define BIDSSIZE 100

int main() {
    int numberofBids;
    float bids[BIDSSIZE]; 
    float highestBid = 0.0;


    printf("Enter the number of bids (N >= 2): ");
    scanf("%d", &numberofBids);

    if (numberofBids < 2) {
        printf("Number of bids must be at least 2.\n");
        return 0;
    }


    printf("Enter the bids (each bid must be at least $100000):\n");
    for (int i = 0; i < numberofBids; i++) {
        while (1) {
            printf("Bid %d: ", i + 1);
            scanf("%f", &bids[i]);
            if (bids[i] >= 100000.0) {
                break; 
            } else {
                printf("Bid must be at least $100000. Please try again.\n");
            }
        }
    }


    highestBid = bids[0]; 
    for (int i = 1; i < numberofBids; i++) {
        if (bids[i] > highestBid) {
            highestBid = bids[i];
        }
    }


    printf("The highest bid is: $%.2f\n", highestBid);

    return 0;
}
