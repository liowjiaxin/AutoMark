#include <stdio.h>

int main()
{
    int bider;
    do{
        printf("Enter The number of bids: ");
        scanf("%d",&bider);
        if (bider<2){
            printf("Error: Number of bids must be at least 2. Please try again\n\n");
        }
    }while (bider<2);    
    
    printf("Enter the bids (must be at least $100000)\n");
    int bits[bider];
    for (int i=0;i<bider;i++){
        do{
            printf("Bid %d: ",i+1);
            scanf("%d",&bits[i]);
            if (bits[i]<100000){
                printf("Error: Bid must be at least $100000. Please try again\n");
            }
        }while (bits[i]<100000);
    }
    
    int max=0;
    for (int i=0;i<bider;i++){
        if (bits[i]>max){
            max=bits[i];
        }
    }
    
    printf("The highest bid is: $%d",max);
}
