#include<stdio.h>

int main(){
    int numbid;
    printf("Enter the number of bids:");
    scanf("%d",&numbid);
    while(numbid<2){
        printf("Error: Number of bids must be at least 2 Pleas try again");
        scanf("%d",&numbid);
    }

    printf("Enter the bid (must be at least $100000)\n");
    long long int array[numbid];
    for(size_t i=0;i<numbid;i++){
        printf("Bid %d:",i+1);
        scanf("%lld",&array[i]);
        while(array[i]<100000){
            printf("Bid must be at least $100000. Please try again");
            scanf("%lld",&array[i]);
        }
    }
    
    long long int highest=array[0];
    for(size_t j=1;j<numbid;j++){
         if(highest<array[j]){
            highest=array[j];
         }
    }
    printf("The highest is:%lld", highest);
    
}