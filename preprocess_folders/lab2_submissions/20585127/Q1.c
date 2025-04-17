#include <stdio.h>
#include <stdlib.h>

int main() {
    int size; //for array size
    int sum; // To store the sum of chosen elements

    printf("Enter the size of the array (N >= 5): ");
    scanf("%d", &size);

    // the size is valid
    while (size < 5) {
        printf("Error: The size must be 5 or more. Try again: ");
        scanf("%d", &size);
    }

    // Dynamically allocates
    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1; // Exit the program if failed
    }

    // Input elements of the array
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1); 
        scanf("%d", &arr[i]);
    }

    // Ask the user to choose two elements
    int choice1, choice2;
    while (1) { // Loop until valid numbers given
        printf("Choose two indices (1 to %d) to add their elements:\n", size); //1 to the number of elemntes there are
        scanf("%d %d", &choice1, &choice2);

        // Validate
        if (choice1 >= 1 && choice1 <= size && choice2 >= 1 && choice2 <= size) {
            sum = arr[choice1 - 1] + arr[choice2 - 1]; // Adjust indices for 0-based array
            printf("The sum of elements at index %d and %d is: %d\n", choice1, choice2, sum);
            break; // Exit loop after valid input
        } else {
            printf("Invalid indices chosen. Please try again.\n");
        }
    }

    // Free the allocated memory
    free(arr);

    return 0;
}
