//qstn 3

#include<stdio.h>
int main(){
    int  N;//declare N
    //declare an array
    printf("enter number of bids: ");
    scanf("%d",&N);//input number of bids
    unsigned long long int bid[N];
    if(N<=2){ //enter input again if condition isnt met
        printf("Number of bids cannot be less than or equal to 2 please enter again: \n");
        scanf("%d",&N);
    }
    for(int i=0; i<N; ++i){
        
        printf("bid %d :",i);
        scanf("%llu",&bid[i]);
        if(bid[i]<100000){//check if condition is ryt
            printf("bid must ne atleast $100000. please try again:\n");
            
        }
        for(int i=0;i<N;++i){         
            printf("%d\n",bid[i]);    
            }    
            puts("");
    }
    for(int pass=1;pass<N;++pass){//do bubble sort to sort from lowest to highers
        for(int i=0;i<N-1;++i){
            if(bid[i]>bid[i+1]){
                unsigned long long int hold=bid[i];
                bid[i]=bid[i+1];
                bid[i+1]=hold;
            }
        }
    }

    
    
    
    printf("the highest bid is %llu",bid[N-1]);// print last value as it is the highets
}
