// highets bidder c program 

#include <stdio.h>
#define minimumBid 100000


int main(){

//ask user for the number of birds to put:

int n;                                    //declare n 
printf("Enter the number of birds: "); 

   //use a whie loop to check the conditions
   while (1){
      scanf("%d", &n);  
      if( n >= 2){
    break;                         //read userinput where n has to be greater or equal to 2
   }

 //otherwise print error message

 printf("Number of bids must be at least 2. Please try again: ");
}


// display the bids
float bid[n];   //array to store the bird bids
printf("Enter the bids (must be at least $100000): \n");

for( int i =1; i < n; i++){
    printf("Bid %d: ", i);
    while (1) {
    scanf("%f", &bid[i]);            //while we keep taking userinput check conditions
    if( bid[i] >= minimumBid){
        break;
        }
        printf("Error: Bid must be at least $100000. Please try again: ");
    }  
    }

//highets bid 
float highestBid= bid[0];
for( int i =0; i < n; i++){
    if( bid[i]> highestBid){
        highestBid= bid[i];           //set bid[i] is highest if it is higher than the previous one
    }
    }

// display the highest bid 

printf(" The highest bid is: %.2f", highestBid);
return 0;
}

