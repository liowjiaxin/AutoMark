/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>



int main() {
    int int_1 = 0;
    int int_2 = 0;
    int int_3 = 0;
    int max  = 0;
    int min = 0;
    
    printf("Enter three integers separated by spaces:");
    scanf("%d %d %d", &int_1, &int_2, &int_3);
    
    int sum = int_1 + int_2 + int_3;
    float avg = sum / 3;
    int product = int_1 * int_2 * int_3;
    
    printf("Sum: %d \n", sum);
    printf("Average: %.2f \n", avg);
    printf("Product: %d \n", product);
     
    if(int_1>int_2) {
        max=int_1;
        min=int_2;
    } 
    else{
        max=int_2;
        min=int_1;
    } 

    if(int_3>max) {
        max=int_3;
    } 
    
    if(int_3<min) {
        min=int_3;
    }
    
    printf("Largest: %d \n", max);
    printf("Smallest: %d", min);
    
    return 0;
}
