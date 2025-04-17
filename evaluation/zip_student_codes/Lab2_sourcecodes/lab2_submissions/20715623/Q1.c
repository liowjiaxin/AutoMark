#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main1()//When using, remove the redundant characters in the file so as not to affect the program
{
    int N;

    // 提示用户输入数组大小
    printf("Enter the size of the array (N >= 5): ");
    scanf("%d", &N);

    while (N < 5) 
    {
        printf("Invalid size! Please enter a size N >= 5: ");
        scanf("%d", &N);
    }
    
    // 动态分配数组内存
    int* arr = (int*)malloc(N * sizeof(int));
    if (arr == NULL) 
    {
        printf("Memory allocation failed!\n");
        return 1; // 错误退出
    }
    // 输入数组元素
    printf("Enter the array elements:\n");
    for (int i = 0; i < N; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int index1, index2;

    // 输入并验证两个索引
    printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", N);
    scanf("%d %d", &index1, &index2);

    while (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N) {
        printf("Error: Indices must be within the range of the array elements. Please try again.\n");
        printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", N);
        scanf("%d %d", &index1, &index2);
    }

    // 计算并打印结果
    int sum = *(arr + index1) + *(arr + index2);
    printf("The sum of the values at indices %d and %d is: %d\n", index1, index2, sum);

    return 0;


}