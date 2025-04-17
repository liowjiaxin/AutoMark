#include <stdio.h>
#include <stdlib.h>

int main() 
{
    //set the variables
    int N, i;
    float bid;

    printf("enter the number of bids: ");
    scanf("%d", &N);

    //set the number limitation for the bids
    while (N < 2) 
    {
        printf("number of bids must be at least 2, please try again: ");
        scanf("%d", &N);
    }

    //allocating the memory
    float* bids = (float*)malloc(N * sizeof(float));

    //exit if memory allocation fails
    if (bids == 0) 
    {
        printf("error\n");
        return 1;
    }

    //getting the data needed
    for (i = 0; i < N; i++) 
    {
        printf("Enter bid %d (must be at least $100000): ", i + 1);
        scanf("%f", &bid);

        //what happends if bid is less than 100k
        while (bid < 100000) 
        {
            printf("bid must be at least $100000, please try again: ");
            scanf("%f", &bid);
        }

        bids[i] = bid;
    }

    //determining the highest bid
    float highest = bids[0];
    for (i = 1; i < N; i++) 
    {
        if (bids[i] > highest) 
        {
            highest = bids[i];
        }
    }

    printf("The highest bid is: $%.0f\n", highest);

    free(bids);

    return 0;
}
