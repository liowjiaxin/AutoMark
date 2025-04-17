#include <stdio.h>

// Functions
int getNumberOfBids(void);
void getBids(int bids[], int numberOfBids);
int findHighestBid(int bids[], int numberOfBids);

int main() {
    // Get number of bids
    int numberOfBids = getNumberOfBids();

    // Array to store the bids
    int bids[numberOfBids];

    // Get each bid value and store in the array
    getBids(bids, numberOfBids);

    // Find the highest bid
    int highestBid = findHighestBid(bids, numberOfBids);

    // Output the highest bid
    printf("The highest bid is: $%d\n", highestBid);

    return 0;
}

// Function to get and validate the number of bids
int getNumberOfBids(void) {
    int n;
    do {
        printf("Enter the number of bids (at least 2): ");
        scanf("%d", &n);
        if (n < 2) {
            printf("Error: Number of bids must be at least 2. Please try again.\n");
        }
    } while (n < 2);
    return n;
}

// To get and validate each bid
void getBids(int bids[], int numberOfBids) {
    for (int i = 0; i < numberOfBids; ++i) {
        do {
            printf("Enter bid %d (must be at least $100000): ", i + 1);
            scanf("%d", &bids[i]);
            if (bids[i] < 100000) {
                printf("Error: Bid must be at least $100000. Please try again.\n");
            }
        } while (bids[i] < 100000);
    }
}

// To find the highest bid in the array
int findHighestBid(int bids[], int numberOfBids) {
    int highest = bids[0];
    for (int i = 1; i < numberOfBids; ++i) {
        if (bids[i] > highest) {
            highest = bids[i];
        }
    }
    return highest;
}
