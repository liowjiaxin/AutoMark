#include <stdio.h>
#include <ctype.h>

// Show the menu options
void displayMenu() 
{
    printf("\nMatrix Operations Menu:\n");
    printf("1. Add Matrices\n");
    printf("2. Subtract Matrices\n");
    printf("3. Transpose Matrix A\n");
    printf("4. Transpose Matrix B\n");
    printf("5. Exit\n");
}

// Validation when user input the rows and columns for the matrix A, B.
// Must one decimal then space then only the second decimal
int isValidDimensions(char *input, int *rows, int *cols) 
{
    int r, c;
    // sscanf extract the value of the eg. r = 2, c = 2 from the input
    if (sscanf(input, "%d %d", &r, &c) == 2 && r > 0 && r <= 10 && c > 0 && c <= 10) 
    {
        *rows = r;
        *cols = c;
        return 1; // Valid dimensions
    }
    return 0; // Invalid dimensions
}

// Used to get valid dimensions
void getDimensions(char *question, int *rows, int *cols) 
{
    char input[100]; // variable to store the user input
    do 
    {
        printf("%s", question); // print the message: "Enter dimensions for Matrix A (rows and columns): "
        fgets(input, sizeof(input), stdin); // get the user input
        // check if the input position is [0, 1, 2]
        if (!isValidDimensions(input, rows, cols)) 
        { 
            printf("Invalid input! Please enter two integers between 1 and 10 separated by a space.\n");
        }
    } while (!isValidDimensions(input, rows, cols));
}

void inputMatrix(int rows, int cols, int matrix[10][10]) 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            // used to check if the value stored in the matrix[i][j] is decimal or not
            // scanf will return 1 when input is valid integer
            while (scanf("%d", &matrix[i][j]) != 1) 
            {
                printf("Invalid input! Enter a valid integer: ");
                // Clear the input buffer
                while (getchar() != '\n'); 
            }
        }
    }
    // Clear buffer after matrix input
    while (getchar() != '\n'); 
}

void printMatrix(int rows, int cols, int matrix[10][10]) 
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

void addMatrix(int rows, int cols, int addMatrixA[10][10], int addMatrixB[10][10], int result[10][10]) 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            result[i][j] = addMatrixA[i][j] + addMatrixB[i][j];
        }
    }
}

void subtractMatrix(int rows, int cols, int subtractMatrixA[10][10], int sutractbMatrixB[10][10], int result[10][10]) 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            result[i][j] = subtractMatrixA[i][j] - sutractbMatrixB[i][j];
        }
    }
}

void transposeMatrix(int rows, int cols, int matrix[10][10], int result[10][10]) 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            result[j][i] = matrix[i][j];
        }
    }
}

int main() 
{
    int inputMatrixA[10][10], inputMatrixB[10][10], result[10][10];
    int inputRowsA, inputColsA, inputRowsB, inputColsB;
    int userChoice;

    // Input rows, columns, and values for Matrix A
    getDimensions("Enter dimensions for Matrix A (rows and columns): ", &inputRowsA, &inputColsA);
    printf("Enter elements for Matrix A:\n");
    inputMatrix(inputRowsA, inputColsA, inputMatrixA);

    // Input rows, columns, and values for Matrix B
    getDimensions("Enter dimensions for Matrix B (rows and columns): ", &inputRowsB, &inputColsB);
    printf("Enter elements for Matrix B:\n");
    inputMatrix(inputRowsB, inputColsB, inputMatrixB);

    do {
        displayMenu();
        printf("Enter your choice: ");

        // when scanf doesn't gets valid integer, it will return 0 (False)
        if(scanf("%d", &userChoice) != 1)
        {
            printf("Invalid choice. Please choose a valid choice\n");
            // clear the input buffer
            while (getchar() != '\n');
            continue;
        }

        switch (userChoice) 
        {
            case 1:
                // check if the dimensions of Matrix A and Matrix B is same or not
                if (inputRowsA == inputRowsB && inputColsA == inputColsB) 
                {
                    addMatrix(inputRowsA, inputColsA, inputMatrixA, inputMatrixB, result);
                    printf("Result of Matrix A + Matrix B:\n");
                    printMatrix(inputRowsA, inputColsA, result);
                } 
                else 
                {
                    printf("Addition is not possible. Both dimensions must same.\n");
                }
                break;

            case 2:
                if (inputRowsA == inputRowsB && inputColsA == inputColsB) 
                {
                    subtractMatrix(inputRowsA, inputColsA, inputMatrixA, inputMatrixB, result);
                    printf("Result of Matrix A - Matrix B:\n");
                    printMatrix(inputRowsA, inputColsA, result);
                } 
                else 
                {
                    printf("Subtraction is not possible. Both dimensions must same.\n");
                }
                break;

            case 3:
                transposeMatrix(inputRowsA, inputColsA, inputMatrixA, result);
                printf("Transpose of Matrix A:\n");
                printMatrix(inputColsA, inputRowsA, result);
                break;

            case 4:
                transposeMatrix(inputRowsB, inputColsB, inputMatrixB, result);
                printf("Transpose of Matrix B:\n");
                printMatrix(inputColsB, inputRowsB, result);
                break;

            case 5:
                printf("Have a nice daay!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (userChoice != 5);

    return 0;
}
