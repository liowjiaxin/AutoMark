#include <stdio.h>
#include <stdlib.h>

int main() {
    int n; //initialize variable for size of array 
    while (1)  //implement an infinite loop which does not break until valid value is given
    {
        printf("Enter the size of the array ( >= 5) : ");  //user input for array size
        scanf("%d", &n);

        if (n < 5)   // loop to verify if given size is greater than 5
        {
            printf("Invalid size, enter again: ");
        } 
        else 
        {
            break;
        }
    }

    int *array = (int *)malloc(n * sizeof(int));  // dynamic memory allocation for array using pointer

    printf("Enter the array elements:\n");
    for (size_t i = 0; i < n; i++)
    {                                               // take user input for each element of the array
        printf("Enter element %d: ", i);
        scanf("%d", (array + i));
    }

    int index1, index2;
    while (1)
    {
        printf("Enter the indices of two elements (0 <= index1, index2 < %d): ", n);   // take user input for index values 
        scanf("%d %d", &index1, &index2);

        if (index1 >= 0 && index1 < n && index2 >= 0 && index2 < n)  // verify if index lies within the array
        {
            break;
        } 
        else
        {
            printf("Indices must be within the range of array elements. Please try again.\n");  // error message for when the given index values are not in the array 
        }
    }

    int sum = *(array + index1) + *(array + index2); // implement pointer arithmetic sum

    printf("The sum of values at indices %d and %d is %d\n", index1, index2, sum);  // print out the output

    free(array);  // free the memory location to prevent memory leaks

    return 0;
}
