#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;

    // validation and input of bids
    do
    {
        printf("Enter the number of bids: ");
        scanf("%d", &N);
        if (N < 2)
        {
            printf("Invalid number of bids, have to be greater than 2.");
        }
    } while (N < 2);

    // input bids and validation

    float bids[N];
    printf("Enter the bids (Must be at least $100000):\n");
    for (int i = 0; i < N; i++)
    {
        printf("Bid %d:\n", i + 1);
        scanf("%f", &bids[i]);
        while (bids[i] < 100000)
        {
            printf("Error: Bid must be at least $100,000. Please try again: ");
            scanf("%f", &bids[i]);
        }
    }

    // determining the highest bid
    float highest_bid = bids[0];
    for (int i = 0; i < N; i++)
    {
        if (bids[i] > highest_bid)
        {
            highest_bid = bids[i];
        }
    }

    // outputting highest bid
    printf("The highest bid is: %.2f", highest_bid);
    return 0;
}
