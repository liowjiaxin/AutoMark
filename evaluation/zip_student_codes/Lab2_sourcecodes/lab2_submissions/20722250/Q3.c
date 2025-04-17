#include <stdio.h>

int main() 
{
    int N;
    float bids[N];
    float highestBid = 0;

    // prompt user to enter number of bids, N
    printf("Enter the number of bids (at least 2): ");

    // validate input (number of bids at least 2)
    do 
    {
        scanf("%d", &N);

        if (N < 2) 
        {
            printf("Error: Number of bids must be at least 2. Please try again: ");
        }
    } while (N < 2);

    // prompt user to enter bids
    printf("Enter the bids (at least $100000):\n");

    for (int i = 0; i < N; i++) 
    {
        printf("Bid %d: ", i+1);

        // validate input (each bid at least $100000)
        do 
        {
            scanf("%f", &bids[i]);

            if (bids[i] < 100000) 
            {
                printf("Error: Bid must be at least $100000. Please try again: ");
            }
        } while (bids[i] < 100000);
    }

    // determine the highest bid
    for (int i = 0; i < N; i++) 
    {
        if (bids[i] > highestBid) 
        {
            highestBid = bids[i];
        }
    }

    // print the highest bid
    printf("The highest bid is: $%.0f\n", highestBid);

    return 0;
}
