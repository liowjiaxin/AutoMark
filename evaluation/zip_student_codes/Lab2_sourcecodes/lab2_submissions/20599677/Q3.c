#include <stdio.h>

int main(){
    int N;
    int bids[N];

    printf("Enter the number of bids: ");
    scanf("%d", &N);

    if(N<2){
        printf("Error: Number of bids must be at least 2. Please try again: ");
        scanf("%d", &N);
    }
    
    printf("Enter the bids (must be at least $100000):\n");
    
    for(int i = 0; i < N; i++){

        while(1){  
            printf("Bid %d: ", i+1);
            scanf("%d", &bids[i]);

            if(bids[i] >= 100000){
                break;
            }

            else{
                printf("Error: Bid must be at least $100000. Please try again.\n");
            }
        }
    }

    int highest_bid = bids[0];
    for(int i = 1; i < N; i++){
        if(bids[i] > highest_bid){
            highest_bid = bids[i];
        }
    }

    printf("The highest bid is: %d", highest_bid);



    return 0;
}