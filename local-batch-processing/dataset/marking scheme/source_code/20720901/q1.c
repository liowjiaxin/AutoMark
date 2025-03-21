#include <stdio.h>
#include <stdlib.h>

#define MAX_MATRIX 10

// function prototype
void printMenu();
void matrixOperation(int rowsA, int columnsA, int matrixA[rowsA][columnsA], const int matrixB[rowsA][columnsA], const char operationType);
void transposeMatrix(int rows, int columns, int matrix[rows][columns], const char matrixType);

// print menu layout
void printMenu()
{
  printf("Matrix Operations Menu: \n");
  printf("1. Add Matrices\n");
  printf("2. Subtract Matrices\n");
  printf("3. Transpose Matrix A\n");
  printf("4. Transpose Matrix B\n");
  printf("5. Exit\n");
}

// add / subtract 2 matrix
void matrixOperation(int rowsA, int columnsA, int matrixA[rowsA][columnsA], const int matrixB[rowsA][columnsA], const char operationType)
{
  // create a temp Matrix
  int tempMatrix[rowsA][columnsA];

  if (operationType == '+')
  {
    for (int i = 0; i < rowsA; i++)
    {
      for (int j = 0; j < columnsA; j++)
      {
        tempMatrix[i][j] = matrixA[i][j] + matrixB[i][j];
      }
    }
  }
  else if (operationType == '-')
  {
    for (int i = 0; i < rowsA; i++)
    {
      for (int j = 0; j < columnsA; j++)
      {
        tempMatrix[i][j] = matrixA[i][j] - matrixB[i][j];
      }
    }
  }

  printf("Result of Matrix A %c Matrix B: \n", operationType);
  for (int i = 0; i < rowsA; i++)
  {
    for (int j = 0; j < columnsA; j++)
    {
      printf("%d ", tempMatrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

// transpose matrix
void transposeMatrix(int rows, int columns, int matrix[rows][columns], const char matrixType)
{
  // Create a temporary matrix for the transpose
  int tempMatrix[columns][rows];

  // Compute the transpose
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      tempMatrix[j][i] = matrix[i][j];
    }
  }

  // Print the transposed matrix
  printf("Transpose of Matrix %c:\n", matrixType);
  for (int i = 0; i < columns; i++)
  {
    for (int j = 0; j < rows; j++)
    {
      printf("%d ", tempMatrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

// allow user to input the size of the Matrix
int rowsA = 0;
int columnsA = 0;
int rowsB = 0;
int columnsB = 0;

int main()
{

  while (1)
  {
    // first Matrix
    printf("Enter dimensions for Matrix A (rows and columns): ");
    scanf("%d %d", &rowsA, &columnsA);

    // error handling for rowsA and columnsA(not more than 10)
    if (rowsA > MAX_MATRIX && columnsA > MAX_MATRIX)
    {
      printf("Maximum matrix size is 10X10\n");
      continue;
    }

    if (rowsA > MAX_MATRIX || columnsA > MAX_MATRIX)
    {
      printf("Maximum matrix row's size is 10\n");
      continue;
    }

    if (rowsA < 1 || columnsA < 1)
    {
      printf("Minimum matrix row's size is 1\n");
      continue;
    }
    // if size is within the range exit the loop
    break;
  }

  int matrixA[rowsA][columnsA];
  printf("Enter elements for Matrix A:\n");

  for (int i = 0; i < rowsA; i++)
  {
    for (int j = 0; j < columnsA; j++)
    {
      printf("Element [%d][%d]: ", i + 1, j + 1);
      scanf("%d", &matrixA[i][j]);
    }
  }

  while (1)
  {
    // first Matrix
    printf("Enter dimensions for Matrix B (rows and columns): ");
    scanf("%d %d", &rowsB, &columnsB);

    // error handling for rowsA and columnsA(not more than 10)
    if (rowsB > MAX_MATRIX && columnsB > MAX_MATRIX)
    {
      printf("Maximum matrix size is 10X10\n");
      continue;
    }

    if (rowsA > MAX_MATRIX || columnsA > MAX_MATRIX)
    {
      printf("Maximum matrix row's size is 10\n");
      continue;
    }

    if (rowsA < 1 || columnsA < 1)
    {
      printf("Minimum matrix row's size is 1\n");
      continue;
    }
    // if size is within the range exit the loop
    break;
  }

  int matrixB[rowsB][columnsB];
  printf("Enter elements for Matrix B:\n");

  for (int i = 0; i < rowsB; i++)
  {
    for (int j = 0; j < columnsB; j++)
    {
      printf("Element [%d][%d]: ", i + 1, j + 1);
      scanf("%d", &matrixB[i][j]);
    }
  }

  while (1)
  {
    // operation menu
    printMenu();

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1: // add
      // see if two matrix size is same or not, if not then print error
      if (rowsA != rowsB || columnsA != columnsB)
      {
        printf("Matrix's size is not compatible.\n\n");
        break;
      }
      matrixOperation(rowsA, columnsA, matrixA, matrixB, '+');
      break;
    case 2: // subtract
      // see if two matrix size is same or not, if not then print error
      if (rowsA != rowsB || columnsA != columnsB)
      {
        printf("Matrix's size is not compatible.\n\n");
        break;
      }
      matrixOperation(rowsA, columnsA, matrixA, matrixB, '-');
      break;
    case 3: // transpose Matrix A
      transposeMatrix(rowsA, columnsA, matrixA, 'A');
      break;
    case 4: // transpose Matrix B
      transposeMatrix(rowsB, columnsB, matrixB, 'B');
      break;
    case 5: // Exit
      printf("Exiting...");
      exit(0); // exit with success code
      break;
    default:
      printf("Invalid input...\n");
      break;
    }
  }

  return 0;
}