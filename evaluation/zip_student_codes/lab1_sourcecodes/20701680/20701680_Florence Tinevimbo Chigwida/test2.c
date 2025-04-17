#include <stdio.h>
int main(){

    
    int num1, num2, num3 ;
    int sum , product , smallest , largest ;
    float average ;
   
    printf("Enter three integer separated by space: ");
    scanf("%d\t%d\t%d",& num1,&num2,&num3);
    sum = num1 +num2 +num3;
    average =  (float)sum/ 3;
    product = num1*num2*num3;
    if (num1>num2 && num1 > num3){
        largest = num1 ;
    }
    else if (num2>num1 && num2 > num3){
        largest = num2 ;
    }
    else {
        largest = num3;
    }
   if (num1<num2 && num1<num3){
    smallest = num1 ;
   }
   else if (num2<num1 && num2<num3){
    smallest = num2 ;
   }
    else {
     smallest = num3; 
    }
    printf("Sum : %d \n" , sum);
    printf("Average : %.2f \n" , average);
    printf("Product : %d \n" , product);
    printf("Smallest : %d \n" , smallest);
    printf("Largest : %d \n" , largest);

    return 0 ;
   


}