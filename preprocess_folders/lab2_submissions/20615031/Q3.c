#include <stdio.h>
#include <stdlib.h>

int main(void){
    int N = 0;  //declare the number of bids

// Prompt the user to enter the number of bits
    do{
    printf("Enter the number of bids ( N >= 2 ): ");
    scanf("%d", &N);
        if (N < 2){
            printf("Error: Number of bids must be at least 2. Please try again: ");
        }
    }while(N < 2);

    //allocate the memory for bids array
    int *bid = (int *) malloc(N * sizeof(int));
    if (bid == NULL){
        printf("Memory not allocated.\n");
        return 1; //Prove there is an error
    }

// Prompt the user to enter the values of the N bid
    for(int i = 0; i < N ; i++){
        do{
            printf("Enter the bids (must be at least $100000)\nBid %d:", i+1);
            scanf("%d", &bid[i]);

            if(bid[i] < 100000){
                printf("Error: Bid must be at least $100000. Please try again: ");
            }
        }while(bid[i] < 100000);
    }

//Find the highest bid
    int highest = bid[0];
    for(int i = 0; i < N ; i++){
        if( bid[i] > highest){
            highest = bid[i];
        }
    }

    printf("The highest bid is: %d", highest);
}