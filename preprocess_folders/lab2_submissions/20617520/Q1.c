#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sizeArr, *arr, index1, index2, sum = 0;

    //promt array size and validate the N>=5
    do{
        printf("Enter the size of the array (N >= 5): ");
        scanf("%d", &sizeArr); //put the size of the array into sizeArr
    } while (sizeArr < 5);

    //allocate memmory for array
    //RMB TO FREE MEMORY!!!
    arr = (int *) malloc (sizeArr * sizeof(int)); //allocate memory for arr
    if (arr == NULL)
    {
        printf("Memory allocation failed. \n"); //print error message if memory alloc fails
        return 1;
    }

    //prompt for array elements
    printf("Enter the array elements: ");
    for (int i = 0; i < sizeArr; i++) //loop to fill the array with elements entered by user
    {
        printf("Element %d: ",i);
        scanf("%d", &arr[i]); //put the elements entered by user into array
    }

    //prompy for indices and validate
    do 
    {
        printf("Enter the indices of the two elemtns (0 <= index1, index2): ");
        scanf("%d %d", &index1, &index2);
    } while(index1 < 0 || index1 >= sizeArr || index2 < 0 || index2 >= sizeArr);

    //sum (must use ptr) ptr arithmetic 
    sum = *(arr + index1) + *(arr + index2); //formula to add the elements that are pointed by pointer using ptr arithmetic

    //pritn output
    printf("The sum of the values ar the indices %d and %d is: %d \n", index1, index2, sum);

    free(arr); //free the memory
    return 0;
}
