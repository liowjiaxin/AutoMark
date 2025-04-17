#include <stdio.h>

#define MIN_BID 100000  // Minimum valid bid amount

// Function prototypes
void getBids(int bids[], int n);
int findHighestBid(int bids[], int n);

int main() {
    int N;

    // Step 1: Prompt user to enter the number of bids
    do {
        printf("Enter the number of bids: ");
        scanf("%d", &N);
        if (N < 2) {
            printf("Errror: The number of bids must be at least 2.\n");
        }
    } while (N < 2);

    // Declare an array to store the bids
    int bids[N];

    // Step 2: Get the bids from the user
    getBids(bids, N);

    // Step 3: Find the highest bid
    int highestBid = findHighestBid(bids, N);

    // Step 4: Output the highest bid
    printf("The highest bid is: $%d\n", highestBid);

    return 0;
}

// Function to get the bids from the user
void getBids(int bids[], int n) {
    for (int i = 0; i < n; i++) {
        do {
            printf("Enter bit %d (must be at least $100,000): ", i + 1);
            scanf("%d", &bids[i]);
            if (bids[i] < MIN_BID) {
                printf("Error: Bid must be at least $100,000.\n");
            }
        } while (bids[i] < MIN_BID);  // Keep asking until the bid is valid
    }
}

// Function to find the highest bid
int findHighestBid(int bids[], int n) {
    int highest = bids[0];  // Assume the first bid is the highest

    for (int i = 1; i < n; i++) {
        if (bids[i] > highest) {
            highest = bids[i];
        }
    }

    return highest;
}