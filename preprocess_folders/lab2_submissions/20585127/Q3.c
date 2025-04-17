#include <stdio.h>

int main(void) {

    int Totalbids;
    int arr[Totalbids];
    
    printf("Enter the number of bids:");
    scanf("%d", &Totalbids);

    while (Totalbids < 2) {
        printf("Error: the number of Total bids must at least be 2, Please try agian:");
        scanf("%d", &Totalbids);
    }
    
    printf("Enter the bids (Must be atleast $100000)");

    for (int i = 0; i < Totalbids; i++) {
        printf("Enter bid %d: ", i + 1); 
        scanf("%d", &arr[i]);
        while (arr[i] < 100000)
        {
            printf("Error: the bids need to be above $100000 try agian:");
            scanf("%d", &arr[i]); 
        }
        
    }

    int highest = arr[0]; //to get highest number
    int n = sizeof(arr) / sizeof(arr[0]); //get arr size    

    for (int i = 0; i < n; i++) {
            printf("Bid %d: %d\n",i + 1, arr[i]);
        } //print bids
    for (int i = 0; i < n; i++) { //loop until find highest number
        if (highest < arr[i])
            highest = arr[i];
    }
    printf("\n");
    // print the  maximum value
    printf("The higest bid is: $%d", highest);


    return 0;
}