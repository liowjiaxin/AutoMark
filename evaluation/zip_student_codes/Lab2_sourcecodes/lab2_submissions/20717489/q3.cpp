#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>  // Includes malloc and free functions

int main() {
    int N, i;
    double highestBid;

    //Get the number of bids, and validate that N >= 2
    do {
        printf("Enter the number of bids (at least 2): ");
        scanf("%d", &N);
        if (N < 2) {
            printf("Error: The number of bids must be at least 2. Please enter again.\n");
        }
    } while (N < 2);  // Keep prompting the user until N >= 2

    //Dynamically allocate memory to store the bids
    double* bids = (double*)malloc(N * sizeof(double));  // Allocate memory

    // Check if memory allocation was successful
    if (bids == NULL) {
        printf("Memory allocation failed.\n");
        return 1;  // Exit if memory allocation fails
    }

    //Get the bids and validate each bid is at least $100,000
    printf("Enter the bids (each bid must be at least $100,000):\n");
    for (i = 0; i < N; i++) {
        while (1) {
            printf("Bid %d: ", i + 1);
            scanf("%lf", &bids[i]);
            if (bids[i] >= 100000) {
                break;  // Exit loop if the bid is valid
            }
            else {
                printf("Bid must be at least $100,000. Please enter again.\n");
            }
        }
    }

    //Find the highest bid
    highestBid = bids[0];  // Initialize highestBid with the first bid
    for (i = 1; i < N; i++) {
        if (bids[i] > highestBid) {
            highestBid = bids[i];  // Update highestBid if a higher bid is found
        }
    }

    //Output the highest bid
    printf("The highest bid is: $%.2lf\n", highestBid);

    // Free dynamically allocated memory
    free(bids);

    return 0;
}