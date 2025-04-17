#include <stdio.h>
#include <stdlib.h>
#define MIN_AMOUNT 100000 

int main (){
    int num_of_bids=0; //initialize number of bids to 0
    float *arrayPtr = NULL; //initialize pointer for dynamic memory allocation as NULL

    //prompt user to input number of bids
    printf("Enter the number of bids: ");
    do {
        scanf("%d", &num_of_bids);
        //validate input and print error message
        if (num_of_bids<2){
            printf("Error: Number of bids must be at least 2. Please try again: ");
        }
    } while (num_of_bids<2); //validate input and if it is not valid, loop back

    //allocate memory for the array
    arrayPtr = (float *)malloc(num_of_bids * sizeof(float));

    //check whether memory allocation is success
    if(arrayPtr == NULL){
        printf("Memory allocation failed.\n");
        return 1; //exit if fail
    }

    //prompt user to enter the amount for each bid
    printf("Enter the bids (must be at least $100000): \n");
    for (int i=0; i<num_of_bids; i++){
        printf("Bid %d: ", i+1);

        do {
            scanf("%f", &arrayPtr[i]);
            //validate input and print error message
            if (arrayPtr[i]<MIN_AMOUNT){
                printf("Error: Bid must be at least $100000. Please try again: ");
            }
        } while (arrayPtr[i]<MIN_AMOUNT); //validate input and if it is not valid, loop back
    }

    float highest = arrayPtr[0]; //initialize the highest to the first element of array
    
    //for loop to compare each element with the current highest
    for (int i=1; i<num_of_bids; i++){
        //if array element is greater than highest, assign it to highest variable
        if (arrayPtr[i]>highest){
            highest = arrayPtr[i];
        }
    }

    //display the highest amount
    printf("The highest bid is: $%.0f\n", highest);

    //free allocates memory
    free(arrayPtr); 

    return 0;
}