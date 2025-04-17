#include <stdio.h>
#define ARRAYLENGTH 100

int main(){
    int numBids = 0;
    int highest = 0;
    int array[ARRAYLENGTH] = {0};

    printf("Enter the number of the bids:");
    scanf("%d", &numBids);
    while(numBids<2){
        printf("Error: Number of bids must be at least 2. Please try again: ");
        scanf("%d", &numBids);
    }

    printf("Enter the bids (must be at least $100000): \n");
    for(int i = 0; i < numBids; i++){
        printf("Bid %d: ", i);
        scanf("%d", &array[i]);
        while(array[i] < 100000){
            printf("Error, Bid must be at least $100000. Please try again: ");
            scanf("%d", &array[i]);
        }
    }

    for (int i =0; i< numBids; i++){
        if (highest < array[i]){
            highest = array[i];
        }
    }

    printf("The highest bid is: %d", highest);
}