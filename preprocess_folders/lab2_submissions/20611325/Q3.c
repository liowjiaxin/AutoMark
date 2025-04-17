#include <stdio.h>

void bubblesort(int bids[], int numberOfBids); //Function prototype to sort the bids

int main(){
    int numberOfBids = 0;
    printf("Enter the number of bids: ");   //Get number of bids from user
    scanf("%d", &numberOfBids);

    while (numberOfBids < 2) { //Re-prompt the condition if the number of bids is less than 2
        printf("Error: Number of bids must be at least 2. Please try again: ");
        scanf("%d", &numberOfBids);
    }

    int bids[numberOfBids]; // Declare the array after getting the number of bids

    printf("Enter the bids (must be at least $100000):\n");  //Get the bids from user
    for (int i = 0; i < numberOfBids; i++) {
        do {
            printf("Bid %d: ", i + 1);
            scanf("%d", &bids[i]);   //Store the bids in the array
            if (bids[i] < 100000) {
                printf("Error: Bid must be at least $100000. Please try again.\n");
            }
        } while (bids[i] < 100000);
    }

    bubblesort(bids, numberOfBids); //Call the function to sort the bids
    printf("The highest bid is: $%d\n", bids[numberOfBids - 1]);  //Print the highest bid
    return 0;
}

void bubblesort(int bids[], int numberOfBids){  //Sort the values in ascending order in the array
    int temp = 0;   //Temporary variable for swapping
    for (int i = 0; i < numberOfBids - 1; i++) {
        for (int j = 0; j < numberOfBids - i - 1; j++) {
            if (bids[j] > bids[j + 1]) {
                temp = bids[j];
                bids[j] = bids[j + 1];
                bids[j + 1] = temp;
            }
        }
    }
}