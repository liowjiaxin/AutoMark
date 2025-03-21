#include <stdio.h>

#define MAX 10  // Maximum size of the matrix

// Function Prototypes
// Function to print a matrix
void printMatrix (int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf ("%d ", matrix[i][j]);
        }
        printf ("\n");
    }
}

// Function to add two matrices
void addMatrices (int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];   // Add coresponding elements
        }
    }
}

// Function to subtract two matrices
void subtractMatrices (int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] - b[i][j];   // Substract corresponding elements
        }
    }
}

// Function to transpose a matrix
void transposeMatrix (int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];    // Swap rows with columns
        }
     }
}

int main () {
    int rowsA, colsA, rowsB, colsB;
    int matrixA[MAX][MAX], matrixB[MAX][MAX];
    int result[MAX][MAX];
    int choice;

    // Prompt user to input dimensions for Matrix A and validate it
    printf ("Enter dimensions for Matrix A (rows and columns): ");
    scanf ("%d %d", &rowsA, &colsA);
    while (rowsA <= 0 || colsA <= 0 || rowsA > MAX || colsB > MAX) {
        printf ("Invalid dimensions for Matrix A. Please enter values between 1 and %d for both rows and columns. \n", MAX);
        printf ("Enter dimensions for Matrix A (rows and columns): ");
        scanf ("%d %d", &rowsA, &colsA);
    }

    // Input elements for Matrix A
    printf ("Enter elements for Matrix A: \n");
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            printf ("Element [%d][%d]: ", i + 1, j + 1);
            scanf ("%d", &matrixA[i][j]);
        }
    }

    // Prompt user to Input dimensions for Matrix B and validate it 
    printf ("Enter dimensions for Matrix B (rows and columns): ");
    scanf ("%d %d", &rowsB, &colsB);
    while (rowsA <= 0 || colsA <= 0 || rowsB > MAX || colsB > MAX) {
        printf ("Invalid dimensions for Matrix B. Please enter values between 1 and %d for both rows and columns. \n", MAX);
        printf ("Enter dimensions for Matrix B (rows and columns): ");
        scanf ("%d %d", &rowsB, &colsB);
    }

    printf ("Enter elements for Matrix B: \n");
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            printf ("Element [%d][%d]: ", i + 1, j + 1);
            scanf ("%d", &matrixB[i][j]);
        }
    }

    // Menu and Operaton loop
    while (1) {
        // Menu display
        printf ("\nMatrix Operation Menu: \n");
        printf ("1. Add Matrics\n");
        printf ("2. Subtract Matrices\n");
        printf ("3. Transpose Matrix A\n");
        printf ("4. Transpose Matrix B\n");
        printf ("5. Exit\n");
        printf ("Enter your choice: ");
        scanf ("%d", &choice);

        // Switch case for operations
        switch (choice) {
            case 1:
                // Add matrices if dimensions match
                if (rowsA == rowsB && colsA == colsB) {
                    addMatrices (matrixA, matrixB, result, rowsA, colsB);
                    printf ("Result of Matrix A + Matrix B: \n");
                    printMatrix (result, rowsA, colsA);
                } else {
                    printf ("Matrix dimensions must match for addition. \n");
                }
                break;
            
            case 2:
                // Subtract matrices if dimensions match
                if (rowsA == rowsB && colsA == colsB) {
                    subtractMatrices (matrixA, matrixB, result, rowsA, colsA);
                    printf ("Result of Matrix A - Matrix B: \n");
                    printMatrix (result, rowsA, colsA);
                } else {
                    printf ("Matrix dimensions must match for subtractions. \n");
                }
                break;

            case 3: 
                // Transpose Matrix A
                transposeMatrix (matrixA, result, rowsA, colsA);
                printf ("Transpose of Matrix A: \n");
                printMatrix (result, colsA, rowsA); // Rows become columns 
                break;

            case 4: 
                // Transpose Matrix B
                transposeMatrix (matrixB, result, rowsB, colsB);
                printMatrix (result, colsB, rowsB);
                break;

            case 5:
                // Exit Program
                printf ("Exiting...\n");
                return 0;

            default:
                // Invalid Menu Choice (Choice > 5)
                printf ("Invalid choice. Please try again. \n");
                break;
        }
    }

    return 0;
}