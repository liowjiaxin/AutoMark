// Library Pull & Variable Definition
#include <stdio.h>
#define MAXIMUM_SIZE 10 // Maximum size for the matrix, 10x10 matrix being the maximum size.

// Function prototypes
void inputDimensions(int *rows, int *columns);
void inputMatrix(int rows, int columns, int matrix[MAXIMUM_SIZE][MAXIMUM_SIZE]);
void addMatrices(int rows, int columns, int A[MAXIMUM_SIZE][MAXIMUM_SIZE], int B[MAXIMUM_SIZE][MAXIMUM_SIZE], int result[MAXIMUM_SIZE][MAXIMUM_SIZE]);
void subtractMatrices(int rows, int columns, int A[MAXIMUM_SIZE][MAXIMUM_SIZE], int B[MAXIMUM_SIZE][MAXIMUM_SIZE], int result[MAXIMUM_SIZE][MAXIMUM_SIZE]);
void transposeMatrix(int rows, int columns, int matrix[MAXIMUM_SIZE][MAXIMUM_SIZE], int result[MAXIMUM_SIZE][MAXIMUM_SIZE]);
void displayMatrix(int rows, int columns, int matrix[MAXIMUM_SIZE][MAXIMUM_SIZE]);


// Function to input matrix dimensions
void inputDimensions(int *rows, int *columns) {
    do {
        printf("Enter dimensions in numerical format (rows and columns, e.g. 5 7): ");
        scanf("%d %d", rows, columns);
        // Validate input to ensure dimensions are within allowed range
        if (*rows <= 0 || *rows > MAXIMUM_SIZE || *columns <= 0 || *columns > MAXIMUM_SIZE) {
            printf("Invalid dimensions. Please enter values between 1 and %d.\n", MAXIMUM_SIZE);
        }
    } while (*rows <= 0 || *rows > MAXIMUM_SIZE || *columns <= 0 || *columns > MAXIMUM_SIZE);
}

// Function to input matrix elements
void inputMatrix(int rows, int columns, int matrix[MAXIMUM_SIZE][MAXIMUM_SIZE]) {
    printf("Enter elements for the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1); // Print line that indicates the location of the element.
            scanf("%d", &matrix[i][j]); // Read and store the element
        }
    }
}

// Function to add two matrices
void addMatrices(int rows, int columns, int A[MAXIMUM_SIZE][MAXIMUM_SIZE], int B[MAXIMUM_SIZE][MAXIMUM_SIZE], int result[MAXIMUM_SIZE][MAXIMUM_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result[i][j] = A[i][j] + B[i][j]; // Add corresponding elements
        }
    }
}

// Function to subtract two matrices
void subtractMatrices(int rows, int columns, int A[MAXIMUM_SIZE][MAXIMUM_SIZE], int B[MAXIMUM_SIZE][MAXIMUM_SIZE], int result[MAXIMUM_SIZE][MAXIMUM_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result[i][j] = A[i][j] - B[i][j]; // Subtract corresponding elements
        }
    }
}

// Function to transpose a matrix
void transposeMatrix(int rows, int columns, int matrix[MAXIMUM_SIZE][MAXIMUM_SIZE], int result[MAXIMUM_SIZE][MAXIMUM_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result[j][i] = matrix[i][j]; // Swap rows and columns
        }
    }
}

// Function to display a matrix
void displayMatrix(int rows, int columns, int matrix[MAXIMUM_SIZE][MAXIMUM_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", matrix[i][j]); // Print each element
        }
        printf("\n"); // Move to the next line after each row
    }
}

int main() {
    int rowsA, columnsA, rowsB, columnsB;
    int matrixA[MAXIMUM_SIZE][MAXIMUM_SIZE], matrixB[MAXIMUM_SIZE][MAXIMUM_SIZE], result[MAXIMUM_SIZE][MAXIMUM_SIZE];
    int choice;

    printf("Welcome to the Basic Operational Matrix System! \nYou'll be asked to enter the dimension of the matrix in addition to the elements inside the matrix.\nIt is of note that once you have inputted the dimensions and elements, you will not be able to change them. \n\n\n");

    // Input for Matrix A
    printf("The following inputs are going to be for Matrix A. \n");
    inputDimensions(&rowsA, &columnsA); // Get dimensions for matrix A
    inputMatrix(rowsA, columnsA, matrixA); // Get elements for matrix A

    // Input for Matrix B
    printf("The following inputs are going to be for Matrix B. \n");
    inputDimensions(&rowsB, &columnsB); // Get dimensions for matrix B
    inputMatrix(rowsB, columnsB, matrixB); // Get elements for matrix B

    do {
        // Display menu
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
                if (rowsA != rowsB || columnsA != columnsB) {
                    printf("Error: Matrices must have the same dimensions for addition.\n");
                } else {
                    addMatrices(rowsA, columnsA, matrixA, matrixB, result); // Add matrices
                    printf("Result of Matrix A + Matrix B:\n");
                    displayMatrix(rowsA, columnsA, result); // Display the result
                }
                break;
            case 2:
                if (rowsA != rowsB || columnsA != columnsB) {
                    printf("Error: Matrices must have the same dimensions for subtraction.\n");
                } else {
                    subtractMatrices(rowsA, columnsA, matrixA, matrixB, result); // Subtract matrices
                    printf("Result of Matrix A - Matrix B:\n");
                    displayMatrix(rowsA, columnsA, result); // Display the result
                }
                break;
            case 3:
                transposeMatrix(rowsA, columnsA, matrixA, result); // Transpose matrix A
                printf("Transpose of Matrix A:\n");
                displayMatrix(columnsA, rowsA, result); // Display the result (note the swapped dimensions)
                break;
            case 4:
                transposeMatrix(rowsB, columnsB, matrixB, result); // Transpose matrix B
                printf("Transpose of Matrix B:\n");
                displayMatrix(columnsB, rowsB, result); // Display the result (note the swapped dimensions)
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5); // Continue until the user chooses to exit

    return 0;
}
