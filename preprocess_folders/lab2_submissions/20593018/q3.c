#include <stdio.h>

#define minbid 100000
int main() {
    int b,i,bid,bids[b],highestbid;
    
    do {
        printf("Enter the number of bids: ");
        scanf("%d", &b);
        if (b<2) {
            printf("Error: Number of bids must be at least 2. Please try again.\n");
        }
    }
    while (b<2);
    
    for (i=0; i<b; i++) {
        do {
            printf("Bid %d: ", i + 1);
            scanf("%d", &bid);
            if (bid<minbid) {
                printf("Error: Bid must be at least $%d. Please try again.\n", minbid);
            } else {
                bids[i]=bid; 
            }
        } 
    while (bid<minbid);
    for (i =0; i<b; i++) {
        if (bids[i] > highestbid) {
            highestbid = bids[i];
        }
    }
    printf("The highest bid is: $%d\n", highestbid);

    return 0;
}
}

