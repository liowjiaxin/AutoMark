#include <stdio.h>
#define MAX 100

int main() {
    // prompt user to enter the number of bids where the number of bids must be at least 2
    int numBids;
    printf("Enter the number of bids: ");
    scanf("%d", &numBids);
    while (numBids < 2) {
        printf("Error: Number of bids must be at least 2. Please try again: "); // Error message displayed when the number of bids is less than 2 and prompt user to enter again
        scanf("%d", &numBids);
    }

    // prompt user to enter the bids where the bid must be at least $100000
    int bids[MAX];
    printf("Enter the bids (must be at least $100000) : \n");
    for (int i = 0; i < numBids; i++) {
        printf("Bid %d: ", i+1);
        scanf("%d", &bids[i]);
        while (bids[i] < 100000) {
            printf("Error: Bid must be at least $100000. Please try again: "); // Error message displayed when the bid is less than $100000 and prompt user to enter again
            scanf("%d", &bids[i]);
        }
    }

    // calculate the highest bid
    int highestBid = bids[0];
    for (int i = 0; i < numBids; i++) {
        if (bids[i] > highestBid) {
            highestBid = bids[i];
        }
    }

    // display the highest bid
    printf("The highest bid is: $%d", highestBid);

    return 0;
}