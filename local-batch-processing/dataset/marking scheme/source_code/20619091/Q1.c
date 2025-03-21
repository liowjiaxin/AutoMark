#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // Max size for matrices (10x10)

// Function to let the user fill in a matrix
void userMatrixInput(int rows, int columns, int matrice[MAX][MAX], char name) {
    printf("Fill in the MAtrix PLease %c (%dx%d):\n", name, rows, columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("Enter value for [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrice[i][j]);
        }
    }
}

// Function to print out a matrix
void displayMatrix(int rows, int columns, int matrice[MAX][MAX]) {
    printf("Here is the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", matrice[i][j]); // Print each value
        }
        printf("\n"); // Move to the next row
    }
}

// Function to add two matrices
void additionOfMatrices(int rows, int columns, int MatrixA[MAX][MAX], int MatrixB[MAX][MAX], int result[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result[i][j] = MatrixA[i][j] + MatrixB[i][j]; // Add corresponding values
        }
    }
}

// Function to subtract Matrix B from Matrix A
void minusOfMatrices(int rows, int columns, int MatrixA[MAX][MAX], int MatrixB[MAX][MAX], int result[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result[i][j] = MatrixA[i][j] - MatrixB[i][j]; // Subtract corresponding values
        }
    }
}

// Function to calculate the transpose of a matrix
void transposeMatrix(int rows, int columns, int matrix[MAX][MAX], int transpose[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            transpose[j][i] = matrix[i][j]; // Flip rows and columns
        }
    }
}

int main() {
    int MatrixA[MAX][MAX], MatrixB[MAX][MAX], result[MAX][MAX]; // The two input matrices and the result matrix
    int row1, column1, row2, column2; // Sizes for both matrices
    int choice; // What the user wants to do

    // Ask the user for the size of Matrix A
    printf("Enter the number of rows for Matrix A: ");
    scanf("%d", &row1);
    printf("Enter the number of columns for Matrix A: ");
    scanf("%d", &column1);

    // Ask the user for the size of Matrix B
    printf("Enter the number of rows for Matrix B: ");
    scanf("%d", &row2);
    printf("Enter the number of columns for Matrix B: ");
    scanf("%d", &column2);

    // Make sure the sizes are valid (not too big or small)
    if (row1 <= 0 || row1 > MAX || column1 <= 0 || column1 > MAX ||
        row2 <= 0 || row2 > MAX || column2 <= 0 || column2 > MAX) {
        printf("Oops! Matrix size must be between 1 and %d.\n", MAX);
        return 1; // Stop the program if sizes are invalid
    }

    // Get the values for both matrices
    userMatrixInput(row1, column1, MatrixA, 'A');
    userMatrixInput(row2, column2, MatrixB, 'B');

    // Show the menu
    do {
        printf("\nWhat do you want to do?\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add matrices
                if (row1 == row2 && column1 == column2) {
                    additionOfMatrices(row1, column1, MatrixA, MatrixB, result);
                    printf("Result of Addition:\n");
                    displayMatrix(row1, column1, result);
                } else {
                    printf("Can't add matrices with different sizes.\n");
                }
                break;

            case 2: // Subtract matrices
                if (row1 == row2 && column1 == column2) {
                    minusOfMatrices(row1, column1, MatrixA, MatrixB, result);
                    printf("Result of Subtraction:\n");
                    displayMatrix(row1, column1, result);
                } else {
                    printf("Can't subtract matrices with different sizes.\n");
                }
                break;

            case 3: // Transpose Matrix A
                transposeMatrix(row1, column1, MatrixA, result);
                printf("Transpose of Matrix A:\n");
                displayMatrix(column1, row1, result);
                break;

            case 4: // Transpose Matrix B
                transposeMatrix(row2, column2, MatrixB, result);
                printf("Transpose of Matrix B:\n");
                displayMatrix(column2, row2, result);
                break;

            case 5: // Exit the program
                printf("Thanks for using the program! Bye!!\n");
                break;

            default: // If the user enters something invalid
                printf("Invalid choice! Please pick a valid option.\n");
        }
    } while (choice != 5); // Keep showing the menu until the user wants to exit

    return 0; // End the program
}
