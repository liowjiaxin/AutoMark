#include <stdio.h>

#define MAXIMUM 10

void inputMatrix(int matrix[MAXIMUM][MAXIMUM], int rows, int columns, char name) {
    // Obtain user input for each Matrix
    printf("Enter elements for Matrix %c:\n", name);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void addMatrices(int A[MAXIMUM][MAXIMUM], int B[MAXIMUM][MAXIMUM], int rows, int columns) {
    // Addition of matrices
    int result[MAXIMUM][MAXIMUM];
    printf("Sum of Matrix A + Matrix B:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result[i][j] = A[i][j] + B[i][j];
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

void subtractMatrices(int A[MAXIMUM][MAXIMUM], int B[MAXIMUM][MAXIMUM], int rows, int columns) {
    // Subtraction of matrices
    int result[MAXIMUM][MAXIMUM];
    printf("Result of Matrix A - Matrix B:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result[i][j] = A[i][j] - B[i][j];
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

void transposeMatrix(int matrix[MAXIMUM][MAXIMUM], int rows, int columns) {
    // Transpose of a matrix
    int result[MAXIMUM][MAXIMUM];
    printf("Transpose of the Matrix:\n");
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            result[i][j] = matrix[j][i];
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[MAXIMUM][MAXIMUM], B[MAXIMUM][MAXIMUM];
    int Arows, Acolumns, Brows, Bcolumns;
    int choice;

    // Input dimensions for Matrix A
    printf("Enter dimensions for Matrix A (rows and columns): ");
    scanf("%d%d", &Arows, &Acolumns);
    if (Arows > MAXIMUM || Acolumns > MAXIMUM || Arows <= 0 || Acolumns <= 0) {
        printf("Invalid dimensions. Please enter values between 1 and %d.\n", MAXIMUM);
        return 1;
    }
    
    // Input elements for Matrix A
    inputMatrix(A, Arows, Acolumns, 'A');

    // Input dimensions for Matrix B
    printf("Enter dimensions for Matrix B (rows and columns): ");
    scanf("%d%d", &Brows, &Bcolumns);
    if (Brows > MAXIMUM || Bcolumns > MAXIMUM || Brows <= 0 || Bcolumns <= 0) {
        printf("Invalid dimensions. Please enter values between 1 and %d.\n", MAXIMUM);
        return 1;
    }

    // Input elements for Matrix B
    inputMatrix(B, Brows, Bcolumns, 'B');

    while (1) {
        // Display menu
        printf("\nMatrix Operations Menu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Use switch case to determine what function to use
        switch (choice) {
            case 1:
                if (Arows == Brows && Acolumns == Bcolumns) {
                    addMatrices(A, B, Arows, Acolumns);
                } else {
                    printf("Matrices must have the same dimensions to be added.\n");
                }
                break;
            case 2:
                if (Arows == Brows && Acolumns == Bcolumns) {
                    subtractMatrices(A, B, Arows, Acolumns);
                } else {
                    printf("Matrices must have the same dimensions to be subtracted.\n");
                }
                break;
            case 3:
                transposeMatrix(A, Arows, Acolumns);
                break;
            case 4:
                transposeMatrix(B, Brows, Bcolumns);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

