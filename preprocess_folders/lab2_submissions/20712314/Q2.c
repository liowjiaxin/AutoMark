#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NAME_LENGTH 50

// Function prototypes
void getStudentData(char names[3][NAME_LENGTH], float marks[3]);
float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[3][NAME_LENGTH], const float marks[], int count, float average);

int main() {
    char names[3][NAME_LENGTH];
    float marks[3];

    getStudentData(names, marks);

    float average = calculateAverage(marks, 3);

    displayStudentData(names, marks, 3, average);

    return 0;
}

void getStudentData(char names[3][NAME_LENGTH], float marks[3]) {
    for (int i = 0; i < 3; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]);
        printf("Enter the mark of student %d: ", i + 1);
        scanf("%f", &marks[i]);
    }
}

float calculateAverage(const float marks[], int count) {
    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }
    return sum / count;
}

void displayStudentData(const char names[3][NAME_LENGTH], const float marks[], int count, float average) {
    printf("\n\nStudent Names and Marks:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %.2f\n", names[i], marks[i]);
    }
    printf("\nAverage Mark: %.2f\n", average);
}
