#include <stdio.h>

#define NAME_LENGTH 50
#define STUDENT_COUNT 3

// Function prototypes
float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count);

int main() {
    // Array to store student names and marks
    char names[STUDENT_COUNT][NAME_LENGTH];
    float marks[STUDENT_COUNT];

    // Step 1: Prompt user to enter student names and marks
    for (int i = 0; i < STUDENT_COUNT; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]); // Read the full name, including spaces
        printf("Enter the mark of student %d: ", i + 1);
        scanf("%f", &marks[i]); // Read the student's mark
    }

    // Step 2: Calculate the average mark
    float average = calculateAverage(marks, STUDENT_COUNT);

    // Step 3: Display the student data and the average mark
    displayStudentData(names, marks, STUDENT_COUNT);
    printf("Average Mark: %.2f\n", average);

    return 0;
}

// Function to calculate the average mark
float calculateAverage(const float marks[], int count) {
    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += marks[i]; // Sum up all the marks
    }
    return sum / count; // Return the average
}

// Function to display student names, marks, and the average mark
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count) {
    printf("\nStudent Names and Marks:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %.2f\n", names[i], marks[i]); // Print each student's name and mark
    }
}
