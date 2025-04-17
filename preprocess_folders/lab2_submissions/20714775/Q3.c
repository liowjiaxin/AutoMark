#include <stdio.h>
int main(){
int N=0;
const int minBid =100000;

printf("Please enter the number of the bids\n");
scanf("%d",&N);


while(N<2){
printf("Nubmer of bids must be at least 2. Please try again");
scanf("%d",&N);
}


int bids[N];
printf("Enter the bids (must be at least $100000 dollars):\n");
for(int i=0; i < N; i=i+1)
{
printf("Bid %d: ",i+1);
scanf("%d",&bids[i]);


while(bids[i] < minBid){
    printf("Error: Bid must be at least $100000 dollars. Please try again\n");
    scanf("%d",&bids[i]);
}
}


int highestBid = bids[0];
for (int i = 1; i < N; i++){
if (bids[i] > highestBid) {
highestBid = bids[i];
}
}

 printf("The highest bid is $%d\n", highestBid);
 return 0;
}