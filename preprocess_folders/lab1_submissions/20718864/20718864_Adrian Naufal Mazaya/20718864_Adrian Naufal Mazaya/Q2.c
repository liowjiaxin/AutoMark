

#include <stdio.h>



int main() {

// Question 2

    int x;
    int y;
    int z;
    double average;

    // prompt user for 3 integer
    printf("Enter 3 integer: ");
    scanf("%d%d%d", &x, &y, &z);
    // sum the 3 integer
    printf("Sum: %d\n", x + y + z);
    // average of the 3 numbers
    printf("Average: %d\n", (x + y + z)/3 );
    // multiply of the 3 numbers
    printf("Product (multiply): %d\n", x * y * z);
    // smallest integer

    if(x >= y && x >= z){
        printf("Biggest: %d\n", x);
            } else if (y >= x && y >= z) {
                printf("Biggest: %d\n", y);
            } else {
                printf("Biggest: %d\n", z);
            }   


        if(x <= y && x <= z){
        printf("Smalest: %d\n", x);
            } else if (y <= x && y <= z) {
                printf("Smallest: %d\n", y);
            } else {
                printf("Smallest: %d\n", z);
            }   

    return 0;
}

    

