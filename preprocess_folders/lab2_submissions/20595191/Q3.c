#include <stdio.h>
#define SIZE 80
#define minBid 100000

int main() {

    int bids[SIZE];
    int bn;
    int max;


    printf("Enter the number of bids: ");
    scanf("%d", &bn);

    while (bn<2){
        printf("Error. Number of bids must be at least 2. Please try again.\n");
        return main();
    }

    printf("Enter the bids (Must be at least $100000): \n");
    for (int i=0;i<bn;++i){
        printf("Bid %d: ",i+1);
        scanf("%d", bids[i]);
        printf("Bid must be at least $100000. please try again. try again: ");
            continue;
    }

    return 0;

}