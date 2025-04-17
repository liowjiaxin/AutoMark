#include <stdio.h>
#define NAME_LENGTH 80
#define STUDENT_COUNT 3

// Function to calculate the average mark of the students
float calculateAverage(const float marks[], int count);

// Function to display the student data
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], float average);

int main() {
    char names[STUDENT_COUNT][NAME_LENGTH];
    float marks[STUDENT_COUNT];

    // Ask the user to enter student names and marks
    for (int i = 0; i < STUDENT_COUNT; i++) {
        printf("Enter the name of Student %d: ", i + 1);
        scanf(" %[^\n]", names[i]);
        printf("Enter the mark of Student %d: ", i + 1);
        scanf("%f", &marks[i]);
    }

    // Calculating the average mark
    float average = calculateAverage(marks, STUDENT_COUNT);

    // Display student data
    displayStudentData(names, marks, average);

    return 0;
}

// Function to calculate the average mark
float calculateAverage(const float marks[], int count) {
    float sum = 0.0f;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }
    return sum / count;
}

// Function to display the data of the students
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], float average) {
    printf("\nStudent Names and Marks:\n");
    for (int i = 0; i < STUDENT_COUNT; i++) {
        printf("Student %d: %s - Mark: %.2f\n", i + 1, names[i], marks[i]);
    }
    printf("Average Mark: %.2f\n", average);
}