#include <stdio.h>
#define MAX 10 // Define the maximum size for matrices as 10x10

// Function prototypes: declarations of functions used in the program
void inputMatrix(int matrix[MAX][MAX], int rows, int cols);
void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void subtractMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void displayMatrix(int matrix[MAX][MAX], int rows, int cols);

int main() {
    int rowsA, colsA, rowsB, colsB; // Variables for matrix dimensions
    int A[MAX][MAX], B[MAX][MAX], result[MAX][MAX]; // Matrices A, B, and result
    int choice; // Variable to store user's menu choice

    // Ask the user to enter dimensions of Matrix A
    printf("Enter dimensions of Matrix A (rows and columns): ");
    scanf("%d %d", &rowsA, &colsA);

    // Ask the user to enter dimensions of Matrix B
    printf("Enter dimensions of Matrix B (rows and columns): ");
    scanf("%d %d", &rowsB, &colsB);

    // Check if the matrix dimensions are within the allowed size
    if (rowsA > MAX || colsA > MAX || rowsB > MAX || colsB > MAX) {
        printf("Matrix dimensions exceed maximum allowed size (%dx%d).\n", MAX, MAX);
        return 1; // Exit the program if dimensions are invalid
    }

    // Input elements of Matrix A
    printf("Enter elements of Matrix A:\n");
    inputMatrix(A, rowsA, colsA);

    // Input elements of Matrix B
    printf("Enter elements of Matrix B:\n");
    inputMatrix(B, rowsB, colsB);

    // Start a loop for the menu
    do {
        // Display menu options
        printf("\nMenu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); // Read user's choice

        switch (choice) {
            case 1:
                // Check if matrices have the same dimensions for addition
                if (rowsA == rowsB && colsA == colsB) {
                    addMatrices(A, B, result, rowsA, colsA);
                    printf("Result of Addition:\n");
                    displayMatrix(result, rowsA, colsA);
                } else {
                    printf("Addition not possible: Dimensions do not match.\n");
                }
                break;
            case 2:
                // Check if matrices have the same dimensions for subtraction
                if (rowsA == rowsB && colsA == colsB) {
                    subtractMatrices(A, B, result, rowsA, colsA);
                    printf("Result of Subtraction:\n");
                    displayMatrix(result, rowsA, colsA);
                } else {
                    printf("Subtraction not possible: Dimensions do not match.\n");
                }
                break;
            case 3:
                // Transpose Matrix A and display the result
                transposeMatrix(A, result, rowsA, colsA);
                printf("Transpose of Matrix A:\n");
                displayMatrix(result, colsA, rowsA);
                break;
            case 4:
                // Transpose Matrix B and display the result
                transposeMatrix(B, result, rowsB, colsB);
                printf("Transpose of Matrix B:\n");
                displayMatrix(result, colsB, rowsB);
                break;
            case 5:
                // Exit the program
                printf("Exiting program.\n");
                break;
            default:
                // Handle invalid input
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5); // Continue the menu loop until the user chooses to exit

    return 0;
}

// Function to input elements of a matrix
void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]); // Read each element of the matrix
        }
    }
}

// Function to add two matrices
void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j]; // Add corresponding elements
        }
    }
}

// Function to subtract two matrices
void subtractMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] - B[i][j]; // Subtract corresponding elements
        }
    }
}

// Function to transpose a matrix
void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j]; // Swap rows and columns
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]); // Print each element
        }
        printf("\n"); // Move to the next row
    }
}
