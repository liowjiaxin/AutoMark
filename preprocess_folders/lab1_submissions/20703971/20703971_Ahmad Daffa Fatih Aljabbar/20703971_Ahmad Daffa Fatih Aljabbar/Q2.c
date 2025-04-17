#include <stdio.h>

int main() {

    int num1;
    int num2;
    int num3;
    int sum;
    int product;
    int smallest;
    int largest;
    float average;

    printf("enter three integers: ");
    scanf("%d %d %d", &num1, &num2, &num3);


    sum = num1 + num2 + num3;
    average = sum / 3.0;
    product = num1 * num2 * num3;

    if (num1 <= num2 && num1 <= num3) {
        smallest = num1;
    } else if (num2 <= num1 && num2 <= num3) {
        smallest = num2;
    } else {
        smallest = num3;
    }
    
    if (num1 >= num2 && num1 >= num3) {
        largest = num1;
    } else if (num2 >= num1 && num2 >= num3) {
        largest = num2;
    } else {
        largest = num3;
    }

    printf("Sum: %d\n", sum);
    printf("Average: %d\n", average);
    printf("Product: %d\n", product);
    printf("Smallest: %d\n", smallest);
    printf("largest: %d\n", largest);
    


}