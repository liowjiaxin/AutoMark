#include <stdio.h>

#define MIN_BID 100000

int main()
{
    int N;
    do {
        printf("Enter the number of bids (must be more than 1): \n");
        scanf("%d", &N);
        if (N < 2) {
            printf("The number of bids must be at least 2. Please try again.\n");
        }
    } while (N < 2);

    
    int bids[N];
    int highest_bid = 0; 

    
    for (int i = 0; i < N; i++) {
        int bid;
        do {
            printf("Enter bid %d (must be at least $%d): $", i + 1, MIN_BID);
            scanf("%d", &bid);
            if (bid < MIN_BID) {
                printf("Bid must be at least $%d. Please try again.\n", MIN_BID);
            }
        } while (bid < MIN_BID);
        bids[i] = bid;

        
        if (bid > highest_bid) {
            highest_bid = bid;
        }
    }

    
    if (highest_bid == 0) {
        printf("No valid bids were entered. The highest bid cannot be determined.\n");
    } else {
        printf("The highest bid is: $%d\n", highest_bid);
    }

    return 0;
}
