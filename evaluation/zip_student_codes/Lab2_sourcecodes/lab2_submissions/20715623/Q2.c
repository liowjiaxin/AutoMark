#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define NAME_LENGTH 50
#define STUDENT_COUNT 3

// 函数原型
float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count, float average);

int main2()//When using, remove the redundant characters in the file so as not to affect the program 
{
    char names[STUDENT_COUNT][NAME_LENGTH]; // 存储学生姓名
    float marks[STUDENT_COUNT]; // 存储学生成绩
    float average;

    // 输入学生姓名和成绩
    for (int i = 0; i < STUDENT_COUNT; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]); 
        printf("Enter the mark of student %d: ", i + 1);
        scanf("%f", &marks[i]);
    }

    // 计算平均成绩
    average = calculateAverage(marks, STUDENT_COUNT);

    // 显示学生数据和平均成绩
    displayStudentData(names, marks, STUDENT_COUNT, average);

    return 0;
}

// 计算平均分函数
float calculateAverage(const float marks[], int count) {
    float sum = 0.0;

    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }

    return sum / count;
}

// 显示学生数据和平均分函数
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count, float average) {
    printf("\nStudent Names and Marks:\n");

    for (int i = 0; i < count; i++) {
        printf("%s: %.2f\n", names[i], marks[i]);
    }

    printf("\nAverage Mark: %.2f\n", average);
}