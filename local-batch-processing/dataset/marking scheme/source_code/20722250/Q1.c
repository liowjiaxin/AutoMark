#include <stdio.h>

#define MAX_SIZE 10

// function prototypes
void inputMtx(int matrix[MAX_SIZE][MAX_SIZE], char name, int *rows, int *cols);
void addMtx(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void subtractMtx(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void transposeMtx(int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void displayMtx(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void displayMenu();

int main() 
{
    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA;
    int rowsB, colsB;
    int choice;

    // input dimensions and elements for matrices A and B
    inputMtx(matrixA, 'A', &rowsA, &colsA);
    inputMtx(matrixB, 'B', &rowsB, &colsB);

    // display menu and execute the selected operation
    do 
    {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline character

        switch (choice) 
        {
            case 1: // add matrices A and B
                if (rowsA == rowsB && colsA == colsB) 
                {
                    addMtx(matrixA, matrixB, result, rowsA, colsA);
                    printf("Result of Matrix A + Matrix B:\n");
                    displayMtx(result, rowsA, colsA);
                } 
                else 
                {
                    printf("Error: Matrices must have the same dimensions to perform addition.\n");
                }
                break;

            case 2: // subtract matrices A and B
                if (rowsA == rowsB && colsA == colsB) 
                {
                    subtractMtx(matrixA, matrixB, result, rowsA, colsA);
                    printf("Result of Matrix A - Matrix B:\n");
                    displayMtx(result, rowsA, colsA);
                } 
                else 
                {
                    printf("Error: Matrices must have the same dimensions to perform subtraction.\n");
                }
                break;

            case 3: // transpose matrix A
                transposeMtx(matrixA, result, rowsA, colsA);
                printf("Transpose of Matrix A:\n");
                displayMtx(result, colsA, rowsA);
                break;

            case 4: // transpose matrix B
                transposeMtx(matrixB, result, rowsB, colsB);
                printf("Transpose of Matrix B:\n");
                displayMtx(result, colsB, rowsB);
                break;

            case 5: // exit
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// function to get matrix dimensions and elements from user input
void inputMtx(int matrix[MAX_SIZE][MAX_SIZE], char name, int *rows, int *cols) 
{
    // input dimensions
    do 
    {
        printf("Enter dimensions for Matrix %c (rows and columns): ", name);
        scanf("%d %d", rows, cols);
        
        if (*rows <= 0 || *rows > MAX_SIZE || *cols <= 0 || *cols > MAX_SIZE) 
        {
            printf("Invalid dimensions. Please enter dimensions between 1 and 10.\n\n");
        }
    } while (*rows <= 0 || *rows > MAX_SIZE || *cols <= 0 || *cols > MAX_SIZE);

    // input elements
    printf("Enter elements for Matrix %c:\n", name);
    for (int i = 0; i < *rows; i++) 
    {
        for (int j = 0; j < *cols; j++) 
        {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// function to add two matrices
void addMtx(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

// function to subtract two matrices
void subtractMtx(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

// function to transpose a matrix
void transposeMtx(int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            result[j][i] = matrix[i][j];
        }
    }
}

// function to display matrix
void displayMtx(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// function to display menu
void displayMenu() 
{
    printf("\nMatrix Operations Menu\n");
    printf("1. Add Matrices\n");
    printf("2. Subtract Matrices\n");
    printf("3. Transpose Matrix A\n");
    printf("4. Transpose Matrix B\n");
    printf("5. Exit\n");
}
