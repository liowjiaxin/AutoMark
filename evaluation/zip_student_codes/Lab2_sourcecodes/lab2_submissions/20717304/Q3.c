#include <stdio.h>

int main() {
    int nbids;

    while (1)
    {
        printf("Enter the number of bids: ");  //take user input for number of bids
        scanf("%d", &nbids);

        if (nbids >= 2)  // validate if there are at least 2 bids, if not display error
        {
            break;
        }
        else
        {
            printf("Error: Number of bids must be at least 2. Please try again.\n");  //error message
        }
    }

    int bids[nbids];

    for (int i = 0; i < nbids; i++)  //traverse through array and take user input 
    {
        while (1)
        {
            printf("Bid %d: ", i + 1);  //user input for bids
            scanf("%d", &bids[i]);

            if (bids[i] >= 100000)  //validat if bids are more than 100k
            {
                break;
            }
            else
            {
                printf("Error: Bid must be at least $100000. Please try again.\n"); //error message 
            }
        }
    }

    int hbid = bids[0];
    for (int i = 1; i < nbids; i++)  //traverse through loop and find highest
    {
        if (bids[i] > hbid)
        {
            hbid = bids[i];
        }
    }

    printf("The highest bid is: $%d\n", hbid);  //output the highiest bid

    return 0;
}
