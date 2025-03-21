#include <stdio.h>
#include <stdlib.h>

// Declare prototype function
void showMenu();
int inputMatrixA(float matrix[50][50], int *row, int *column);
int inputMatrixB(float matrix[50][50], int *row, int *column);
void addMatrices(float matrixA[50][50], int *row, int *column, float matrixB[50][50], float sum[50][50]);
void substractMatrices(float matrixA[50][50], int *row, int *column, float matrixB[50][50], float sub[50][50]);
void transposeMatrixA(float matrix[50][50], int *row, int *column, float transpose[50][50]);
void transposeMatrixB(float matrix[50][50], int *row, int *column, float transpose[50][50]);

int main()
{
  // decalre global variables
    int rowA, columnA, rowB, columnB;
    float a[50][50], b[50][50], result[50][50], transposeA[50][50], transposeB[50][50];

    while(1){
        int validateA=inputMatrixA(a, &rowA, &columnA);
        if(validateA!=1){
            break;
        }
    }

    while(1){
        int validateB=inputMatrixB(b, &rowB, &columnB);
        if(validateB!=1 && rowA == rowB && columnA == columnB){
            break;
        } 
         else {
            printf("Error: Matrices must have the same dimensions for addition and subtraction.\n");
        }
    }

  while(1){
    showMenu();

    int decision;

    printf("Enter your choice: ");
    scanf("%d", &decision);
    getchar();

    // all main function going here
    switch (decision)
    {
    case 1: 
      addMatrices(a, &rowA, &columnA, b, result);
      break;
    case 2:
      substractMatrices(a, &rowA, &columnA, b, result);
      break;
    case 3: 
      transposeMatrixA(a, &rowA, &columnA, transposeA);
      break;
    case 4: 
      transposeMatrixB(b, &rowB, &columnB, transposeB);
      break;
    case 5: 
      printf("Exiting...\n");
      exit(0);
    default:
      printf("Invalid choice. \n");
      printf("Please enter a number between 1 to 5...\n");
      break;
    }
  }
    return 0;
}

// Landing page
void showMenu()
{
  printf("\nMatrix Operations Menu:\n");
  printf("1. Add Matrices\n");
  printf("2. Substract Matrices\n");
  printf("3. Transpose Matrix A\n");
  printf("4. Transpose Matrix B\n");
  printf("5. Exit\n");
}

int inputMatrixA(float matrix[50][50], int *row, int *column){

    printf("\nEnter dimensions for Matrix A (rows and columns): ");
    scanf ("%d %d", row, column);

    // validate the inputs
    if(*row<=0 || *column<=0){
        printf("Invalid inputs for dimensions !\n");
        return 1;
    }

  // taking input using nested for loop
    printf("Enter elements for Matrix A:\n");
    for (int i = 0; i < *row; ++i)
     for (int j = 0; j < *column; ++j)
    {
      printf("Element [%d][%d]: ", i + 1, j + 1);
      scanf("%f", &matrix[i][j]);
    }
    return 0;
}

int inputMatrixB(float matrix[50][50], int *row, int *column){

    printf("\nEnter dimensions for Matrix B (rows and columns): ");
    scanf ("%d %d", row, column);

    // validate the inputs
    if(*row<=0 || *column<=0){
        printf("Invalid inputs for dimensions !\n");
        return 1;
    }

    // taking input using nested for loop
    printf("Enter elements for Matrix B:\n");
    for (int i = 0; i < *row; ++i)
     for (int j = 0; j < *column; ++j)
    {
      printf("Element [%d][%d]: ", i + 1, j + 1);
      scanf("%f", &matrix[i][j]);
    }
    return 0;
}

void addMatrices(float matrixA[50][50], int *row, int *column, float matrixB[50][50], float sum[50][50]){
    for (int i = 0; i < *row; ++i)
    for (int j = 0; j < *column; ++j)
    {
      sum[i][j] = matrixA[i][j] + matrixB[i][j];
    }

  // Displaying the sum
    printf("\nResult of Matrix A + Matrix B:\n");

   for (int i = 0; i < *row; ++i){
    for (int j = 0; j < *column; ++j)
    {
      printf("%.1f\t", sum[i][j]);
    }
     printf("\n");
   }
}

void substractMatrices(float matrixA[50][50], int *row, int *column, float matrixB[50][50], float sub[50][50]){
    for (int i = 0; i < *row; ++i)
     for (int j = 0; j < *column; ++j)
    {
      sub[i][j] = matrixA[i][j] - matrixB[i][j];
    }

  // Displaying the substract
    printf("\nResult of Matrix A - Matrix B:\n");

   for (int i = 0; i < *row; ++i){
    for (int j = 0; j < *column; ++j)
    {
      printf("%.1f\t", sub[i][j]);
    }
     printf("\n");
   }
}

void transposeMatrixA(float matrix[50][50], int *row, int *column, float transpose[50][50]){
    
    // computing the transpose for matrix A
  for (int i = 0; i < *row; ++i)
  for (int j = 0; j < *column; ++j) {
    transpose[j][i] = matrix[i][j];
  }

  // printing the transpose
  printf("\nTranspose of the matrix A:\n");
  for (int i = 0; i < *column; ++i){
  for (int j = 0; j < *row; ++j) {
    printf("%.1f\t ", transpose[i][j]);
  }
     printf("\n");
  }
}

void transposeMatrixB(float matrix[50][50], int *row, int *column, float transpose[50][50]){
    
    // computing the transpose for matrix B
  for (int i = 0; i < *row; ++i)
  for (int j = 0; j < *column; ++j) {
    transpose[j][i] = matrix[i][j];
  }

  // printing the transpose
  printf("\nTranspose of the matrix B:\n");
  for (int i = 0; i < *column; ++i){
  for (int j = 0; j < *row; ++j) {
    printf("%.1f\t ", transpose[i][j]);
  }
     printf("\n");
  }
}