#include <stdio.h>
#define MINIMUM 100000

int main()
{
    int bidnum;
    
    printf("Enter the number of bids: ");
    scanf("%d",&bidnum);
    while (bidnum < 2){
        printf("Error: number of bids must be at least 2. Please try again: ");
        scanf("%d",&bidnum);
    }

    int bids[bidnum];
    int bid;
    int highest;
    printf("Enter the bids (must be at least $%d)\n", MINIMUM);
    for (int i = 1;i<=bidnum;i++){
        printf("Bid %d: ", i);
        scanf("%d",&bid);
        while (bid < MINIMUM){
            printf("Error: Bid mut be at least $%d. Please try again: ", MINIMUM);
            scanf("%d",&bid);
        }
        if (i == 1){
            highest = bid;
        } else if (bid > highest){
            highest = bid;
        }// if not the first loop, check if the bid entered is higher than the highest bid recorded
    }
    printf("The highest bid is: $%d",highest);
    
    return 0;
}