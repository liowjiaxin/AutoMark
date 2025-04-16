#include <stdio.h>

#define MAX 10 // Defining the maximum size of matrices

// Function prototypes
void inputMatrix(int rows, int cols, int matrix[MAX][MAX]); // Fucntion to input a matrix
void printMatrix(int rows, int cols, int matrix[MAX][MAX]); // Function to print a matrix
void addMatrices(int rows, int cols, int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX]); // Function to add two matrices
void subtractMatrices(int rows, int cols, int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX]); // Function to subtract two matrices
void transposeMatrix(int rows, int cols, int matrix[MAX][MAX], int result[MAX][MAX]); // Function to find the transpose of a matrix.

int main() {
    int rowsA, colsA, rowsB, colsB; // Variable for storing dimensions of both matrices
    int matrixA[MAX][MAX], matrixB[MAX][MAX]; // Arrays to store elements of both matices
    int result[MAX][MAX]; // Storing result of operations 
    int choice; // Varaible to store the user's menu choice

    // Input dimensions and validate
    printf("Enter dimensions for Matrix A (rows and columns): ");
    scanf("%d %d", &rowsA, &colsA);
    if (rowsA > MAX || colsA > MAX || rowsA <= 0 || colsA <= 0) { // Validate dimensions (useful)
        printf("Invalid dimensions! Maximum size is %dx%d.\n", MAX, MAX);
        return 1; // Exit if invalid
    }

    // Input elements for Matrix A
    printf("Enter elements for Matrix A:\n");
    inputMatrix(rowsA, colsA, matrixA);

    // Input dimensions for Matrix B 
    printf("Enter dimensions for Matrix B (rows and columns): ");
    scanf("%d %d", &rowsB, &colsB);
    if (rowsB > MAX || colsB > MAX || rowsB <= 0 || colsB <= 0) {
        printf("Invalid dimensions! Maximum size is %dx%d.\n", MAX, MAX);
        return 1;
    }

    // Input elements for Matrix B
    printf("Enter elements for Matrix B:\n");
    inputMatrix(rowsB, colsB, matrixB);

    do {
        // Display menu
        printf("\nMatrix Operations Menu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add Matrices 
                if (rowsA == rowsB && colsA == colsB) { // Check if dimensions match
                    addMatrices(rowsA, colsA, matrixA, matrixB, result); // Perform addition 
                    printf("Result of Matrix A + Matrix B:\n");
                    printMatrix(rowsA, colsA, result); // Print result 
                } else {
                    printf("Matrices must have the same dimensions for addition.\n");
                }
                break;
            case 2: // Subtract Matrices
                if (rowsA == rowsB && colsA == colsB) { // Check if dimensions match
                    subtractMatrices(rowsA, colsA, matrixA, matrixB, result); // Peform subtarction
                    printf("Result of Matrix A - Matrix B:\n");
                    printMatrix(rowsA, colsA, result); // Print result 
                } else {
                    printf("Matrices must have the same dimensions for subtraction.\n");
                }
                break;
            case 3: //Transpose Matrix A 
                transposeMatrix(rowsA, colsA, matrixA, result); // Find transpose of Matrix A 
                printf("Transpose of Matrix A:\n");
                printMatrix(colsA, rowsA, result); // Print result 
                break;
            case 4: // Transpose Matrix B 
                transposeMatrix(rowsB, colsB, matrixB, result); // Find transpose of Matrix B 
                printf("Transpose of Matrix B:\n");
                printMatrix(colsB, rowsB, result); // Print result 
                break;
            case 5: // Exit 
                printf("Exiting...\n");
                break;
            default: // Handle invalid choice 
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5); // Repeat until user chooses to exit 

    return 0; // End program 
}

void inputMatrix(int rows, int cols, int matrix[MAX][MAX]) {
    for (int i = 0; i < rows; i++) { // Loop through rows 
        for (int j = 0; j < cols; j++) { // Loop through columns
            printf("Element [%d][%d]: ", i + 1, j + 1); // Prompt for each element
            scanf("%d", &matrix[i][j]); // Read element
        }
    }
}

void printMatrix(int rows, int cols, int matrix[MAX][MAX]) {
    for (int i = 0; i < rows; i++) { // Loop through rows
        for (int j = 0; j < cols; j++) { // Loop through columns
            printf("%d ", matrix[i][j]); // Print element 
        }
        printf("\n"); // New line after each row
    }
}

void addMatrices(int rows, int cols, int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX]) {
    for (int i = 0; i < rows; i++) { // Loop through rows
        for (int j = 0; j < cols; j++) { // Loop through coloumns
            result[i][j] = a[i][j] + b[i][j]; // Add corresponding elements
        }
    }
}

void subtractMatrices(int rows, int cols, int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX]) {
    for (int i = 0; i < rows; i++) { // Loop through rows
        for (int j = 0; j < cols; j++) { // Loop through coloumns 
            result[i][j] = a[i][j] - b[i][j]; // Subtract corresponding elements
        }
    }
}

void transposeMatrix(int rows, int cols, int matrix[MAX][MAX], int result[MAX][MAX]) {
    for (int i = 0; i < rows; i++) { // Loop through rows 
        for (int j = 0; j < cols; j++) { // Loop through columns 
            result[j][i] = matrix[i][j]; // Transpose element
        }
    }
}
