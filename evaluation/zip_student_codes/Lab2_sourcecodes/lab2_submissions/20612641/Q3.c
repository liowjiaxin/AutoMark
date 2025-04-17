#include <stdio.h>
#define SIZE 100
#define minBid 100000

int main() {

    int bids[SIZE];
    int bidsNum;
    int max;


    printf("Enter the number of bids: ");
    scanf("%d", &bidsNum);

    while (bidsNum<2){
        printf("Error. Number of bids must be at least 2. Please try again.\n");
        return main();
    }

    printf("Enter the bids (Must be at least $100000): \n");
    for (int i=0;i<bidsNum;++i){
        printf("Bid %d: ",i+1);
        scanf("%d", bids[i]);
        if (bids>bidsNum){
        printf("Bid must be at least $100000. please try again. try again: ");
            continue;
        }
    }

    return 0;

    for (int i = 0; i < bidsNum; i++) {
        if (bids[i] > max) max = bids[i];
        printf("The highest bid is: $%d",max);
    }
}
