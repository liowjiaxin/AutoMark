#include <stdio.h>
#include <stdlib.h>

int main(){
    //initialise varaibles
    int N;

    //ask for amount of bids
    printf("Enter the amount the bids:");
    scanf("%d", &N);

    //initialise more variables
    int bids[N];
    int temp = 0;

    //check if enough bids
    if (N <= 2){
        printf("Not enough bids to determine who higher");
    }

    else{
        
        //ask for bids
        printf("Enter the bids (must be at least $100000)\n");
        for (int i = 0; i < N; ++i){
            printf("Enter bid %d: ", i); //ask for bid 
            scanf("%d", bids + i);
            if (*(bids + i) < 100000){ //check if bid too small or not
                printf("Bid too small, try again\n");
                exit(0);
            }
            else if (temp < *(bids + i)){ //check if bid is bigger than current highest bid
                temp = *(bids + i);
            }
        }
        printf("Highest bid is $%d", temp); //display highest bid
    }

}