#include <stdio.h>

// Function declarations
void getMatrix(int mat[10][10], int rows, int cols);
void displayMatrix(int mat[10][10], int rows, int cols);
void addMatrices(int mat1[10][10], int mat2[10][10], int result[10][10], int rows, int cols);
void subtractMatrices(int mat1[10][10], int mat2[10][10], int result[10][10], int rows, int cols);
void transposeMatrix(int mat[10][10], int transposed[10][10], int rows, int cols);

int main() {
    int r1, c1, r2, c2;
    int matrix1[10][10], matrix2[10][10], output[10][10];
    int option;

    // Input matrix dimensions
    printf("Enter rows and columns of Matrix A: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and columns of Matrix B: ");
    scanf("%d %d", &r2, &c2);

    // Dimension check
    if (r1 > 10 || c1 > 10 || r2 > 10 || c2 > 10 || r1 <= 0 || c1 <= 0 || r2 <= 0 || c2 <= 0) {
        printf("Matrix dimensions should be between 1 and 10.\n");
        return 1;
    }

    // Input matrix elements
    printf("Enter elements of Matrix A:\n");
    getMatrix(matrix1, r1, c1);
    printf("Enter elements of Matrix B:\n");
    getMatrix(matrix2, r2, c2);

    // Menu-driven program
    do {
        printf("\nOptions:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                if (r1 == r2 && c1 == c2) {
                    addMatrices(matrix1, matrix2, output, r1, c1);
                    printf("Sum of Matrices:\n");
                    displayMatrix(output, r1, c1);
                } else {
                    printf("Addition not possible. Matrices must have the same dimensions.\n");
                }
                break;
            case 2:
                if (r1 == r2 && c1 == c2) {
                    subtractMatrices(matrix1, matrix2, output, r1, c1);
                    printf("Difference of Matrices:\n");
                    displayMatrix(output, r1, c1);
                } else {
                    printf("Subtraction not possible. Matrices must have the same dimensions.\n");
                }
                break;
            case 3:
                transposeMatrix(matrix1, output, r1, c1);
                printf("Transpose of Matrix A:\n");
                displayMatrix(output, c1, r1);
                break;
            case 4:
                transposeMatrix(matrix2, output, r2, c2);
                printf("Transpose of Matrix B:\n");
                displayMatrix(output, c2, r2);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (option != 5);

    return 0;
}

// Function to input matrix elements
void getMatrix(int mat[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &mat[i][j]);
        }
    }
}

// Function to display a matrix
void displayMatrix(int mat[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrices(int mat1[10][10], int mat2[10][10], int result[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrices(int mat1[10][10], int mat2[10][10], int result[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

// Function to transpose a matrix
void transposeMatrix(int mat[10][10], int transposed[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = mat[i][j];
        }
    }
}
