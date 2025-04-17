#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    //Making a valid array size 
    do {
        printf("Enter the size of the array(N >= 5): ");
        scanf("%d", &size);
        if (size < 5){
            printf("Invalid size. Please enter a size of at least 5.\n"); //Validation for minimum number of elements
        }
    } while (size < 5);
    //Allocate memory for array
    int *array = (int*)malloc(size *sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed.");
        return 1; //Program terminates if error.
    }
    //Request user to enter array elements 
    printf("Enter the array elements:\n", size);
    for (int i = 0; i < size ; i++){
        printf("Element %d:", i);
        scanf("%d", array + i);
    }
    //Enter valid indices to be calculated
    int index1, index2;
    do{ 
        printf("Enter the indices of two elements by space (0 - %d): ", size - 1);
        scanf("%d %d", &index1, &index2);
        if (index1 < 0 || index1 >= size || index2 < 0 || index2>size) {
            printf("Error. Indices must be within the range of the array elements. Please try again.\n");
        } 
       } while (index1 < 0 || index1 >= size || index2 < 0 || index2 >= size);
        //Applying pointers to compute the sum of the two indices entered
        int sum = *(array + index1) + *(array + index2);
        //Print the sum of elements 
        printf("The sum of the elements at indices %d and %d : %d\n", index1, index2, sum);
        //Free allocated memory
        free(array);
        
        return 0;
    
}
