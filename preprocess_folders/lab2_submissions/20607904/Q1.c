#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *arr = NULL; //initialising the pointer to the dynamic array to NULL
    int N, index1, index2; //initialing 3 int variables

    int first_time = 1; //initialing first_time variable so that it wont show an error message the first time
    do {
        if (first_time != 1) {
            printf("Array must be larger than 5, try again\n"); //displaying an error message if this is not the first time the user is attempting to input the variable
        }
        printf("Enter the size of the array (N ≥ 5): ");
        scanf("%d", &N);
        first_time = 0;
    } while (N < 5); //checking if the user input is less than 5, if it is loop back

    //Reallocating memory to the size of the array(N) * the size of an int
    int *temp = realloc(arr, N * sizeof(int)); //we reallocate temp in case it fails initially instead of arr
    if(temp == NULL) {
        printf("Memory allocation failed"); //printing an error and freeing memory in the case of the memory failing to allocate
        free(arr);
        return 0;
    }
    arr = temp; //setting arr to the reallocated memory address

    for(int i = 0; i<N; i++) { //running a for loop to read user input for elemnts and storing them in the array
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    first_time = 1; //resetting first_time variable so that it wont show an error message the first time
    do {
        if (first_time != 1) {
            printf("Error: Indices must be within range of the array elements. Please try again.\n"); //displaying an error message if this is not the first time
        }
        printf("Enter the indices of the two elements (0 <= index1, index < %d): ", N);
        scanf("%d %d", &index1, &index2); //reading two integers separated by a space
        first_time = 0;
    } while (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N); //checking if the two indexes given by the user are within bounds 

    //using pointer arithmatics to calculate the sum of the two numbers
    int *num1ptr = arr + index1;  
    int *num2ptr = arr + index2;  
    int sum = *num1ptr + *num2ptr;   

    printf("The sum of the values at indices %d and %d is: %d", index1, index2, sum); //printing sum  of the two numbers and their index

    free(arr); //freeing arr as its not being used anymore
    return 0;
}