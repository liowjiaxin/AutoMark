#include <stdio.h>

// Function to find the highest bid
float findHighestBid(const float bids[], int n) {
    float highest = bids[0];
    for (int i = 1; i < n; ++i) {
        if (bids[i] > highest) {
            highest = bids[i];
        }
    }
    return highest;
}

int main() {
    int n;

    printf("Enter the number of bids: ");
    while (1) {
        scanf("%d", &n);

        if (n < 2) {
            printf("Error: Number of bids must be at least 2. Please try again: ");
        } else {
            break;
        }
    }

    float bids[n]; // Declare the array 
    int i;

    printf("Enter the bids (must be at least $100,000): \n");

    // Input bids with validation
    for (i = 0; i < n; ++i) { 
        while (1) {
            printf("Bid %d: ", i + 1); 
            scanf("%f", &bids[i]);

            if (bids[i] >= 100000) {
                break; 
            } else {
                printf("Error: Bid must be at least $100,000. Please try again.\n");
            }
        }
    }

    float highestBid = findHighestBid(bids, n);

    printf("The highest bid is: $%.2f\n", highestBid);

    return 0;
}