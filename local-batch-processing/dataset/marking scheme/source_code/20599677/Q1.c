#include <stdio.h>

#define MAX_SIZE 10

//function to add matrices
void add_Matrices(int rows, int cols, int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE]) {
    int result[MAX_SIZE][MAX_SIZE];

    printf("Result of Matrix A + Matrix B:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

//function to subtract matrices
void subtract_Matrices(int rows, int cols, int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE]) {
    int result[MAX_SIZE][MAX_SIZE];

    printf("Result of Matrix A - Matrix B:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] - B[i][j];
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

//function to transpose a matrix
void transpose_Matrices(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE], char matrixName) {
    printf("Transpose of Matrix %c:\n", matrixName);
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d ", matrix[j][i]);
        }
        printf("\n");
    }
}

int main() {
    int rows_A, cols_A, rows_B, cols_B;
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE];

    //prompt user to input dimensions for matrix a
    printf("Enter dimensions for Matrix A (rows and columns): ");
    scanf("%d %d", &rows_A, &cols_A);

    //prompt user to input elements of matrix a
    printf("Enter elements for Matrix A:\n");
    for (int i = 0; i < rows_A; i++) {
        for (int j = 0; j < cols_A; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &A[i][j]);
        }
    }

    //prompt user to input dimensions for matrix b
    printf("Enter dimensions for Matrix B (rows and columns): ");
    scanf("%d %d", &rows_B, &cols_B);

    //prompt user to input elements of matrix b
    printf("Enter elements for Matrix B:\n");
    for (int i = 0; i < rows_B; i++) {
        for (int j = 0; j < cols_B; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &B[i][j]);
        }
    }

    while (1) {
        int choice;

        printf("\nMatrix Operations Menu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");

        //prompt user to input a choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (rows_A == rows_B && cols_A == cols_B) {
                    add_Matrices(rows_A, cols_A, A, B);
                } else {
                    printf("Error: Please make sure the matrices dimensions are the same.\n");
                }
                break;

            case 2:
                if (rows_A == rows_B && cols_A == cols_B) {
                    subtract_Matrices(rows_A, cols_A, A, B);
                } else {
                    printf("Error: Please make sure the matrices dimensions are the same.\n");
                }
                break;

            case 3:
                transpose_Matrices(rows_A, cols_A, A, 'A');
                break;

            case 4:
                transpose_Matrices(rows_B, cols_B, B, 'B');
                break;

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Error: Please enter a number between 1 and 5.\n");
        }
    }

    return 0;
}
