#include <stdio.h>

int main(){
    
    int number = 0;
    int bids = 0;
    int m = 0;
    int max = 0;
    int min = 0;
    
    printf("Enter the number of bids: ");
    scanf("%d", &number);
    
    for(int i = 1; i <= number; i++){
        if(number >= 2){
            printf("Enter the bids (must be at least $100000): ");
            scanf("%d", &m);
            
            
        }
        else{
        printf("Error: Number of bids must be at least 2. Please try again.");
        }
    }
    
    
    printf("The highest bid is: ");
    
    
    return 0;
}