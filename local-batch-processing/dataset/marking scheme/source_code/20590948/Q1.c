#include <stdio.h>

#define MAX_SIZE 10  // Define the maximum size for the matrix

// Function declarations for matrix operations
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int rows, int cols);
void subtractMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int rows, int cols);
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);

int main() {
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE];  // Matrices A and B
    int rowsA, colsA, rowsB, colsB;  // Dimensions of matrices
    int choice;  // User's choice for the operation

    // Input the size and elements of Matrix A
    printf("Enter the number of rows and columns for Matrix A: ");
    scanf("%d %d", &rowsA, &colsA);

    if (rowsA > MAX_SIZE || colsA > MAX_SIZE) {
        printf("Error: Dimensions of Matrix A exceed the allowed limit.\n");
        return 1;  // Exit the program if dimensions are invalid
    }

    printf("Enter the elements of Matrix A:\n");
    inputMatrix(A, rowsA, colsA);

    // Input the size and elements of Matrix B
    printf("Enter the number of rows and columns for Matrix B: ");
    scanf("%d %d", &rowsB, &colsB);

    if (rowsB > MAX_SIZE || colsB > MAX_SIZE) {
        printf("Error: Dimensions of Matrix B exceed the allowed limit.\n");
        return 1;  // Exit the program if dimensions are invalid
    }

    printf("Enter the elements of Matrix B:\n");
    inputMatrix(B, rowsB, colsB);

    // Display a menu for matrix operations
    do {
        printf("\nMatrix Operations Menu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Perform matrix addition
                if (rowsA == rowsB && colsA == colsB) {
                    printf("Result of Matrix A + Matrix B:\n");
                    addMatrices(A, B, rowsA, colsA);
                } else {
                    printf("Error: Matrices must have the same dimensions for addition.\n");
                }
                break;

            case 2:
                // Perform matrix subtraction
                if (rowsA == rowsB && colsA == colsB) {
                    printf("Result of Matrix A - Matrix B:\n");
                    subtractMatrices(A, B, rowsA, colsA);
                } else {
                    printf("Error: Matrices must have the same dimensions for subtraction.\n");
                }
                break;

            case 3:
                // Transpose Matrix A
                printf("Transpose of Matrix A:\n");
                transposeMatrix(A, rowsA, colsA);
                break;

            case 4:
                // Transpose Matrix B
                printf("Transpose of Matrix B:\n");
                transposeMatrix(B, rowsB, colsB);
                break;

            case 5:
                // Exit the program
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please select a valid option from the menu.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to input matrix elements
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element at position [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display a matrix
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");  // Move to the next row
    }
}

// Function to add two matrices and display the result
void addMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int result[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];  // Perform element-wise addition
        }
    }
    printMatrix(result, rows, cols);
}

// Function to subtract one matrix from another and display the result
void subtractMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int result[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] - B[i][j];  // Perform element-wise subtraction
        }
    }
    printMatrix(result, rows, cols);
}

// Function to calculate and display the transpose of a matrix
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int result[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            result[i][j] = matrix[j][i];  // Swap rows and columns
        }
    }
    printMatrix(result, cols, rows);
}
