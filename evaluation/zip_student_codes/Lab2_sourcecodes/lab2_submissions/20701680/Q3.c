#include <stdio.h>

int main() {
    int n ;
 
    int highestbid = 0;
    
    
   
    printf("Enter the number of bids");
    scanf("%d",&n);
    int bid[n] ;
    if (n < 2)
    {
        printf("Number of bids must be atleast 2 please  try again");
        scanf("%d",&n);
       
    }
    for (int i = 1 ; i < n+1 ; i ++){
    printf("Enter the bids (must be atleast$100000) :");
    printf("Bid %d  " , i);
    scanf("%d",& bid[i] );
    if (bid[i]< 100000){
        printf("Bid must be atleast $100000. Please try again");
          printf("Bid %d  " , i);
    scanf("%d",& bid[i] );
    }
    if (bid[i] > highestbid){
        highestbid = bid[i];
    }
    
   }
    printf("The highest bid is : %d",highestbid);
   }
   
    
   return 0 ; 
  
}
