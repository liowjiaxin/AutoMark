#include <stdio.h>

#define NAME_LENGTH 50
#define STUDENT_COUNT 3

// List the function prototypes
float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count);

int main() {
    char names[STUDENT_COUNT][NAME_LENGTH];
    float marks[STUDENT_COUNT];

    // Request user input for names and marks of three students
    for (int i = 0; i < STUDENT_COUNT; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]); // Read full name with spaces
        printf("Enter the marks of %s: ", names[i]);
        scanf("%f", &marks[i]); // Accept marks as input 
    }

    // Compute the average of the marks 
    float average = calculateAverage(marks, STUDENT_COUNT);

    // Display student data and the computer average 
    displayStudentData(names, marks, STUDENT_COUNT);
    printf("Average marks: %.2f\n", average);

    return 0;
}

// Function to find the average of the given marks 
float calculateAverage(const float marks[], int count) {
    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }
    return sum / count;
}

// Create a function to display names, marks, and the average
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count) {
    printf("\nStudent Data:\n");
    for (int i = 0; i < count; i++) {
        printf("Student %d: %s - Marks: %.2f\n", i + 1, names[i], marks[i]);
    }
}
