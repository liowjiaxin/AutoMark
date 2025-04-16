#include <stdio.h>
#include <stdlib.h>

#define MAX 10

//Define the prototypes of five functions that are used for matrix operations
void inputMatrix(int rows, int cols, int matrix[MAX][MAX]);
void printMatrix(int rows, int cols, int matrix[MAX][MAX]);
void addMatrices(int rows, int cols, int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX]);
void subtractMatrices(int rows, int cols, int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX]);
void transposeMatrix(int rows, int cols, int matrix[MAX][MAX], int result[MAX][MAX]);

int main() {
    //Declare several variables to be used in the matrix operations
    int rowsA, colsA, rowsB, colsB;
    int matrixA[MAX][MAX], matrixB[MAX][MAX];
    int result[MAX][MAX];
    int choice;

    // Input dimensions for Matrix A
    printf("Enter dimensions for Matrix A (rows and columns): ");
    scanf("%d %d", &rowsA, &colsA);

    //Ensure input matrix dimensions are valid for accurate matrix calculations
    if (rowsA > MAX || colsA > MAX || rowsA <= 0 || colsA <= 0 ) {
        printf("Invalid matrix dimensions. Maximum allowed is %dx%d.\n", MAX, MAX);
        return 1;
    }

    // Input Matrix A
    printf("Enter elements for Matrix A:\n");
    inputMatrix(rowsA, colsA, matrixA);
    
    // Input dimensions for Matrix B
    printf("Enter dimensions for Matrix B (rows and columns): ");
    scanf("%d %d", &rowsB, &colsB);

    if (rowsB > MAX || colsB > MAX || rowsB <= 0 || colsB <= 0) {
        printf("Invalid matrix dimensions. Maximum allowed is %dx%d.\n", MAX, MAX);
        return 1;
    }

    // Input Matrix B
    printf("Enter elements of Matrix B:\n");
    inputMatrix(rowsB, colsB, matrixB);

    do {
        //Print the menu options
        printf("\nMenu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        //Enter the choice
        printf("Enter your choice: ");
        scanf("%d", &choice);
        //Process the choice
        switch (choice) {
            case 1://Add Matrices 
                if (rowsA == rowsB && colsA == colsB) {
                    addMatrices(rowsA, colsA, matrixA, matrixB, result);
                    printf("Resultant Matrix after Addition:\n");
                    printMatrix(rowsA, colsA, result);
                } else {
                    printf("Matrix dimensions do not match for addition.\n");
                }
                break;
            case 2://Subtract Matrices
                if (rowsA == rowsB && colsA == colsB) {
                    subtractMatrices(rowsA, colsA, matrixA, matrixB, result);
                    printf("Resultant Matrix after Subtraction:\n");
                    printMatrix(rowsA, colsA, result);
                } else {
                    printf("Matrix dimensions do not match for subtraction.\n");
                }
                break;
            case 3://Transpose Matrix A
                transposeMatrix(rowsA, colsA, matrixA, result);
                printf("Transpose of Matrix A:\n");
                printMatrix(colsA, rowsA, result);
                break;
            case 4://Transpose Matrix B 
                transposeMatrix(rowsB, colsB, matrixB, result);
                printf("Transpose of Matrix B:\n");
                printMatrix(colsB, rowsB, result);
                break;
            case 5://Exit the program
                printf("Exiting ...\n");
                break;
            default://Handle invalid choices
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

//This function is used to input a matrix
void inputMatrix(int rows, int cols, int matrix[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

//This function is used to print a matrix
void printMatrix(int rows, int cols, int matrix[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

//This function is used to compute the addition of two matrices
void addMatrices(int rows, int cols, int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

//This function is used to compute the subtraction of two matrices
void subtractMatrices(int rows, int cols, int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

//This function is used to compute the transpose of a matrix
void transposeMatrix(int rows, int cols, int matrix[MAX][MAX], int result[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}
