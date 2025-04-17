#include <stdio.h>
#include <stdlib.h>

int main(){
    int N;  // Number of birds
    int * bids;
    int highestBid;

    // Step 1: Prompt the user for the number of bids and validate
    printf("Enter the number of bids (N): ");
    scanf("%d",&N);
    if (N<2){
        printf("Error: Number of bids must be at least 2. Please try again: ");
        scanf("%d",&N);
    }
    // Step 2: Dynamically allocated memory for storingg the bids
    bids=(float *)malloc(N * sizeof(float));
    if (bids==NULL){
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Step 3: Prompt the user to enter the bids with validation
    printf("Enter the bids (minimum $100,000 each);\n");
    for (int i=0;i<N;i++){
        while (1){
            printf("Bid %d: $", i+1);
            scanf("%f", &bids[i]);
            if (bids[i]>=100000){
                break;  // Valid bid
            }
            printf("Invaid bid. Each bid must be at least $100,000. Please try again.\n");
        }
    }

    // Step 4: Determine the highest bid
    int highestBid = bids[0];
    for(int i=1;i<N;i++){
        if(bids[i]>highestBid){
            highestBid=bids[i];
        }
    }

    // Step 5: Display the highest bid
    printf("\nThe highest bid is $%.2d\n",highestBid);

    // Free allocated memory
    free(bids);

    return 0;
    
    
}

