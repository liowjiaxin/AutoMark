#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Function to input matrix element
void inputMatrix (int matrix[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j< cols; j ++) {
            printf ("Enter element [%d][%d]: ", i + 1, j + 1); // Prompt user for each element
            scanf ("%d", &matrix[i][j]); // Read the input element
        }
    }
}

// Function to display matrix element
void displayMatrix( int matrix[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]); // Print each element
        }
        printf ("\n"); // New line after each row
    }
}

// Function to add two matrices
void addMatrices (int matrixA[][MAX_SIZE], int matrixB[][MAX_SIZE], int result[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j =0; j < cols; j ++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j]; // add corresponding elements
        }
    }
}

// Function to subtract two matrices
void subtractMatrices (int matrixA[][MAX_SIZE], int matrixB[][MAX_SIZE], int result[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j =0; j < cols; j ++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j]; // subtract corresponding elements
        }
    }
}

// Function to transpose matrix
void transposeMatrix (int matrix[][MAX_SIZE], int transposed[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j =0; j < cols; j ++) {
            transposed[j][i] = matrix[i][j]; // Swap rows & columns
        }
    }
}

// Main menu
void displayMenu () {
    printf ("Matrix Operations Menu: \n");
    printf ("1. Add Matrices\n");
    printf ("2. Subtract Matrices\n");
    printf ("3. Transpose Matrix A\n");
    printf ("4. Transpose Matrix B\n");
    printf ("5. Exit\n");
}

int main () {
    // Declare matrices & variables
    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE], result [MAX_SIZE][MAX_SIZE], transposedA[MAX_SIZE][MAX_SIZE], transposedB[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA, rowsB, colsB, choice;

    choice =0; // Initialize choice to a non-zero value to enter the loop

    // Input matrix A&B
    printf ("Enter dimensions of matrix A (rows and columns): ");
    scanf ("%d %d", &rowsA, &colsA);
    printf("Enter the elements of matrix A:\n");
    inputMatrix(matrixA, rowsA, colsA);
    printf ("Enter dimensions of matrix B (rows and columns): ");
    scanf ("%d %d", &rowsB, &colsB);
    printf("Enter the elements of matrix B:\n");
    inputMatrix(matrixB, rowsB, colsB);

    while (choice != 5) {
        displayMenu (); 
        printf("Enter your choice: ");
        scanf ("%d", &choice);

        switch (choice) {
            case 1:
                // Check dimensions are compatible or not
                if (rowsA == rowsB && colsA == colsB) {
                    addMatrices(matrixA, matrixB, result, rowsA, colsA);
                    printf ("Result of adding matrices A and B:\n");
                    displayMatrix(result, rowsA, colsA);
                } else {
                    printf ("Matrices cannot be added. Different dimension\n");
                }
                break;
            case 2:
                // Check dimensions are compatible or not
                if (rowsA == rowsB && colsA == colsB) {
                    subtractMatrices(matrixA, matrixB, result, rowsA, colsA);
                    printf ("Result of subtracting matrices A and B:\n");
                    displayMatrix(result, rowsA, colsA);
                } else {
                    printf ("Matrices cannot be subtracted. Different dimension\n");
                }
                break;
            case 3:
                transposeMatrix(matrixA, transposedA, rowsA, colsA);
                printf("Tranpose of matrix A:\n");
                displayMatrix(transposedA, colsA, rowsA);
                break;
            case 4:
                transposeMatrix(matrixB, transposedB, rowsB, colsB);
                printf("Transpose of matrix B:\n");
                displayMatrix(transposedB, colsB, rowsB);
                break;
            case 5:
                printf ("Exiting...\n");
                break;
            default:
                printf ("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}