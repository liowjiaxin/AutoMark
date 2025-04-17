#include <stdio.h>

#define MIN 100000

int validateBid(int bidNumber);

int main()
{
    int numBids, highestBid = 0;

    printf("Enter the number of bids: ");

    while (1)
    {
        scanf("%d", &numBids);
        
        if(numBids != 1 || numBids < 2)
        {
            printf("Error: Number of bids must be at least 2. Please try again: ");
        }
        else
        {
            break;
        }
    }

    if (numBids < 2)
    {
        printf("Error: Number of bids must be at least 2. Exiting program.\n");

        return -1;
    }

    // User Input & Validate: Bids
    int bids[numBids];

    printf("Enter the bids (must be at least $%d):\n", MIN);

    for (int i = 0; i < numBids; i++)
    {
        bids[i] = validateBid(i + 1);

        if (bids[i] > highestBid)
        {
            highestBid = bids[i];
        }
    }

    // Display Highest Bid
    printf("The highest bid is: $%d\n", highestBid);

    return 0;
}


// Function to validate individual bids ---------------------------------------
int validateBid(int bidNumber) {
    int bid;
    printf("Bid %d: ", bidNumber);
    
    while (1)
    {
        scanf("%d", &bid);
        if (scanf("%d", &bid) != 1 || bid < MIN)
        {
            printf("Error: Bid must be at least $%d. Please try again: ", MIN);
        }
        else
        {
            break;
        }
    }

    return bid;
}