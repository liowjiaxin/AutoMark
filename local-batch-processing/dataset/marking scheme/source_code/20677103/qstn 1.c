#include <stdio.h>

// Defining the maximum size for the matrices
#define MAX_SIZE 10

// Declarations of functions: The functions will be defined afterwards
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void subtractMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int transposed[MAX_SIZE][MAX_SIZE], int rows, int cols);

int main() {
    // Declare matrices and result arrays
    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int transposedA[MAX_SIZE][MAX_SIZE], transposedB[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA, rowsB, colsB; // Variables for the number of rows and columns of each matrix
    int choice; // To store the user's menu choice

    // Input matrix A's dimensions and elements
    printf("Enter the number of rows and columns for Matrix A (max 10x10): ");
    scanf("%d %d", &rowsA, &colsA);  // Taking input for rows and columns
    printf("Enter the elements of Matrix A:\n");
    inputMatrix(matrixA, rowsA, colsA);  // Function to input the elements of Matrix A

    // Input matrix B's dimensions and elements
    printf("Enter the number of rows and columns for Matrix B (max 10x10): ");
    scanf("%d %d", &rowsB, &colsB);  // Taking input for rows and columns
    printf("Enter the elements of Matrix B:\n");
    inputMatrix(matrixB, rowsB, colsB);  // Function to input the elements of Matrix B

    // Loop to display the menu and ask the user for an operation until the exit condition
    do {
        // Display matrix operations menu
        printf("\nMatrix Operations Menu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); // Get user choice for operation

        switch (choice) {
            case 1:
                // Add matrices A and B if their dimensions match
                if (rowsA == rowsB && colsA == colsB) {
                    addMatrices(matrixA, matrixB, result, rowsA, colsA);  // Call function to add matrices
                    printf("Matrix A + Matrix B =\n");
                    displayMatrix(result, rowsA, colsA);  // Display the result of the addition
                } else {
                    printf("Matrix dimensions must match for addition.\n");
                }
                break;

            case 2:
                // Subtract matrices A and B if their dimensions match
                if (rowsA == rowsB && colsA == colsB) {
                    subtractMatrices(matrixA, matrixB, result, rowsA, colsA); // Call function to subtract matrices
                    printf("Matrix A - Matrix B =\n");
                    displayMatrix(result, rowsA, colsA);  // Display the result of the subtraction
                } else {
                    printf("Matrix dimensions must match for subtraction.\n");
                }
                break;

            case 3:
                // Transpose matrix A
                transposeMatrix(matrixA, transposedA, rowsA, colsA);  // Call function to transpose Matrix A
                printf("Transpose of Matrix A:\n");
                displayMatrix(transposedA, colsA, rowsA);  // Display the transposed matrix (rows and cols swapped)
                break;

            case 4:
                // Transpose matrix B
                transposeMatrix(matrixB, transposedB, rowsB, colsB);  // Call function to transpose Matrix B
                printf("Transpose of Matrix B:\n");
                displayMatrix(transposedB, colsB, rowsB);  // Display the transposed matrix (rows and cols swapped)
                break;

            case 5:
                // Quit the program
                printf("Exiting the program.\n");
                break;

            default:
                // If the user entered an invalid choice, prompt them to try again
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);  // Repeat the loop until the user chooses to exit

    return 0;  // Terminates the program
}

// Input function for the elements of the matrix
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    // Loop to take input for each element of the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);  // Display a prompt for the user to enter the element
            scanf("%d", &matrix[i][j]);  // Store the element in the matrix
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    // Loop to display the elements of the matrix in a formatted way
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);  // Print each element followed by a space
        }
        printf("\n");  // Print a new line after each row
    }
}

// Function to add two matrices
void addMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    // Loop through each element of the matrices and add corresponding elements
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];  // Add corresponding elements of A and B
        }
    }
}

// Function to subtract two matrices
void subtractMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    // Loop through each element of the matrices and subtract corresponding elements
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];  // Subtract corresponding elements of A and B
        }
    }
}

// Function to transpose a matrix
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int transposed[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    // Loop through each element and assign it to the transposed position
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];  // Swap the row and column indices
        }
    }
}
