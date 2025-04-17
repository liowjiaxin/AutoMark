#include <stdio.h>
#include <stdlib.h>

int main() {
    // define variable and array
    int size;
    int *array = NULL;

    // ask user to input the size of the array
    printf("Enter the size of array (N >= 5): ");
    while (1) {
        scanf("%d", &size);
        while(getchar() != '\n');
        if (size < 5) {
            printf("Error: invalid size. Enter again: ");
        }
        else {
            break;
        }
    }

    // make array
    array = malloc(size * sizeof(int));

    // ask user to input elements
    printf("Enter the array elements: \n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i);
        scanf("%d", &array[i]);
        while (getchar() != '\n');
    }

    // ask user to input two indexes
    int index1, index2;
    while (1) {
        printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", size);
        scanf("%d %d", &index1, &index2);
        if (index2 < index1 || index1 < 0 || index2 >= size){  
            printf("Error: Indices must be within the range of the array elemtns. Please try again.\n");
        }
        else{
            break;
        }
    }

    // calculate the sum
    int sum = 0;
    for (int i = index1; i <= index2; i++) {
        sum += array[i];
    }
    // printing the sum 
    printf("The sum of the values at indices %d and %d is: %d", index1, index2, sum);
    return 0;
}