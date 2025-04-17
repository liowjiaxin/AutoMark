#include <stdio.h>

#define MIN_BID 100000 // Define minimum valid bid amount as 100,000

// Function to get the highest bid (with a logical error fixed)
int getHighestBid(int bids[], int N) {
    int highest = bids[0]; // Start with the first bid as the highest value
    for (int i = 1; i < N; i++) { // Loop through the rest of the bids
        if (bids[i] > highest) { // If the current bid is greater than the highest
            highest = bids[i]; // Update the highest bid to the current bid
        }
    }
    return highest; // Return the highest bid found
}

int main() {
    int N; // Variable to store the number of bids entered by the user
    printf("Enter the number of bids: "); // Prompt user for the number of bids
    scanf("%d", &N); // Read the number of bids from user input

    // Validate that N is at least 2
    while (N < 2) { // If N is less than 2, prompt again for valid input
        printf("Error: Number of bids must be at least 2. Please try again: ");
        scanf("%d", &N); // Read the number of bids again
    }

    int bids[N]; // Declare an array to store the bid amounts

    // Get the bids and validate each one
    for (int i = 0; i < N; i++) { // Loop through to get each bid
        printf("Bid %d: ", i + 1); // Prompt the user to enter the bid for the current index
        scanf("%d", &bids[i]); // Read the bid from the user input

        // Validate that the bid is at least $100,000
        while (bids[i] < MIN_BID) { // If the bid is less than $100,000
            printf("Error: Bid must be at least $100000. Please try again: ");
            scanf("%d", &bids[i]); // Prompt the user to enter a valid bid
        }
    }

    // Get and display the highest bid
    printf("The highest bid is: $%d\n", getHighestBid(bids, N)); // Call the function to get the highest bid and display it

    return 0; // End of program
}


