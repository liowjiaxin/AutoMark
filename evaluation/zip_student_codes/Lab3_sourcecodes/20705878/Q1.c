#include <stdio.h>

#define MAX_SIZE 10   // Define the maximum matrix size as 10x10 to restrict input.

// Function prototypes for every function
void addMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int rows, int cols);
void subtractMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int rows, int cols);
void transposeMatrix(int A[MAX_SIZE][MAX_SIZE], int T[MAX_SIZE][MAX_SIZE], int rows, int cols);
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);

int main() {
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], C[MAX_SIZE][MAX_SIZE];   // Declare matrices A, B, and C
    int T_A[MAX_SIZE][MAX_SIZE], T_B[MAX_SIZE][MAX_SIZE];                      // Declare matrices to store transposed matrices
    int rowsA, colsA, rowsB, colsB;                       // Variables to store dimensions of matrices A and B
    int choice;                                           // Variable to store user's choice from the menu

    // Input dimensions for Matrix A
    printf("Enter dimensions for Matrix A (rows and columns): ");
    scanf("%d %d", &rowsA, &colsA);                                            // Read dimensions for Matrix A
    while (rowsA < 1 || rowsA > 10 || colsA < 1 || colsA > 10) {               // Validate dimensions
        printf("Invalid dimensions. Enter dimensions for Matrix A (rows and columns): ");
        scanf("%d %d", &rowsA, &colsA);                  // Re-read dimensions if invalid
    }

    // Input elements for Matrix A
    printf("Enter elements for Matrix A:\n");
    for (int i = 0; i < rowsA; i++) {            // Iterate through each row
        for (int j = 0; j < colsA; j++) {        // Iterate through each column.
            printf("Element [%d][%d]: ", i+1, j+1);     // Prompt user for input at position (i+1, j+1)
            scanf("%d", &A[i][j]);                      // Read the element into the matrix
        }
    }

    // Input dimensions for Matrix B
    printf("Enter dimensions for Matrix B (rows and columns): ");
    scanf("%d %d", &rowsB, &colsB);
    while (rowsB < 1 || rowsB > 10 || colsB < 1 || colsB > 10) {
        printf("Invalid dimensions. Enter dimensions for Matrix B (rows and columns): ");
        scanf("%d %d", &rowsB, &colsB);
    }

    // Input elements for Matrix B
    printf("Enter elements for Matrix B:\n");
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            printf("Element [%d][%d]: ", i+1, j+1);
            scanf("%d", &B[i][j]);
        }
    }

    do {
        // Display menu
        printf("\nMatrix Operations Menu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);     // Read user's choice

        switch (choice) {
            case 1:
                if (rowsA == rowsB && colsA == colsB) {               // Check if matrices have the same dimensions
                    addMatrices(A, B, C, rowsA, colsA);               // Call function to add matrices
                    printf("Result of Matrix A + Matrix B:\n");
                    printMatrix(C, rowsA, colsA);                     // Print the result
                } else {
                    printf("Error! Matrices must have the same dimensions for addition.\n");
                }
                break;
            case 2:
                if (rowsA == rowsB && colsA == colsB) {
                    subtractMatrices(A, B, C, rowsA, colsA);
                    printf("Result of Matrix A - Matrix B:\n");
                    printMatrix(C, rowsA, colsA);
                } else {
                    printf("Error! Matrices must have the same dimensions for subtraction.\n");
                }
                break;
            case 3:
                transposeMatrix(A, T_A, rowsA, colsA);
                printf("Transpose of Matrix A:\n");
                printMatrix(T_A, colsA, rowsA);
                break;
            case 4:
                transposeMatrix(B, T_B, rowsB, colsB);
                printf("Transpose of Matrix B:\n");
                printMatrix(T_B, colsB, rowsB);
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);         // Loop until user chooses to exit

    return 0;
}

// Function to add two matrices
void addMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {                // Iterate through each row
        for (int j = 0; j < cols; j++) {            // Iterate through each column
            C[i][j] = A[i][j] + B[i][j];            // Add corresponding elements of A and B and store in C
        }
    }
}

// Function to subtract two matrices
void subtractMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] - B[i][j];           // Subtract corresponding elements of B from A and store in C
        }
    }
}

// Function to transpose a matrix
void transposeMatrix(int A[MAX_SIZE][MAX_SIZE], int T[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            T[j][i] = A[i][j];                    // Swap rows and columns to transpose the matrix
        }
    }
}

// Function to print a matrix
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);          // Print each element
        }
        printf("\n");                             // Move to the next row
    }
}