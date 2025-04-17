#include<stdio.h>

int main() {

int num1,num2,num3;
int sum;
int average;
int product;
int smallest;
int largest;


printf("Enter 3 integers separated by space: "); //enter 3 integers
scanf("%d %d %d",&num1,&num2,&num3);

sum=num1+num2+num3;
average=(num1+num2+num3)/3;
product=num1*num2*num3;

printf("\nSum: %d",sum);
printf("\nAverage: %d",average);
printf("\nProduct: %d",product);

//check for largest
if(num1>=num2 && num1>=num3){
    printf("\nLargest is %d",num1);
}
else if(num2>=num1&&num2>=num3){
    printf("\nLargest is %d",num2);
}
else if(num3>=num1 && num3>=num2){
    printf("\nLargest is %d",num3);
}
//check for smallest
if(num1<=num2 && num1<=num3){
    printf("\nSmallest is %d",num1);
}
else if(num2<=num1 && num2<=num3){
    printf("\nSmallest is %d",num2);
}
else if(num3<=num1 && num3<=num2){
    printf("\nSmallest is %d",num3);
}



}