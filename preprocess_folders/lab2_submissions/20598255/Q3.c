#include <stdio.h> 

int main(){
    int N;
    float highestBid =0.0;

    //prompt user to enter number of bids
    do{
        printf("Enter the number of bids:");
        scanf("%d", &N);

        //check if number of bids is at least 2
        if (N< 2){
            printf("Error: Number of bids must be at least 2. Please try again:\n");
        }
    } while (N <2);

    //array to store bids
    float bids[N]; 

    //prompt user to enter bid
    printf("Enter the bids(must be at least $100000):\n");
    for (int i=0; i<N; i++){
        
        //prompt user to enter bid amount
        do{
           printf("Bid %d: ", i+1);
           scanf("%f", &bids[i]);

            // check if bid is higher than $100000
           if (bids[i]< 100000.0){
                printf("Error. BId must be at least $100000. Please enter again:\n");

           }
        } while (bids[i]< 100000.0);
        
    }

    //determining the highest bid
    for (int i=0; i< N; i++){
        if (bids[i]> highestBid){
            highestBid= bids[i];
        }
    }

    //display highest bid 
    printf("The highest bid is: $%.2f\n", highestBid);

    return 0;
}