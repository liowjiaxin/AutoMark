#include <stdio.h>

// Function to input the elements of a matrix
void inputMatrix(int rows, int cols, int mat[10][10]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat[i][j]); // Take input for each element
        }
    }
}

// Function to print a matrix
void printMatrix(int rows, int cols, int mat[10][10]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", mat[i][j]); // Print each element
        }
        printf("\n"); // Move to the next row
    }
}

// Function to add two matrices
void addMatrices(int rows, int cols, int mat1[10][10], int mat2[10][10], int result[10][10]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j]; // Add corresponding elements
        }
    }
}

// Function to subtract one matrix from another
void subtractMatrices(int rows, int cols, int mat1[10][10], int mat2[10][10], int result[10][10]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j]; // Subtract corresponding elements
        }
    }
}

// Function to transpose a matrix
void transposeMatrix(int rows, int cols, int mat[10][10], int result[10][10]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = mat[i][j]; // Swap rows and columns
        }
    }
}

int main() {
    int row1, col1, row2, col2; // Dimensions of the matrices
    int matA[10][10], matB[10][10], matResult[10][10];
    int choice;

    // Input the size of the matrices
    printf("Enter dimensions of Matrix A (rows cols): ");
    scanf("%d %d", &row1, &col1);
    printf("Enter dimensions of Matrix B (rows cols): ");
    scanf("%d %d", &row2, &col2);

    // Validate matrix sizes
    if (row1 > 10 || col1 > 10 || row2 > 10 || col2 > 10) {
        printf("Error: Maximum size of matrices is 10x10.\n");
        return 1;
    }

    // Input the elements of both matrices
    printf("Enter elements of Matrix A:\n");
    inputMatrix(row1, col1, matA);
    printf("Enter elements of Matrix B:\n");
    inputMatrix(row2, col2, matB);

    do {
        // Display menu for user actions
        printf("\nMenu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Check if dimensions match for addition
                if (row1 == row2 && col1 == col2) {
                    addMatrices(row1, col1, matA, matB, matResult);
                    printf("Result of Addition:\n");
                    printMatrix(row1, col1, matResult);
                } else {
                    printf("Error: Matrices dimensions must match for addition.\n");
                }
                break;

            case 2:
                // Check if dimensions match for subtraction
                if (row1 == row2 && col1 == col2) {
                    subtractMatrices(row1, col1, matA, matB, matResult);
                    printf("Result of Subtraction:\n");
                    printMatrix(row1, col1, matResult);
                } else {
                    printf("Error: Matrices dimensions must match for subtraction.\n");
                }
                break;

            case 3:
                // Transpose Matrix A
                transposeMatrix(row1, col1, matA, matResult);
                printf("Transpose of Matrix A:\n");
                printMatrix(col1, row1, matResult);
                break;

            case 4:
                // Transpose Matrix B
                transposeMatrix(row2, col2, matB, matResult);
                printf("Transpose of Matrix B:\n");
                printMatrix(col2, row2, matResult);
                break;

            case 5:
                printf("Exiting the program.\n"); // Exit the loop
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
