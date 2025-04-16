#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

#define ALLOCATE_MATRIX(rows, columns) (int**)malloc(rows * sizeof(int*) + rows * columns * sizeof(int))

// Function prototypes

void addMatrices(int rows, int cols, int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]);
void subtractMatrices(int rows, int cols, int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]);
void transposeMatrix(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]);
void inputMatrix(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE]);
void printMatrix(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE]);

// Function to add 
void addMatrices(int rows, int columns, int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

// Function to subtract 
void subtractMatrices(int rows, int columns, int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

// Function to transpose 
void transposeMatrix(int rows, int columns, int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

// Function to input elements of a matrix
void inputMatrix(int rows, int columns, int matrix[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print a matrix
void printMatrix(int rows, int columns, int matrix[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int a[MAX_SIZE][MAX_SIZE], b[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];
    int rowsA, columnsA, rowsB, columnsB;
    int matrixA, matrixB;
    int choice;

    // Input for matrix A and B
  printf("Enter dimensions for Matrix A (rows and columns): ");
  scanf("%d %d", &rowsA, &columnsA);
  while (getchar() != '\n'); //clear buffer

  printf("Enter elements for Matrix A:\n");
  inputMatrix(rowsA, columnsA, a);

  printf("\nEnter dimensions for Matrix B (rows and columns): ");
  scanf("%d %d", &rowsB, &columnsB);
  while (getchar() != '\n');

  printf("Enter elements for Matrix B:\n");
  inputMatrix(rowsB, columnsB, b);

  //menu
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
        if (rowsA == rowsB && columnsA == columnsB) {
          addMatrices(rowsA, columnsA, a, b, result);
          printf("\nResult of Matrix A + Matrix B:\n");
          printMatrix(rowsA, columnsA, result);
        } else {
          printf("Error: Matrices must have same dimensions to add.\n");
        }
        break;

      case 2:
        if (rowsA == rowsB && columnsA == columnsB) {
          subtractMatrices(rowsA, columnsA, a, b, result);
          printf("\nResult of Matrix A - Matrix B:\n");
          printMatrix(rowsA, columnsA, result);
        } else {
          printf("Error: Matrices must have same dimensions to subtract.\n");
        }
        break;

      case 3:
        transposeMatrix(rowsA, columnsA, a, result);
        printf("\nTranspose of Matrix A:\n");
        printMatrix(columnsA, rowsA, result);
        break;

      case 4:
        transposeMatrix(rowsB, columnsB, b, result);
        printf("\nTranspose of Matrix B:\n");
        printMatrix(columnsB, rowsB, result);
        break;

      case 5:
        printf("Exiting....\n");
        break;

      default:
        printf("Invalid choice. Please try again.\n");
    }
  } while (choice != 5);

  return 0;
}

//End of program