#include<stdio.h>
#define minbid 100000 //min bid 

int main(){
    int numbids, i;
    float maxbid;

    maxbid=0.0;

    printf("Enter the number of bids: ");
    scanf("%d", &numbids);

    //Check bid value 
    while (numbids<2){
        printf("Error: Number of bids must be at least 2. Please try again: ");
        scanf("%d", &numbids);
    }
    
    //Dynamically create an array to store bid values
    float bids[numbids];
    
    for (i=0; i< numbids; i++){
        printf("Enter the bids (must be at least $100000): ", i+1, (float)minbid);
        scanf("%f", &bids[i]);

        //Check bid value is over 100000
        if(bids[i]< minbid){
            printf("Error: Bid must be at least $100000. Please try again: ", (float)minbid);
            i--;
        }
    }
    for (i=0; i< numbids; i++){
        if (bids[i]> maxbid){
            maxbid=bids[i];
        }
    }
    printf("The highest bid is: $%.2f\n", maxbid);

    return 0;
}