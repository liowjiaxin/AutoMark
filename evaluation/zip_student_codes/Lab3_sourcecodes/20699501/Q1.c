#include <stdio.h>

// Matrix declarations
int MatrixA[10][10];
int MatrixB[10][10];
int transpose[10][10];  // For transpose operations
int sum[10][10];
int difference[10][10];
int rows1, columns1, rows2, columns2;

// Add Matrices
int AddMatrices() {
    if (rows1 != rows2 || columns1 != columns2) {
        printf("Matrix dimensions do not match for addition!\n");
        return -1;
    }

    for (int i = 0; i < rows1; i++)
        for (int j = 0; j < columns1; j++) {
            sum[i][j] = MatrixA[i][j] + MatrixB[i][j];
        }

    printf("\nResult of Matrix A + Matrix B:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns1; j++) {
            printf("%d   ", sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// Subtract Matrices
int SubtractMatrices() {
    if (rows1 != rows2 || columns1 != columns2) {
        printf("Matrix dimensions do not match for subtraction!\n");
        return -1;
    }

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns1; j++) {
            difference[i][j] = MatrixA[i][j] - MatrixB[i][j];
        }
    }

    printf("\nResult of Matrix A - Matrix B:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns1; j++) {
            printf("%d   ", difference[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// Transpose Matrix A
int TransposeMatrixA() {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns1; j++) {
            transpose[j][i] = MatrixA[i][j];
        }
    }

    printf("Transpose of Matrix A:\n");
    for (int i = 0; i < columns1; i++) {
        for (int j = 0; j < rows1; j++) {
            printf("%d   ", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// Transpose Matrix B
int TransposeMatrixB() {
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < columns2; j++) {
            transpose[j][i] = MatrixB[i][j];
        }
    }

    printf("Transpose of Matrix B:\n");
    for (int i = 0; i < columns2; i++) {
        for (int j = 0; j < rows2; j++) {
            printf("%d   ", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// Main Function
int main() {
    int choice;
    printf("\nEnter dimensions for Matrix A (rows and columns): ");
    scanf("%d %d", &rows1, &columns1);

    printf("Enter elements of Matrix A:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns1; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &MatrixA[i][j]);
        }
    }

    printf("\nEnter dimensions for Matrix B (rows and columns): ");
    scanf("%d %d", &rows2, &columns2);

    printf("Enter elements of Matrix B:\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < columns2; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &MatrixB[i][j]);
        }
    }
        
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
                AddMatrices();
                break;
            case 2:
                SubtractMatrices();
                break;
            case 3:
                TransposeMatrixA();
                break;
            case 4:
                TransposeMatrixB();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}
