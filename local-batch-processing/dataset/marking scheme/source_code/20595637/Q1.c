#include <stdio.h>

#define MAX_SIZE 10

// Function prototypes for matrix operations
void getInputMatrix(int rowCount, int colCount, int matrix[MAX_SIZE][MAX_SIZE]);
void showMatrix(int rowCount, int colCount, int matrix[MAX_SIZE][MAX_SIZE]);
void addTwoMatrices(int rowCount, int colCount, int firstMatrix[MAX_SIZE][MAX_SIZE], int secondMatrix[MAX_SIZE][MAX_SIZE], int sumMatrix[MAX_SIZE][MAX_SIZE]);
void subtractTwoMatrices(int rowCount, int colCount, int firstMatrix[MAX_SIZE][MAX_SIZE], int secondMatrix[MAX_SIZE][MAX_SIZE], int diffMatrix[MAX_SIZE][MAX_SIZE]);
void transposeOfMatrix(int rowCount, int colCount, int matrix[MAX_SIZE][MAX_SIZE], int transposedMatrix[MAX_SIZE][MAX_SIZE]);

// Function for obtaining user-provided matrix values
void getInputMatrix(int rowCount, int colCount, int matrix[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            printf("Please enter the value for position [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

//  Function to print the matrix elements to the console for display

void showMatrix(int rowCount, int colCount, int matrix[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to output the matrix content to the screen
void addTwoMatrices(int rowCount, int colCount, int firstMatrix[MAX_SIZE][MAX_SIZE], int secondMatrix[MAX_SIZE][MAX_SIZE], int sumMatrix[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            sumMatrix[i][j] = firstMatrix[i][j] + secondMatrix[i][j];
        }
    }
}

// Function to compute the result of subtracting one matrix from another
void subtractTwoMatrices(int rowCount, int colCount, int firstMatrix[MAX_SIZE][MAX_SIZE], int secondMatrix[MAX_SIZE][MAX_SIZE], int diffMatrix[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            diffMatrix[i][j] = firstMatrix[i][j] - secondMatrix[i][j];
        }
    }
}

// Function to find the transpose of a given matrix
void transposeOfMatrix(int rowCount, int colCount, int matrix[MAX_SIZE][MAX_SIZE], int transposedMatrix[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            transposedMatrix[j][i] = matrix[i][j];  // Switch rows and columns
        }
    }
}

int main() {
    int rowsFirstMatrix, colsFirstMatrix, rowsSecondMatrix, colsSecondMatrix;
    int firstMatrix[MAX_SIZE][MAX_SIZE], secondMatrix[MAX_SIZE][MAX_SIZE]; // Matrices for storing values
    int resultMatrix[MAX_SIZE][MAX_SIZE]; // Matrix to store the result of operations
    int userChoice;

    // Asking the user to enter the dimensions for the first matrix
    printf("Enter the dimensions for Matrix 1 (rows and columns): ");
    scanf("%d %d", &rowsFirstMatrix, &colsFirstMatrix);
    if (rowsFirstMatrix <= 0 || rowsFirstMatrix > MAX_SIZE || colsFirstMatrix <= 0 || colsFirstMatrix > MAX_SIZE) {
        printf("The dimensions you entered for Matrix 1 are invalid.\n");
        return 1;
    }
    printf("Enter values for Matrix 1:\n");
    getInputMatrix(rowsFirstMatrix, colsFirstMatrix, firstMatrix);

    // Requesting input for the second matrix dimensions
    printf("Enter the dimensions for Matrix 2 (rows and columns): ");
    scanf("%d %d", &rowsSecondMatrix, &colsSecondMatrix);
    if (rowsSecondMatrix <= 0 || rowsSecondMatrix > MAX_SIZE || colsSecondMatrix <= 0 || colsSecondMatrix > MAX_SIZE) {
        printf("The dimensions you entered for Matrix 2 are invalid.\n");
        return 1;
    }
    printf("Enter values for Matrix 2:\n");
    getInputMatrix(rowsSecondMatrix, colsSecondMatrix, secondMatrix);

    // Providing the user with a menu of matrix operations
    do {
        printf("\nSelect a matrix operation:\n");
        printf("1. Add the matrices\n");
        printf("2. Subtract the matrices\n");
        printf("3. Transpose Matrix 1\n");
        printf("4. Transpose Matrix 2\n");
        printf("5. Exit\n");
        printf("Your choice: ");
        scanf("%d", &userChoice);

        switch (userChoice) {
            case 1:
                // If the matrices have the same dimensions, perform addition
                if (rowsFirstMatrix == rowsSecondMatrix && colsFirstMatrix == colsSecondMatrix) {
                    addTwoMatrices(rowsFirstMatrix, colsFirstMatrix, firstMatrix, secondMatrix, resultMatrix);
                    printf("Sum of Matrix 1 and Matrix 2:\n");
                    showMatrix(rowsFirstMatrix, colsFirstMatrix, resultMatrix);
                } else {
                    printf("Addition not possible: Matrices have different sizes.\n");
                }
                break;
            case 2:
                // If the matrices have the same dimensions, perform subtraction
                if (rowsFirstMatrix == rowsSecondMatrix && colsFirstMatrix == colsSecondMatrix) {
                    subtractTwoMatrices(rowsFirstMatrix, colsFirstMatrix, firstMatrix, secondMatrix, resultMatrix);
                    printf("Difference between Matrix 1 and Matrix 2:\n");
                    showMatrix(rowsFirstMatrix, colsFirstMatrix, resultMatrix);
                } else {
                    printf("Subtraction not possible: Matrices have different sizes.\n");
                }
                break;
            case 3:
                // Compute and show the transpose of the first matrix
                transposeOfMatrix(rowsFirstMatrix, colsFirstMatrix, firstMatrix, resultMatrix);
                printf("Transpose of Matrix 1:\n");
                showMatrix(colsFirstMatrix, rowsFirstMatrix, resultMatrix);
                break;
            case 4:
                // Compute and show the transpose of the second matrix
                transposeOfMatrix(rowsSecondMatrix, colsSecondMatrix, secondMatrix, resultMatrix);
                printf("Transpose of Matrix 2:\n");
                showMatrix(colsSecondMatrix, rowsSecondMatrix, resultMatrix);
                break;
            case 5:
                // Exit the program
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option, please choose again.\n");
        }
    } while (userChoice != 5);

    return 0;
}
