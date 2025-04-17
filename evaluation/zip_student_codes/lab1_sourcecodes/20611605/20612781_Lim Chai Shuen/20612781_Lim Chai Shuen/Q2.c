#include <stdio.h>

int main()
{
    // define variable
    int integer1;
    int integer2;
    int integer3;
    int sum = 0;
    int smallest;
    int largest;

    // ask user input 3 integer seperated with space
    printf("Enter three integers seperated by spaces: ");
    scanf("%d %d %d", &integer1, &integer2, &integer3);
    
    // calculate sum
    sum = integer3 + integer2 + integer1;
    printf("Sum: %d\n", sum); // display sum
    
    // calculate average of 3 integer
    float average = (float) sum / 3;
    
    // calculate product of 3 integer
    int product = integer1 * integer2 * integer3;
    
    // display average and product result
    printf("Average: %.2f\n", average);
    printf("Product: %d\n", product);
    
    // condition for choosing largeat value and smallest value
    if (integer1>integer2 && integer1>integer3 && integer3>integer2) {
        // diaplay result
        smallest = integer2;
        largest = integer1;
    }
    
    else if (integer2>integer1 && integer2>integer3 && integer1>integer3) {
        // diaplay result
        smallest = integer3;
        largest = integer2;
    }
    
    else if (integer3>integer1 && integer3>integer2 && integer1>integer2) {
        // diaplay result
        smallest = integer2;
        largest = integer3;
    }
    
    printf("Smallest: %d\n", smallest);
    printf("Largest: %d\n", largest);
    
    return 0; // program execute successfully
}
