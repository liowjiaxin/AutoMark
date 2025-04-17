#include <stdio.h>

int main() {
    int N, index1, index2;

    // user input size of array
    do {
        printf("Enter the size of the array (N >= 5): ");
        scanf("%d", &N);
        if (N < 5) {
            printf("Incorrect array size, Please enter an array size of 5 or more.");
        }
    }

    while (N < 5);
    // Declare an array N
    int array[N];

    // user input elements of the array one by one
    printf("Enter the array elements:\n");
    for (int i = 0; i < N; i++) {
        printf("Element %d: ", i);
        scanf("%d", &array[i]);
    }

    // user input the indices and validate
    do {
        printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", N);
        scanf("%d %d", &index1, &index2);
        if (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N) {
            printf("Error: Indices must be less than the size of the array. Try again.\n");
        }
    } while (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N);
    // Compute sum
    int sum = array[index1] + array[index2];
    // Print the result
    printf("The sum of the values at indices %d and %d is: %d\n", index1, index2, sum);

    return 0;
}
