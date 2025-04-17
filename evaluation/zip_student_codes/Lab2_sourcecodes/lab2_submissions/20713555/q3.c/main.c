#include <stdio.h>
#include <stdlib.h>

#define MIN_BID 100000 // Minimum valid bid
#define MAX_BIDS 100   // Maximum number of bids allowed

// Function prototypes
int getNumberOfBids();
void getBids(int N, float *bids);
float findHighestBid(int N, float *bids);

int main() {
    // Introduce the element 
    int N; 
    float bids[MAX_BIDS];

    // Prompt the user to enter the number of bids
    N = getNumberOfBids();

    // Prompt the user to enter the value of bids
    getBids(N, bids);

    // Determine the highest value of bid
    float highestBid = findHighestBid(N, bids);

    // Output the value of the highest bid
    printf("The highest bid is: $%.2f\n", highestBid);

    return 0;
}

// Function to get the number of bids from the user
int getNumberOfBids() {
    int N;
    do {
        printf("Enter the number of bids (N >= 2): ");
        scanf("%d", &N);
        if (N < 2) {
            printf("Error: Number of bids must be at least 2. Please try again.\n");
        }
    } while (N < 2);
    
    return N;
}

// Function to get valid bids from the user
void getBids(int N, float *bids) {
    printf("Enter the bids (must be at least $%d):\n", MIN_BID);
    
    for (int i = 0; i < N; i++) {
        float bid;
        do {
            printf("Bid %d: ", i + 1);
            scanf("%f", &bid);
            if (bid < MIN_BID) {
                printf("Error: Bid must be at least $%d. Please try again.\n", MIN_BID);
            }
        } while (bid < MIN_BID);
        
        // Store the valid bid in the array
        bids[i] = bid;
    }
}

// Function to find the highest bid from the entered values
float findHighestBid(int N, float *bids) {
    float highestBid = bids[0]; // Start with the first bid as the highest

    for (int i = 1; i < N; i++) {
        if (bids[i] > highestBid) {
            highestBid = bids[i]; // Update highest bid if current is greater
        }
    }

    return highestBid;
}