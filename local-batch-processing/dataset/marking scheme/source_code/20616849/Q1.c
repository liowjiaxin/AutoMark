#include <stdio.h>

#define MAX_DIM 10

// Function prototypes
void inputMatrix(int rows, int cols, int matrix[MAX_DIM][MAX_DIM]);
void displayMatrix(int rows, int cols, int matrix[MAX_DIM][MAX_DIM]);
void addMatrices(int rows, int cols, int mat1[MAX_DIM][MAX_DIM], int mat2[MAX_DIM][MAX_DIM], int result[MAX_DIM][MAX_DIM]);
void subtractMatrices(int rows, int cols, int mat1[MAX_DIM][MAX_DIM], int mat2[MAX_DIM][MAX_DIM], int result[MAX_DIM][MAX_DIM]);
void transposeMatrix(int rows, int cols, int matrix[MAX_DIM][MAX_DIM], int transposed[MAX_DIM][MAX_DIM]);

void inputMatrix(int rows, int cols, int matrix[MAX_DIM][MAX_DIM]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int rows, int cols, int matrix[MAX_DIM][MAX_DIM]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int rows, int cols, int mat1[MAX_DIM][MAX_DIM], int mat2[MAX_DIM][MAX_DIM], int result[MAX_DIM][MAX_DIM]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void subtractMatrices(int rows, int cols, int mat1[MAX_DIM][MAX_DIM], int mat2[MAX_DIM][MAX_DIM], int result[MAX_DIM][MAX_DIM]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void transposeMatrix(int rows, int cols, int matrix[MAX_DIM][MAX_DIM], int transposed[MAX_DIM][MAX_DIM]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int rowsMat1, colsMat1, rowsMat2, colsMat2;
    int mat1[MAX_DIM][MAX_DIM], mat2[MAX_DIM][MAX_DIM];
    int resultMatrix[MAX_DIM][MAX_DIM];
    int menuChoice;

    // Input dimensions and elements for Matrix 1
    printf("Enter dimensions for Matrix A (rows and columns): ");
    scanf("%d %d", &rowsMat1, &colsMat1);
    if (rowsMat1 <= 0 || rowsMat1 > MAX_DIM || colsMat1 <= 0 || colsMat1 > MAX_DIM) {
        printf("Invalid dimensions for Matrix A.\n");
        return 1;
    }
    printf("Enter elements for Matrix A:\n");
    inputMatrix(rowsMat1, colsMat1, mat1);

    // Input dimensions and elements for Matrix 2
    printf("Enter dimensions for Matrix B (rows and columns): ");
    scanf("%d %d", &rowsMat2, &colsMat2);
    if (rowsMat2 <= 0 || rowsMat2 > MAX_DIM || colsMat2 <= 0 || colsMat2 > MAX_DIM) {
        printf("Invalid dimensions for Matrix B.\n");
        return 1;
    }
    printf("Enter elements for Matrix B:\n");
    inputMatrix(rowsMat2, colsMat2, mat2);

    do {
        // Display menu
        printf("\nMatrix Operations Menu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &menuChoice);

        switch (menuChoice) {
            case 1:
                if (rowsMat1 == rowsMat2 && colsMat1 == colsMat2) {
                    addMatrices(rowsMat1, colsMat1, mat1, mat2, resultMatrix);
                    printf("Result of Matrix A + Matrix B:\n");
                    displayMatrix(rowsMat1, colsMat1, resultMatrix);
                } else {
                    printf("Matrices cannot be added due to incompatible dimensions.\n");
                }
                break;
            case 2:
                if (rowsMat1 == rowsMat2 && colsMat1 == colsMat2) {
                    subtractMatrices(rowsMat1, colsMat1, mat1, mat2, resultMatrix);
                    printf("Result of Matrix A - Matrix B:\n");
                    displayMatrix(rowsMat1, colsMat1, resultMatrix);
                } else {
                    printf("Matrices cannot be subtracted due to incompatible dimensions.\n");
                }
                break;
            case 3:
                transposeMatrix(rowsMat1, colsMat1, mat1, resultMatrix);
                printf("Transpose of Matrix A:\n");
                displayMatrix(colsMat1, rowsMat1, resultMatrix);
                break;
            case 4:
                transposeMatrix(rowsMat2, colsMat2, mat2, resultMatrix);
                printf("Transpose of Matrix B:\n");
                displayMatrix(colsMat2, rowsMat2, resultMatrix);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (menuChoice != 5);

    return 0;
}