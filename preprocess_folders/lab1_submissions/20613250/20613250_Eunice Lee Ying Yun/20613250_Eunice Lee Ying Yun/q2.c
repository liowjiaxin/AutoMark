#include <stdio.h>

int main(void)
{
    int num1, num2, num3; //3 integer
    
    //request 3 integer separated by spaces
    printf("Enter three integers separated by spaces: ");
    scanf("%d%d%d", &num1, &num2, &num3);

    printf("Sum: %d\n", num1+num2+num3); // sum of integers
    printf("Average: %.2f\n", (double)((num1+num2+num3)/3)); // average of integers
    printf("Product: %d\n", num1*num2*num3); // product of integers
    
    //compare for the smallest integer
    if ((num1<num2) && (num1<num3)){ //check num1 is smallest
        printf("Smallest: %d\n", num1);
    }
    else{
        if (num2<num3){ //check num2 is smallest
            printf("Smallest: %d\n", num2);
        }
        else{ //num3 is smallest
            printf("Smallest: %d\n", num3);
        }
    }
    
    //compare for the largest integer
    if ((num1>num2) && (num1>num3)){ //check num1 is largest
        printf("Largest: %d\n", num1);
    }
    else{
        if (num2>num3){ //check num2 is largest
            printf("Largest: %d\n", num2);
        }
        else{ //num3 is largest
            printf("Largest: %d\n", num3);
        }
    }
    
    return 0;
}