#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define NAME_LENGTH 50
#define STUDENT_COUNT 3

float calculateAverage(const float marks[], int count) {
    float sum = 0;
    int i = 0;

    for (i = 0; i < count; i++) {
        sum += marks[i];
    }

    return sum / count;
}

void displayStudentData(const char names[][NAME_LENGTH], const float marks[]) {
    int i = 0;
    float avg = 0;

    printf("\nStudent Data:\n");
    for (i = 0; i < STUDENT_COUNT; i++) {
        printf("Student %d: %s\n", i + 1, names[i]);
        printf("Mark: %.2f\n", marks[i]);
    }

    avg = calculateAverage(marks, STUDENT_COUNT);
    printf("\nAverage Mark: %.2f\n", avg);
}

int main() {
    char names[STUDENT_COUNT][NAME_LENGTH] = { 0 };
    float marks[STUDENT_COUNT] = { 0 };
    int i = 0;
    char temp = 0;

    for (i = 0; i < STUDENT_COUNT; i++) {
        printf("Enter student %d name: ", i + 1);
        scanf("%c", &temp);
        scanf("%[^\n]", names[i]);

        printf("Enter mark for %s: ", names[i]);
        scanf("%f", &marks[i]);
    }

    displayStudentData(names, marks);

    return 0;
}