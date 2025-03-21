/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

#define MAX_DIM 10 // Maximum dimension for matrices

// Function prototypes
void getMatrixInput(int rows, int cols, int matrix[MAX_DIM][MAX_DIM]);
void printMatrix(int rows, int cols, int matrix[MAX_DIM][MAX_DIM]);
void matrixAddition(int rows, int cols, int mat1[MAX_DIM][MAX_DIM], int mat2[MAX_DIM][MAX_DIM], int result[MAX_DIM][MAX_DIM]);
void matrixSubtraction(int rows, int cols, int mat1[MAX_DIM][MAX_DIM], int mat2[MAX_DIM][MAX_DIM], int result[MAX_DIM][MAX_DIM]);
void matrixTranspose(int rows, int cols, int matrix[MAX_DIM][MAX_DIM], int transposed[MAX_DIM][MAX_DIM]);

int main() {
    int rows1, cols1, rows2, cols2;
    int mat1[MAX_DIM][MAX_DIM], mat2[MAX_DIM][MAX_DIM];
    int result[MAX_DIM][MAX_DIM];
    int option;

    // Input Matrix A dimensions and elements
    printf("Enter dimensions for Matrix A (rows and columns): ");
    scanf("%d %d", &rows1, &cols1);
    if (rows1 <= 0 || rows1 > MAX_DIM || cols1 <= 0 || cols1 > MAX_DIM) {
        printf("Error: Invalid dimensions for Matrix A.\n");
        return 1;
    }
    printf("Enter elements for Matrix A:\n");
    getMatrixInput(rows1, cols1, mat1);

    // Input Matrix B dimensions and elements
    printf("Enter dimensions for Matrix B (rows and columns): ");
    scanf("%d %d", &rows2, &cols2);
    if (rows2 <= 0 || rows2 > MAX_DIM || cols2 <= 0 || cols2 > MAX_DIM) {
        printf("Error: Invalid dimensions for Matrix B.\n");
        return 1;
    }
    printf("Enter elements for Matrix B:\n");
    getMatrixInput(rows2, cols2, mat2);

    do {
        // Display menu for operations
        printf("\nMatrix Operations Menu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                if (rows1 == rows2 && cols1 == cols2) {
                    matrixAddition(rows1, cols1, mat1, mat2, result);
                    printf("Result of Matrix A + Matrix B:\n");
                    printMatrix(rows1, cols1, result);
                } else {
                    printf("Error: Matrices have incompatible dimensions for addition.\n");
                }
                break;
            case 2:
                if (rows1 == rows2 && cols1 == cols2) {
                    matrixSubtraction(rows1, cols1, mat1, mat2, result);
                    printf("Result of Matrix A - Matrix B:\n");
                    printMatrix(rows1, cols1, result);
                } else {
                    printf("Error: Matrices have incompatible dimensions for subtraction.\n");
                }
                break;
            case 3:
                matrixTranspose(rows1, cols1, mat1, result);
                printf("Transpose of Matrix A:\n");
                printMatrix(cols1, rows1, result);
                break;
            case 4:
                matrixTranspose(rows2, cols2, mat2, result);
                printf("Transpose of Matrix B:\n");
                printMatrix(cols2, rows2, result);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please choose again.\n");
        }
    } while (option != 5);

    return 0;
}

// Function to take matrix input
void getMatrixInput(int rows, int cols, int matrix[MAX_DIM][MAX_DIM]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print matrix
void printMatrix(int rows, int cols, int matrix[MAX_DIM][MAX_DIM]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function for matrix addition
void matrixAddition(int rows, int cols, int mat1[MAX_DIM][MAX_DIM], int mat2[MAX_DIM][MAX_DIM], int result[MAX_DIM][MAX_DIM]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

// Function for matrix subtraction
void matrixSubtraction(int rows, int cols, int mat1[MAX_DIM][MAX_DIM], int mat2[MAX_DIM][MAX_DIM], int result[MAX_DIM][MAX_DIM]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

// Function to transpose a matrix
void matrixTranspose(int rows, int cols, int matrix[MAX_DIM][MAX_DIM], int transposed[MAX_DIM][MAX_DIM]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
}
