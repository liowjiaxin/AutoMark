#include <stdio.h>

int main() {
    int n = 0;
    int bid[n];
    printf("Enter the number of bids: ");   //Prompt the user to enter the number of bids
    scanf("%d", &n);

    if(n<2) {
        printf("Number of bids must be atleast 2. Please try again: ");  //Prompt the user to enter number again if <2
        scanf("%d", &n);
    }

    printf("Enter the bids (must be atleast $100000):\n ");
    for(int i = 0; i<n;i++) {       //Use for loop to store bidding amount in an array
        printf("Bid %d: ", i+1);
        scanf("%d", &bid[i]);

        if(bid[i] < 100000) {
            printf("Error: Bid must be atleast $100000. Please try again: ");   //Give error if bidding amount is < 100000
             scanf("%d", &bid[i]);
        }
    }

    for(int i = 0; i<n;i++) {
        if(bid[i+1]>bid[i]) {
            printf("The highest bid is: %d", bid[i+1]);     //Print highest bid
        }
    }
}

