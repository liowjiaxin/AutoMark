#include <stdio.h>
#define MAX_SIZE 10 // Define the maximum size for matrices

// Function to add two matrices
void add_matrix(int row, int col, int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE]) {
    int result[MAX_SIZE][MAX_SIZE];

    // Calculate the addition of matrices
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    // Print the result
    printf("\nResult of Matrix Addition:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

// Function to subtract two matrices
void sub_matrix(int row, int col, int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE]) {
    int result[MAX_SIZE][MAX_SIZE];

    // Calculate the subtraction of matrices
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }

    // Print the result
    printf("\nResult of Matrix Subtraction:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

// Function to calculate the transpose of a matrix
void transpose_matrix(int row, int col, int matrix[MAX_SIZE][MAX_SIZE]){
    int result[MAX_SIZE][MAX_SIZE];

    // Calculate the transpose
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result[j][i] = matrix[i][j];
        }
    }

    // Print the transpose
    printf("Transpose of the Matrix:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int rowA = 0, colA = 0; // Dimensions for Matrix A
    int valuesA[MAX_SIZE][MAX_SIZE]; // Values of Matrix A
    int rowB = 0, colB = 0; // Dimensions for Matrix B
    int valuesB[MAX_SIZE][MAX_SIZE]; // Values of Matrix B
    int choice = 0; // User's menu choice

    // Input for Matrix A and Matrix B with validation
    while(1){
        printf("Enter dimensions for Matrix A: (rows and columns): ");
        scanf("%d", &rowA);
        scanf("%d", &colA);

        if ((rowA <= MAX_SIZE) && (colA <= MAX_SIZE)) {
            printf("Enter elements for Matrix A:");
            for (int i = 0; i < rowA; i++) {
                for (int j = 0; j < colA; j++) {
                    printf("\nElement [%d][%d]: ", i + 1, j + 1);
                    scanf("%d", &valuesA[i][j]);
                }
            }
        } else {
            printf("Matrix dimensions exceed the maximum allowed size of %d.\n", MAX_SIZE);
        }
    
        printf("\nEnter dimensions for Matrix B: (rows and columns): ");
        scanf("%d", &rowB);
        scanf("%d", &colB);

        if ((rowB <= MAX_SIZE) && (colB <= MAX_SIZE)) {
            printf("Enter elements for Matrix B:");
            for (int i = 0; i < rowB; i++) {
                for (int j = 0; j < colB; j++) {
                    printf("\nElement [%d][%d]: ", i + 1, j + 1);
                    scanf("%d", &valuesB[i][j]);
                }
            }
        } else {
            printf("Matrix dimensions exceed the maximum allowed size of %d.\n", MAX_SIZE);
        }

        // Ensure both matrices have the same dimensions
        if (rowA != rowB || colA != colB) {
            printf("Error! The number of rows and columns for both Matrices must be the same!\n");
            continue; // Restart the loop for re-entry
        } else {
            break; // Exit the loop
        }
    }
    
    // Menu to perform matrix operations
    while (1) {
        printf("\nMatrix Operation Menu:\n");
        printf("1. Add Matrix\n");
        printf("2. Subtract Matrix\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add matrices
                add_matrix(rowA, colA, valuesA, valuesB);
                break;
            case 2: // Subtract matrices
                sub_matrix(rowA, colA, valuesA, valuesB);
                break;
            case 3: // Transpose Matrix A
                transpose_matrix(rowA, colA, valuesA);
                break;
            case 4: // Transpose Matrix B
                transpose_matrix(rowB, colB, valuesB);
                break;
            case 5: // Exit the program
                printf("Exiting...\n");
                return 0;
            default: // Invalid input
                printf("Invalid choice. Please enter 1, 2, 3, 4, or 5.\n");
        }
    }

    return 0;
}
