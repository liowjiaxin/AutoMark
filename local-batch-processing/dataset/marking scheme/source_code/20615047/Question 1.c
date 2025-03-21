#include <stdio.h>

// Function prototypes
void addition(int a, int b, int ElementA[10][10], int c, int d, int ElementB[10][10]);
void subtract(int a, int b, int ElementA[10][10], int c, int d, int ElementB[10][10]);
void transposeA(int a, int b, int ElementA[10][10]);
void transposeB(int c, int d, int ElementB[10][10]);

int main(void) {
    int a, b, c, d;

    // Input dimensions for Matrix A
    printf("Enter dimensions for Matrix A (rows and columns, max 10x10): ");
    scanf("%d %d", &a, &b);
    while (1) {    
    if (a > 10 || b > 10 || a <= 0 || b <= 0) {
        printf("Invalid dimensions for Matrix A. Enter Again: \n");
        scanf("%d %d", &a, &b);
        continue;
    }
    break; }

    int ElementA[a][b];

    // Input elements for Matrix A
    printf("Enter elements for Matrix A:\n");
    for (int x = 0; x < a; x++) {
        for (int y = 0; y < b; y++) {
            printf("Element [%d][%d]: ", x + 1, y + 1);
            scanf("%d", &ElementA[x][y]);
        }
    }

    // Input dimensions for Matrix B
    printf("Enter dimensions for Matrix B (rows and columns, max 10x10): ");
    scanf("%d %d", &c, &d);
    while (1) {
    if (c > 10 || d > 10 || c <= 0 || d <= 0) {
        printf("Invalid dimensions for Matrix B. Enter Again: \n");
        scanf("%d %d", &c, &d);
        continue;
    }
    break; }

    int ElementB[c][d];

    // Input elements for Matrix B
    printf("Enter elements for Matrix B:\n");
    for (int x = 0; x < c; x++) {
        for (int y = 0; y < d; y++) {
            printf("Element [%d][%d]: ", x + 1, y + 1);
            scanf("%d", &ElementB[x][y]);
        }
    }

    int choice = 0;
    do {
        // Menu
        printf("\nMatrix Operation Menu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addition(a, b, ElementA, c, d, ElementB);
                break;

            case 2:
                subtract(a, b, ElementA, c, d, ElementB);
                break;

            case 3:
                transposeA(a, b, ElementA);
                break;

            case 4:
                transposeB(c, d, ElementB);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to add matrices
void addition(int a, int b, int ElementA[a][b], int c, int d, int ElementB[c][d]) {
    if (a != c || b != d) {
        printf("Matrices dimensions do not match for addition.\n");
        return;
    }

    int result[10][10];
    printf("\nResult of Matrix A + Matrix B:\n");
    for (int x = 0; x < a; x++) {
        for (int y = 0; y < b; y++) {
            result[x][y] = ElementA[x][y] + ElementB[x][y];
            printf("%d ", result[x][y]);
        }
        printf("\n");
    }
}

// Function to subtract matrices
void subtract(int a, int b, int ElementA[a][b], int c, int d, int ElementB[c][d]) {
    if (a != c || b != d) {
        printf("Matrices dimensions do not match for subtraction.\n");
        return;
    }

    int result[10][10];
    printf("\nResult of Matrix A - Matrix B:\n");
    for (int x = 0; x < a; x++) {
        for (int y = 0; y < b; y++) {
            result[x][y] = ElementA[x][y] - ElementB[x][y];
            printf("%d ", result[x][y]);
        }
        printf("\n");
    }
}

// Function to transpose Matrix A
void transposeA(int a, int b, int ElementA[a][b]) {
    printf("\nTranspose of Matrix A:\n");
    for (int x = 0; x < b; x++) {
        for (int y = 0; y < a; y++) {
            printf("%d ", ElementA[y][x]);
        }
        printf("\n");
    }
}

// Function to transpose Matrix B
void transposeB(int c, int d, int ElementB[c][d]) {
    printf("\nTranspose of Matrix B:\n");
    for (int x = 0; x < d; x++) {
        for (int y = 0; y < c; y++) {
            printf("%d ", ElementB[y][x]);
        }
        printf("\n");
    }
}