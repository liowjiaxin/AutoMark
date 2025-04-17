#include <stdio.h>

int findsmallest(int integer1, int integer2, int integer3){
    int smallest = integer1;

    if(integer2 < smallest){
        smallest = integer2;
    }
    if(integer3 < smallest){
        smallest = integer3;
    }

    return smallest;


}

int findlargest(int integer1, int integer2, int integer3){
    int largest = integer1;

    if(integer2 > largest){
        largest = integer2;
    }
    if(integer3 > largest){
        largest = integer3;
    }

    return largest;


}

int main(){

    int numberOfIntegers = 0;
    int integer1 = 0;
    int integer2 = 0;
    int integer3 = 0;
    int sum = 0;
    float average = 0.0;
    float product = 0.0;

    printf("Enter 3 integers separated by space: \n");
    scanf("%d %d %d", &integer1, &integer2, &integer3);

    sum = integer1 + integer2 + integer3;
    average = (float)sum / 3;
    product = (float) integer1 * integer2 * integer3;

    int smallest = findsmallest(integer1, integer2, integer3);
    int largest = findlargest(integer1, integer2, integer3);

    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);
    printf("Product: %.2f\n", product);
    printf("Smallest: %d\n", smallest);
    printf("Largest: %d\n", largest);



    return 0;
}