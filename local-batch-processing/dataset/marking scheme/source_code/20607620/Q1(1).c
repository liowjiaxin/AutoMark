#include <stdio.h>

#define MAX 10 // Max matrix size

// Input elements
void inputMatrix(int matrix[MAX][MAX], int numRows, int numCols) {
    for (int row = 0; row < numRows; row++) { // Loop through rows
        for (int col = 0; col < numCols; col++) { // Loop through columns
            printf("Element [%d][%d]: ", row + 1, col + 1); 
            scanf("%d", &matrix[row][col]); 
        }
    }
}

// Addition matrix
void sumMatrices(int matrixA[MAX][MAX], int matrixB[MAX][MAX], int resultMatrix[MAX][MAX], int numRows, int numCols) {
    for (int row = 0; row < numRows; row++) { // Loop through rows
        for (int col = 0; col < numCols; col++) { // Loop through columns
            resultMatrix[row][col] = matrixA[row][col] + matrixB[row][col]; 
        }
    }
}

// Subtraction matrix
void diffMatrices(int matrixA[MAX][MAX], int matrixB[MAX][MAX], int resultMatrix[MAX][MAX], int numRows, int numCols) {
    for (int row = 0; row < numRows; row++) { // Loop through rows
        for (int col = 0; col < numCols; col++) { // Loop through columns
            resultMatrix[row][col] = matrixA[row][col] - matrixB[row][col]; 
        }
    }
}

// Transpose function
void computeTranspose(int original[MAX][MAX], int transposed[MAX][MAX], int numRows, int numCols) {
    for (int row = 0; row < numRows; row++) { // Loop through rows
        for (int col = 0; col < numCols; col++) { // Loop through columns
            transposed[col][row] = original[row][col]; // Swap rows and columns
        }
    }
}

// Display matrix
void printMatrix(int matrix[MAX][MAX], int numRows, int numCols) {
    for (int row = 0; row < numRows; row++) { // Loop through rows
        for (int col = 0; col < numCols; col++) { // Loop through columns
            printf("%d ", matrix[row][col]); 
        }
        printf("\n"); 
    }
}


int main() {
    int rowsMatrixA, colsMatrixA, rowsMatrixB, colsMatrixB; // Dimensions of matrices
    int matrixA[MAX][MAX], matrixB[MAX][MAX], resultMatrix[MAX][MAX]; // Matrices for input and results
    int transposedMatrix[MAX][MAX]; // Transposed matrix
    int userChoice; // User's menu choice

    // Input dimensions and elements of Matrix A
    printf("Enter dimensions for Matrix A (rows and columns): ");
    scanf("%d %d", &rowsMatrixA, &colsMatrixA);
    printf("Enter elements for Matrix A:\n");
    inputMatrix(matrixA, rowsMatrixA, colsMatrixA);

    // Input dimensions and elements of Matrix B
    printf("Enter dimensions for Matrix B (rows and columns): ");
    scanf("%d %d", &rowsMatrixB, &colsMatrixB);
    printf("Enter elements for Matrix B:\n");
    inputMatrix(matrixB, rowsMatrixB, colsMatrixB);

    
    do {
        printf("\nMatrix Operations Menu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &userChoice); 

        switch (userChoice) {
            case 1: // Add matrices
                if (rowsMatrixA == rowsMatrixB && colsMatrixA == colsMatrixB) { // Check if dimensions match
                    sumMatrices(matrixA, matrixB, resultMatrix, rowsMatrixA, colsMatrixA);
                    printf("Result of Matrix A + Matrix B:\n");
                    printMatrix(resultMatrix, rowsMatrixA, colsMatrixA); 
                } else {
                    printf("Error: Matrices dimensions do not match for addition.\n");
                }
                break;
            case 2: // Subtract matrices
                if (rowsMatrixA == rowsMatrixB && colsMatrixA == colsMatrixB) { // Check if dimensions match
                    diffMatrices(matrixA, matrixB, resultMatrix, rowsMatrixA, colsMatrixA);
                    printf("Result of Matrix A - Matrix B:\n");
                    printMatrix(resultMatrix, rowsMatrixA, colsMatrixA); 
                } else {
                    printf("Error: Matrices dimensions do not match for subtraction.\n");
                }
                break;
            case 3: // Transpose Matrix A
                computeTranspose(matrixA, transposedMatrix, rowsMatrixA, colsMatrixA);
                printf("Transpose of Matrix A:\n");
                printMatrix(transposedMatrix, colsMatrixA, rowsMatrixA); 
                break;
            case 4: // Transpose Matrix B
                computeTranspose(matrixB, transposedMatrix, rowsMatrixB, colsMatrixB);
                printf("Transpose of Matrix B:\n");
                printMatrix(transposedMatrix, colsMatrixB, rowsMatrixB); 
                break;
            case 5: 
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (userChoice != 5); // Loop until the user chooses to exit

    return 0; // Exit the program
}