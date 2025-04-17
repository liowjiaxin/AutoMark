#include <stdio.h>
#include <stdlib.h>

// function to validate input as an integer
int getValidInteger(const char *prompt) {
    int value;
    char term;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d%c", &value, &term) != 2 || term != '\n') {
            printf("Error: Please enter a valid integer.\n");
            while (getchar() != '\n'); 
        } else {
            break;
        }
    }
    return value;
}

// Function to validate and get the array size
int getValidSize() {
    int size;
    do {
        size = getValidInteger("Enter the size of the array (N >= 5): ");
        if (size < 5) {
            printf("Error: Size must be at least 5.\n");
        }
    } while (size < 5);
    return size;
}

// function to input elements into the array 
void inputArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        *(arr + i) = getValidInteger(""); // assign the values
    }
}

// function to validate and get the indices
void getValidIndices(int *index1, int *index2, int size) {
    do {
        *index1 = getValidInteger("Enter the first index: ");
        *index2 = getValidInteger("Enter the second index: ");
        if (*index1 < 0 || *index1 >= size || *index2 < 0 || *index2 >= size) {
            printf("Error: Indices must be within the range 0 to %d.\n", size - 1);
        }
    } while (*index1 < 0 || *index1 >= size || *index2 < 0 || *index2 >= size);
}

// function to sum the two elements
int calculateSum(int *arr, int index1, int index2) {
    return *(arr + index1) + *(arr + index2); 
}

int main() {
    // get a valid size for the array
    int size = getValidSize();

    // dynamically allocate mmemory for the array
    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // insert the elements using pointers
    inputArray(arr, size);

    // get valid indices
    int index1, index2;
    getValidIndices(&index1, &index2, size);

    // calculate the sum of the chosen elements
    int sum = calculateSum(arr, index1, index2);
    printf("The sum of elements at indices %d and %d is: %d\n", index1, index2, sum);


    free(arr); // free the memory allocated

    return 0;
}