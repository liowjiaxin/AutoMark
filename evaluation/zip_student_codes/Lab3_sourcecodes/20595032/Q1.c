#include <stdio.h>

// Define maximum size of the matrix (10x10)
#define MAX 10

void input(int matrix[MAX][MAX], int rows, int cols);
void print(int matrix[MAX][MAX], int rows, int cols);
void add(int a[MAX][MAX], int b[MAX][MAX], int rows, int cols);
void sub(int a[MAX][MAX], int b[MAX][MAX], int rows, int cols);
void transpose(int matrix[MAX][MAX], int rows, int cols);

int main() {
    int rowA, rowB;
    int colsA, colsB;
    int matrixA[MAX][MAX], matrixB[MAX][MAX];
    int prompt;

    // Prompt user to enter the dimensions of matrix A and B

    printf("Please enter the dimensions of matrix A (rows cols): ");
    scanf("%d %d", &rowA, &colsA);

    //ensure it is within a 10x10
    if (rowA > MAX || colsA > MAX || rowA <= 0 || colsA <= 0) {
        printf("Dimensions must be between 1 and 10.(Digits only)\n");
        return 1;
    }

    printf("Please enter the dimensions of matrix B (rows cols): ");
    scanf("%d %d", &rowB, &colsB);

    if (rowB > MAX || colsB > MAX || rowB <= 0 || colsB <= 0) {
        printf("Dimensions must be between 1 and 10.(Digits only)\n");
        return 1;
    }
    
    // Prompt users to enter the elements for matrix A and B 

    printf("\nEnter elements for Matrix A:\n");
    input(matrixA, rowA, colsA);

    printf("\nEnter elements for Matrix B:\n");
    input(matrixB, rowB, colsB);

    do {
        printf("\nMatrix Operations Menu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &prompt);

        // Set case 1-5, loop it for ease of use

        switch (prompt) {
            case 1:
                if (rowA == rowB && colsA == colsB) {
                    add(matrixA, matrixB, rowA, colsA);
                } else {
                    printf("Matrices require the same rows and columns for addition.\n");
                }
                break;
            case 2:
                if (rowA == rowB && colsA == colsB) {
                    sub(matrixA, matrixB, rowA, colsA);
                } else {
                    printf("Matrices require the same rows and columns for subtraction.\n");
                }
                break;
            case 3:
                transpose(matrixA, rowA, colsA);
                break;
            case 4:
                transpose(matrixB, rowB, colsB);
                break;
            case 5:
                printf("\nExiting...\n");
                break;
            default:
                printf("Invalid choice! Please select between 1-5.\n");
        }
    } while (prompt != 5);

    return 0;
}

void input(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void print(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void add(int a[MAX][MAX], int b[MAX][MAX], int rows, int cols) {
    int result[MAX][MAX];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
    printf("\nResult of Addition:\n");
    print(result, rows, cols);
}

void sub(int a[MAX][MAX], int b[MAX][MAX], int rows, int cols) {
    int result[MAX][MAX];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
    printf("\nResult of Subtraction:\n");
    print(result, rows, cols);
}

void transpose(int matrix[MAX][MAX], int rows, int cols) {
    int transposed[MAX][MAX];
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            transposed[i][j] = matrix[j][i];
        }
    }
    printf("\nResult of Transposition:\n");
    print(transposed, cols, rows);
}