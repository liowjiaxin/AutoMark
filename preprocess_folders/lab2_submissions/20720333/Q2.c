#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 50
#define STUDENT_COUNT 3

float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count);

int main() {
    char names[STUDENT_COUNT][NAME_LENGTH];
    float marks[STUDENT_COUNT];
    int count;

    for (count = 0; count < STUDENT_COUNT; count++) {
        printf("Enter the name of student %d: ", count + 1);
        fgets(names[count], NAME_LENGTH, stdin);
        names[count][strcspn(names[count], "\n")] = 0;

        printf("Enter the mark of student %d: ", count + 1);
        scanf("%f", &marks[count]);

        while (getchar() != '\n');
    }

    float average = calculateAverage(marks, STUDENT_COUNT);
    displayStudentData(names, marks, STUDENT_COUNT);
    printf("\nThe average mark is: %.2f\n", average);

    return 0;
}

float calculateAverage(const float marks[], int count) {
    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }
    return sum / count;
}

void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count) {
    printf("\nStudent Names and Marks:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %.2f\n", names[i], marks[i]);
    }
}
