/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#define MAX_SIZE 10 // Defines the maximum size for the matrices

// Function prototypes for matrix operations
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, char name); // Reads a matrix from user input
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols); // Prints a matrix
void addMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int rows, int cols); // Adds two matrices
void subtractMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int rows, int cols); // Subtracts one matrix from another
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols); // Transposes a matrix

int main() {
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE]; // Matrices A and B in integer
    int rowsA, colsA, rowsB, colsB; // row and collumn of matrices A and B in integer
    int choice; // User's menu choice

    // dimensions and elements for Matrix A
    printf("Enter dimensions for Matrix A (rows and columns): "); // prompt for dimensions of Matrix A
    scanf("%d %d", &rowsA, &colsA); // check if dimensions of matrix A is valid
    while (rowsA > MAX_SIZE || colsA > MAX_SIZE || rowsA <= 0 || colsA <= 0) {
        printf("Invalid dimensions. Please enter again: ");
        scanf("%d %d", &rowsA, &colsA);
    }
    inputMatrix(A, rowsA, colsA, 'A');

    // dimensions and elements for Matrix B
    printf("Enter dimensions for Matrix B (rows and columns): "); // prompt for dimensions of Matrix B
    scanf("%d %d", &rowsB, &colsB); // check if dimensions of matrix A is valid
    while (rowsB > MAX_SIZE || colsB > MAX_SIZE || rowsB <= 0 || colsB <= 0) {
        printf("Invalid dimensions. Please enter again: ");
        scanf("%d %d", &rowsB, &colsB);
    }
    inputMatrix(B, rowsB, colsB, 'B');

    // menu loop for matrix operations
    do {
        printf("\nMatrix Operations Menu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
		// check if matrixes have the same dimension
                if (rowsA == rowsB && colsA == colsB) {
                    addMatrices(A, B, rowsA, colsA); // use function for adding matrices from below
                } else {
                    printf("Addition not possible. Matrices must have the same dimensions.\n"); 
                }
                break;
            case 2:
		// check if matrixes have the same dimension
                if (rowsA == rowsB && colsA == colsB) {
                    subtractMatrices(A, B, rowsA, colsA); // use function for subtracting matrices from below
                } else {
                    printf("Subtraction not possible. Matrices must have the same dimensions.\n");
                }
                break;
            case 3:
                transposeMatrix(A, rowsA, colsA); // use function for transposing Matrix A
                break;
            case 4:
                transposeMatrix(B, rowsB, colsB); // use function for transposing Matrix B
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0; //terminate program
}

// function for inputting matrix
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, char name) {
    printf("Enter elements for Matrix %c:\n", name);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// function for printing matrix
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// function for adding matrices
void addMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int result[MAX_SIZE][MAX_SIZE]; // Resultant matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j]; // Element-wise addition
        }
    }
    printf("Result of Matrix A + Matrix B:\n");
    printMatrix(result, rows, cols); // Prints the resulting matrix
}

// function for subtracting matrices
void subtractMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int result[MAX_SIZE][MAX_SIZE]; // Resultant matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] - B[i][j]; // Element-wise subtraction
        }
    }
    printf("Result of Matrix A - Matrix B:\n");
    printMatrix(result, rows, cols); // Prints the resulting matrix
}

// function for tranosing matrices
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int result[MAX_SIZE][MAX_SIZE]; // Transposed matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j]; // Swaps rows and columns
        }
    }
    printf("Transpose of the Matrix:\n");
    printMatrix(result, cols, rows); // Prints the transposed matrix
}