#include <stdio.h> 
#include <stdlib.h> 
 
int main() { 
    int size = 0;
    int indices1 = 0;
    int indices2 = 0;
    printf("Enter the size of the array: "); 
    scanf("%d", &size); 
    
    if(size >= 5){
    // Allocate memory for the array 
    int *array = (int *)malloc(size * sizeof(int)); 
    if (array == NULL) { 
        printf("Memory allocation failed\n"); 
        return 1; // Exit if allocation fails 
    } 
 
    //Fill the array with user input 
    for (int i = 0; i < size; i++) { 
        printf("Enter element %d: ", i + 1); 
        scanf("%d", &array[i]); 
    } 
 
    //Print the array 
    printf("You entered: "); 
    for (int i = 0; i < size; i++) { 
        printf("%d ", array[i]); 
    } 
    printf("\n"); 
    
    // Free the allocated memory 
    free(array); 
    }
    else{
        printf("Number entered is not within range!");
    }
    
    printf("Enter the indices of two elements (0 <= index1, index < %d): ", size);
    scanf("%d %d", &indices1, &indices2);
    
    
    if (indices1 && indices2 <= 0 && size){
        printf("Enter the indices of two elements (0 <= index1, index < %d): ", size, indices1, indices2);
    }
    else{
        printf("Error: Indices must be within  the range of array elements. Please try again.");
    }
    
    
    
    return 0; 
} 