#include <stdio.h>

// Function to get the number of bids and validate
int bid_count_validate () {
    int num_bids;
    printf ("Enter the number of bids: ");
    scanf ("%d", &num_bids);
    
    while (num_bids < 2) {
        printf ("Error: Number of bids must be at least 2. Please try again: ");
        scanf ("%d", &num_bids);
    }
    return num_bids;
}

// Function to get a valid bid amount
int valid_bid (int bid_number) {
    int bid;
    printf ("Bid %d: ", bid_number);
    scanf ("%d", &bid);

    while (bid < 100000) {
        printf ("Error: Bid must be at least $100000. Please try again: ");
        scanf ("%d", &bid);
    }
    return bid;
}

// Function to find the highest bid in the array
int find_highest_bid (int bids[], int num_bids) {
    int highest_bid = bids[0];
    for (int i = 1; i < num_bids; i++) {
        if (bids[i] > highest_bid) {
            highest_bid = bids[i];
        }
    }
    return highest_bid;
}

int main () {
    int num_bids = bid_count_validate ();
    int bids[num_bids];

    for (int i = 0; i < num_bids; i++) {
        bids[i] = valid_bid (i + 1);
    }

    int highest_bid = find_highest_bid (bids, num_bids);
    printf ("The highest bid is: $%d\n", highest_bid);

    return 0;
}