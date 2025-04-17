


#include <stdio.h>

int validateNumberOfBids(); // to intialize the function which checks whether the number of bids are more than 2
void TheBids(int bids[], int n);// to intialize the function called bids which takes n inputes from the user and store it in array
int findHighestBid(int bids[], int n);// initializing the function which finds out the highest bid

int main() {
    int n; // intiliazing the integer called n which is number of bids

    
    n = validateNumberOfBids();
    if (n < 2) { // putting a condition such that if the value of n is less than 2 , the following message is shown
        printf("Invalid input: At least two valid bids are required to determine the highest bid.\n"); // this message is displayed
        return 0;
    }

    
    int bids[n]; // initializing an array to store the bids
    TheBids(bids, n); // inputting the bids with validation

   
    int highestBid = findHighestBid(bids, n); // intialiazing the function for highest bid and finding it out by checking the array
    printf("The highest bid is $%d.\n", highestBid); // the highest bid is displayed

    return 0;
}


int validateNumberOfBids() { // the function to validate the number of bids
    int n;
    do { // a do loop is used to ensure the validity
        printf("Enter the number of bids (N ≥ 2): "); // asking the user to input the number of bids
        scanf("%d", &n); // scanf function is used to read the input
        if (n < 2) { // if the input is less than 2, the following message is displayed
            printf("Invalid input: You must have at least 2 bids.\n");
        }
    } while (n < 2); // this is to ensure that the loop is repeated and the user has a chance to input the correct way
    return n;
}


void TheBids(int bids[], int n) { // intialzing a function to get valid bids from the user
    for (int i = 0; i < n; i++) { 
        do {
            printf("Enter bid #%d (minimum $100,000): ", i + 1); // asking the user to enter a bid one by one
            scanf("%d", &bids[i]);// using scanf to read the input
            if (bids[i] < 100000) { // if the bid is less tha 100000, the following message is shown.
                printf("Invalid bid: Each bid must be at least $100,000.\n"); 
            }
        } while (bids[i] < 100000);// this is to ensure that the loop is repeated and the user can input the bid in the correct way
    }
}


int findHighestBid(int bids[], int n) { // intializing a function to find the highest id
    int highest = bids[0]; // intializing the first element to be the highest
    for (int i = 1; i < n; i++) {
        if (bids[i] > highest) { // using the compare method with each element and eventually finding the highest.
            highest = bids[i]; // after finding the highest , assigning it to highest
        }
    }
    return highest; // used to return the highest value.
}