#include <stdio.h>
#include <stdlib.h>

int main(){
    int bid=0;
    int *arrPtr = (int*)malloc(bid*sizeof(int));    // create a size modfiyable array which is base on user input
    printf("Enter number of bids: ");
    scanf("%d", &bid);

    if (bid < 2){
        printf("Error: Number of bids must be at least 2. Pls try again: ");
        scanf("%d", &bid);
    }

    while(bid >=2){
        int bid_amount=0;
        printf("Enter the bids (must be at least $100 000): ");
        
        for (int i=0; i<bid; i++){
            printf("\nBid %d: ", i+1);
            scanf("%d", &bid_amount);
            arrPtr[i] = bid_amount;
            if (bid_amount <= 100000){   // if amount is <= $100 000, print error message
                printf("Error: Bid must be at least $100 000. Pls try again: ");
            }
        }
        
        int highest = 0;
        for (int i = 1; i < bid; ++i) {
            if (arrPtr[0] < arrPtr[i]) {    // if arrPtr[i] > arrPtr[0]
            arrPtr[0] = arrPtr[i];          // arrPtr[0] is current largest num
            }
        }
        highest = arrPtr[0];
        printf("The highest bid is: %d", highest);
        break;
    }

    return 0;
}