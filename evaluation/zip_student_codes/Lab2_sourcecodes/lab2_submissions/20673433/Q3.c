#include <stdio.h>

int main()
{
    int num;
    int bids[100];
  printf("Enter the number of bid:\n");
  scanf("%d",&num);
  if(num<2){
      printf("Please Try Again");
  }else{
     for(int i=0; i<num;i++){
         printf("Enter Bids:\n");
         scanf("%d",&bids[100]);
         if(bids[100]<100000){
             printf("Please enter at least 100000");
         }else{
             for (int j = 1; j <bids; ++i) {
             if (bids[0] < bids[j]) {
              bids[0] = bids[i];
    }
         }
     }
          
  }
}