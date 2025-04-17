#include <stdio.h>

int maxer(int arr[], int count);

int main(void)
{
    int numbids;
    int bid;
    int maxbid;

    numbids = 0;
    printf("Enter the number of bids\n");
    while (numbids <= 2)
    {
        scanf("%d", &numbids);
    }

    int bids[numbids];
    bid = 0;
    maxbid = 0;

    int i = 0;
    while (i < numbids)
    {
        printf("Enter your bid: \n");
        scanf("%d", &bid);

        if (bid < 100000)
        {
            printf("Bid cannot be less than $100000\n");
        }
        else
        {
            bids[i] = bid;
            i++;
        }
    }

    maxbid = maxer(bids, numbids);

    printf("The highest bid is: $%d", maxbid);
}

int maxer(int arr[], int count)
{
    int max;

    max = 0;
    for (int i = 0; i < count; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}