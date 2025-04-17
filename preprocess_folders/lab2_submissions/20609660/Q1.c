#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Initialisation
    int arraySize = 0;
    int *ptr = NULL;
    int firstIndex = 0;
    int secondIndex = 0;

    printf("Size of the array: ");
    scanf(" %d", &arraySize);

    // Allocate memory for the array using pointer
    ptr = (int *)malloc(arraySize * sizeof(int));

    // Error handling if memory allocation fail
    if (ptr == NULL)
    {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else
    {
        // Get the elements of the array from user
        for (int i = 0; i < arraySize; i++)
        {
            printf("Enter Number %d: ", i + 1);
            scanf(" %d", &ptr[i]);
        }
    }

    // Input validating from user, user must provide a value of indices that is within the range of the array
    while (1)
    {
        // Prompt user to input 2 indices seperated by " "
        printf("Enter 2 indices (positions) to sum up together [Enter 2 numbers between 0 and %d]: ", arraySize - 1);
        scanf(" %d %d", &firstIndex, &secondIndex);

        // If user's input value is within the range of the array, it will print out the sum of both the values from the indices
        if (firstIndex >= 0 && firstIndex < arraySize && secondIndex >= 0 && secondIndex < arraySize)
        {
            void sum(int *ptr, int firstIndex, int secondIndex); // Function prototype
            sum(ptr, firstIndex, secondIndex);                   // Sum the values and print out
            break;
        }
        else
        {
            // Error message and prompt user to enter again
            printf("Invalid indices entered. Please try again.\n");
        }
    }
}

// A function to sum up all values based on the index input by User
void sum(int *ptr, int firstIndex, int secondIndex)
{
    int sum = ptr[firstIndex] + ptr[secondIndex];
    printf("Sum of elements at indices %d and %d is: %d\n", firstIndex, secondIndex, sum);
}