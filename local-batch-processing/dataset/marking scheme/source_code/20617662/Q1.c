#include <stdio.h>

#define MAXIMUM 10

//Function to input the elements of a matrix 
void input_matrix(int matrix[MAXIMUM][MAXIMUM], int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}


//Function to display the elements of a matrix
void display_matrix(int matrix[MAXIMUM][MAXIMUM], int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}


// Function to add two matrices
void addMatrices(int A[MAXIMUM][MAXIMUM], int B[MAXIMUM][MAXIMUM], int rows, int columns) {
    int result[MAXIMUM][MAXIMUM];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    printf("Result of Matrix A + Matrix B:\n");
    display_matrix(result, rows, columns);
}


// Function to substract matrix B from matrix A 
void substract_matrices(int A[MAXIMUM][MAXIMUM], int B[MAXIMUM][MAXIMUM], int rows, int columns) {
    int result[MAXIMUM][MAXIMUM];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
    printf("Result of Matrix A - Matrix B:\n");
    display_matrix(result, rows, columns);
}


// Function to transpose a matrix 
void transposeMatrix(int matrix[MAXIMUM][MAXIMUM], int rows, int columns) {
    int transposed[MAXIMUM][MAXIMUM];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
    printf("Transposed Matrix:\n");
    display_matrix(transposed, columns, rows);
}

int main() {
    int A[MAXIMUM][MAXIMUM], B[MAXIMUM][MAXIMUM]; // Matrices A & B
    int rowsA, columnsA, rowsB, columnsB; // Dimensions of matrices 
    int choice; //User's menu choice 
    

    printf("Enter dimensions for Matrix A (rows and columns): ");
    scanf("%d %d", &rowsA, &columnsA);

    printf("Enter elements for Matrix A:\n");
    input_matrix(A, rowsA, columnsA);

    printf("Enter dimensions for Matrix B (rows and columns): ");
    scanf("%d %d", &rowsB, &columnsB);

    printf("Enter elements for Matrix B:\n");
    input_matrix(B, rowsB, columnsB);

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
            case 1:
                if (rowsA == rowsB && columnsA == columnsB) {
                    addMatrices(A, B, rowsA, columnsA);
                } else {
                    printf("Matrix dimensions do not match for addition!\n");
                }
                break;
            case 2:
                if (rowsA == rowsB && columnsA == columnsB) {
                    substract_matrices(A, B, rowsA, columnsA);
                } else {
                    printf("Matrix dimensions do not match for subtraction!\n");
                }
                break;
            case 3:
                transposeMatrix(A, rowsA, columnsA);
                break;
            case 4:
                transposeMatrix(B, rowsB, columnsB);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
