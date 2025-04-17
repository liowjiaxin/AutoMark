#include <stdio.h>
#include <stdlib.h> // For dynamic memory allocation

int main() {
    int numberOfBids;       // To store the number of bids
    int *bidsArray = NULL;  // Pointer for storing bids dynamically
    int maxBid = 0;     // Variable to track the highest bid

    // Step 1: Get the number of bids (must be at least 2)
    while (1) {
        printf("Enter the number of bids: ");
        scanf("%d", &numberOfBids);

        if (numberOfBids >= 2) {
            break; // Exit the loop if the number of bids is valid
        } else {
            printf("Error: Number of bids must be at least 2. Please try again.\n");
        }
    }

    // Step 2: Allocate memory for the bids based on user input
    bidsArray = (int *)malloc(numberOfBids * sizeof(int));
    if (bidsArray == NULL) { // Check if memory allocation was successful
        printf("Memory allocation failed! Exiting program.\n");
        return 1; // Exit with an error code
    }

    // Step 3: Input each bid and validate it
    printf("Enter the bids (must be at least $100000):\n");
    for (int i = 0; i < numberOfBids; i++) {
        while (1) {
            printf("Bid %d: ", i + 1);
            scanf("%d", &bidsArray[i]);

            if (bidsArray[i] >= 100000) { 
                break; // Accept the bid if it meets the minimum requirement
            } else {
                printf("Error: Bid must be at least $100000. Please try again.\n");
            }
        }
    }

    // Step 4: Find the highest bid from the array
    for (int i = 0; i < numberOfBids; i++) {
        if (bidsArray[i] > maxBid) {
            maxBid = bidsArray[i]; // Update the maximum bid if a higher bid is found
        }
    }

    // Step 5: Display the highest bid
    printf("The highest bid is: $%d\n", maxBid);

    // Step 6: Free allocated memory to avoid memory leaks
    free(bidsArray);

    return 0; // Indicate successful program execution
}
