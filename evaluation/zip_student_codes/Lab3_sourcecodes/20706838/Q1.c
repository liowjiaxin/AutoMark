#include <stdio.h>

#define max 10 // Maximum size for the matrices which can be inserted

// Function to input elements into a matrix
void inputMatrix(int rows, int cols, int matrix[max][max]) {
    printf("Enter elements of the matrix (%d %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display a matrix
void displayMatrix(int rows, int cols, int matrix[max][max]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add the two matrices
void addMatrices(int rows, int cols, int a[max][max], int b[max][max], int result[max][max]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrices(int rows, int cols, int a[max][max], int b[max][max], int result[max][max]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

// Function to transpose a matrix
void transposeMatrix(int rows, int cols, int matrix[max][max], int transposed[max][max]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int a[max][max], b[max][max], result[max][max];
    int transposed[max][max];
    int rowsA, colsA, rowsB, colsB, choice;

    // For the inputs of the dimensions of the  matrix 
    printf("Enter dimensions of Matrix A (rows cols): ");
    scanf("%d %d", &rowsA, &colsA);
    printf("Enter dimensions of Matrix B (rows cols): ");
    scanf("%d %d", &rowsB, &colsB);

    // Check for validity of the  dimensions
    if (rowsA > max || colsA > max || rowsB > max || colsB > max || rowsA != rowsB || colsA != colsB) {
        printf("Invalid dimensions.\n");
        return 1;
    }

    // Input the elements of the matrix
    printf("Matrix A:\n");
    inputMatrix(rowsA, colsA, a);
    printf("Matrix B:\n");
    inputMatrix(rowsB, colsB, b);

    // Menu for the operations to be carried
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
                // Perform addition of matricess
                addMatrices(rowsA, colsA, a, b, result);
                printf("Result of Addition:\n");
                displayMatrix(rowsA, colsA, result);
                break;
            case 2:
                // Perform subtraction of the matrices
                subtractMatrices(rowsA, colsA, a, b, result);
                printf("Result of Subtraction:\n");
                displayMatrix(rowsA, colsA, result);
                break;
            case 3:
                // Transpose of Matrix A
                transposeMatrix(rowsA, colsA, a, transposed);
                printf("Transpose of Matrix A:\n");
                displayMatrix(colsA, rowsA, transposed);
                break;
            case 4:
                // Transpose of Matrix B
                transposeMatrix(rowsB, colsB, b, transposed);
                printf("Transpose of Matrix B:\n");
                displayMatrix(colsB, rowsB, transposed);
                break;
            case 5:
                // Exit
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
