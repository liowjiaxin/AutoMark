#include <stdio.h>
#define NAME_LENGTH 50
#define STUDENT_COUNT 3

// Function to calculate the average of marks
float calculateAverage(const float marks[], int count) {
    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }
    return sum / count;
}

// Function to display student names, marks, and the average
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count) {
    printf("\nStudent Data:\n");
    for (int i = 0; i < count; i++) {
        printf("Student %d: %s, Marks: %.2f\n", i + 1, names[i], marks[i]);
    }
}

// Function prototypes
float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count);

int main() {
    char names[STUDENT_COUNT][NAME_LENGTH];  // Array to store student names
    float marks[STUDENT_COUNT];             // Array to store student marks

    // 1.Input student names and marks
    for (int i = 0; i < STUDENT_COUNT; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]);  // Read full name including spaces
        printf("Enter the marks of %s: ", names[i]);
        scanf("%f", &marks[i]);  // Read marks
    }

    // 2.Calculate the average mark
    float average = calculateAverage(marks, STUDENT_COUNT);

    // 3.Display student data and average
    displayStudentData(names, marks, STUDENT_COUNT);
    printf("\nThe average mark is: %.2f\n", average);

    return 0;
}
