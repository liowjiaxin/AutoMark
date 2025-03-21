#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

//  functions for working with matrices
void inputMatrix(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE], char name); //get user input
void displayMatrix(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE]); //print
void addMatrices(int rows, int cols, int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]); //add
void subtractMatrices(int rows, int cols, int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]); //subtract
void transposeMatrix(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]); //transpose

int main() { 
    // Initialize variables
    int rowsA, colsA, rowsB, colsB;
    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];
    int choice;

    // Get dimensions for Matrix A
    printf("Matrix A dimensions (rows cols): ");
    scanf("%d %d", &rowsA, &colsA);
    if (rowsA > MAX_SIZE || colsA > MAX_SIZE) {
        printf("Max size is %dx%d.\n", MAX_SIZE, MAX_SIZE);
        return 1;
    }

    inputMatrix(rowsA, colsA, matrixA, 'A');

    // Get dimensions for Matrix B
    printf("Matrix B dimensions (rows cols): ");
    scanf("%d %d", &rowsB, &colsB);
    if (rowsB > MAX_SIZE || colsB > MAX_SIZE) {
        printf("Max size is %dx%d.\n", MAX_SIZE, MAX_SIZE);
        return 1;
    }

    inputMatrix(rowsB, colsB, matrixB, 'B');

    // Keep asking user what they want to do
    do {
        printf("\nMatrix operations menu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: //if choice is 1
                if (rowsA == rowsB && colsA == colsB) { //check if rows and cols are the same
                    addMatrices(rowsA, colsA, matrixA, matrixB, result);
                    printf("Sum is:\n");
                    displayMatrix(rowsA, colsA, result);
                } else { //if rows and cols are not the same
                    printf("Addition needs matrices of the same size.\n"); 
                }
                break;

            case 2: //if choice is 2
                if (rowsA == rowsB && colsA == colsB) { //check if rows and cols are the same
                    subtractMatrices(rowsA, colsA, matrixA, matrixB, result);
                    printf("Difference is:\n");
                    displayMatrix(rowsA, colsA, result);
                } else { //if rows and cols are not the same
                    printf("Subtraction needs matrices of the same size.\n");
                }
                break;

            case 3: //if choice is 3
                transposeMatrix(rowsA, colsA, matrixA, result);
                printf("Matrix A Transposed:\n");
                displayMatrix(colsA, rowsA, result);
                break;

            case 4: //if choice is 4
                transposeMatrix(rowsB, colsB, matrixB, result);
                printf("Matrix B Transposed:\n");
                displayMatrix(colsB, rowsB, result);
                break;

            case 5: //if choice is 5
                printf("Bye!\n");
                break;

            default:
                printf("Not a valid choice. Try again.\n");
        }

    } while (choice != 5);

    return 0;
}

// Get user input for a matrix
void inputMatrix(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE], char name) {
    printf("Fill in Matrix %c:\n", name); 
    for (int i = 0; i < rows; i++) { //loop to get number of rows
        for (int j = 0; j < cols; j++) { //nested loop to get number of columns
            printf("%c[%d][%d]: ", name, i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Add two matrices
void addMatrices(int rows, int cols, int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) { //get each element
            result[i][j] = matrixA[i][j] + matrixB[i][j]; //matrices are added by adding corresponding elements
        }
    }
}

// Subtract two matrices
void subtractMatrices(int rows, int cols, int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) { //get each element
            result[i][j] = matrixA[i][j] - matrixB[i][j]; //matrices are subtracted by subtracting corresponding elements
        }
    }
}

// Transpose a matrix
void transposeMatrix(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]) { //to transpose a matrix is to switch rows and columns
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) { //get each element
            result[j][i] = matrix[i][j]; //switch rows and columns
        }
    }
}
