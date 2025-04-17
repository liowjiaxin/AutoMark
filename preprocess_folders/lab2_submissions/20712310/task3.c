
#include <stdio.h>
#define MIN_BID 100000 //each bid at least 100000

    int main(void){
    int N;
    int bids[100]; 
    int maxBid = -1;
    int validBids = 0;

   
    printf("Enter the number of bids : ");
    scanf("%d", &N);
    if (N < 2) {
        printf("At least two bids are required to determine the highest bid.Please try again\n");
        return 1;
    } //determine wether <2 or not
    
    printf("Enter the bids (each bid must be at least $ %d):\n", MIN_BID);
    for (int i = 0; i < N; i++) {
        printf("Bid %d: $", i + 1);
        scanf("%d", &bids[i]);
        if (bids[i] >= MIN_BID) {
            validBids++;
            if (bids[i] > maxBid) {
                maxBid = bids[i];
            }
        } else {
            printf("Invalid bid.  bid must be at least $%d. Please try again.", MIN_BID);
            i--; 
        }
    }

    
    if (validBids < 2) {
        printf("At least two valid bids are required to determine the highest bid.\n");
        return 1;
    }

   
    printf("The highest bid is: $%d\n", maxBid);

    return 0;
}
