#include <stdio.h>

int main(){
    int num1,num2,num3;
    //Input 3 integers in one line seperated by spaces
    printf("Enter three integers seperated by spaces: ");
    scanf("%d%d%d",&num1,&num2,&num3);
    //Calculate the sum of 3 integers and print output
    int sum= num1+num2+num3;
    printf("Sum: %d\n",sum);
    //Calculate the average of 3 integers and print output
    double average= sum/3;
    printf("Average: %.2f\n",average);
    //Calculate the product of 3 integers and print output
    int product = num1*num2*num3;
    printf("Product: %d\n",product);

    // Compare 3 integers to get the smallest and the largest
    // Assume and set the maximum and minimum with the first two integers
    int max =num1;
    int min =num2;
    // Compare the first two integers and assign it as minimum and maximum
    if (num1<num2){
        max=num2;
        min=num1;
    }
    //Compare the third number with th assigned minimum and maximum
    if (num3>max){
        max= num3;
    }
    if(num3<min){
        min= num3;
    }
    //print output 
    printf("Smallest: %d\n",min);
    printf("Largest: %d\n",max);
    return 0;
}