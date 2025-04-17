#include <stdio.h>

int main()
{
    int bid, userint, largest;
    printf("Enter the number of bids: ");   //Asking user to input number of bids
    scanf("%d", &bid);
    while (bid < 2) {       //Validating that input
        printf("Error: The number of bids must be at least 2. Please try again: ");
        scanf("%d", &bid);
    }
    int bids[100] = {0};
    printf("Enter the bids (must be at least $100000)\n");  //User inputting all the bids 
    for (int i = 1; i <= bid; i+= 1) {
        printf("Bid %d:", i);
        scanf("%d",&userint);
        while (userint < 100000) {      //Validating the bids
            printf("Error: Bid must be at least $100000. Try Again :");
            scanf("%d",&userint);
        }
        bids[i-1] = userint;
    }
    for (int i = 0; i < bid; i +=1) {   //Checking which bid is the largest
        if (bids[i] > largest) {
            largest = bids[i];
        }
    }
    printf("The highest bid is $%d", largest);

    return 0;
}