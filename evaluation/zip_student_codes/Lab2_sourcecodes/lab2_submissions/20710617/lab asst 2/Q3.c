#include <stdio.h>

int main() {
int N;
printf("Enter the number of bids: ");
scanf("%d",&N);
 while (N<2){
      printf("Error: Number of bids must be atleast 2.Please try again: ");
         scanf("%d",N);
 }
 
 int bids[N];
 int highestBid;
  
  for (int i=0;i<N;i++){
      printf("Bid %d: ",i+1);
      scanf("%d",&bids[i]);
      
      while (bids[i]<10000){
     printf("Error: Bid must be greater than 100000. Please try again:");
      scanf("%d",&bids[i]);
      
     if(bids[i]>bids[i+1]){
        highestBid=bids[i];
     }
     else{
          highestBid=bids[i+1];
     }
 }
}
 printf("The highest bid is : %d\n",highestBid);
 return 0;
}