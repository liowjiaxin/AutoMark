#include <stdio.h>

int main() {
    int n;

    while (1)
    {
        printf("Enter the number of bids: ");  //take user input for number of bids
        scanf("%d", &n);

        if (n >= 2)  // validate if there are at least 2 bids
        {
            break;
        }
        else
        {
            printf("Error: Number of bids must be at least 2. Please try again.\n");  //error message
        }
    }

    int bids[n];

    for (int i = 0; i < n; i++)  //loop for user input 
    {
        while (1)
        {
            printf("Bid %d: ", i + 1);  //user input for bids
            scanf("%d", &bids[i]);

            if (bids[i] >= 100000)  //validation loop for if bids are more than 100k
            {
                break;
            }
            else
            {
                printf("Error: Bid must be at least $100000. Please try again.\n"); //error message 
            }
        }
    }

    int highestBid = bids[0];
    for (int i = 1; i < nbids; i++)  //linear search
    {
        if (bids[i] > highestBid)
        {
            highestBid = bids[i];
        }
    }

    printf("The highest bid is: $%d\n", highestBid);  //output

    return 0;
}