#include <stdio.h>

int main()
{
    int NumBids, i;
    int bids [100];

    //Get num of bids
    do 
    {
        printf("Enter the number of bids: ");
        scanf("%d", &NumBids); //put number of bids into NumBids

        if (NumBids < 2) //print error if user enters number of bids <= 2
        {
            printf("Error: Number of bids must be at least 2. Please try again. \n");
        }
    } while (NumBids < 2);

    //get bid values from user and validate
    for (int i = 0; i < NumBids; i++)
    {
        do
        {
            printf("Enter bid %d (must be at least $100000): ", i+1);
            scanf("%d", &bids[i]); //put the $$$ of bids in bids[i]

            if (bids[i] < 100000) //print error if user enters bid <= 100000
            {
                printf("Error: Bid must be at least $100000. PLease try again. \n");
            }
        }while(bids[i] < 100000);
    }

    //find hightest bid
    int highest_bid = bids[0];
    for (int i = 1; i < NumBids; i++)
    {
        if (bids[i] > highest_bid)
        {
            highest_bid = bids[i];
        }
    }

    //display highets bid
    printf("The highest bid is: $%d \n", highest_bid);

    return 0;
}
