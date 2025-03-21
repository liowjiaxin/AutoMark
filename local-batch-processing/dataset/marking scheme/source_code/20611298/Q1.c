#include <stdio.h>
#define Value 10

// Function Prototype
void Dimensions_input(int *rows, int *columns, char Matrix_Name);
void Matrix_Add(int A[Value][Value], int B[Value][Value], int result[Value][Value], int rows, int columns);
void Matrix_subtract(int A[Value][Value], int B[Value][Value], int result[Value][Value], int rows, int columns);
void Matrix_Input(int matrix[Value][Value], int rows, int columns, char name);
void Matrix_Print(int matrix[Value][Value], int rows, int columns);
void Matrix_Tranposed(int matrix[Value][Value], int transposed[Value][Value], int rows, int columns);

// Function for the input matric including the error validation
// use of do while loop to repeat it until getting the valid input
void Dimensions_input(int *rows, int *columns, char Matrix_Name)
{
    int valid = 0;

    do
    {
        printf("Enter the dimensions of Matrix %c (rows and columns): ", Matrix_Name);

        // Read and validate the input
        // To make sure theres two input
        if (scanf("%d %d", rows, columns) == 2)
        {
            if (*rows > 0 && *rows <= Value && *columns > 0 && *columns <= Value)
            {
                // valid input
                valid = 1;
            }
            else
            {
                printf("Invalid dimensions. Please enter positive integers within the range 1 to %d.\n", Value);
            }
        }
        else
        {
            printf("Invalid input. Please enter two integers separated by a space.\n");
        }

        // Clear the buffer
        while (getchar() != '\n')
            ;

    } while (!valid);
}

// Matrices Adding
void Matrix_Add(int A[Value][Value], int B[Value][Value], int result[Value][Value], int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Matrices subtarcting by using For loop
void Matrix_subtract(int A[Value][Value], int B[Value][Value], int result[Value][Value], int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Matrices inputing
void Matrix_Input(int matrix[Value][Value], int rows, int columns, char name)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%c[%d][%d]: ", name, i + 1, j + 1);
            while (scanf("%d", &matrix[i][j]) != 1)
            {
                printf("Invalid input. Please enter an integer\n%c[%d][%d]: ", name, i + 1, j + 1);
                // clear the input buffer
                while (getchar() != '\n')
                    ;
            }
        }
    }
}

// Matrices printing
void Matrix_Print(int matrix[Value][Value], int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Matrix transposed
void Matrix_Tranposed(int matrix[Value][Value], int transposed[Value][Value], int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            transposed[j][i] = matrix[i][j];
        }
    }
}

int main()
{
    int rowsA, columnsA, rowsB, columnsB;
    int A[Value][Value], B[Value][Value], result[Value][Value];
    int choices;

    // input function for matrix A
    Dimensions_input(&rowsA, &columnsA, 'A');

    // prompt the user to input the value of Matrix A
    printf("Enter elements for Matrix A:\n");
    Matrix_Input(A, rowsA, columnsA, 'A');

    // Input function for matrix B
    Dimensions_input(&rowsB, &columnsB, 'B');

    // prompt the user to input the value of Matrix B
    printf("Enter elements for Matrix B:\n");
    Matrix_Input(B, rowsB, columnsB, 'B');

    // Start the matrix operation menu
    do
    {
        printf("\nMatrix Operations Menu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        // make sure the user enter valid value
        if (scanf("%d", &choices) != 1)
        { // clear input buffer
            printf("Invalid choice. Please enter a number between 1 and 5.");
            while (getchar() != '\n')
                ;
            choices = -1;
            continue;
        }

        switch (choices)
        {
        case 1:
            if (rowsA == rowsB && columnsA == columnsB)
            {
                Matrix_Add(A, B, result, rowsA, columnsA);
                printf("Result of Matrix A + Matrix B:\n");
                Matrix_Print(result, rowsA, columnsA);
            }
            else
            {
                printf("Matrix addition not possible. Dimensions must match.\n");
            }
            break;
        case 2:
            if (rowsA == rowsB && columnsA == columnsB)
            {
                Matrix_subtract(A, B, result, rowsA, columnsA);
                printf("Result of Matrix A - Matrix B:\n");
                Matrix_Print(result, rowsA, columnsA);
            }
            else
            {
                printf("Matrix subtraction not possible. Dimensions must match.\n");
            }
            break;
        case 3:
        {
            int transposed[Value][Value];
            Matrix_Tranposed(A, transposed, rowsA, columnsA);
            printf("Transpose of Matrix A:\n");
            Matrix_Print(transposed, columnsA, rowsA);
        }
        break;
        case 4:
        {
            int transposed[Value][Value];
            Matrix_Tranposed(B, transposed, rowsB, columnsB);
            printf("Transpose of Matrix B:\n");
            Matrix_Print(transposed, columnsB, rowsB);
        }
        break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (choices != 5);

    return 0;
}
