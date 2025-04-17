#include <stdio.h>
#include <stdlib.h>

int main(){
    int arr_size = 0;       // size of arraw
    int *arr;               // pointer to the array
    int step = sizeof(int); // size of 1 element
    int index1, index2;     // indexes in the array to find the sum of its elements

    while (1){
        // enter the array size
        printf("Enter the size of array (N >= 5): ");
        scanf("%d", &arr_size);

        // if the input is wrong
        if (arr_size < 5) printf("Error: The size of array must be within the range (N >= 5)\n");
        else break; // if the input is correct , exit the infinite loop
    }

    arr = calloc(arr_size, step); // allocating memory forthe array

    printf("Enter the array Elements:\n");

    // Entering array elements
    for (int i = 0; i < arr_size; i++){
        printf("Element No.%d: ", i);
        scanf("%d", arr + i * step);
    }


    while (1) {
        //enter the indeces
        printf("Enter the indices of 2 elements (0 < index1, index2 < %d): ", arr_size);
        scanf("%d %d", &index1, &index2);

        // check that indeces are within the array bounds
        if ((index1 <= 0 || index1 >= arr_size) || (index2 <= 0 || index2 >= arr_size)) 
            printf("Error: The indeces must be within the range of array elements. Please, try again.\n");
        else break; // if the input is correct ,exit the infinite loop
    }

    // calculate the sum of 2 elements pointed by indeces
    int sum = *(arr + index1 * step) + *(arr + index2 * step);

    // output the sum
    printf("The sum of the values at indices at %d and %d is: %d", index1, index2, sum);
    return 0;
}