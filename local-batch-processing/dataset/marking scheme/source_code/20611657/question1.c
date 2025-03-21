#include <stdio.h>

#define MAX 10 // Define the maximum size for the matrix as 10x10

// Function to take input for a matrix
void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) { // Loop through each row
        for (int j = 0; j < cols; j++) { // Loop through each column
            printf("Enter element [%d][%d]: ", i + 1, j + 1); // Prompt user to enter matrix element
            scanf("%d", &matrix[i][j]); // Store the input in the matrix
        }
    }
}

// Function to print a matrix
void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) { // Loop through each row
        for (int j = 0; j < cols; j++) { // Loop through each column
            printf("%d ", matrix[i][j]); // Print the element at the current position
        }
        printf("\n"); // Move to the next line after each row
    }
}

// Function to add two matrices
void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) { // Loop through each row
        for (int j = 0; j < cols; j++) { // Loop through each column
            C[i][j] = A[i][j] + B[i][j]; // Add corresponding elements of A and B
        }
    }
}

// Function to subtract one matrix from another
void subtractMatrices(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) { // Loop through each row
        for (int j = 0; j < cols; j++) { // Loop through each column
            C[i][j] = A[i][j] - B[i][j]; // Subtract corresponding elements of B from A
        }
    }
}

// Function to compute the transpose of a matrix
void transposeMatrix(int matrix[MAX][MAX], int transposed[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) { // Loop through each row
        for (int j = 0; j < cols; j++) { // Loop through each column
            transposed[j][i] = matrix[i][j]; // Assign the element at (i, j) to (j, i)
        }
    }
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], result[MAX][MAX]; // Declare matrices A, B, and result
    int rowsA, colsA, rowsB, colsB; // Variables to store dimensions of A and B
    int choice; // Variable to store user's menu choice

    // Input dimensions of matrix A
    printf("Enter rows and columns of matrix A (max 10x10): ");
    scanf("%d %d", &rowsA, &colsA);

    // Input dimensions of matrix B
    printf("Enter rows and columns of matrix B (max 10x10): ");
    scanf("%d %d", &rowsB, &colsB);

    // Check if dimensions match for addition and subtraction
    if (rowsA != rowsB || colsA != colsB) {
        printf("Addition and subtraction require matrices of the same dimensions.\n");
    }

    // Input elements for matrix A
    printf("Enter elements for matrix A:\n");
    inputMatrix(A, rowsA, colsA);

    // Input elements for matrix B
    printf("Enter elements for matrix B:\n");
    inputMatrix(B, rowsB, colsB);

    // Menu-driven program to perform matrix operations
    do {
        printf("\nMenu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add matrices
                if (rowsA == rowsB && colsA == colsB) { // Ensure dimensions match
                    addMatrices(A, B, result, rowsA, colsA); // Call addition function
                    printf("Result of Addition:\n");
                    printMatrix(result, rowsA, colsA); // Print the result
                } else {
                    printf("Cannot perform addition due to mismatched dimensions.\n");
                }
                break;
            case 2: // Subtract matrices
                if (rowsA == rowsB && colsA == colsB) { // Ensure dimensions match
                    subtractMatrices(A, B, result, rowsA, colsA); // Call subtraction function
                    printf("Result of Subtraction:\n");
                    printMatrix(result, rowsA, colsA); // Print the result
                } else {
                    printf("Cannot perform subtraction due to mismatched dimensions.\n");
                }
                break;
            case 3: // Transpose matrix A
                transposeMatrix(A, result, rowsA, colsA); // Call transpose function
                printf("Transpose of Matrix A:\n");
                printMatrix(result, colsA, rowsA); // Print the transposed matrix
                break;
            case 4: // Transpose matrix B
                transposeMatrix(B, result, rowsB, colsB); // Call transpose function
                printf("Transpose of Matrix B:\n");
                printMatrix(result, colsB, rowsB); // Print the transposed matrix
                break;
            case 5: // Exit the program
                printf("Exiting program.\n");
                break;
            default: // Handle invalid menu choices
                printf("Invalid choice!\n");
        }
    } while (choice != 5); // Repeat until the user chooses to exit

    return 0; // Exit the program
}
