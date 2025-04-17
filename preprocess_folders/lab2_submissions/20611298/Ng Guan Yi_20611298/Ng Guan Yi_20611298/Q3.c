#include <stdio.h>

// Function prototypes
void EnterBids(int bids[], int count);
int HighestBid(const int bids[], int count);

// recceive the bid from user
void EnterBids(int bids[], int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("Bid %d: ", i + 1);
        scanf("%d", &bids[i]);

        // make sure each bid is at least $100000
        while (bids[i] < 100000)
        {
            printf("Error: Bid must be at least $100000. Please try again: ");
            scanf("%d", &bids[i]);
        }
    }
}

// calculation for the highest bid
int HighestBid(const int bids[], int count)
{
    int highest = bids[0];
    for (int i = 1; i < count; i++)
    {
        if (bids[i] > highest)
        {
            highest = bids[i];
        }
    }

    return highest;
}

int main()
{
    int N;

    // prompt the user to enter the number of bids
    printf("Enter the number of bids: ");
    scanf("%d", &N);

    // use while loop to make sure that the value dont excess 2
    while (N < 2)
    {
        printf("Error: Number of bids must be at least 2. Please try again: ");
        scanf("%d", &N);
    }

    int bids[N];

    // prompt use to enter the bids
    printf("Enter the bids (must be at least $100000):\n");
    EnterBids(bids, N);

    // determine the highest bid calculate form the
    int highestBid = HighestBid(bids, N);

    // print the final output
    printf("The highest bid is: $%d\n", highestBid);

    return 0;
}
