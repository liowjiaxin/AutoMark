#include <stdio.h>
#define Rows_Size 10
#define Colomns_Size 10

int first[Rows_Size][Colomns_Size];
int second[Rows_Size][Colomns_Size];
int sum[Rows_Size][Colomns_Size];
int substact[Rows_Size][Colomns_Size];
int transposeA[Colomns_Size][Rows_Size];
int transposeB[Colomns_Size][Rows_Size];
int r, c, option;

void Keyin();
void Add_Matrices();
void Substact_Matrices();
void Transpose_Matrix_A();
void Transpose_Matrix_B();

int main() {
    Keyin();
    while (1) {
        printf("\nMatrix Operations Menu\n");
        printf("1. Add Matrices\n");
        printf("2. Substract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                Add_Matrices();
                break;
            case 2:
                Substact_Matrices();
                break;
            case 3:
                Transpose_Matrix_A();
                break;
            case 4:
                Transpose_Matrix_B();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice...\n");
                break;
        }
    }
    return 0;
}

void Keyin() {
    int i, j;
    printf("\nEnter the dimensions of Matrix A (rows and columns): \n");
    scanf("%d %d", &r, &c);

    printf("Enter the elements for Matrix A: \n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("Element [%d][%d] :", i + 1, j + 1);
            scanf("%d", &first[i][j]);
        }
    }

    printf("Enter the elements for Matrix B: \n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("Element [%d][%d] :", i + 1, j + 1);
            scanf("%d", &second[i][j]);
        }
    }
}

void Add_Matrices() {
    int i, j;
    printf("Result of Matrix A + Matrix B:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            sum[i][j] = first[i][j] + second[i][j];
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
}

void Substact_Matrices() {
    int i, j;
    printf("Result of Matrix A - Matrix B:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            substact[i][j] = first[i][j] - second[i][j];
            printf("%d ", substact[i][j]);
        }
        printf("\n");
    }
}

void Transpose_Matrix_A() {
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            transposeA[j][i] = first[i][j];
        }
    }
    printf("Transpose of Matrix A:\n");
    for (i = 0; i < c; i++) {
        for (j = 0; j < r; j++) {
            printf("%d ", transposeA[i][j]);
        }
        printf("\n");
    }
}

void Transpose_Matrix_B() {
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            transposeB[j][i] = second[i][j];
        }
    }
    printf("Transpose of Matrix B:\n");
    for (i = 0; i < c; i++) {
        for (j = 0; j < r; j++) {
            printf("%d ", transposeB[i][j]);
        }
        printf("\n");
    }
}

    


 


