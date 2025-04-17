#include <stdio.h>

void inputBids(float bids[], int n);
float findHighestBid(const float bids[], int n);

int main() {
    int n;

    do {
        printf("Enter the number of bids: ");
        scanf("%d", &n);
        if (n < 2) {
            printf("Error: Number of bids must be at least 2. Please try again.\n");
        }
    } while (n < 2);

    float bids[n];
    
    inputBids(bids, n);
    float highestBid = findHighestBid(bids, n);
    printf("The highest bid is: $%.0f\n", highestBid);

    return 0;
}


void inputBids(float bids[], int n) {
    for (int i = 0; i < n; i++) {
        do {
            printf("Bid %d: ", i + 1);
            scanf("%f", &bids[i]);
            if (bids[i] < 100000) {
                printf("Error: Bid must be at least $100000. Please try again.\n");
            }
        } while (bids[i] < 100000); 
    }
}


float findHighestBid(const float bids[], int n) {
    float highest = bids[0];   // Assume first bid is the highest
    for (int i = 1; i < n; i++) {
        if (bids[i] > highest) {
            highest = bids[i];
        }
    }
    return highest;
}
