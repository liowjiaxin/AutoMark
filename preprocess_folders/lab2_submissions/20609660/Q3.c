#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Initialisation
    int numberOfBids = 0;

    // Prompt user to enter the number of bids
    printf("Enter the number of bids: ");
    scanf(" %d", &numberOfBids);

    // Input validating from user, user must provide a value of bids that is at least 2
    while (numberOfBids < 2)
    {
        printf("Error: Number of bids must be at least 2. Please try again: ");
        scanf(" %d", &numberOfBids);
    }

    // Allocate memory for the array for purpose to store all the value of bidding
    int *bidArrayPtr = (int *)malloc(numberOfBids * sizeof(int));

    // Error handling if memory allocation fail
    if (bidArrayPtr == NULL)
    {
        printf("Memory not allocated.\n");
        exit(0);
    }

    // Get the bids from user and store it in the array by looping through the index
    for (size_t i = 0; i < numberOfBids; i++)
    {
        // Initialisation
        int biddingValue = 0;

        // Prompt user to enter the bids
        printf("Enter bid %d (Must be at least $100000): ", i + 1);
        scanf(" %d", &biddingValue);

        // Input validating from user, user must provide a value of bids that is at least $100000
        while (biddingValue < 100000)
        {
            printf("Error: Bid must be at least $100000. Please try again: ");
            scanf(" %d", &biddingValue);
        }

        // Store the value of bidding into the array
        bidArrayPtr[i] = biddingValue;
    }

    // Initialisation for a variable to store the highest bid
    int highestBid = bidArrayPtr[0];

    // Loop through the array to get the highest bid
    for (int i = 1; i < numberOfBids; i++)
    {
        // If the value of the highest bid is less than the value of the bid in the array, it will replace the value of the highest bid
        if (highestBid < bidArrayPtr[i])
        {
            highestBid = bidArrayPtr[i];
        }
    }

    // Print out the highest bid
    printf("The highest bid is $%d", highestBid);
}