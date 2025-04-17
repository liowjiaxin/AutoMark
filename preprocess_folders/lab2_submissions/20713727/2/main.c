#include <stdio.h>
#define STUDENT_COUNT 3
#define NAME_LENGTH 50

// Function prototypes
float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count);

int main() {
    char names[STUDENT_COUNT][NAME_LENGTH];
    float marks[STUDENT_COUNT];
    float average;

    // Prompt the user to enter student names and marks
    for (int i = 0; i < STUDENT_COUNT; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]);
        printf("Enter the mark of student %d：", i + 1);
        scanf("%f", &marks[i]);
    }

    average = calculateAverage(marks, STUDENT_COUNT);

    // Display the student data and average mark
    displayStudentData(names, marks, STUDENT_COUNT);
    printf("Average Mark: %.2f\n", average);

    return 0;
}

// Function to calculate the average mark
float calculateAverage(const float marks[], int count) {
    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }
    return sum / count;
}

// Function to display student names, marks, and the average mark
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count) {
    printf("\nStudent Name and Marks:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Marks: %.2f\n", names[i], marks[i]);
    }
}
