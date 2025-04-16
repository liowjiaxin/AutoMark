#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void subtractMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int transposed[MAX_SIZE][MAX_SIZE], int rows, int cols);

int main() {
	int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
	int rowsA,colsA, rowsB, colsB;
	int choice;

	printf("Enter dimensions for Matrix A (rows and columns): ");
	scanf("%d %d", &rowsA, &colsA);
//matrix dimensions validation for A
	while (rowsA>MAX_SIZE||colsA>MAX_SIZE||rowsA<=0||colsA<=0) {
		printf("Invalid dimensions. Exiting!\n");
		scanf("%d %d",&rowsA,&colsA);
	}
	printf("Enter elements for Matrix A:\n");
	inputMatrix(A,rowsA,colsA);

	printf("Enter dimensions for Matrix B (rows and columns): ");
	scanf("%d %d", &rowsB, &colsB);
//matrix dimensions validation for B
	while(rowsB>MAX_SIZE||colsB>MAX_SIZE||rowsB<=0||colsB<=0)  {
		printf("Invalid dimensions. Exiting!\n");
		scanf("%d %d",&rowsB,&colsB);
	}
	printf("Enter elements for Matrix B:\n");
	inputMatrix(B,rowsB,colsB);

	do {
		printf("\nMatrix Operations Menu:\n");
		printf("1. Add Matrices\n");
		printf("2. Subtract Matrices\n");
		printf("3. Transpose Matrix A\n");
		printf("4. Transpose Matrix B\n");
		printf("5. Exit\n");
		printf("Enter your choice:");
		scanf("%d",&choice);

		switch(choice) {
		case 1://add
			if(rowsA==rowsB&&colsA==colsB) {
				addMatrices(A,B,result,rowsA,rowsB);
				printf("Result of Matrix A + Matrix B:\n");
				displayMatrix(result,rowsA,colsA);
			} else {
				printf("Error!Matrices must have the same dimensions for addition.\n");
			}
			break;

		case 2://subtract
			if(rowsA==rowsB&&colsA==colsB) {
				subtractMatrices(A,B,result,rowsA,rowsB);
				printf("Result of Matrix A - Matrix B:\n");
				displayMatrix(result,rowsA,colsA);
			} else {
				printf("Error!Matrices must have the same dimensions for suntraction.\n");
			}
			break;

		case 3://transpose for A
			transposeMatrix(A,result,rowsA,colsA);
			printf("Transpose of Matrix A:\n");
			displayMatrix(result,colsA,rowsA);
			break;

		case 4://transpose for B
			transposeMatrix(B,result,rowsB,colsB);
			printf("Transpose of Matrix B:\n");
			displayMatrix(result,colsB,rowsB);
			break;

		case 5:
			printf("Exiting…\n");
			break;

		default:
			printf("Invalid choice!Please try again.\n");
		}
	} while (choice!=5);
	return 0;
}
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
	for (int i=0; i<rows; i++) {
		for(int j=0; j<cols; j++) {
			printf("Element [%d][%d]:",i+1,j+1);
			scanf("%d",&matrix[i][j]);
		}
	}
}
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
	for (int i=0; i<rows; i++) {
		for(int j=0; j<cols; j++) {
			printf("%d",matrix[i][j]);

		}
		printf("\n");
	}
}

void addMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
	for (int i=0; i<rows; i++) {
		for(int j=0; j<cols; j++) {
			result[i][j]=A[i][j]+B[i][j];
		}
	}
}

void subtractMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
	for (int i=0; i<rows; i++) {
		for(int j=0; j<cols; j++) {
			result[i][j]=A[i][j]-B[i][j];
		}
	}
}

void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int transposed[MAX_SIZE][MAX_SIZE], int rows, int cols) {
	for (int i=0; i<rows; i++) {
		for(int j=0; j<cols; j++) {
			transposed[j][i]=matrix[i][j];
		}
	}
}
