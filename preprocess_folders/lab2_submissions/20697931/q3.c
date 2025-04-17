#include <stdio.h>

void main(){
    int bid_num = 0;
    
    
    int bid_array[100] = {0};
    

    //Enter bid number
    printf("Enter the number of bids: ");
    scanf("%d", &bid_num);
    
    while (bid_num < 2){
        printf("\nError: Number of bids must be >= 2");
        printf("\nEnter the number of bids: ");
        scanf("%d", &bid_num);
    }


    //Enter each bid amount into array
    for (int i = 0; i < bid_num; i++){
        printf("Bid %d: ", i + 1);
        scanf("%d", &bid_array[i]);
        
        while (bid_array[i] < 100000){
            printf("Try again. Bid %d: ", i + 1);
            scanf("%d", &bid_array[i]);
        }
    }
   
   //check highest value
    int highest = 0;
    for (int i = 0; i < bid_num; i++){
        if (bid_array[i] > highest){
            highest = bid_array[i];
        }
    }

    printf("The highest bid is: $%d\n", highest);
}
