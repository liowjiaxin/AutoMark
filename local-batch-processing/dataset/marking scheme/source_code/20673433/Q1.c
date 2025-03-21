#include <stdio.h>

// Function to add two matrices
void addMatrices(int m1[10][10], int m2[10][10], int result[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrices(int m1[10][10], int m2[10][10], int result[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = m1[i][j] - m2[i][j];
        }
    }
}

// Function to transpose a matrix
void transposeMatrix(int matrix[10][10], int transposed[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m1[10][10], m2[10][10], result[10][10], transposed[10][10];
    int rows, cols, choice;

    printf("Enter the number of rows of the matrices: ");
    scanf("%d", &rows);
    printf("Enter the number of columns of the matrices: ");
    scanf("%d", &cols);

    printf("Enter the elements of the first matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &m1[i][j]);
        }
    }

    printf("Enter the elements of the second matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &m2[i][j]);
        }
    }

    do {
        printf("\nMenu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose First Matrix\n");
        printf("4. Transpose Second Matrix\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMatrices(m1, m2, result, rows, cols);
                printf("Result of Addition:\n");
                displayMatrix(result, rows, cols);
                break;
            case 2:
                subtractMatrices(m1, m2, result, rows, cols);
                printf("Result of Subtraction:\n");
                displayMatrix(result, rows, cols);
                break;
            case 3:
                transposeMatrix(m1, transposed, rows, cols);
                printf("Transpose of First Matrix:\n");
                displayMatrix(transposed, cols, rows);
                break;
            case 4:
                transposeMatrix(m2, transposed, rows, cols);
                printf("Transpose of Second Matrix:\n");
                displayMatrix(transposed, cols, rows);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}