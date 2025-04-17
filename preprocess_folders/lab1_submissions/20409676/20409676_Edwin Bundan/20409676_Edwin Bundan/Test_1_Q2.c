Question 2

#include <stdio.h>

int main() {    

    int number1, number2, number3, sum, product, smallest, biggest;
    float average;
    
    printf("Enter three integers: ");
    scanf("%d %d %d", &number1, &number2, &number3);

    // calculate the sum
    sum = number1 + number2 + number3;      
    printf("sum: %d", sum);
    
    // calculate the average
    average = sum/3.0;
    printf("\naverage: %.2f", average);
    
    // calculate the product
    product = number1 * number2 * number3;      
    printf("\nproduct: %d", product);
    
    //biggest
    
    if (number1 >= number2 && number1 >= number3)
        printf("\nbiggest: %d", number1);

    // if n2 is greater than both n1 and n3, n2 is the largest
    if (number2 >= number1 && number2 >= number3)
        printf("\nbiggest: %d", number2);

    // if n3 is greater than both n1 and n2, n3 is the largest
    if (number3 >= number1 && number3 >= number2)
        printf("\nbiggest: %d", number3);
        
    //smallest
    
    if (number2 >= number1 && number3 >= number1)
        printf("\nsmallest: %d", number1);

    if (number1 >= number2 && number3 >= number2)
        printf("\nsmallest: %d", number2);

    if (number1 >= number3 && number2 >= number3)
        printf("\nsmallest: %d", number2);
        
return 0;
}
