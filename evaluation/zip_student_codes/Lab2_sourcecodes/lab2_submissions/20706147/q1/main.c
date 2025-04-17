/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, *arr, index1, index2;
    // Prompt the size of the array (N >= 5)
    do {
        printf("Enter the size of the array (N >= 5): ");
        scanf("%d", &N);
    } while (N < 5);
    // Dynamicallt allocate memory for the array
    arr = (int*)malloc(N * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;  // Exit the program if memory allocation fails
    }
    // Prompt each element of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < N; i++) {
        printf("Element %d: ", i);
        scanf("%d", &arr[i]);
    }
    // Prompt the two indices and validate
    do {
        printf("Enter the two indices (0 <= index1, index2 < N): ");
        scanf("%d %d", &index1, &index2);
        if (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N) {
            printf("Invalid indices. Please try again.\n");
        }
    } while (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N);

    //Calculate the sum of the two elements
    int *ptr1 = arr + index1; 
    int *ptr2 = arr + index2;
    int sum = *ptr1 + *ptr2; 
    // Print the sum of the two elements
    printf("The sum of the elements at indices %d and %d is: %d\n", index1, index2, sum);
    free(arr);
    return 0;
}
