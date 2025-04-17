#include <stdio.h>
#define MIN_BID 100000

int main()
{
    int num; 
    int bids[num];
    
    do {
        printf("Enter the number of bids: ");
        scanf("%d", &num);
        if (num < 2) {
            printf("Error: Number of bids must be at least 2. Please try again\n");
        }
    } while (num < 2);
    
    for (int i = 0; i < num; i++) {
        do {
            printf("Enter the bids (must be at least $100000):\n");
            scanf("%d", &bids[i]);
            if (bids[i] < MIN_BID) {
                printf("Error: Bid must be at least $100000. Please try again: ");
            }
        } while (bids[i] < MIN_BID);
    }
    
    int highest_bid = bids[0];
    for (int i = 0; i < num; i++) {
        if (bids[i] > highest_bid){
            highest_bid = bids[i];
        }
    }
    
    printf("The highest bid is: %d\n", highest_bid);
    
    return 0;
}