#include <stdio.h>
#define BUFFER 20
int main(){
    int arr[BUFFER];
    int num_bids=0;
    int highest_bid=0;

    printf("\nEnter the number of bids: ");
    scanf("%d",&num_bids);

    while(num_bids<2){
        printf("\nError: Number of bids must be at least 2. Please try again.");
        printf("\nEnter the number of bids: ");
        scanf("%d",&num_bids);
    }

    printf("\nEnter the bids (must be at least $100000): ");
    for(int i=0;i<num_bids;i++){
        printf("\nBid %d: ",i+1);
        scanf("%d",&arr[i]);

        while(arr[i]<100000){
            printf("\nError: Bid must be at least $100000. Please try again.");
            printf("\nBid %d: ",i+1);
            scanf("%d",&arr[i]);
        }
        
    }

    //Comparison to see which is the highest bid
    for(int i=0;i<num_bids;i++){
        for(int j=0;j<num_bids;j++){
            if(arr[i]>arr[j]){
            highest_bid=arr[i];
            }
            else if(arr[j]>arr[i]){
            highest_bid=arr[j];
            }
        }
    }
    
    printf("\nThe highest bid is: $%d",highest_bid);
    return 0;
} 