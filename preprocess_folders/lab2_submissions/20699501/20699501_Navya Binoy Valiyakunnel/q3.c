#include<stdio.h>

int bids[];
int size;

int main(){

    printf("Enter number of bids: ");
    scanf("%d", &size);

    int bids[size];

    for(int i = 0; i <= size; i++){
        int bid; 
        while(bid < 100000){
            printf("Enter the bids(must be at least $100000):\n Bid %d:", i + 1);
            scanf("%d", &bid);

            if(bid < 100000){
            printf("Bid must be at least $100000.\n ");
            }
        }

    }


    for (int i = 1; i < bids; i++) {
        if (bids[0] < bids[i]) {
                bids[0] = bids[i];
        }
    }

  printf("The highest bid is %d", bids[0]);


 return 0;
}