#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define NUM_STUDENTS 3
#define NAME_LENGTH 50

// Function to calculate the average mark
float calculateAverage(const float marks[], int count) {
    float sum = 0;

    for (int i = 0; i < count; i++) {
        sum += marks[i];  // Add each student's marks
    }

    return sum / count;  // Return the average
}

// Function to display student names and marks
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]) {
    printf("\nStudent Data:\n");
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Name: %s, Marks: %.2f\n", names[i], marks[i]);
    }
}

int main() {
    char names[NUM_STUDENTS][NAME_LENGTH];  // Array to store student names
    float marks[NUM_STUDENTS];               // Array to store student marks

    // Input student names and marks
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]); // Read the name with spaces

        printf("Enter the marks for %s: ", names[i]);
        scanf("%f", &marks[i]);  // Read the marks
    }

    // Calculate the average mark
    float average = calculateAverage(marks, NUM_STUDENTS);

    // Display student data and the average mark
    displayStudentData(names, marks);
    printf("Average mark: %.2f\n", average);

    return 0;
}
