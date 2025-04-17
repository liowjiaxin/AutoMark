#include <stdio.h>
#include <stdlib.h>


int main()
{
    int N, index1, index2;
    int *array;

    printf("Enter the size of the array (N >= 5) : ");
    scanf("%d", &N);

    while (N < 5 || N <= 0)     // validate N >= 5
    {
        printf("Please make sure N >= 5");
        printf("Enter the size of the array (N >= 5) : ");
        scanf("%d", &N);
    }

    array = (int *)malloc(N * sizeof(int));     // allocate memory for array
    
    printf("Enter the array elements : \n");
    for (int i = 0; i < N; i++)
    {
        printf("Elements %d : ", i);
        scanf("%d", &array[i]);
    }

    printf("Enter the indices of the two elements (index1 >= 0, index2 < %d) : ", N-1);
    scanf("%d %d", &index1, &index2);

    while (index1 < 0 || index2 > N)     // Validate index 1 and 2
    {
        printf("Indices must be within the range of array elements. Please try again.\n");
        printf("Enter the indices of the two elements (0 <= index1, index2 < %d) : ", N-1);
        scanf("%d %d", &index1, &index2);
    } 

    int sum = *(array + index1) + *(array + index2); 


    printf("The sum of the elements at indices %d and %d is : %d\n", index1, index2, sum);   // Print the sum


    return 0;
}