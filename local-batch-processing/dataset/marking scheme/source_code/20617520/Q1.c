#include <stdio.h>

#define MAX_SIZE 10

//function prototypes
void AddMatrix(int matrixA[10][10], int matrixB[10][10], int row, int col);
void SubtractMatrix(int matrixA[10][10], int matrixB[10][10], int row, int col);
void TransposeMatrix(int matrix[10][10], int row, int col);
void PrintMatrix(int matrix[10][10], int row, int col);
void InputMatrix(int matrix[10][10], int row, int col);


int main()
{
    int matrixA[10][10];
    int matrixB[10][10];
    int rowA, colA;
    int rowB, colB;
    int option;
    char again = 'y';
    
    while ((again == 'Y')||(again == 'y'))
    {
        //print menu
        printf("Matrix Operations Menu:\n");
        printf("1. Add Matrices \n2. Subtract Matrices \n3. Transpose Matrix A \n4. Transpose Matrix B \n5. Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option)
        {
            case 1: //addition
                //prompt user for dimentions for addition
                printf("Enter dimensions (rows and columns) for Matrix A: ");
                scanf("%d %d", &rowA, &colA);
                while (rowA <= 0 || colA <= 0 || rowA > MAX_SIZE || colA > MAX_SIZE)
                {
                    printf("Invalid dimensions! Rows and Columns must be positive integers and not exceed %d. \n", MAX_SIZE);
                    printf("Enter dimensions (rows and columns) for Matrix A: ");
                    scanf("%d %d", &rowA, &colA);
                }


                printf("Enter dimensions (rows and columns) for Matrix B: ");
                scanf("%d %d", &rowB, &colB);
                while (rowB <= 0 || colB <= 0 || rowB > MAX_SIZE || colB > MAX_SIZE)
                {
                    printf("Invalid dimensions! Rows and Columns must be positive integers. \n");
                    printf("Enter dimensions (rows and columns) for Matrix B: ");
                    scanf("%d %d", &rowB, &colB);
                }


                if (rowA != rowB || colA != colB)
                {
                    printf("Matrices must be the same size! \n");
                    break;
                }

                //input matrix
                printf("Enter elements of Matrix A: \n");
                InputMatrix(matrixA, rowA, colA);
                printf("Enter elements of Matrix B: \n");
                InputMatrix(matrixB, rowA, colB);

                //addition
                printf("Result after addition: \n");
                AddMatrix(matrixA, matrixB, rowA, colA);
                break;

            case 2: //subtraction
                printf("Enter dimensions (rows and columns) for Matrix A: ");
                scanf("%d %d", &rowA, &colA);
                while (rowA <= 0 || colA <= 0 || rowA > MAX_SIZE || colA > MAX_SIZE)
                {
                    printf("Invalid dimensions! Rows and Columns must be positive integers and not exceed %d. \n", MAX_SIZE);
                    printf("Enter dimensions (rows and columns) for Matrix A: ");
                    scanf("%d %d", &rowA, &colA);
                }


                printf("Enter dimensions (rows and columns) for Matrix B: ");
                scanf("%d %d", &rowB, &colB);
                while (rowB <= 0 || colB <= 0 || rowB > MAX_SIZE || colB > MAX_SIZE)
                {
                    printf("Invalid dimensions! Rows and Columns must be positive integers. \n");
                    printf("Enter dimensions (rows and columns) for Matrix B: ");
                    scanf("%d %d", &rowB, &colB);
                }


                if (rowA != rowB || colA != colB)
                {
                    printf("Matrices must be the same size! \n");
                    break;
                }

                //input matrix
                printf("Enter elements of Matrix A: \n");
                InputMatrix(matrixA, rowA, colA);
                printf("Enter elements of Matrix B: \n");
                InputMatrix(matrixB, rowA, colB);

                //subtraction
                SubtractMatrix(matrixA, matrixB, rowA, colA);
                break;

            case 3: //transpose matrix A
                //input dimensions for transpose
                printf("Enter dimensions (rows and columns) for Matrix A: ");
                scanf("%d %d", &rowA, &colA);
                while (rowA <= 0 || colA <= 0 || rowA > MAX_SIZE || colA > MAX_SIZE)
                {
                    printf("Invalid dimensions! Rows and Columns must be positive integersand not exceed %d. \n", MAX_SIZE);
                    printf("Enter rows and columns for Matrix A: \n");
                    scanf("%d %d", &rowA, &colA);
                }

                //input matrix
                printf("Enter elements of Matrix A: \n");
                InputMatrix(matrixA, rowA, colA);

                printf("Transpose of Matrix A: \n");

                //transpose matrix A
                TransposeMatrix(matrixA, rowA, colA);
                break;

            case 4: //case to transpose matrix B
                //input dimensions for transpose
                printf("Enter dimensions (rows and columns) for Matrix B: ");
                scanf("%d %d", &rowB, &colB);
                while (rowB <= 0 || colB <= 0 || rowB > MAX_SIZE || colB > MAX_SIZE)
                {
                    printf("Invalid dimensions! Rows and Columns must be positive integers and not exceed %d. \n", MAX_SIZE);
                    printf("Enter rows and columns for Matrix B: \n");
                    scanf("%d %d", &rowB, &colB);
                }

                //input elements into matrix
                printf("Enter elements of Matrix B: \n");
                InputMatrix(matrixB, rowB, colB);

                printf("Transpose of Matrix B: \n");
                //transpose matrix B
                TransposeMatrix(matrixB, rowB, colB);
                break;

            case 5:
                printf("Exiting...");
                return 0;

            default:
                printf("Invalid option. Please enter a valid option. \n");

        }

        printf("Do you want to perform another operation? (y/n): ");
        scanf(" %c", &again);
    }

    return 0;
    
}

void InputMatrix(int matrix[10][10], int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("Element [%d] [%d]: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void PrintMatrix(int matrix[10][10], int row, int col)
{
    int result[10][10];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void AddMatrix(int matrixA[10][10], int matrixB[10][10], int row, int col)
{
    int result[10][10];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            result[i][j] = matrixA[i][j] + matrixB[i][j]; 
        }
    }
    PrintMatrix(result, row, col);
}

void SubtractMatrix(int matrixA[10][10], int matrixB[10][10], int row, int col)
{
    int result[10][10];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
    PrintMatrix(result, row, col);
}

void TransposeMatrix(int matrix[10][10], int row, int col)
{
    int result[10][10];
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            result[i][j] = matrix[j][i];
        }
    }
    PrintMatrix(result, col, row);
}