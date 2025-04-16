#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 10

// FUNCTION PROTOTYPES
// Main functions
void transpose(int[][MAX_SIZE], char, int[]); 
void add_matrices(int[][MAX_SIZE], int[], int[][MAX_SIZE], int[]);
void substract_matrices(int[][MAX_SIZE], int[], int[][MAX_SIZE], int[]);
void print_matrix(int matrix[][MAX_SIZE], int dimensions[]);

//INPUT FUNCTIONS + VALIDATION 
void standard_input(char[], size_t); // Primary way to get input, size_t is size of array.
void clear_buffer(void); // Flush buffer
void matrix_input(int[][MAX_SIZE], char, int[]); // Get matrix
int is_digit(char[]); // Return 1 if string only contain digits, else return 0
int is_empty(char[]); // Return 1 if string is empty, else return 0
int is_zero(char[]); // Return 1 if input is 01, 03, 0XX, else return 0

int main (void) {
    int matrix_A[MAX_SIZE][MAX_SIZE] = {0};
    int matrix_B[MAX_SIZE][MAX_SIZE] = {0};
    char a = 'A';
    char b = 'B';
    int dimensions_A[2] = {0};
    int dimensions_B[2] = {0};
    char input[10] = "\0";
    int choice = -1;

    while (1) {
        puts("==== MATRIX OPERATIONS MENU ====");
        puts("Enter 1 to Add Matrices");
        puts("Enter 2 to Substract Matrices");
        puts("Enter 3 to Transpose Matrix A");
        puts("Enter 4 to Transpose Matrix B");
        puts("Enter 5 to exit program");
        printf("Choice: ");
            standard_input(input, sizeof(input));
            if (is_empty(input)) continue; // Get input again if is empty
            if (!is_digit(input)) continue; // Get input again if non digit
            if (is_zero(input)) continue; // Get input again if input is 01, 02, 0XX
            choice = atoi(input); // Convert input to int
            if (choice == 5) {
                puts("Exiting program");
                break;
            }

        switch (choice) {
            default:
                puts("Invalid input. Please enter a number (1-5)");
                break;
            case 1:
                // Get matrix
                matrix_input(matrix_A, a, dimensions_A);
                matrix_input(matrix_B, b, dimensions_B);
                add_matrices(matrix_A, dimensions_A, matrix_B, dimensions_B);
                break;
            case 2:
                // Get matrix
                matrix_input(matrix_A, a, dimensions_A);
                matrix_input(matrix_B, b, dimensions_B);
                substract_matrices(matrix_A, dimensions_A, matrix_B, dimensions_B);
                break;
            case 3:
                // Get matrix
                matrix_input(matrix_A, a, dimensions_A);
                transpose(matrix_A, a, dimensions_A);
                break;
            case 4:
                // Get matrix
                matrix_input(matrix_B, b, dimensions_B);
                transpose(matrix_B, b, dimensions_B);
                break;
        }
    }
    return 0;
}


// Main functions
void transpose(int matrix[][MAX_SIZE], char choice, int dimensions[]) {
    int rows = dimensions[0];
    int columns = dimensions[1];
    int transposed_matrix[MAX_SIZE][MAX_SIZE]; // Columns and rows swapped

    // Transpose
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            transposed_matrix[j][i] = matrix[i][j];
        }
    }

    // Print transposed matrix
    print_matrix(transposed_matrix, dimensions);
}

void add_matrices(int matrix_A[][MAX_SIZE], int dimensions_A[], int matrix_B[][MAX_SIZE], int dimensions_B[]) {
    int rows = dimensions_A[0];
    int columns = dimensions_A[1];
    int matrix_result[MAX_SIZE][MAX_SIZE]; // Columns and rows swapped
    // Check if Matrix A and Matrix B has same dimensions
    if (dimensions_A[0] != dimensions_B[0] || dimensions_A[1] != dimensions_B[1]) {
        puts("Invalid addition of matrices");
        puts("Matrix A and Matrix B must have same dimensions");
        return;
    }
    
    // Do addition 
    puts("Matrix A + Matrix B");
    for (int i = 0; i < dimensions_A[0]; i++) {
        for (int j = 0; j < dimensions_A[1]; j++) {
            matrix_result[i][j] = matrix_A[i][j] + matrix_B[i][j];
        }
    }

    // Print result
    print_matrix(matrix_result, dimensions_A);

}

