#include <stdio.h>

int main(){ 
    int bids;
    
    printf("enter the no. of bids: \n", bids);
    scanf("%d", &bids);
    while (bids < 2) {
        printf("invalid no. of bids. try again.\n");
        printf("enter the no. of bids: \n", bids);
        scanf("%d", &bids);
    int bidarr[bids];
    }
    for (int i = 0; i < bids; i++) {
        int bidarr[bids];
        printf("Enter bid %d: \n", i+1);
        scanf("%d", &bidarr[i]);
        if (bidarr[i] >= 100000) {
            continue; 
        }
        else{
            printf("error, bid must $100k. Try again.\n");
            i--;
        }
    }
    int max_bid = 0;
    for (int i = 0; i < bids; i++) {
        int bidarr[bids];
        if (bidarr[i] > max_bid) {
            max_bid = bidarr[i];
        }
        
    }
    printf("the highest bid is %d ", max_bid);


    return 0;
}