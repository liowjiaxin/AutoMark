#include <stdio.h>
int main() {
    int N;

   printf("Enter the number of bids: ");                // Prompt the user to enter number of bids
   scanf("%d", &N);

    
    if (N < 2) {
        printf("Error: Number of bids must be at least 2.Please try again:");    // Check if N is at least 2
        scanf("%d",&N);
    }

    int bids[N];
    int i;

   for (i = 0; i < N; i++) {
        do {
            printf("Enter the bids (must be at least $100000):\n");         //  Prompt the user to enter bids
            printf("Bid %d:",i+1);
            scanf("%d", &bids[i]);

             if (bids[i] < 100000) {
                printf("Error:Bid must be at least $100000.Please try again:" );    // Validate that the bid is at least $100,000
                scanf("%d", &bids[i]);
            }
        } while (bids[i] < 100000);
    }

    
    int highestBid = bids[0];                 
    for (int i = 1; i < N; i++) {
        if (bids[i] > highestBid) {                   //Determine the highest bid
            highestBid = bids[i];
        }
    }

    printf("\nThe highest bid is: $%d\n", highestBid);    // Output the value of highest bid

    return 0;
}