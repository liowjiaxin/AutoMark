#include <stdio.h>

// function to validate the number of bids
int getNumberOfBids() {
    int n;
    printf("Enter the number of bids (N): ");
    while (scanf("%d", &n) != 1 || n < 2) {
        printf("Invalid input. N must be an integer and at least 2.\n");
        printf("Enter the number of bids (N): ");
        while (getchar() != '\n'); // Clear invalid input
    }
    return n;
}

// function to validate and get the bid values
void getBids(int bids[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter bid %d (minimum $100,000): ", i + 1);
        while (scanf("%d", &bids[i]) != 1 || bids[i] < 100000) {
            printf("Invalid input. Bid must be an integer and at least $100,000.\n");
            printf("Enter bid %d (minimum $100,000): ", i + 1);
            while (getchar() != '\n'); // Clear invalid input
        }
    }
}

// function to find the highest bid
int findHighestBid(int bids[], int n) {
    int maxBid = bids[0];
    for (int i = 1; i < n; i++) {
        if (bids[i] > maxBid) {
            maxBid = bids[i];
        }
    }
    return maxBid;
}

int main() {
    int n;

    // get the number of bids with validation
    n = getNumberOfBids();

    // create array to store the bids and get the bid values
    int bids[n];
    getBids(bids, n);

    // find the highest bid
    int highestBid = findHighestBid(bids, n);

    
    printf("The highest bid is $%d.\n", highestBid);

    return 0;
}