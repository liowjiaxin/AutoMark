#include <stdio.h>

// Function to get bids from the user
void getBids(int bids[], int count) 
{
    for (int i = 0; i < count; i++) 
    {
        printf("Bid %d: ", i + 1);
        scanf("%d", &bids[i]);

        // Validation of each bid must at least $100000
        while (bids[i] < 100000) 
        {
            printf("Error: Bid must be at least $100000. Please try again: ");
            scanf("%d", &bids[i]);
        }
    }
}

// Function to search for the highest bid
int getHighestBid(const int bids[], int count) 
{
    int highest = bids[0];
    // No need to compare with itself
    for (int i = 1; i < count; i++) 
    {
        if (bids[i] > highest) {
            highest = bids[i];
        }
    }
    return highest;
}

int main() 
{
    int numberOfBids;

    printf("Enter the number of bids: ");
    scanf("%d", &numberOfBids);

    while (numberOfBids < 2) 
    {
        printf("Error: Number of bids must be at least 2. Please try again: ");
        scanf("%d", &numberOfBids);
    }

    // To set the size of arrays based on the total number of bids of user enter 
    int bids[numberOfBids];

    printf("Enter the bids (must be at least $100000):\n");
    getBids(bids, numberOfBids);

    int highestBid = getHighestBid(bids, numberOfBids);

    printf("The highest bid is: $%d\n", highestBid);

    return 0;
}


