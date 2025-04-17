#include <stdio.h>

int main() {

    int N;
    float bids[50]; // assuming maximum of 50 people is going to attend

    printf("Enter number of bids: ");
    scanf("%d", &N);

    // ensure that the bid is more than 2
    if(N<2) {
        printf("Not enough bids to determine the highest bid.\n");
        return 0;
    }
    
    // Input the bid value
    for (int j = 0; j < N; j++){
        do {
            printf("Enter the value of bid %d: ", j + 1);
            scanf("%f", &bids[j]);
            if (bids[j] < 100000){
                printf("Bid must be at least $100000. Please try again: \n");
            }
        } while (bids[j] < 100000);
    }

    // determine the highest bid
    float highestBid = bids[0]; 
    for (int j = 1; j < N; j++) {
        if (bids[j] > highestBid){
            highestBid = bids[j];
        }
    }


    printf("The highest bid is: $%2.f", highestBid);

    return 0;
}

    