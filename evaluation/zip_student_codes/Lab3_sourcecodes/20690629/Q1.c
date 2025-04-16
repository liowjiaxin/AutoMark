#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 10

void inputMatrix(int matrix[MAX][MAX], int rows, int cols)
{
    // for every row
    for (int i = 0; i < rows; i++)
    {
        // for every column
        for (int j = 0; j < cols; j++)
        {
            // prompt user to input each element
            printf("Enter element %dx%d: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void AddMatrices(int p[MAX][MAX], int q[MAX][MAX], int ans[MAX][MAX], int rows, int cols)
{
    // for every row
    for (int i = 0; i < rows; i++)
    {
        // for every column
        for (int j = 0; j < cols; j++)
        {
            // calculate the sum of elements in the same position of matrices A and B and store in answer matrix
            ans[i][j] = p[i][j] + q[i][j];
        }
    }
}

void SubtractMatrices(int p[MAX][MAX], int q[MAX][MAX], int ans[MAX][MAX], int rows, int cols)
{
    // for every row
    for (int i = 0; i < rows; i++)
    {
        // for every column
        for (int j = 0; j < cols; j++)
        {
            // calculate the difference of elements in the same position of matrices A and B and store in answer matrix
            ans[i][j] = p[i][j] - q[i][j];
        }
    }
}

void TransposeMatrix(int matrix[MAX][MAX], int ans[MAX][MAX], int rows, int cols)
{
    // for every row
    for (int i = 0; i < rows; i++)
    {
        // for every column
        for (int j = 0; j < cols; j++)
        {
            // change the position of elements in matrix
            ans[j][i] = matrix[i][j];
        }
    }
}

void Display(int matrix[MAX][MAX], int rows, int cols)
{
    // for every row
    for (int i = 0; i < rows; i++)
    {
        // for every column
        for (int j = 0; j < cols; j++)
        {
            // display each item on console
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    // my double array for matrix A is p and for matrix B is q
    int p[MAX][MAX], q[MAX][MAX], ans[MAX][MAX];
    int rowp, colp, rowq, colq;
    int choice = -1;
    int option = 0;

    // input number of rows, columns, and elements of each matrix
    printf("Enter the dimensions of matrices separated with a space\n");

    printf("\nEnter rows of matrix A: ");
    scanf("%d", &rowp);

    printf("\nEnter columns of matrix A: ");
    scanf("%d", &colp);

    printf("\nEnter elements for matrix A\n");
    inputMatrix(p, rowp, colp);

    printf("\nEnter rows of matrix B: ");
    scanf("%d", &rowq);

    printf("\nEnter columns of matrix B: ");
    scanf("%d", &colq);

    printf("\nEnter elements for matrix B\n");
    inputMatrix(q, rowq, colq);

    while (choice)
    {
        // prompt user to choose an operation on matrices p and q
        printf("Matrix Operations\n");
        printf("1. Add Matrices\n2. Subtract Matrices\n3. Transpose Matrix\n4. Display Matrix\n0. Exit\n");
        printf("Enter your choice of operation: ");
        scanf("%d", &choice);

        // choice is a sentinal value, loop terminates when 0 is input
        switch(choice)
        {
            case 0:
                break;
            case 1:
                // if matrices have same dimensions, addition can happen
                if (rowp == rowq && colp == colq)
                {
                    AddMatrices(p, q, ans, rowp, colp);
                    Display(ans, rowp, colp);
                }
                else
                {
                    printf("\nDimensions of matrices are not the same\n\n");
                }
                break;
            case 2:
                // if matrices have same dimensions, subtraction can happen
                if (rowp == rowq && colp == colq)
                {
                    SubtractMatrices(p, q, ans, rowp, colp);
                    Display(ans, rowp, colp);
                }
                else
                {
                    printf("\nDimensions of matrices are not the same\n\n");
                }
                break;
            case 3:
                // prompt input from user on which matrix to transpose
                option = 0;
                printf("Enter 1 for matrix A, 2 for matrix B: ");
                scanf("%d", &option);
                if (option == 1) 
                {
                    TransposeMatrix(p, ans, rowp, colp);
                    Display(ans, colp, rowp);
                }
                else if (option == 2)
                {
                    TransposeMatrix(q, ans, rowq, colq);
                    Display(ans, colq, rowq);
                }
                else 
                {
                    printf("option is not valid\n");
                }
                break;
            case 4:
                // display only matrix A and matrix B
                printf("Matrix A\n");
                Display(p, rowp, colp);
                printf("\n");
                printf("Matrix B\n");
                Display(q, rowq, colq);
                break;
            default:
                // user must input a valid operation
                printf("You did not enter a valid option\n");
                break;
        }
    }
}