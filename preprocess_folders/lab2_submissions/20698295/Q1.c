#include <stdio.h>
int main(){
    int N,num1,num2,i;
    int element;
    printf("Enter size of array: ");
    scanf("%d",&N);
    int array[]={0};
    int *arrayptr=array;
    if (N>=5){
        printf("Enter the array elements: \n");
        for(i=0; i<N ;i++){
            printf("Element %d:",i);
            scanf("%d",&arrayptr+1);

        printf("Enter the indices of 2 elements (0<=inde1, index2< %d): ",N);
        scanf("%d %d", num1, num2);
        while(num1<0 || num2>N){
            printf("Error: the indices must be within the range of array elements. please try again. ");
            printf("Enter the indices of 2 elements (0<=inde1, index2< %d): ",N);
            scanf("%d %d", num1, num2);
        }

    }
    int sum;
    sum=((*arrayptr+num1)+(*arrayptr+num2));
    printf("The sum of values is: %d", sum);
    
        

    }


}
