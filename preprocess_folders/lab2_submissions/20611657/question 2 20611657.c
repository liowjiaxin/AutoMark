#include <stdio.h>
#include <string.h>

#define NUM_STUDENTS 3
#define NAME_LENGTH 50

// Function prototypes
float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count);

int main() {
    char names[NUM_STUDENTS][NAME_LENGTH];
    float marks[NUM_STUDENTS];
    float average;

    // Collect names and marks from the user
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]); // Read full name including spaces
        printf("Enter the mark of student %d: ", i + 1);
        scanf("%f", &marks[i]);
    }

    // Calculate the average marks
    average = calculateAverage(marks, NUM_STUDENTS);

    // Display the results
    printf("\nStudent Names and Marks:\n");
    displayStudentData(names, marks, NUM_STUDENTS);

    // Print the average
    printf("\nAverage Mark: %.2f\n", average);

    return 0;
}

// Function to calculate the average of marks
float calculateAverage(const float marks[], int count) {
    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }
    return sum / count;
}

// Function to display student names and marks
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%s: %.2f\n", names[i], marks[i]);
    }
}
