#include <stdio.h>
#include <stdlib.h>

//Addition handling function
void addMatrices(int **A, int **B, int rows, int cols, int **result) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

//Subtraction handling function
void subtractMatrices(int **A, int **B, int rows, int cols, int **result) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

//Transpose handling function
void transposeMatrix(int **A, int rows, int cols, int **result) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = A[i][j];
        }
    }
}

//Displaying handling function
void displayMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrixA_rows, matrixA_cols, matrixB_rows, matrixB_cols;

    // Input dimensions for matrix A
    printf("Enter dimensions for Matrix A:\n");
    printf("Rows: ");
    scanf("%d", &matrixA_rows);
    printf("Cols: ");
    scanf("%d", &matrixA_cols);

    // Input dimensions for matrix B
    printf("Enter dimensions for Matrix B:\n");
    printf("Rows: ");
    scanf("%d", &matrixB_rows);
    printf("Cols: ");
    scanf("%d", &matrixB_cols);

    // Validate dimensions for matrix operations
    if (matrixA_rows != matrixB_rows || matrixA_cols != matrixB_cols) {
        printf("Error: Matrices must have the same dimensions for addition and subtraction.\n");
        return 1;
    }

    // Allocate memory for matrices
    int **matrixA = (int **)malloc(matrixA_rows * sizeof(int *));
    int **matrixB = (int **)malloc(matrixB_rows * sizeof(int *));
    int **result = (int **)malloc(matrixA_rows * sizeof(int *));

    for (int i = 0; i < matrixA_rows; i++) {
        matrixA[i] = (int *)malloc(matrixA_cols * sizeof(int));
        matrixB[i] = (int *)malloc(matrixB_cols * sizeof(int));
        result[i] = (int *)malloc(matrixA_cols * sizeof(int));
    }

    // Input elements for matrix A
    printf("Enter elements for Matrix A:\n");
    for (int i = 0; i < matrixA_rows; i++) {
        for (int j = 0; j < matrixA_cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrixA[i][j]);
        }
    }

    // Input elements for matrix B
    printf("Enter elements for Matrix B:\n");
    for (int i = 0; i < matrixB_rows; i++) {
        for (int j = 0; j < matrixB_cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrixB[i][j]);
        }
    }

    int choice;
    do {
        //menu options
        printf("----------------------------");
        printf("\nMatrix Operations Menu:\n");
        printf("----------------------------\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        //handling menu options
        switch (choice) {
            case 1:
                addMatrices(matrixA, matrixB, matrixA_rows, matrixA_cols, result);
                printf("\nResult of Matrix A + Matrix B:\n");
                displayMatrix(result, matrixA_rows, matrixA_cols);
                break;
            case 2:
                subtractMatrices(matrixA, matrixB, matrixA_rows, matrixA_cols, result);
                printf("\nResult of Matrix A - Matrix B:\n");
                displayMatrix(result, matrixA_rows, matrixA_cols);
                break;
            case 3:
                transposeMatrix(matrixA, matrixA_rows, matrixA_cols, result);
                printf("\nTranspose of Matrix A:\n");
                displayMatrix(result, matrixA_cols, matrixA_rows);
                break;
            case 4:
                transposeMatrix(matrixB, matrixB_rows, matrixB_cols, result);
                printf("\nTranspose of Matrix B:\n");
                displayMatrix(result, matrixB_cols, matrixB_rows);
                break;
            case 5:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 5);

    // Free allocated memory
    for (int i = 0; i < matrixA_rows; i++) {
        free(matrixA[i]);
        free(matrixB[i]);
        free(result[i]);
    }
    free(matrixA);
    free(matrixB);
    free(result);

    return 0;
}