void substract_matrices(int matrix_A[][MAX_SIZE], int dimensions_A[], int matrix_B[][MAX_SIZE], int dimensions_B[]) {
    int rows = dimensions_A[0];
    int columns = dimensions_A[1];
    int matrix_result[MAX_SIZE][MAX_SIZE]; // Columns and rows swapped
    // Check if Matrix A and Matrix B has same dimensions
    if (dimensions_A[0] != dimensions_B[0] || dimensions_A[1] != dimensions_B[1]) {
        puts("Invalid substraction of matrices");
        puts("Matrix A and Matrix B must have same dimensions");
        return;
    }
    
    // Do substraction
    puts("Matrix A - Matrix B");
    for (int i = 0; i < dimensions_A[0]; i++) {
        for (int j = 0; j < dimensions_A[1]; j++) {
            matrix_result[i][j] = matrix_A[i][j] - matrix_B[i][j];
        }
    }

    // Print result
    print_matrix(matrix_result, dimensions_A);
}

void print_matrix(int matrix[][MAX_SIZE], int dimensions[]) {
    for (int i = 0; i < dimensions[0]; i++) {
        for (int j = 0; j < dimensions[1]; j++) {
            printf("%-5d", matrix[i][j]);
        }
        printf("\n\n");
    }
}


//INPUT FUNCTIONS + VALIDATION 
void clear_buffer(void){
    while(getchar() != '\n');
}

void standard_input(char input[], size_t size) {
    fgets(input, size, stdin); // Directly read into the passed array
    if (!strchr(input, '\n')) { // Check if the newline was not present (overflow occurred)
        clear_buffer(); // Clear the buffer
    } 
    else {
        input[strcspn(input, "\n")] = '\0'; // Remove newline character if present
    }
}

void matrix_input(int matrix[][MAX_SIZE], char choice, int dimensions[]) {
    char input[5] = "\0";
    printf("Enter dimensions of matrix %c\n", choice);
    while(1) {
        printf("Enter rows: ");
        standard_input(input, sizeof(input));
        if (is_empty(input)) continue; // Get input again if is empty
        if (!is_digit(input)) continue; // Get input again if non digit
        if (is_zero(input)) continue; // Get input again if input is 01, 02, 0XX
        if (atoi(input) == 0) {
            puts("Invalid input. Rows can not be 0");
            continue; // Get input again
        }
        if (atoi(input) > MAX_SIZE) {
            puts("Invalid input. Maximum number rows is 10");
            continue; // Get input again if rows more than 10
        }
        dimensions[0] = atoi(input); // Convert input to int
        break;
    }
    while(1) {
        printf("Enter columns: ");
        standard_input(input, sizeof(input));
        if (is_empty(input)) continue; // Get input again if is empty
        if (!is_digit(input)) continue; // Get input again if non digit
        if (is_zero(input)) continue; // Get input again if input is 01, 02, 0XX
        if (atoi(input) == 0) {
            puts("Invalid input. Columns can not be 0");
            continue; // Get input again
        }
        if (atoi(input) > MAX_SIZE) {
            puts("Invalid input. Maximum number of columns is 10");
            continue; // Get input again if columns more than 10
        }
        dimensions[1] = atoi(input); // Convert input to int
        break;
    }

    for (int i = 0; i < dimensions[0]; i ++) {
        for (int j = 0; j < dimensions[1]; j++) {
            while(1) {
            printf("Element[%d][%d]: ", i + 1, j + 1);
            standard_input(input, sizeof(input));
            if (is_empty(input)) continue; // Get input again if is empty
            if (!is_digit(input)) continue; // Get input again if non digit
            if (is_zero(input)) continue; // Get input again if input is 01, 02, 0XX
            matrix[i][j] = atoi(input); // Convert input to int
            break;
            }
        }
    }
}

int is_digit(char input[]){
    if(!isdigit(input[0]) && input[0] != '-') { // Allow first character to be negative
        puts("Invalid input. Input must only contain digits.");
        return 0;
    }
    for(int i = 1; i < strlen(input); i++){
        if(!isdigit(input[i])) {
            puts("Invalid input. Input must only contain digits.");
            return 0; // Test failed
        }
    }
    return 1; // Test pass
}

int is_empty(char input[]){
    if (strlen(input) == 0) {
        puts("Invalid input. Input can not be empty.");
        return 1; // Empty, return 1
    }
    return 0; // Not empty, return 0
}

int is_zero(char input[]) {
    if (input[0] == '0' && input[1] != '\0') {
        printf("0 can not have following numbers after it.\n"); 
        return 1;
    }
    return 0;
}