#include <stdio.h>

#define MIN_BID 100000
#define MAX_BIDS 100

void main() {
    int N, i;
    double bids[MAX_BIDS];  // Array to store bids set to 100 max
    double highest_bid = 0.0;
    int valid_bids_count = 0; //bids that are stored in array

    do {
        printf("Enter the number of bids (must be at least 2): ");
        scanf("%d", &N);

        if (N < 2) {
            printf("Number of bids must be at least 2.\n"); //make sure more than 2
        } else if (N > MAX_BIDS) {
            printf("Maximum number of bids is %d.\n", MAX_BIDS); //make sure less than 100, else array full
        }
    } while (N < 2 || N > MAX_BIDS);

  
    printf("\nEnter the bid amounts (minimum $100,000):\n");
    for (i = 0; i < N; i++) {
        double current_bid;
        
        do {
            printf("Bid %d: ", i + 1);
            scanf("%lf", &current_bid);

            if (current_bid < MIN_BID) {
                printf("Bid must be at least $100,000.\n");
            } else {
                bids[i] = current_bid;
                valid_bids_count++;
            }
        } while (current_bid < MIN_BID);
    }

    
    if (valid_bids_count >= 2) { //finding the highest bidder
        highest_bid = bids[0];
        for (i = 1; i < N; i++) {
            if (bids[i] > highest_bid) {
                highest_bid = bids[i];
            }
        }

        printf("\nAuction Results:\n");
        printf("Highest Bid: $%.2lf\n", highest_bid); //printing highest bidder
    }

}                                 