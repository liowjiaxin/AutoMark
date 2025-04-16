#include <stdio.h>
#define MAX_SIZE 10 // Define maximum size of the matrix

// Function prototypes
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int *rows, int *columns, char name);
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int columns);
void addMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int rows, int columns);
void subMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int rows, int columns);
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int columns, char name);

int main() {
	int rowsA, columnsA, rowsB, columnsB;
	int matrixA[MAX_SIZE][MAX_SIZE] = {0};
	int matrixB[MAX_SIZE][MAX_SIZE] = {0};
	int choice;
	
	inputMatrix(matrixA, &rowsA, &columnsA, 'A'); // input Matrix A
	inputMatrix(matrixB, &rowsB, &columnsB, 'B'); // input Matrix B

	// Main menu
	do {
		printf("\nMatrix Operations Menu:\n");
		printf("1. Add Matrices\n");
		printf("2. Subtract Matrices\n");
		printf("3. Transpose Matrix A\n");
		printf("4. Transpose Matrix B\n");
		printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

		// handle user choice using switch case
		switch (choice) {
		case 1:
			// add matrices if they have the same dimension
			if (rowsA == rowsB && columnsA == columnsB) { 
				addMatrices(matrixA, matrixB, rowsA, columnsA);
			}
			else {
				printf("Matrices must have the same dimension to be added.\n");
			}
			break;
		case 2:
			// subtract matrices if they have the same dimension
			if (rowsA == rowsB && columnsA == columnsB) {
				subMatrices(matrixA, matrixB, rowsA, columnsA);
			}
			else {
				printf("Matrices must have the same dimension to be subtracted.\n");
			}
			break;
		case 3:
			transposeMatrix(matrixA, rowsA, columnsA, 'A'); // transpose Matrix A
			break;
		case 4:
			transposeMatrix(matrixB, rowsB, columnsB, 'B'); // transpose Matrix B
			break;
        case 5:
            printf("Exiting...\n");
            break;
		default:
			printf("Invalid choice. Please enter again.\n");
		} 

	} while (choice != 5);

	return 0;
}

// Function to input a matrix
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int *rows, int *columns, char name){
	// Prompt the user to enter dimension of matrix
	do {
		printf("Enter dimensions for Matrix %c (rows and columns): ", name);
		scanf("%d %d", rows, columns);

		// Check if the matrix size exceed the maximum size allowed
		if (*rows > MAX_SIZE || *columns > MAX_SIZE) {
			printf("Matrix size exceeds the maximum size (%dx%d).\n", MAX_SIZE, MAX_SIZE);
			printf("Please enter again.\n");
		}
	} while (*rows > MAX_SIZE || *columns > MAX_SIZE);

	// Prompt the user to enter elements for the matrix
	printf("Enter elements for Matrix %c:\n", name);
	for (int i = 0; i < *rows; i++) { // outer loop control rows
		for (int j = 0; j < *columns; j++) { // inner loop control columns
			printf("Elements [%d][%d]: ", i+1, j+1);
			scanf("%d", &matrix[i][j]);
		}
	}
}

// Function to print matrices
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			printf("%-3d", matrix[i][j]);
		}
        printf("\n");
	} 
}

// Function to add matrices
void addMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int rows, int columns) {
	int result[MAX_SIZE][MAX_SIZE];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			result[i][j] = matrixA[i][j] + matrixB[i][j];
		}
	}
	printf("Result of Matrix A + Matrix B:\n");
	printMatrix(result, rows, columns);
}

// Function to subtract matrices
void subMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int rows, int columns) {
	int result[MAX_SIZE][MAX_SIZE];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			result[i][j] = matrixA[i][j] - matrixB[i][j];
		}
	}
	printf("Result of Matrix A - Matrix B:\n");
	printMatrix(result, rows, columns);
}

// Function to transpose matrix
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int columns, char name) {
	int result[MAX_SIZE][MAX_SIZE];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			result[j][i] = matrix[i][j]; // swap rows and columns
		}
	}
	printf("Transpose of Matrix %c:\n", name);
	printMatrix(result, columns, rows); 
}