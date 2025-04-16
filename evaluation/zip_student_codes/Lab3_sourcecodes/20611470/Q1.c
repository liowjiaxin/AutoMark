#include <stdio.h>
#define Max 10

// Input matrix
void inputMatrix(int mat[Max][Max], int rows, int cols) 
{ 
    printf("Enter elements of the matrix:\n"); 
    for (int i = 0; i < rows; i++) 
    { 
        for (int j = 0; j < cols; j++) 
        { 
            printf("Element[%d][%d] :",i+1 ,j+1);
            scanf("%d", &mat[i][j]); 
        } 
    } 
}

// Display matrix
void printMatrix(int mat[Max][Max], int rows, int cols) 
{  
    for (int i = 0; i < rows; i++) 
    { 
        for (int j = 0; j < cols; j++) 
        { 
            printf("%d ", mat[i][j]); 
        } 
        printf("\n");
    } 
}

// Function to perform addition
void addMatrices(int matA[Max][Max], int matB[Max][Max], int result[Max][Max], int rows, int cols)
{
    for (int i = 0; i < rows; i++) 
    { 
        for (int j = 0; j < cols; j++) 
        { 
            result[i][j] = matA[i][j] + matB[i][j];
        } 
    } 
}

// Function to perform subtraction
void subMatrices(int matA[Max][Max], int matB[Max][Max], int result[Max][Max], int rows, int cols)
{
    for (int i = 0; i < rows; i++) 
    { 
        for (int j = 0; j < cols; j++) 
        { 
            result[i][j] = matA[i][j] - matB[i][j];
        } 
    } 
}

// Function to transpose a matrix
void transposeMatrix(int mat[Max][Max], int result[Max][Max], int rows, int cols) 
{  
    for (int i = 0; i < rows; i++) 
    { 
        for (int j = 0; j < cols; j++) 
        { 
            result[j][i] = mat[i][j];
        } 
    } 
}

// Main
int main()
{
    // Initialization
    int matA[Max][Max], matB[Max][Max], result[Max][Max];
    int choice, rowsA, colsA, rowsB, colsB;

    // Input value for matrix A 
    printf("Enter the dimensions of Matrix A (rows and columns): ");
    scanf("%d %d", &rowsA, &colsA);
    if (rowsA > Max || colsA > Max || rowsA <= 0 || colsA <= 0)
    {
        printf("Invalid dimensions for Matrix A. Exiting.\n");
        return 1;
    }
    inputMatrix(matA, rowsA, colsA);
    
    // Input value for matrix B
    printf("Enter the dimensions of Matrix B (rows and columns): ");
    scanf("%d %d", &rowsB, &colsB);
    if (rowsB > Max || colsB > Max || rowsB <= 0 || colsB <= 0)
    {
        printf("Invalid dimensions for Matrix B. Exiting.\n");
        return 1;
    }
    inputMatrix(matB, rowsB, colsB);

    do
    {
        // Display menu
        printf("\nMatrix Operations Menu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Switch case for choice
        switch (choice)
        {
            case 1:
                if (rowsA == rowsB && colsA == colsB)
                {
                    addMatrices(matA, matB, result, rowsA, colsA);
                    printf("Result of Matrix A + Matrix B :\n");
                    printMatrix(result, rowsA, colsA);
                }
                else
                {
                    printf("Matrices dimensions are not compatible for addition.\n");
                }
                break;

            case 2:
                if (rowsA == rowsB && colsA == colsB)
                {
                    subMatrices(matA, matB, result, rowsA, colsA);
                    printf("Result of Matrix A - Matrix B :\n");
                    printMatrix(result, rowsA, colsA);
                }
                else
                {
                    printf("Matrices dimensions are not compatible for subtraction.\n");
                }
                break;

            case 3:
                transposeMatrix(matA, result, rowsA, colsA);       
                printf("Transpose of Matrix A:\n"); 
                printMatrix(result, colsA, rowsA);
                break;

            case 4:
                transposeMatrix(matB, result, rowsB, colsB); 
                printf("Transpose of Matrix B:\n"); 
                printMatrix(result, colsB, rowsB);
                break;

            case 5:
                printf("Exiting...\n");
                break;
            
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);      // when 5 exit
    
    return 0;   
}
