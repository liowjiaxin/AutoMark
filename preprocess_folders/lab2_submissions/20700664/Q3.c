#include <stdio.h>

int main(){
    int N, price, max;
    int array[100];

    printf("Enter the number of bids: ");//number of bids 
    scanf("%d", &N);
    while(N<2){                          //if number is less than 2, try again
        printf("Number of bids must be at least 2.");
        printf("Please try again: ");
        scanf("%d", &N);
    }
    printf("Enter the bids (must be at least $100000): ");//enter the bids
    for(int i=0; i<N; i++){
        printf("Bid %d: ", N);
        scanf("%d", &price);
        while(price<100000){                              //if the price is less than 100000, try again
            printf("Bid must be at least $100000.");
            printf("Plaese try again: ");
            scanf("%d", &price);
        }
        array[i]= price;
    }

    max= array[0];
    for(int i=0; i<N; i++){         //compare
        if(array[i]>max){
            max=array[i];
        }
    }
    printf("The highest bid is: $%d\n", max);
}