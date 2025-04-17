#include <stdio.h>
#include <stdlib.h> //for malloc

int main() {

    //1) Prompt the user to enter the size N of the array. Validate if N ≥ 5.
    int N;
    do {
        printf("Enter the size of the array (N >= 5): ");
        scanf("%d", &N); //while N is less than 5 it will keep asking 
    } while (N < 5);

    //2) Dynamically allocate memory for the array using pointers.
    int *array = malloc(N * sizeof(int)); //allocating memory for the array using malloc. Malloc is a function that returns a pointer to the allocated memory. 

    //3) Prompt the user to enter each element of the array one by one.
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }

    //4) Prompt the user to enter the two indices (positions) of the array elements of their choice. Validate if the indices are within the range of the array elements 0 <= index1, index2 < N). Prompt the user for input again until the indices entered are valid.
    int index1, index2;
    do {
        printf("Enter the first index: ");
        scanf("%d", &index1);
        printf("Enter the second index: ");
        scanf("%d", &index2);
    } while (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N); //index1 >= N || index2 >= N will check if the index is greater than or equal to the size of the array

    //5) Use a pointer-based approach to find the sum of the values of the two array elements.
    int sum = array[index1] + array[index2];

    //6) Print the output for the sum.
    printf("The sum of the values of the two array elements is: %d", sum);

    return 0;
}