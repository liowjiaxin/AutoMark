#include <stdio.h>

#define MIN_BID 100000  // minimum bid amount

int main() {
    int N;              // number of bids
    float bids[100];    // array to store bids 
    float highestBid;   // variable to store the highest bid

    // ask the user to enter the number of bids and validate
    do {
        printf("Enter the number of bids: ");
        scanf("%d", &N);

        if (N < 2) {
            printf("Error: Number of bids must me at least 2. Please try again.\n");
        }
    } while (N < 2);  // repeat until N >= 2

    // input and validate each bid
    for (int i = 0; i < N; i++) {
        printf("Enter bid %d (minimum $%d): ", i + 1, MIN_BID);
        scanf("%f", &bids[i]);

        // Validate the bid amount
        while (bids[i] < MIN_BID) {
            printf("Error: Bid must be at least $%d. Please try again: ", MIN_BID);
            scanf("%f", &bids[i]);
        }
    }

    // determine the highest bid
    highestBid = bids[0];  
    for (int i = 1; i < N; i++) {
        if (bids[i] > highestBid) {
            highestBid = bids[i];  
        }
    }

    // output the highest bid
    printf("The highest bid is: $%f\n", highestBid);

    return 0;
}
