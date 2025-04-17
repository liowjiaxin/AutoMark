#include <stdio.h>

int main() {
    int num1, num2, num3; //Declare variables
    
    printf("Enter three integers separated by spaces: ");
    scanf("%d %d %d", &num1, &num2, &num3 ); //Input three integers from user
    
    int sum = 0; //variable in which sum is stored
    sum = num1 + num2 + num3;
    
    float average = 0; //variable in which average is stored
    average = (float) (num1 + num2 + num3) / 3;
    
    int product = 0;
    product = num1 * num2 * num3;
    
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);
    printf("Product: %d\n", product);
    
    if (num1 < num2 && num1 < num3) { //finding the largest number in the 3 integers
        printf("Smallest: %d\n", num1);
    } else if (num2 < num1 && num2 < num3) {
        printf("Smallest: %d\n", num2);
    } else if (num3 < num1 && num3 < num3) {
        printf("Smallest: %d\n", num3);
    } else {
        printf("Error: May be caused by they are all equal");
    }
    
    if (num1 > num2 && num1 > num3) { //finding the largest number in the 3 integers
        printf("Largest: %d\n", num1);
    } else if (num2 > num1 && num2 > num3) {
        printf("Largest: %d\n", num2);    
    } else if (num3 > num1 && num3 > num2) {
        printf("Largest: %d\n", num3);
    } else {
        printf("Error: May be caused by they are all equal");
    }
    
    return 0; //Indicate successful execution
}
 