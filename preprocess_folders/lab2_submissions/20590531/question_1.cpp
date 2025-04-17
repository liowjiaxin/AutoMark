#include <stdio.h>

// Function to get a valid array size (N >= 5)
int valid_array_size () {
    int N;
    printf ("Enter the size of the array (N >= 5): ");
    scanf ("%d", &N);

    // Ensure the array size is at least 5
    while (N < 5) {
        printf ("Error. The size of the array must be at least 5. Please try again: \n");
        scanf ("%d", &N);
    }
    return N;   // Return the valid array size
}

// Function to prompt the user enter the array element
void array_elements (int arr[], int N) {
    printf ("Enter the array elements: \n");
    for (int i = 0; i < N; i++) {
        printf ("Element %d: ", i);
        scanf ("%d", &arr[i]);  // Store input in the array
    }
}

// Function to get valid indices within the range of the array
void valid_indices (int N, int *index1, int *index2) {
    while (1) {
        printf ("Enter the indices of two elements (0 <= index1, index2 < %d): ", N);
        scanf("%d %d", index1, index2); 

        // Validate that both indices are within the array bounds
        if (*index1 >= 0 && *index1 < N && *index2 >= 0 && *index2 < N) {
            break;  // Exit the loop if indices are valid
        } else {
            printf ("Error: Indices must be within the range of the array elements. Please try again.\n");
        }
    }
}

// Function to calculate the sum of elements
int calculate_sum (int arr[], int index1, int index2) {
    return arr[index1] + arr[index2];
}

int main () {
    int N = valid_array_size ();

    int arr[N]; // Define an array of size N
    array_elements (arr,N);

    int index1, index2;
    valid_indices (N, &index1, &index2);

    int sum = calculate_sum (arr, index1, index2);

    printf ("The sum of the values at indices %d and %d is: %d\n", index1, index2, sum);

    return 0;   // End of the program
}