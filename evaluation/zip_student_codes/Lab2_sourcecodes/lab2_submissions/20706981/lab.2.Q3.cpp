#include <stdio.h>
#include <stdlib.h>

// Function prototype
int findHighestBid(const int bids[], int count);

int main() {
    int N;

    // Step 1: Prompt the user to enter the number of bids and validate
    do {
        printf("Enter the number of bids (N >= 2): ");
        scanf("%d", &N);
        if (N < 2) {
            printf("Error: Number of bids must be at least 2. Please try again.\n");
        }
    } while (N < 2);

    // Dynamically allocate memory for the bids
    int *bids = (int *)malloc(N * sizeof(int));
    if (bids == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    // Step 2: Input the bid values and validate each bid
    printf("Enter the bids (must be at least $100000):\n");
    for (int i = 0; i < N; i++) {
        do {
            printf("Bid %d: ", i + 1);
            scanf("%d", &bids[i]);
            if (bids[i] < 100000) {
                printf("Error: Bid must be at least $100000. Please try again.\n");
            }
        } while (bids[i] < 100000);
    }

    // Step 3: Find the highest bid
    int highestBid = findHighestBid(bids, N);

    // Step 4: Output the highest bid
    printf("The highest bid is: $%d\n", highestBid);

    // Free the memory
    free(bids);

    return 0;
}

// Function to find the highest bid
int findHighestBid(const int bids[], int count) {
    int highest = bids[0]; // Assume the first bid is the highest initially
    for (int i = 1; i < count; i++) {
        if (bids[i] > highest) {
            highest = bids[i]; // Update the highest bid
        }
    }
    return highest;
}
