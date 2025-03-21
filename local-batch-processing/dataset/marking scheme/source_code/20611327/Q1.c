/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

#define MAX_SIZE 10

// Function prototypes
void inputMatrix(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE]);
void displayMatrix(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE]);
void addMatrices(int rows, int cols, int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]);
void subtractMatrices(int rows, int cols, int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]);
void transposeMatrix(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE], int transposed[MAX_SIZE][MAX_SIZE]);

int main() {
    int rowsA, colsA, rowsB, colsB;
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];
    int choice;

    // Input dimensions and elements for Matrix A
    printf("Enter dimensions of Matrix A (rows and columns): ");
    scanf("%d %d", &rowsA, &colsA);
    if (rowsA <= 0 || rowsA > MAX_SIZE || colsA <= 0 || colsA > MAX_SIZE) {
        printf("Invalid dimensions for Matrix A.\n");
        return 1;
    }
    printf("Enter elements of Matrix A:\n");
    inputMatrix(rowsA, colsA, A);

    // Input dimensions and elements for Matrix B
    printf("Enter dimensions of Matrix B (rows and columns): ");
    scanf("%d %d", &rowsB, &colsB);
    if (rowsB <= 0 || rowsB > MAX_SIZE || colsB <= 0 || colsB > MAX_SIZE) {
        printf("Invalid dimensions for Matrix B.\n");
        return 1;
    }
    printf("Enter elements of Matrix B:\n");
    inputMatrix(rowsB, colsB, B);

    do {
        // Display menu
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
                if (rowsA == rowsB && colsA == colsB) {
                    addMatrices(rowsA, colsA, A, B, result);
                    printf("Result of Addition:\n");
                    displayMatrix(rowsA, colsA, result);
                } else {
                    printf("Matrices cannot be added due to incompatible dimensions.\n");
                }
                break;
            case 2:
                if (rowsA == rowsB && colsA == colsB) {
                    subtractMatrices(rowsA, colsA, A, B, result);
                    printf("Result of Subtraction:\n");
                    displayMatrix(rowsA, colsA, result);
                } else {
                    printf("Matrices cannot be subtracted due to incompatible dimensions.\n");
                }
                break;
            case 3:
                transposeMatrix(rowsA, colsA, A, result);
                printf("Transpose of Matrix A:\n");
                displayMatrix(colsA, rowsA, result);
                break;
            case 4:
                transposeMatrix(rowsB, colsB, B, result);
                printf("Transpose of Matrix B:\n");
                displayMatrix(colsB, rowsB, result);
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

void inputMatrix(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int rows, int cols, int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtractMatrices(int rows, int cols, int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

void transposeMatrix(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE], int transposed[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
}
