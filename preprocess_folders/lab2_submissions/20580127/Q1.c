#include <stdio.h>
#include <stdlib.h>

// Function to validate if the entered index is in valid range
int validate_index(int index, int size) {
    return (index >= 0 && index < size);
}

int main() {
int N;


printf("Enter the size of the array (N >= 5): ");
scanf("%d", &N);

// check if N is at least 5
while (N < 5) {
printf("Invalid size. Please enter a size of at least 5: ");
scanf("%d", &N);
}

//allocate memory for the array using pointers
int *array = (int *)malloc(N * sizeof(int));
if (array == NULL) {
printf("Memory allocation failed.\n");
    return 1;
    }

// Prompt the user to enter each element of the array
printf("Enter %d elements of the array:\n", N);
for (int i = 0; i < N; i++) {
    printf("Element %d: ", i + 1);
    scanf("%d", &array[i]);
        }

    int index1, index2;

// Prompt the user to enter the two indices
printf("Enter the first index: ");
scanf("%d", &index1);
while (!validate_index(index1, N)) {
    printf("Invalid index. Please enter a valid index (0 to %d): ", N-1 );
    scanf("%d", &index1);
    }

printf("Enter the second index: ");
scanf("%d", &index2);
while (!validate_index(index2, N)) {
    printf("Invalid index. Please enter a valid index (0 to %d): ", N-1 );
    scanf("%d", &index2);
    }

//find the sum of the values of the two array elements
int sum = *(array + index1) + *(array + index2);


printf("The sum of the elements at indices %d and %d is: %d\n", index1, index2, sum);



    return 0;
}