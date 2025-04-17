#include <stdio.h>


int getValidBidCount() {
    int N;
    do {
        printf("Enter the number of bids (N >= 2): ");
        scanf("%d", &N);
        if (N < 2) {
            printf("The number of bids must be at least 2.\n");
        }
    } while (N < 2);
    return N;
}

// Function to get valid bid values (each bid must be >= 100000)
void getValidBids(int bids[], int N) {
	int i;
    for (i = 0; i < N; i++) {
        do {
            printf("Enter bid %d: ", i + 1);
            scanf("%d", &bids[i]);
            if (bids[i] < 100000) {
                printf("Bid must be at least 100,000.\n");
            }
        } while (bids[i] < 100000);
    }
}

// Function to find the highest bid
int findHighestBid(int bids[], int N) {
    int highest = bids[0];
    int i;
    for ( i = 1; i < N; i++) {
        if (bids[i] > highest) {
            highest = bids[i];
        }
    }
    return highest;
}

int main() {
    int N = getValidBidCount();  // Get the valid number of bids
    int bids[N];  

    getValidBids(bids, N);  // Get valid bids from the user

    int highestBid = findHighestBid(bids, N);  // Find the highest bid

    printf("The highest bid is: %d\n", highestBid);

    return 0;
}

