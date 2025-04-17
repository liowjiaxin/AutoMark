#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Enter the number of bids: ");
    while (1){
        scanf("%d",&n);
        if(n>1){
            break;
        }
        else{
            printf("Number of bids must be at least 2. Please try again: ");
        }
    }

    int bid[n];
    for (int i = 0; i < n; ++i) {
        printf("Bid %d: ", i+1);
        while (1) {
            int bidding;
            scanf("%d", &bidding);
            if(bidding > 100000){   
                bid[i]=bidding;          
                break;
            }else{
                printf("Bid must be at least $100,000. Please try again:");
            }
        }
    }

    int highest;
    for (int i = 0; i < n; ++i) {
        if (highest <= bid[i]){
            highest = bid[i];
        }
    }

    printf("The highes bid is $%d", highest);
    
    
   }