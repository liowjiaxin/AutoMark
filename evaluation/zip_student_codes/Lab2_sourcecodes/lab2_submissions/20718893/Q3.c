#include<stdio.h>
#define BID_SIZE 30
int main(){
    int N,bid[BID_SIZE];
    //comment user to enter the number of bids(N)
    printf("Enter the number of bids:");
    scanf("%d",&N);
    while(N < 2){
        printf("Error: Number of bids must be at least 2.Please try again:");
        scanf("%d",&N);
    }
    //comment user to enter the values of bids
    printf("Enter the bidss (must be at least $100000):");
    for(int i = 1; i <= N; i++){
        printf("Bids%d:",i);
        scanf("%d",&bid[i]);
        while(bid[i] < 100000){
            printf("Error: Bid must be at least $100000.Please try again:");
            scanf("%d",&bid[i]);
        }
    }
    //calculate the highestbid
    int highestbid = -1;
    for(int i = 1; i <= N; i++){
        if(bid[i] > highestbid){
            highestbid = bid[i];
        }
    }
    printf("The highest bid is: $%d",highestbid);
}