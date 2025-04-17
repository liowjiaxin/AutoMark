/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, *array, index1, index2, sum;

    // Prompt user to enter the size of the array and check the validation
    do {
        printf("Enter the size of the array (N >= 5): ");
        scanf("%d", &N);
        if (N < 5) {
            printf("Error: N must be at least 5. Please try again.\n");
        }
    } while (N < 5);

    // Try to allocate the memory for the array
    array = (int *)malloc(N * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    //  Enter the input elements into the array
    printf("Enter the array elements:\n");
    for (int i = 0; i < N; i++) {
        printf("Element %d: ", i);
        scanf("%d", (array + i));
    }

    //  Prompt user to enter the value of indices and check the validation
    while (1) {
        printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", N);
        scanf("%d %d", &index1, &index2);

        if (index1 >= 0 && index1 < N && index2 >= 0 && index2 < N) {
            break; // Validation of the indices
        } else {
            printf("Error: Indices must be within the range of the array elements. Please try again.\n");
        }
    }

    // Calculate the sum (using pointers)
    sum = *(array + index1) + *(array + index2);

    printf("The sum of the values at indices %d and %d is: %d\n", index1, index2, sum);

    return 0;
}
