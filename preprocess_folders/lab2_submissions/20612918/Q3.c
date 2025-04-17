#include <stdio.h>

int main(){
    int N;
    int value[N];

    printf("Enter the number of bids: ");
    scanf("%d", &N);

    //to check if bids are more than or equal 2, error message if not
    if (N<2){
        printf("Error: Number of bids must be at least 2. Please try again: ");
        scanf("%d", &N);
    }

    printf("Enter the bids (must be at least $100000):\n");

    // loop to input bid money
    for(int i=0; i<N; i++){
        printf("Bid %d: ", i+1);
        scanf("%d", &value[i]);

        // check if bid money is too little
        if (value[i]<100000){
            printf("Error: Bid must be at least $100000. Please try again: ");
            scanf("%d", &value[i]);
        }
    }

    //for loop to find the highest bid
    int  highest = 0;
    for(int i=0; i<N; i++){
        if (highest < value[i]){
            highest = value[i];
        }
    }

    //displaying the highest bid
    printf("The highest bid is: $%d", highest);
}