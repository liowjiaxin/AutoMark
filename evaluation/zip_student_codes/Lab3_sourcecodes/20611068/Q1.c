#include <stdio.h>

// Function to get matrix dimensions 
void dimensions(int *rows, int *cols) {
    scanf("%d %d", rows, cols); // Read rows and columns
}

// Function to get matrix elements
void elements(int rows, int cols, int matrix[rows][cols]) {
    // Loop through each element of the matrix and get input
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]); // Read each element
        }
    }
}

// Function to add two matrices
void add(int rows, int cols, int matrixA[rows][cols], int matrixB[rows][cols], int result[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

// Function to subtract two matrices
void subtract(int rows, int cols, int matrixA[rows][cols], int matrixB[rows][cols], int result[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

// Function to transpose matrix
void transpose(int rows, int cols, int matrix[rows][cols], int transposed[cols][rows]) {
    // Swap rows with columns
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
}

// Function to print a matrix
void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]); // Print each element
        }
        printf("\n"); // Newline after each row
    }
}

int main() {
    int rowsA, colsA, rowsB, colsB;
    int matrixA[10][10], matrixB[10][10], result[10][10], transposed[10][10];
    int choice;

    // Get dimensions and elements for both matrices
    printf("Enter dimensions for Matrix A (rows and columns):");
    dimensions(&rowsA, &colsA); // Get dimensions for Matrix A
    printf("Enter elements for Matrix A:\n");
    elements(rowsA, colsA, matrixA); // Get elements for Matrix A

    printf("\nEnter dimensions for Matrix B (rows and columns):");
    dimensions(&rowsB, &colsB); // Get dimensions for Matrix B
    printf("Enter elements for Matrix B:\n");
    elements(rowsB, colsB, matrixB); // Get elements for Matrix B

    // Display menu 
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
            case 1: // Add Matrices
                if (rowsA == rowsB && colsA == colsB) {
                    add(rowsA, colsA, matrixA, matrixB, result);
                    printf("Result of Matrix A + Matrix B:\n");
                    printMatrix(rowsA, colsA, result);
                } else {
                    printf("Matrices cannot be added. Dimensions must be the same.\n");
                }
                break;
            case 2: // Subtract Matrices
                if (rowsA == rowsB && colsA == colsB) {
                    subtract(rowsA, colsA, matrixA, matrixB, result);
                    printf("Result of Matrix A - Matrix B:\n");
                    printMatrix(rowsA, colsA, result);
                } else {
                    printf("Matrices cannot be subtracted. Dimensions must be the same.\n");
                }
                break;
            case 3: // Transpose of Matrix A
                transpose(rowsA, colsA, matrixA, transposed);
                printf("Transpose of Matrix A:\n");
                printMatrix(colsA, rowsA, transposed); 
                break;
            case 4: // Transpose of Matrix B
                transpose(rowsB, colsB, matrixB, transposed);
                printf("Transpose of Matrix B:\n");
                printMatrix(colsB, rowsB, transposed);  
                break;
            case 5: // Exit
                printf("Exiting program...\n");
                break;
            default: // Invalid input
                printf("Invalid choice. Please enter again.\n");
        }
    } while (choice != 5);

    return 0;
}
