QUESTION 2)

#include <stdio.h>

#define STUDENT_COUNT 3
#define NAME_LENGTH 50

// Function prototypes
float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]);

int main() {
    char names[STUDENT_COUNT][NAME_LENGTH];  // Array to store student names
    float marks[STUDENT_COUNT];              // Array to store student marks
    float average;                           // Variable to store the average mark

    // Step 1: Input student names and marks
    for (int i = 0; i < STUDENT_COUNT; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]);  // Read the name (allows spaces)
        printf("Enter the mark of student %d: ", i + 1);
        scanf("%f", &marks[i]);  // Read the mark as a float
    }

    // Step 2: Calculate the average mark
    average = calculateAverage(marks, STUDENT_COUNT);

    // Step 3: Display student names, marks, and average
    displayStudentData(names, marks);
    printf("Average Mark: %.2f\n", average);  // Print the average with 2 decimal places

    return 0;
}

// Function to calculate the average of marks
float calculateAverage(const float marks[], int count) {
    float sum = 0;

    // Sum all the marks
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }

    // Return the average
    return sum / count;
}

// Function to display student names and marks
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]) {
    printf("\nStudent Names and Marks:\n");

    // Loop through all students and print their name and mark
    for (int i = 0; i < STUDENT_COUNT; i++) {
        printf("%s: %.2f\n", names[i], marks[i]);
    }
}
