#include <stdio.h>

int main() {
    int N;

    // Prompt user to enter the size of the array
    do {
        printf("Enter the size of the array (N >= 5): ");
        scanf("%d", &N);
        if (N < 5) {
            printf("Error: Size of the array must be at least 5. Please try again.\n");
        }
    } while (N < 5);

    // Declare a static array with a maximum possible size
    int array[N];

    // Prompt user to enter the array elements
    printf("Enter the array elements:\n");
    for (int i = 0; i < N; i++) {
        printf("Element %d: ", i);
        scanf("%d", &array[i]);
    }

    int index1, index2;

    // Prompt user to enter indices and validate them
    while (1) { // 1 is used for the while condition to create an infinite while loop
        printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", N);
        scanf("%d %d", &index1, &index2);

        if (index1 >= 0 && index1 < N && index2 >= 0 && index2 < N) {
            break; // If the If indices are valid then break will stop the infinite loop else false criteria will display the error message
        } else {
            printf("Error: Indices must be within the range of the array elements. Please try again.\n");
        }
    }

    // Calculates the sum using array indexing
    int sum = array[index1] + array[index2];

    // Outputs the sum of the 2 index's
    printf("The sum of the values at indices %d and %d is: %d\n", index1, index2, sum);

    return 0;
}