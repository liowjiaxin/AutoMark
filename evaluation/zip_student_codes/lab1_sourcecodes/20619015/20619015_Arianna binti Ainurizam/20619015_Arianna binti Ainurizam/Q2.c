
#include <stdio.h>

int main() {
    int num1, num2, num3;
    int sum, product;
    float average;
    
    //Prompt user to input 3 numbers
    printf("Enter 3 integers separated by spaces: ");
    scanf("%d %d %d", &num1, &num2, &num3);
    
    //Calculate each value
    sum = num1+num2+num3;
    average = (float)sum/3;
    product = num1*num2*num3;
    
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);
    printf("Product: %d\n", product);

    //To find smallest number
    if (num1 <= num2 && num1 <= num3) {
            printf("Smallest: %d\n", num1);
        } else if (num2 <= num1 && num2 <=num3){
            printf("Smallest: %d\n", num2);
        } else {
            printf("Smallest: %d\n", num3);
        }
    
    //To find largest number    
    if (num1 >= num2 && num1 >= num3) { //Check if num1 is the largest
        printf("Largest: %d\n", num1); 
    } else if (num2 >= num1 && num2 >= num3) { //Check if num2 is the largest
        printf("Largest: %d\n", num2);
    } else { //Check if num3 is the largest
        printf("Largest: %d\n", num3);
    }
    return 0;
}