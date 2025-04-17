#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int N; 
    int *array;
    int index1, index2;
    int sum = 0;

    // prompt user to enter size of array, N
    printf("Enter the size of the array (N >= 5): ");

    // validate input (size of array at least 5)
    do
    {
        scanf("%d", &N);

        if (N < 5) 
        {
            printf("Invalid size. Please enter a value of N >= 5: ");
        }
    } while (N < 5);

    // allocate memory for the array
    array = (int*)malloc(N * sizeof(int));
    if (array == NULL) 
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // prompt user to enter the array elements
    printf("Enter the array elements:\n");
    for (int i = 0; i < N; i++) 
    {
        printf("Element %d: ", i);
        scanf("%d", (array + i));
    }

    // prompt user to enter the indices of two elements (validate input)
    while (1) 
    {
        printf("Enter the indices of two elements (index1 >= 0, index2 < %d): ", N);
        scanf("%d %d", &index1, &index2);

        if (index1 >= 0 && index2 < N) 
        {
            break;
        }
        printf("Error: Indices must be within the range of the array elements. Please try again.\n");
    }

    // calculate the sum using pointers
    sum = *(array + index1) + *(array + index2);

    // display the sum
    printf("The sum of the values at indices %d and %d is: %d\n", index1, index2, sum);

    // free allocated memory
    free(array);

    return 0;
}
