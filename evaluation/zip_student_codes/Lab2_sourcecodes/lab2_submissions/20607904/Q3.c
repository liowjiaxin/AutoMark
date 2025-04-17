#include <stdio.h>
#include <stdlib.h>

int main(void) {
    double *bids = NULL;  //initialising the pointer to the dynamic array to NULL
    int N; //initialing an int variable to store the number of bids

    int first_time = 1; //initialing first_time variable so that it wont show an error message the first time
    do {
        if (first_time != 1) {
            printf("number of bids must be at least 2. Please try again\n"); //displaying an error message if this is not the first time the user is attempting to input the variable
        }
        printf("Enter the number of bids (N ≥ 2): ");
        scanf("%d", &N);
        first_time = 0;
    } while (N < 2); //checking if the user input is less than 2, if it is loop back


    //Reallocating memory to the number of bids * the size of a double
    double *temp = realloc(bids, N * sizeof(double)); //we reallocate temp in case it fails initially instead of bids
    if(temp == NULL) {
        printf("Memory allocation failed"); //printing an error and freeing memory in the case of the memory failing to allocate
        free(bids);
        return 0;
    }
    bids = temp; //setting bids to the reallocated memory address

    printf("Enter the bids (must be at least $100000)\n"); //printing a header message
    for(int i = 0; i<N; i++) { //running a for loop depending on the number of bids the user wants to input
        first_time = 1; //resetting first_time varaible
        do {
            if (first_time != 1) {
                printf("Error: Bid must be at least $100000. Please try again\n"); //printing an error message if its not the first_time or first_time = 0
            }
            printf("Bid %d: ", i + 1);
            scanf("%lf", &bids[i]);
            first_time = 0;
        } while (bids[i] < 100000); //checking if the bid is less than 100000, if it is loop back
    }

    double max = bids[0]; //initialing max to the first element of the array
    for(int i = 1; i<N; i++) { //run through the entire array skipping the first element
        if(bids[i] > max) { //checking if an element is in the array is larger than the max, if so set max to that element
            max = bids[i];
        }
    }

    printf("The highest bid is: $%.0lf", max); //printing the highest bid

    free(bids); //freeing bids as its not being used anymore
    return 0;
}