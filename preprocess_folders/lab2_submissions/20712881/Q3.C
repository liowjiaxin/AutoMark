#include <stdio.h>

//Function prototypes
int validateNumberOfBids(); // Function to validate and return the number of bids
void getBids(int bids[], int n); // Function to collect valid bids from the user
// Function to find and return the highest bid from the array
int findHighestBid(int bids[], int n);

int main() {
    int n; // Variable to store the number of bids

    // Validate and get number of bids
    n = validateNumberOfBids();
    // If the number of bids is less than 2, output an error message 
    if (n < 2) {
        printf("Error: At least two valid bids are required to determine the highest bid.\n");
        return 0; 
    }

    int bids[n]; // Declare an array to hold the bids
    getBids(bids, n); // Function call to populate the bids array

    // Find the highest bid
    int highestBid = findHighestBid(bids, n); // Function call to find the highest bid

    printf("The highest bid is $%d.\n", highestBid); // Output the highest bid

    return 0; 
}

// Function to validate and get the number of bids
int validateNumberOfBids() {
    int n; // Variable to store the number of bids
    do {
        // Prompt the user to enter the number of bids
        printf("Enter the number of bids (N ≥ 2): ");
        scanf("%d", &n); // Read user input
        // Check if the input is valid (N ≥ 2)
        if (n < 2) {
            printf("Invalid input. You must have at least 2 bids.\n");
        }
    } while (n < 2); // Repeat until a valid number is entered
    return n; // Return the valid number of bids
}

// Function to collect valid bids from the user
void getBids(int bids[], int n) {
    for (int i = 0; i < n; i++) { // Loop through each bid
        do {
            // Prompt the user to enter the bid amount
            printf("Enter bid #%d (minimum $100,000): ", i + 1);
            scanf("%d", &bids[i]); // Read user input
            // Validate that the bid is at least $100,000
            if (bids[i] < 100000) {
                printf("Invalid bid. Each bid must be at least $100,000.\n");
            }
        } while (bids[i] < 100000); // Repeat until a valid bid is entered
    }
}

// Function to find and return the highest bid in the array
int findHighestBid(int bids[], int n) {
    int highest = bids[0]; // Initialize the highest bid as the first bid in the array
    for (int i = 1; i < n; i++) { // Start loop from the second bid
        // If the current bid is greater than the highest, update the highest
        if (bids[i] > highest) {
            highest = bids[i];
        }
    }
    return highest; // Return the highest bid
}