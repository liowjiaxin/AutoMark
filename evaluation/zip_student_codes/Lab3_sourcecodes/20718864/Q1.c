#include <stdio.h>

#define SIZE 10  // Maximum matrix size

// Declare matrices and variables
int A[SIZE][SIZE], B[SIZE][SIZE];
int rowsA, rowsB, columnA, columnB;
int result[SIZE][SIZE];
int choice = 0;  // Initialize choice to 0

// Function to input matrix elements
void inputMatrix(int rows, int column, int matrix[SIZE][SIZE]) 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < column; j++) 
        {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print a matrix
void printMatrix(int rows, int column, int matrix[SIZE][SIZE]) 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < column; j++) 
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add matrices
void addMatrices(int rows, int column, int matrix[SIZE][SIZE]) 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < column; j++) 
        {
            result[i][j] = A[i][j] + B[i][j];  // Corrected matrix addition logic
        }
    }
    printMatrix(rows, column, result);
}

// Function to subtract matrices
void subtractMatrices(int rows, int column, int matrix[SIZE][SIZE]) 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < column; j++) 
        {
            result[i][j] = A[i][j] - B[i][j];  // Corrected matrix subtraction logic
        }
    }
    printMatrix(rows, column, result);
}

// Function to transpose a matrix
void transposeMatrix(int rows, int column, int matrix[SIZE][SIZE]) 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < column; j++) 
        {
            result[j][i] = matrix[i][j];  // Swap rows and columns
        }
    }
    printMatrix(column, rows, result);  // Print the transposed matrix (rows and columns swapped)
}

int main() 
{
    // Input the dimensions of matrices A and B
    printf("Enter rows and columns for Matrix A (max 10x10): ");
    scanf("%d %d", &rowsA, &columnA);
    printf("Enter rows and columns for Matrix B (max 10x10): ");
    scanf("%d %d", &rowsB, &columnB);

    // Check for valid matrix dimensions before inputting matrix elements
    if (rowsA > SIZE || columnA > SIZE || rowsB > SIZE || columnB > SIZE || rowsA <= 0 || columnA <= 0 || rowsB <= 0 || columnB <= 0) 
    {
        printf("Invalid dimensions. Exiting.\n");
        return 1;
    }

    // Input elements for both matrices
    printf("\nEnter elements for Matrix A:\n");
    inputMatrix(rowsA, columnA, A);
    printf("\nEnter elements for Matrix B:\n");
    inputMatrix(rowsB, columnB, B);

    // Menu-driven program to perform matrix operations
    printf("\nMenu:\n");
    printf("1. Add Matrices\n");
    printf("2. Subtract Matrices\n");
    printf("3. Transpose Matrix A\n");
    printf("4. Transpose Matrix B\n");
    printf("5. Exit\n");

    // Menu-driven program to perform matrix operations
    while (choice != 5) 
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                if (rowsA == rowsB && columnA == columnB) 
                {
                    printf("Result of Addition:\n");
                    addMatrices(rowsA, columnA, A);
                } else 
                {
                    printf("Error: Matrices must have the same dimensions for addition.\n");
                }
                break;
            case 2:
                if (rowsA == rowsB && columnA == columnB) 
                {
                    printf("Result of Subtraction:\n");
                    subtractMatrices(rowsA, columnA, A);
                } else 
                {
                    printf("Error: Matrices must have the same dimensions for subtraction.\n");
                }
                break;
            case 3:
                printf("Transpose of Matrix A:\n");
                transposeMatrix(rowsA, columnA, A);
                break;
            case 4:
                printf("Transpose of Matrix B:\n");
                transposeMatrix(rowsB, columnB, B);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
