#include <stdio.h>

int promptSize(int*, int*, char);
int createMatrix(int[], int, int, char);
void printMatrix(int*, int, int);
void addMatrix(int*, int*, int, int);
void subMatrix(int*, int*, int, int);
void transposeMatrix(int*, int, int, char);

// To clear input buffer until a newline
void clearInput() {
    scanf("%*[^\n]");scanf("%*c");
}

int main() {
    int rowA=0, colA=0, rowB=0, colB=0;
    puts("Welcome to Matrix calculator");
    
    // Prompts user for size of matrix A for initialization
    while (1) {
        if (promptSize(&rowA, &colA, 'A')==-1) {
            continue;
        }
        break;
    }
    // Initializes matrix A
    int MatrixA[rowA*colA];
    createMatrix(MatrixA, rowA, colA, 'A');

    // Prompts user for size of matrix B for initialization
    while (1) {
        if (promptSize(&rowB, &colB, 'B')==-1) {
            continue;
        }
        break;
    }
    // Initializes matrix B
    int MatrixB[rowB*colB];
    createMatrix(MatrixB, rowB, colB, 'B');

    int choice = 0;
    int exit = 0;

    while (!exit) {
        printf("\nMatrix Operations Menu\n"
               "1. Add matrices\n"
               "2. Subtract matrices\n"
               "3. Transpose of matrix A\n"
               "4. Transpose of matrix B\n"
               "5. Exit\n"
               "Enter you choice: ");
        scanf("%d",&choice);
        getchar();
        switch (choice) {
            case 1:
                if (rowA != rowB || colA != colB) {
                    printf("Error: Matrices need to be of the same dimension.\n");
                    break;
                }
                addMatrix(MatrixA, MatrixB, rowA, colA);
                break;
            case 2:
                if (rowA != rowB || colA != colB) {
                    printf("Error: Matrices need to be of the same dimension.\n");
                    break;
                }
                subMatrix(MatrixA, MatrixB, rowA, colA);
                break;
            case 3:
                transposeMatrix(MatrixA, rowA, colA, 'A');
                break;
            case 4:
                transposeMatrix(MatrixB, rowB, colB, 'B');
                break;
            case 5:
                printf("Exiting...");
                exit = 1;
                break;
            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}
int promptSize(int *rowptr, int *colptr, char name) {
    int rows = 0, cols = 0;
    printf("Enter dimensions for Matrix %c (rows and columns): ", name);
    scanf("%d %d", &rows, &cols);
    clearInput();

    // Checks for row and column max is 10
    if (rows < 1 || 10 < rows) {
        printf("Error: rows has to be between 1 and 10 inclusive.\n");
        return -1;
    }
    if (cols < 1 || 10 < cols) {
        printf("Error: columns has to be between 1 and 10 inclusive\n");
        return -1;
    }

    *rowptr = rows;
    *colptr = cols;
    return 0;
}

// Creates Matrix returns error code and changes row and col by address
int createMatrix(int matrix[], int rows, int cols, char name) {

    // Matrix is of the form "contiguous array of rows"
    printf("Enter elements for matrix %c:\n", name);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Because of the matrix storage, elements can be accessed with the formula, columns*rowIndex + colIndex
            printf("Element [%d][%d]: ", i+1, j+1);
            scanf("%d", &matrix[cols*i + j]);
            clearInput();
        }
    }
    return 0;
}

void printMatrix(int matrix[], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[cols*i + j]);
        }
        puts("");
    }
}

void addMatrix(int MatrixA[], int MatrixB[], int rows, int cols) {
    int result[rows*cols];
    // Adds matching indexes of matrix elements in each matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[cols*i+j] = MatrixA[cols*i+j] + MatrixB[cols*i+j];
        }
    }
    puts("Result of Matrix A + Matrix B:");
    printMatrix(result, rows, cols);
}

void subMatrix(int MatrixA[], int MatrixB[], int rows, int cols) {
    int result[rows*cols];
    // Subtracts matching indexes of matrix elements in each matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[cols*i+j] = MatrixA[cols*i+j] - MatrixB[cols*i+j];
        }
    }
    puts("Result of Matrix A + Matrix B:");
    printMatrix(result, rows, cols);
}

void transposeMatrix(int matrix[], int rows, int cols, char name) {
    int result[rows*cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Switches from an array of rows to an array of columns
            result[rows*j+i] = matrix[cols*i + j];
        }
    }
    printf("Result of transpose Matrix %c\n", name);
    printMatrix(result, cols, rows);
}
/*
1 2 3
4 5 6

1 2 3 4 5 6

1 4
2 5
3 6

1 4 2 5 3 6
*/