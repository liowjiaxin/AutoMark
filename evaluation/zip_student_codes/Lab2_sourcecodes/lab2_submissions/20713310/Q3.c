#include <stdio.h>
int highbid(const int a[],int n);
int main()
{
    int bid;
    printf("Enter the number of bids:");
    scanf("%d",&bid);

    if(bid<2)
    {
        while(bid<2)
        {
            printf("Try again:");
            scanf("%d",&bid);
        }
    }

    int i,auction[bid];
    printf("Enter the bids (Must be atleast $100000):\n");
    for (i = 0; i < bid; i++)
    {
        printf("\tBid %d:",i+1);
        scanf("%d",&auction[i]);

        if (auction[i]<100000)
        {
            while (auction[i]<100000)
            {
                printf("\tPlease try again:");
                scanf("%d",&auction[i]);
            }
            
        }
        
    }

    int high_bid=0,big;
    big=auction[0];

    for(i=0;i<=bid;i++)
    {
        if(big<auction[i])
        {
            big=auction[i];
        }

        else{
            big=big;
        }
    }
    high_bid=big;
    
    printf("Highest bid: %d",high_bid);

    return 0;    
}
