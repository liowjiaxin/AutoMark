#include <stdio.h>
#define MAX 10 // maximum size of the matrix

void input(int matrix[MAX][MAX], int row, int col, char name) { // enter the element of the matrix
    printf("Enter the elements for Matrix %c:\n", name);
    for (int i = 0; i < row; i++) { // outer loop use to input rows
        for (int j = 0; j < col; j++) { // inner loop use to input columns
            printf("Element [%d][%d]: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void add(int A[MAX][MAX], int B[MAX][MAX], int sum[MAX][MAX], int row, int col) { // add matrices
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            sum[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtract(int A[MAX][MAX], int B[MAX][MAX], int sum[MAX][MAX], int row, int col) { //  subtract matrices
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            sum[i][j] = A[i][j] - B[i][j];
        }
    }
}

void transpose(int matrix[MAX][MAX], int T[MAX][MAX], int row, int col) { // transpose matrix
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            T[j][i] = matrix[i][j];
        }
    }
}

void print(int matrix[MAX][MAX], int row, int col) { // display the matrix
    for (int i = 0; i < row; i++) { // outer loop use to input rows
        for (int j = 0; j < col; j++) { // inner loop use to input columns
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void menu(){
    printf("\nMatrix Operations Menu:\n");
    printf("1. Add Matrices\n");
    printf("2. Subtract Matrices\n");
    printf("3. Transpose Matrix A\n");
    printf("4. Transpose Matrix B\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], sum[MAX][MAX];// matrices
    char nameA = 'A';
    char nameB = 'B';
    int rowsA, colsA, rowsB, colsB;
    int choice;// choose the operation

    printf("Enter the dimensions for matrix A (rows and columns): ");
    scanf("%d %d", &rowsA, &colsA);
    input(A, rowsA, colsA, nameA);

    printf("Enter the dimensions for matrix B (rows and columns): ");
    scanf("%d %d", &rowsB, &colsB);
    input(B, rowsB, colsB, nameB);

    do {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (rowsA == rowsB && colsA == colsB) { // if matrices have same dimensions then add
                    add(A, B, sum, rowsA, colsA);
                    printf("Result of Matrix A + Matrix B:\n");
                    print(sum, rowsA, colsA);
                } else {
                    printf("Invalid opreation. Matrices have different dimensions.\n");
                }
                break;
            case 2:
                if (rowsA == rowsB && colsA == colsB) { // if matrices have same dimensions then subtract
                    subtract(A, B, sum, rowsA, colsA);
                    printf("Result of Matrix A - Matrix B:\n");
                    print(sum, rowsA, colsA);
                } else {
                    printf("Invalid opreation. Matrices have different dimensions.\n");
                }
                break;
            case 3:
                transpose(A, sum, rowsA, colsA); // tranpose Matrix A
                printf("Transpose of Matrix A:\n");
                print(sum, colsA, rowsA);
                break;
            case 4:
                transpose(B, sum, rowsB, colsB); // transpose Matrix B
                printf("Transpose of Matrix B:\n");
                print(sum, colsB, rowsB);
                break;
            case 5:
                printf("Exiting...\n"); // exit
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}