#include <stdio.h>

#define MAX_SIZE 10

int main()
{
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA, rowsB, colsB;
    int choice;

    // Input dimensions for matrix A
    printf("Enter the number of rows and columns for matrix A (max 10x10): ");
    scanf("%d %d", &rowsA, &colsA);

    // Input elements for matrix A
    printf("Enter the elements for matrix A:\n");
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsA; j++)
        {
            printf("Enter element A[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &A[i][j]);
        }
    }

    // Input dimensions for matrix B
    printf("Enter the number of rows and columns for matrix B (max 10x10): ");
    scanf("%d %d", &rowsB, &colsB);

    // Input elements for matrix B
    printf("Enter the elements for matrix B:\n");
    for (int i = 0; i < rowsB; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            printf("Enter element B[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &B[i][j]);
        }
    }

    do
    {
        // Display menu
        printf("\nMenu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // Matrix addition requires A and B to have the same dimensions
            if (rowsA == rowsB && colsA == colsB)
            {
                for (int i = 0; i < rowsA; i++)
                {
                    for (int j = 0; j < colsA; j++)
                    {
                        result[i][j] = A[i][j] + B[i][j];
                    }
                }
                printf("Result of A + B:\n");
                for (int i = 0; i < rowsA; i++)
                {
                    for (int j = 0; j < colsA; j++)
                    {
                        printf("%d ", result[i][j]);
                    }
                    printf("\n");
                }
            }
            else
            {
                printf("Matrices A and B must have the same dimensions to add.\n");
            }
            break;

        case 2:
            // Matrix subtraction requires A and B to have the same dimensions
            if (rowsA == rowsB && colsA == colsB)
            {
                for (int i = 0; i < rowsA; i++)
                {
                    for (int j = 0; j < colsA; j++)
                    {
                        result[i][j] = A[i][j] - B[i][j];
                    }
                }
                printf("Result of A - B:\n");
                for (int i = 0; i < rowsA; i++)
                {
                    for (int j = 0; j < colsA; j++)
                    {
                        printf("%d ", result[i][j]);
                    }
                    printf("\n");
                }
            }
            else
            {
                printf("Matrices A and B must have the same dimensions to subtract.\n");
            }
            break;

        case 3:
            // Transpose of Matrix A
            printf("Transpose of Matrix A:\n");
            for (int i = 0; i < colsA; i++)
            {
                for (int j = 0; j < rowsA; j++)
                {
                    printf("%d ", A[j][i]);
                }
                printf("\n");
            }
            break;

        case 4:
            // Transpose of Matrix B
            printf("Transpose of Matrix B:\n");
            for (int i = 0; i < colsB; i++)
            {
                for (int j = 0; j < rowsB; j++)
                {
                    printf("%d ", B[j][i]);
                }
                printf("\n");
            }
            break;

        case 5:
            printf("Exiting the program.\n");
            break;

        default:
            printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
