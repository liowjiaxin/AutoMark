#include <stdio.h>
#include <stdlib.h>

int main(){

    int N;

    //Obtain user input on number of bids
    do{
    printf("Enter number of bids:");
    scanf("%d",&N);
    if(N<2){ //Check if number of bids is less than 2 or not
        printf("Error: Number of bids must be at least 2.Please try again!\n"); //Output error if user entered a number that is less than 2
    }
    }while(N<2); //use a do while loop to ensure correct input from user
   

    //allocate and initialise to 0
    int *bids = (int *)malloc(N * sizeof(int));
    if (bids == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    //Obtain bids from user
    for(int i =0; i<N;i++){
        do{
        printf("Enter the bids:");
        scanf("%d",&bids[i]);
        if(bids[i]<100000){ // Check if user input is less than 100000 or not
            printf("Bid must be at least $100000.Please try again!\n"); //Output error if user input is less than 100000
        }
        }while(bids[i]<100000); //Use do while loops to ensure correct input from user

    }

    //Search for the largest bid in the array
    int max = bids[0];
    for(int j = 0; j< N;j++){
        if(bids[j]> max){
            max = bids[j];
        }
    }

    //Output the highest bid
    printf("The highest bid is: $%d",max);

    //free the memory
    free(bids);

    return 0;
}