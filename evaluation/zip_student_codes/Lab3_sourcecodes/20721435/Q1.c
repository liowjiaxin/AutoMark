#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void matrixInput(int *rowsA, int *columnsA, int *rowsB, int *columnsB, int matrixA[10][10], int matrixB[10][10]);
void menu(int *rowsA, int *columnsA, int *rowsB, int *columnsB, int matrixA[10][10], int matrixB[10][10]);
void selection(int choice, int *rowsA, int *columnsA, int *rowsB, int *columnsB, int matrixA[10][10], int matrixB[10][10]);
void addMatrices(int rowsA, int columnsA, int rowsB, int columnsB, int matrixA[10][10], int matrixB[10][10]);
void subtractMatrices(int rowsA, int columnsA, int rowsB, int columnsB, int matrixA[10][10], int matrixB[10][10]);
void transposeMatrixA(int rows, int columns, int matrix[10][10]);
void transposeMatrixB(int rows, int columns, int matrix[10][10]);
void exitProgram();

// Main function
int main() {
    // Variables to store dimensions of matrices
    int rowsA, columnsA, rowsB, columnsB;
    // Arrays to store matrices
    int matrixA[10][10], matrixB[10][10];
    
    matrixInput(&rowsA, &columnsA, &rowsB, &columnsB, matrixA, matrixB);
    while (1) {
        menu(&rowsA, &columnsA, &rowsB, &columnsB, matrixA, matrixB);
    }
    
    return 0;
}

// Function to input matrices
void matrixInput(int *rowsA, int *columnsA, int *rowsB, int *columnsB, int matrixA[10][10], int matrixB[10][10]) {
    while (1) {
        printf("Enter dimensions for Matrix A (rows and columns): ");
        // Read and validate input
        if (scanf("%d %d", rowsA, columnsA) != 2) {
            printf("Invalid input. Please enter two integers.\n");
            while (getchar() != '\n');
            continue;
        }
        // If dimensions are valid
        if (*rowsA > 0 && *rowsA <= 10 && *columnsA > 0 && *columnsA <= 10) {
            printf("Enter elements for Matrix A:\n");
            for (int i = 0; i < *rowsA; i++) {
                for (int j = 0; j < *columnsA; j++) {
                    printf("Element [%d][%d]: ", i + 1, j + 1);
                    // Read and validate input
                    if (scanf("%d", &matrixA[i][j]) != 1) {
                        printf("Invalid input. Please enter an integer.\n");
                        while (getchar() != '\n');
                        j--;
                        continue;
                    }
                }
            }
            break;

        // If dimensions are invalid
        } else {
            printf("Invalid dimensions for Matrix A. Rows and columns must be > 0 and <= 10.\n");
            continue;
        }
    }

    while (1) {
        printf("Enter dimensions for Matrix B (rows and columns): ");
        // Read and validate input
        if (scanf("%d %d", rowsB, columnsB) != 2) {
            printf("Invalid input. Please enter two integers.\n");
            while (getchar() != '\n');
            continue;
        }
        // If dimensions are valid
        if (*rowsB > 0 && *rowsB <= 10 && *columnsB > 0 && *columnsB <= 10) {
            printf("Enter elements for Matrix B:\n");
            for (int i = 0; i < *rowsB; i++) {
                for (int j = 0; j < *columnsB; j++) {
                    printf("Element [%d][%d]: ", i + 1, j + 1);
                    // Read and validate input
                    if (scanf("%d", &matrixB[i][j]) != 1) {
                        printf("Invalid input. Please enter an integer.\n");
                        while (getchar() != '\n');
                        j--;
                        continue;
                    }
                }
            }
            break;
        // If dimensions are invalid
        } else {
            printf("Invalid dimensions for Matrix A. Rows and columns must be > 0 and <= 10.\n");
            continue;
        }
    }
}

// Function to display menu
void menu(int *rowsA, int *columnsA, int *rowsB, int *columnsB, int matrixA[10][10], int matrixB[10][10]) {
    printf("Matrix Operations Menu:\n");
    printf("1. Add Matrices\n");
    printf("2. Subtract Matrices\n");
    printf("3. Transpose Matrix A\n");
    printf("4. Transpose Matrix B\n");
    printf("5. Exit\n");
    printf("Enter your choice: \n");
    int choice;
    // Read and validate input
    if (scanf("%d", &choice) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        while (getchar() != '\n');
        return;
    }
    selection(choice, rowsA, columnsA, rowsB, columnsB, matrixA, matrixB);
}

// Function to select operation
void selection(int choice, int *rowsA, int *columnsA, int *rowsB, int *columnsB, int matrixA[10][10], int matrixB[10][10]) {
    switch (choice) {
        case 1:
            addMatrices(*rowsA, *columnsA, *rowsB, *columnsB, matrixA, matrixB);
            break;
        case 2:
            subtractMatrices(*rowsA, *columnsA, *rowsB, *columnsB, matrixA, matrixB);
            break;
        case 3:
            transposeMatrixA(*rowsA, *columnsA, matrixA);
            break;
        case 4:
            transposeMatrixB(*rowsB, *columnsB, matrixB);
            break;
        case 5:
            exitProgram();
            exit(0);
            break;
        default:
            printf("Invalid choice. Please enter a number between 1 and 5.\n");
            break;
    }
}

// Function to add matrices
void addMatrices(int rowsA, int columnsA, int rowsB, int columnsB, int matrixA[10][10], int matrixB[10][10]) {
    // Check if both matrices have the same dimensions
    if (rowsA != rowsB || columnsA != columnsB) {
        printf("Cannot add matrices. Dimensions of Matrix A and Matrix B are not the same.\n");
    } else {
        int result[10][10];
        for (int i = 0; i < rowsA; i++) {
            for (int j = 0; j < columnsA; j++) {
                result[i][j] = matrixA[i][j] + matrixB[i][j];
            }
        }
        printf("Result of Matrix A + Matrix B:\n");
        for (int i = 0; i < rowsA; i++) {
            for (int j = 0; j < columnsA; j++) {
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

// Function to subtract matrices
void subtractMatrices(int rowsA, int columnsA, int rowsB, int columnsB, int matrixA[10][10], int matrixB[10][10]) {
    // Check if both matrices have the same dimensions
    if (rowsA != rowsB || columnsA != columnsB) {
        printf("Cannot subtract matrices. Dimensions of Matrix A and Matrix B are not the same.\n");
    } else {
        int result[10][10];
        for (int i = 0; i < rowsA; i++) {
            for (int j = 0; j < columnsA; j++) {
                result[i][j] = matrixA[i][j] - matrixB[i][j];
            }
        }
        printf("Result of Matrix A - Matrix B:\n");
        for (int i = 0; i < rowsA; i++) {
            for (int j = 0; j < columnsA; j++) {
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

// Function to transpose Matrix A
void transposeMatrixA(int rows, int columns, int matrixA[10][10]) {
    int result[10][10];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result[j][i] = matrixA[i][j];
        }
    }
    printf("Transposed of Matrix A:\n");
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to transpose Matrix B
void transposeMatrixB(int rows, int columns, int matrixB[10][10]) {
    int result[10][10];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result[j][i] = matrixB[i][j];
        }
    }
    printf("Transposed of Matrix B:\n");
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to exit the program
void exitProgram() {
    printf("Exiting...\n");
}