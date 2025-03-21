#include <stdio.h>

void print_matrices(int matrix[10][10], int rows, int columns){   // function to display matrices
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%d \t", matrix[i][j]);
        }
        printf("\n");
    }    

}

void construct_matrix(int matrix[10][10], int *rows, int *columns, const char *name) { // function to construct the matrix according to user input
    while (1)
    {
        printf("Enter the number of rows you want in %s (max 10): ", name);
        scanf("%d", rows);

        printf("Enter the number of columns you want in %s (max 10): ", name);
        scanf("%d", columns);

        if (*rows <= 0 || *rows > 10 || *columns <= 0 || *columns > 10)
        {
            printf("Invalid number of rows or columns. Please re-enter the values.\n");  // validating user input
            continue;
        }
        else
        {
            break;
        }
    }

    printf("Enter the elements for %s:\n", name);
    for (int i = 0; i < *rows; i++)
    {
        for (int j = 0; j < *columns; j++)
        {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void add_matrices(int matrix_1[10][10], int matrix_2[10][10], int rows, int columns, int sum[10][10]) { // function to add matrices ( will not work unless the dimensions of the matrices are the same)
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            sum[i][j] = matrix_1[i][j] + matrix_2[i][j];
        }
    }

    printf("The sum of the Matrices :\n");
    print_matrices(sum, rows, columns);
}

void subtract_matrices(int matrix_1[10][10], int matrix_2[10][10], int rows, int columns, int difference[10][10]) { // function to subtract matrices ( will not work unless the dimensions of the matrices are the same)
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            difference[i][j] = matrix_1[i][j] - matrix_2[i][j];
        }
    }

    printf("The difference between the Matrices :\n");
    print_matrices(difference, rows, columns);

}

void transpose(int matrix[10][10], int rows, int columns){ //  function to invert or transpose the matrices
    int transpose[10][10];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }  
    print_matrices(transpose, rows, columns);  

}

int main() {
    int Matrix_1[10][10];
    int Matrix_2[10][10];
    int sum[10][10];
    int rows_1, columns_1;
    int rows_2, columns_2;
    int choice;

    construct_matrix(Matrix_1, &rows_1, &columns_1, "Matrix 1");
    construct_matrix(Matrix_2, &rows_2, &columns_2, "Matrix 2");

    while (1)
    {
        printf("\nMatrix Operations Menu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");        // user input menu
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (rows_1 == rows_2 && columns_1 == columns_2)
                {
                    add_matrices(Matrix_1, Matrix_2, rows_1, columns_1, sum);
                }
                else
                {
                    printf("Error: Matrices should be of the same dimensions for them to be added together.\n"); // erroe message
                }
                break;

            case 2:
                if (rows_1 == rows_2 && columns_1 == columns_2)
                {
                    subtract_matrices(Matrix_1, Matrix_2, rows_1, columns_1, sum);
                }
                else
                {
                    printf("Error: Matrices should be of the same dimensions for them to be subtracted.\n"); // error message
                }
                break;

            case 3:
                transpose(Matrix_1, rows_1, columns_1);
                break;

            case 4:
                transpose(Matrix_2, rows_2, columns_2);
                break;    

            case 5:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Not a valid choice. Please re-enter.\n");
                break;
        }
    }

    return 0;
}
