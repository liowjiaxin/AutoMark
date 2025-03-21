#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10

// 函数声明
void inputMatrix(int matrix[MAX][MAX], int rows, int cols); // 输入矩阵元素的函数
void printMatrix(int matrix[MAX][MAX], int rows, int cols); // 打印矩阵的函数
void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols); // 矩阵加法的函数
void subtractMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols); // 矩阵减法的函数
void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols); // 求矩阵转置的函数

int main1() //使用时删除main后的字符防程序无法运行
{
    int A[MAX][MAX], B[MAX][MAX]; // 矩阵A和B
    int rowsA, colsA, rowsB, colsB; // 矩阵A和B的维度
    int result[MAX][MAX]; // 存储结果的矩阵
    int choice; // 用户菜单选择变量

    // 输入矩阵A的维度
    printf("Enter the number of rows and columns for Matrix A (max 10x10): ");
    scanf("%d %d", &rowsA, &colsA);

    // 输入矩阵B的维度
    printf("Enter the number of rows and columns for Matrix B (max 10x10): ");
    scanf("%d %d", &rowsB, &colsB);

    // 验证矩阵维度是否合法
    if (rowsA > MAX || colsA > MAX || rowsB > MAX || colsB > MAX || rowsA <= 0 || colsA <= 0 || rowsB <= 0 || colsB <= 0)
    {
        printf("Invalid matrix dimensions. Please use dimensions between 1 and 10.\n");
        return 1; // 如果维度无效，则退出程序
    }

    // 输入矩阵A的元素
    printf("Enter elements for Matrix A:\n");
    inputMatrix(A, rowsA, colsA);

    // 输入矩阵B的元素
    printf("Enter elements for Matrix B:\n");
    inputMatrix(B, rowsB, colsB);

    // 矩阵操作的菜单驱动程序
    do 
    {
        printf("\nMatrix Operations Menu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
        case 1:
            // 矩阵A和B相加
            if (rowsA == rowsB && colsA == colsB) 
            {
                addMatrices(A, B, result, rowsA, colsA);
                printf("Result of Matrix A + Matrix B:\n");
                printMatrix(result, rowsA, colsA);
            }
            else 
            {
                printf("Addition not possible. Matrices must have the same dimensions.\n");
            }
            break;

        case 2:
            // 矩阵A和B相减
            if (rowsA == rowsB && colsA == colsB) 
            {
                subtractMatrices(A, B, result, rowsA, colsA);
                printf("Result of Matrix A - Matrix B:\n");
                printMatrix(result, rowsA, colsA);
            }
            else 
            {
                printf("Subtraction not possible. Matrices must have the same dimensions.\n");
            }
            break;

        case 3:
            // 矩阵A的转置
            transposeMatrix(A, result, rowsA, colsA);
            printf("Transpose of Matrix A:\n");
            printMatrix(result, colsA, rowsA);
            break;

        case 4:
            // 矩阵B的转置
            transposeMatrix(B, result, rowsB, colsB);
            printf("Transpose of Matrix B:\n");
            printMatrix(result, colsB, rowsB);
            break;

        case 5:
            // 退出程序
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5); // 循环直到用户选择退出

    return 0;
}

// 输入矩阵元素的函数
void inputMatrix(int matrix[MAX][MAX], int rows, int cols) 
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++) 
        {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// 打印矩阵的函数
void printMatrix(int matrix[MAX][MAX], int rows, int cols) 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]); // 打印每个元素
        }
        printf("\n"); // 换行
    }
}

// 矩阵加法的函数
void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols) 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            result[i][j] = A[i][j] + B[i][j]; // 对应元素相加
        }
    }
}

// 矩阵减法的函数
void subtractMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols) 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            result[i][j] = A[i][j] - B[i][j]; // 对应元素相减
        }
    }
}

// 求矩阵转置的函数
void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols) 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            result[j][i] = matrix[i][j]; // 行列交换
        }
    }
}
