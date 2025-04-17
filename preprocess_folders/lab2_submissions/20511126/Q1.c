#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    printf("Enter the size of the array (N >=5): ");
    scanf("%d", &N);

    // Validate if N > 5
    while (N < 5)
    {
        printf("Invalid size, please enter a number >= 5");
        scanf("%d", &N);
    }

    // Dynamically allocate pointers
    int *array = (int *)malloc(N * sizeof(int));
    if (array == NULL)
    {
        printf("Memory allocation failed. Exiting program.\n");
        return 1;
    }

    // Prompting the user to enter all elements of the array
    printf("Enter the array elements: \n");
    for (int i = 0; i < N; i++)
    {
        printf("Element %d: ", i);
        scanf("%d", (array + i));
    }

    int index1, index2;
    // Prompt the user to input two indices that are valid
    do
    {
        printf("Enter the indices of the two elements: ");
        scanf("%d %d", &index1, &index2);

        if (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N)
        {
            printf("Invalid indices. Indices should be between 0 and %d.\n", N - 1);
        }
    } while (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N);

    // Calculating the sum
    int *ptr1 = &array[index1];
    int *ptr2 = &array[index2];

    int sum = *ptr1 + *ptr2;

    printf("The sum of the elements at indices %d and %d is %d", index1, index2, sum);
    free(array);

    return 0;
}
