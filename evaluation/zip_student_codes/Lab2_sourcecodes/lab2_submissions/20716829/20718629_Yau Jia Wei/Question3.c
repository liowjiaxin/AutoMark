// Question 3

#include <stdio.h>

int main()
{
    int count; 
    float bids[100];       //Array to store the bid
    float highestbids = 0;
    
    //Prompt the user to input the number of bids
    do { 
        printf("Enter the number of bids: ");
        scanf("%d", &count);
        
        if (count < 2){
            printf("Error: Number of bids must be at least 2. Please try again: "); //Print the error messages
        }
    } while (count < 2);
    
    //Prompt the users to enter the bids
    printf("Enter the bids (must be at least $100000). \n");
    
    for (int i = 0 ; i < count; i++){
        printf("Bids %d: ", i + 1 );
        scanf("%f", &bids[i]);
        
        if (bids[i] < 100000){  //Print the error messages when bids is smaller than 100000
            printf("Error: Bid must be at least $100000. Please try again. \n");
            i--;
            continue;
        }
        
        if (bids[i] > highestbids){
            highestbids = bids[i];
        }
    }
    
    // Print the result 
    printf("THe highest bid is: $ %.2f", highestbids);
    
    return 0;
}
