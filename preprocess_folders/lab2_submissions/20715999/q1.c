#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void clear_buffer(void) {
    while (getchar() != '\n'); // Flush the input buffer
}

void standard_input(char input[], size_t size) {
    fgets(input, size, stdin); // Directly read into the passed array
    if (!strchr(input, '\n')) { // Check if the newline was not present (overflow occurred)
        clear_buffer(); // Clear the buffer
    } else {
        input[strcspn(input, "\n")] = '\0'; // Remove newline character if present
    }
}

int is_digit(char input[]){
    for(int i = 0; i < strlen(input); i++){
        if(!isdigit(input[i])) {
            puts("Invalid input. Input must only contain digits.");
            return 0; // Test failed
        }
    }
    return 1; // Test pass
}

int main(void){
    char input[10] = "\0";
    int N = 0;
    int arr[] = {0}; 
    int *arrPtr = arr;
    arrPtr = malloc(100*sizeof(int));
    int index1 = 0;
    int index2 = 0;
    int sum = 0;
    
    do {
        printf("Enter the size of the array (N>= 5): ");
        standard_input(input, sizeof(input)); // Get input
        N = atoi(input); // Convert string to int
    } while (N < 5);

    printf("%d\n", N);

    for (int i = 0; i < N;) { // Code is not functioning here, please tell me why
        printf("Element %d: ", i);
        standard_input(input, sizeof(input));
        if (!is_digit(input)) continue; // Get input again if not a number
        *(arr + i) = atoi(input); // Convert string to int
        i++; 
    }

    while (1) {
        printf("Enter the indices of two elements (0 <= index1, index2 < %d)\n", N);
        // Get index1
        printf("enter index1: ");
        standard_input(input, sizeof(input));
        if (!is_digit(input)) continue; // Get input again if not a number
        index1 = atoi(input); // Convert string to int
        
        // Get index2
        printf("enter index2: ");
        standard_input(input, sizeof(input));
        if (!is_digit(input)) continue; // Get input again if not a number
        index2 = atoi(input); // Convert string to int
        
        // Validate index1 and index2
        if (index1 < 0 || index2 >= N ){
            puts("Error, indices must be within the range of the array elements. Please try again");
            continue; // Get input again
        }
        break;
    }
    
    // Get sum
    sum += *(arrPtr + index1);
    sum += *(arrPtr + index2);

    printf("The sum of values at the two indices %d and %d are %d", index1, index2, sum);
    
    free(arrPtr); // Free memory
}