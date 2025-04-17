#include <stdio.h>
#define MAX_BIDS 20
int numbids ;

int bids[MAX_BIDS];
int main(){
    printf ("Enter the number of bids: ");
    scanf("%d", &numbids);

    if(numbids>=2){

        for (int i = 0; i < numbids; i++){
            printf("Enter the bids (must be atleast $100000) : ");
            scanf("%d", &bids[i]);
            
        }

        
            
                int n = sizeof(bids) / sizeof(bids[0]);

                // Intialize the variable which will denote the  maximum
                // element
                int res = bids[0];

                // Find the maximum value in the array and store it in
                // res

                for (int i = 0; i < n; i++) {
                    if (res < bids[i])
                        res = bids[i];
                }
        
    
                printf("\n");
                // print the  maximum bid
                printf("The highest bid is: %d", res);
            

        
            
    }
    
    else{
        
        printf("invalid input");
    }




    return 0;
}