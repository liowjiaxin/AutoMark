#include <stdio.h>

#define NUM_STUDENTS 3
#define NAME_LENGTH 50

// Function prototypes
float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count, float average);

int main() {
    char names[NUM_STUDENTS][NAME_LENGTH];  // Array to store student names
    float marks[NUM_STUDENTS];              // Array to store student marks
    float average;

    // Prompt user to enter names and marks
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Enter the name of student %d: ", i+1);
        scanf(" %[^\n]", names[i]);  // Read the full name
        printf("Enter the mark of student %d: ", i+1);
        scanf("%f", &marks[i]);     // Read the marks
    }

    // Calculate average mark
    average = calculateAverage(marks, NUM_STUDENTS);

    // Display the data
    displayStudentData(names, marks, NUM_STUDENTS, average);

    return 0;
}

// Function to calculate the average of marks
float calculateAverage(const float marks[], int count) {
    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }
    return sum / count;
}

// Function to display student names, marks, and the average
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count, float average) {
    printf("\nStudent Names and Marks:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %.2f\n", names[i], marks[i]);
    }
    printf("\nAverage Marks: %.2f\n", average);
}
