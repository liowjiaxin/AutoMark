// Q1 Matrix Operations max size 10

#include <stdio.h>
#define MAX_SIZE 10

// Function to input matrix values
void inputM(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element at (%d, %d): ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display a matrix
void displayM(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addM(int rows, int cols, int a[rows][cols], int b[rows][cols], int r[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            r[i][j] = a[i][j] + b[i][j];
        }
    }
}

// Function to subtract two matrices
void SubtM(int rows, int cols, int a[rows][cols], int b[rows][cols], int r[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            r[i][j] = a[i][j] - b[i][j];
        }
    }
}

// Function to transpose a matrix
void TransM(int rows, int cols, int matrix[rows][cols], int result[cols][rows]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

int main() {
   int z, y, x, w;
   int a[MAX_SIZE][MAX_SIZE], b[MAX_SIZE][MAX_SIZE], r[MAX_SIZE][MAX_SIZE]; // Matrix[row][column]

   int choice;
   int valid = 0;

    do {
        printf("Enter dimensions of Matrix A (rows columns): ");
        scanf("%d %d", &z, &y);
        if (z > 10 || y > 10 || z <= 0 || y <= 0) {
            printf("Invalid input. Dimensions must be between 1 and 10.\n");
        }
    } 
    while (z > 10 || y > 10 || z <= 0 || y <= 0); //amke sure in range

    do {
        printf("Enter dimensions of Matrix B (rows columns): ");
        scanf("%d %d", &x, &w);
        if (x > 10 || w > 10 || x <= 0 || w <= 0) {
            printf("Invalid input. Dimensions must be between 1 and 10.\n");
        }
    } 
    while (x > 10 || w > 10 || x <= 0 || w <= 0);//amke sure in range

   // Input matrices
   printf("\nEnter values for matrix A:\n");
   inputM(z, y, a);
   printf("\nEnter values for matrix B:\n");
   inputM(x, w, b);

   // Display matrices
   printf("\nMatrix A:\n");
   displayM(z, y, a);
   printf("\nMatrix B:\n");
   displayM(x, w, b);

   while (1) {
      printf("\nMatrix Operations Window\n");
      printf("1. Add\n");
      printf("2. Subtract\n");
      printf("3. Transpose Matrix A\n");
      printf("4. Transpose Matrix B\n");
      printf("5. Exit\n");
      printf("\nEnter Choice: ");
      scanf("%d", &choice);

      // Validatation on input
      if (choice >= 1 && choice <= 5) {
          valid = 1;
      } 
      else {
          printf("Invalid choice. Please enter a number between 1 and 5.\n");
          valid = 0;
      }

       if (valid) {
         // Switch case for options
          switch (choice) {
              case 1: // Add
                  if (z != x || y != w) {
                     printf("Matrix dimensions must match for addition!\n");
                  } 
                  else {
                     addM(z, y, a, b, r);
                     printf("Matrix A + Matrix B:\n");
                     displayM(z, y, r);
                  }
                  break;

              case 2: // Subtract
                  if (z != x || y != w) {
                     printf("Matrix dimensions must match for subtraction!\n");
                  } 
                  else {
                     SubtM(z, y, a, b, r);
                     printf("Matrix A - Matrix B:\n");
                     displayM(z, y, r);
                  }
                  break;

               case 3: // Transpose A
                  {
                      int transposedA[MAX_SIZE][MAX_SIZE];  // Declare inside the case block
                      TransM(z, y, a, transposedA);
                      printf("Transpose of Matrix A:\n");
                      displayM(y, z, transposedA); // Transpose has swapped dimensions
                  }
                  break;

              case 4: // Transpose B
                  {
                      int transposedB[MAX_SIZE][MAX_SIZE];  // Declare inside the case block
                      TransM(x, w, b, transposedB);
                      printf("Transpose of Matrix B:\n");
                      displayM(w, x, transposedB); // Transpose has swapped dimensions
                  }
                  break;

              case 5: // Exit
                  printf("Exiting the program.\n");
                  return 0;

              default:
                  break;
          }
      }
   }

   return 0;
}
   
