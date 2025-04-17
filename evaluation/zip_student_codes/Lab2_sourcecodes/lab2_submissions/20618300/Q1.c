#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int number, index1, index2, *array;

    // Ask user to enter the size of the array
    printf("Enter the size of the array (N >= 5): ");
    scanf("%d", &number);

    // Fix that number >= 5
    while (number < 5) 
    {
        printf("Size must be at least 5. Please try again: ");
        scanf("%d", &number);
    }

    // Allocate memory for the array based on the user input
    array = (int *)malloc(number * sizeof(int));
    if (array == NULL) 
    {
        printf("Memory allocation failed. Exiting program.\n");
        return 1;
    }

    // Ask the user to enter the elements of the array
    printf("Enter the array elements:\n");
    for (int i = 0; i < number; i++) 
    {
        printf("Element %d: ", i);
        scanf("%d", &array[i]); 
    }

    // Use while True to keep asking the user to enter two valid elements based on the requirement
    while (1) 
    {
        printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", number);
        scanf("%d %d", &index1, &index2);

        // Check if the the range is valid
        if (index1 >= 0 && index1 < number && index2 >= 0 && index2 < number) 
        {
            break; 
        } 
        else 
        {
            printf("Error: Indices must be within the range of the array elements. Please try again.\n");
        }
    }

    // Sum of the two elements
    int sum = array[index1] + array[index2];

    printf("The sum of the values at indices %d and %d is: %d\n", index1, index2, sum);

    // Free the allocated memory
    free(array);

    return 0;
}
