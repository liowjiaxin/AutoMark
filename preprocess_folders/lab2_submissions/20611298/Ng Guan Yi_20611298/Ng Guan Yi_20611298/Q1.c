#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    // pointer array
    int *array;
    // declare two variable
    int index1;

    int index2;

    // prompt the user to enter the size of the array
    printf("Enter the size of the array (N >= 5): ");
    scanf("%d", &N);

    // use while loop to check if N value is above 5
    while (N < 5)
    {
        printf("Error: N must be at least 5. Please try again.\n");
        printf("Enter the size of the array (N >= 5): ");
        scanf("%d", &N);
    }

    // allocate memory for the array
    array = (int *)malloc(N * sizeof(int));
    if (array == NULL)
    {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    // prompt user to enter all the elements for the array
    printf("Enter the array elements:\n");

    for (int i = 0; i < N; i++)
    {
        printf("Element %d: ", i);
        scanf("%d", (array + i));
    }

    printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", N);
    scanf("%d %d", &index1, &index2);

    // check if indices are within range
    while (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N)
    {
        // if not in range, prompt the user to enter it agian
        printf("Error: Indices must be within the range of the array elements. Please try again.\n");
        printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", N);
        scanf("%d %d", &index1, &index2);
    }

    // declare pointer to do the sum
    int sum = *(array + index1) + *(array + index2);

    // print output
    printf("The sum of the values at indices %d and %d is: %d\n", index1, index2, sum);

    // free memoryy
    free(array);

    return 0;
}