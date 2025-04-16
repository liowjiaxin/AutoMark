#include <stdio.h>
#define ROWS 10
#define COLUMNS 10

// Function prototypes
void matrixAdd(int matA[ROWS][COLUMNS], int matB[ROWS][COLUMNS], int sum[ROWS][COLUMNS], int row, int col);
void matrixSub(int matA[ROWS][COLUMNS], int matB[ROWS][COLUMNS], int diff[ROWS][COLUMNS], int row, int col);
void transposeMatrix(int mat[ROWS][COLUMNS], int transpose[ROWS][COLUMNS], int row, int col);
void printMatrix(int matrix[ROWS][COLUMNS], int row, int col, const char *title);

int main() {
    // Declare matrices and variables
    int matA[ROWS][COLUMNS];
    int matB[ROWS][COLUMNS];
    int sum[ROWS][COLUMNS];
    int diff[ROWS][COLUMNS];
    int transposeA[ROWS][COLUMNS];
    int transposeB[ROWS][COLUMNS];
    int rowA, colA, rowB, colB;

    // Input dimensions and elements for Matrix A
    do {
        printf("Enter dimensions for Matrix A (rows and columns): ");
        scanf("%d %d", &rowA, &colA);
        if (rowA <= 0 || colA <= 0 || rowA > 10 || colA > 10) {
            printf("Invalid dimensions. Please enter values between 1 and 10.\n");
        }
    } while (rowA <= 0 || colA <= 0 || rowA > 10 || colA > 10);

    printf("Enter elements for Matrix A:\n");
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colA; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matA[i][j]);
        }
    }

    // Input dimensions and elements for Matrix B
    do {
        printf("Enter dimensions for Matrix B (rows and columns): ");
        scanf("%d %d", &rowB, &colB);
        if (rowB <= 0 || colB <= 0 || rowB > 10 || colB > 10) {
            printf("Invalid dimensions. Please enter values between 1 and 10.\n");
        } else if (rowA != rowB || colA != colB) {
            printf("Error: Matrices must have the same dimensions for addition and subtraction.\n");
        }
    } while (rowB <= 0 || colB <= 0 || rowB > 10 || colB > 10 || rowA != rowB || colA != colB);

    printf("Enter elements for Matrix B:\n");
    for (int i = 0; i < rowB; i++) {
        for (int j = 0; j < colB; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matB[i][j]);
        }
    }

    int choice;
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
                matrixAdd(matA, matB, sum, rowA, colA);
                printMatrix(sum, rowA, colA, "Result of Matrix A + Matrix B");
                break;
            case 2:
                matrixSub(matA, matB, diff, rowA, colA);
                printMatrix(diff, rowA, colA, "Result of Matrix A - Matrix B");
                break;
            case 3:
                transposeMatrix(matA, transposeA, rowA, colA);
                printMatrix(transposeA, colA, rowA, "Transpose of Matrix A");
                break;
            case 4:
                transposeMatrix(matB, transposeB, rowB, colB);
                printMatrix(transposeB, colB, rowB, "Transpose of Matrix B");
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

// Function to add two matrices
void matrixAdd(int matA[ROWS][COLUMNS], int matB[ROWS][COLUMNS], int sum[ROWS][COLUMNS], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            sum[i][j] = matA[i][j] + matB[i][j];
        }
    }
}

// Function to subtract Matrix B from Matrix A
void matrixSub(int matA[ROWS][COLUMNS], int matB[ROWS][COLUMNS], int diff[ROWS][COLUMNS], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            diff[i][j] = matA[i][j] - matB[i][j];
        }
    }
}

// Function to transpose a matrix
void transposeMatrix(int mat[ROWS][COLUMNS], int transpose[ROWS][COLUMNS], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            transpose[j][i] = mat[i][j];
        }
    }
}

// Function to print a matrix with a title
void printMatrix(int matrix[ROWS][COLUMNS], int row, int col, const char *title) {
    printf("\n%s:\n", title);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
