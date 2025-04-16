#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXIMUM_SIZE 100

int validation(int row, int column) {
    if(row > 0 && row <= 10 && column > 0 && column <=10) {
        return 1;
    }
    return 0;
}

void present(int *result, int row, int column){
    for (int i = 0; i < row * column; i++) {
        printf("%d ", result[i]);
        if ((i + 1) % row == 0) {
            printf("\n");
        }
    }
}

void Print_Menu(int a) {
    printf("Matrix Operations Menu:\n");
    if (a == 1) {
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
    }
    else {
        printf("1. Transpose Matrix A\n");
        printf("2. Transpose Matrix B\n");
        printf("3. Exit\n");
    }
}

void add(int result[], int A[], int B[], int row, int column) {
    for (int i = 0; i < row * column; i++) {
        result[i] = A[i] + B[i];
    }
}

void subtract(int result[], int A[], int B[], int row, int column) {
    for (int i = 0; i < row *column; i++) {
        result[i] = A[i] - B[i];
    }
}

void Transpose(int *matrix, int row_matrix, int column_matrix) {
    for (int i = 0; i < column_matrix; i++) {
        for (int j = 0; j < row_matrix; j++) {
            printf("%d ", matrix[j * column_matrix + i]);
        }
        printf("\n");
    }
}

int main() {
    int rowA, rowB, columnA, columnB, choice, ch;
    int A[MAXIMUM_SIZE], B[MAXIMUM_SIZE], result[MAXIMUM_SIZE];
    do {
        printf("Enter dimensions for Matrix A(rows and columns): ");
        scanf(" %d %d", &rowA, &columnA);
        while((ch = getchar()) != '\n' && ch != EOF){}
    }
    while (validation(rowA, columnA) == 0);
    printf("Enter elements for Matrix A:\n");
    for (int i = 0; i < rowA * columnA; i++) {
        printf("Element[%d][%d]:", ((i - (i % rowA)) / rowA) + 1, (i % rowA) + 1);
        scanf(" %d", &A[i]);
    }
    do {
        printf("Enter dimensions for Matrix B(rows and columns): ");
        scanf("%d %d", &rowB, &columnB);
        while((ch = getchar()) != '\n' && ch != EOF){}
    }
    while (validation(rowB, columnB) == 0);
    printf("Enter elements for Matrix B:\n");
    for (int i = 0; i < rowB * columnB; i++) {
        printf("Element[%d][%d]:", ((i - (i % rowB)) / rowB) + 1, (i % rowB) + 1);
        scanf(" %d", &B[i]);
    }
    for (int i = 0; i < rowA * columnA; i++) {
        printf("%d ", A[i]);
        if ((i + 1) % rowA == 0) {
            printf("\n");
        }
}
    int same = 0;
    if (rowA == rowB && columnA == columnB) {
        same = 1;
    }
    if (same == 1) {
        while (1) {
            Print_Menu(same);
            printf("Enter your choice:");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                add(result, A, B, rowA, columnA);
                present(result, rowA, columnA);
                break;
            case 2:
                subtract(result, A, B, rowA, columnA);
                present(result, rowA, columnA);
                break;
            case 3:
                Transpose(A, rowA, columnA);
                break;
            case 4:
                Transpose(B, rowB, columnB);
                break;
            case 5:
                return 0;
            default:
                break;
            }

        }
    } else {
        while (1) {
            Print_Menu(same);
            printf("Enter your choice:");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                Transpose(A, rowA, columnA);
                break;
            case 2:
                Transpose(B, rowB, columnB);
                break;
            case 3:
                return 0;
            default:
                break;
            
            }
        }
    }
}