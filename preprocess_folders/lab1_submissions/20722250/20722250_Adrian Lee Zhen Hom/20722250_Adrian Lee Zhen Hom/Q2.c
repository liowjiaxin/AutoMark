#include <stdio.h>

int main()
{
    int num1, num2, num3;
    int sum = 0;
    double average;
    int product;
    int min, max;

    //prompt and read 3 integers from user
    printf("Enter three integers separated by spaces: ");
    scanf("%d %d %d", &num1, &num2, &num3);
    
    //calculate sum
    sum = num1 + num2 + num3;
    
    //calculate average
    average = (double) sum / 3;

    //calculate product
    product = num1 * num2 * num3;
    
    //find smallest integer
    if(num1<num2 && num1<num3)
    {
        min = num1;
    }
    else if(num2<num1 && num2<num3)
    {
        min = num2;
    }
    else if(num3<num1 && num3<num2)
    {
        min = num3;
    }

    //find largest integer
    if(num1>num2 && num1>num3)
    {
        max = num1;
    }
    else if(num2>num1 && num2>num3)
    {
        max = num2;
    }
    else if(num3>num1 && num3>num2)
    {
        max = num3;
    }

    //display result
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);
    printf("Product: %d\n", product);
    printf("Smallest: %d\n", min);
    printf("Largest: %d\n", max); 

    return 0;
}