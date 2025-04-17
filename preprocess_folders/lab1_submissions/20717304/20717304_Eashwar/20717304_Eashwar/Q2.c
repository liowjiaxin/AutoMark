#include <stdio.h>

int main(){
    int a;
    int b;
    int c;
    printf("Enter three integers seperated by a space ");
    scanf("%d%d%d", &a, &b, &c);                            // Reads user input and saves it to 3 different variables
    
    int sum;                   // Adds the three integers
    sum = a + b + c;
    printf("Sum : %d\n", sum);

    int avg;                   // Finds the average of the three integers
    avg = sum/3;
    printf("Average : %d\n", avg);

    int prod;                  // Multiplies the three integers
    prod = a * b * c;
    printf("Product : %d\n", prod);

    int small = a;             // Finds the smallest of the three integers
    if(small > b)              // Compares the integers one by one to a variable named small which is initially assigned to the first integer
    {
        small = b;
    }
    if(small > c)
    {
        small = c;
    }
    printf("Smallest : %d\n", small);

    int big = a;               // Finds the biggest of the three integers
    if(big < b)                // Compares the integers one by one to a variable named small which is initially assigned to the first integer
    {
        big = b;
    }
    if (big < c)
    {
        big = c;
    }
    printf("Largest : %d\n", big);
}