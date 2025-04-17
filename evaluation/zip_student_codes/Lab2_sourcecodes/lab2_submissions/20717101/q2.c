#include <stdio.h>

#define NUM_STUDENTS 3
#define NAME_LENGTH 50

// Function prototypes
float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count);

int main() {
    char names[NUM_STUDENTS][NAME_LENGTH];
    float marks[NUM_STUDENTS];
    int i;

    // Input student names and marks
    for (i = 0; i < NUM_STUDENTS; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]);  // Read name including spaces
        printf("Enter the mark of student %d: ", i + 1);
        scanf("%f", &marks[i]);
    }

    // Calculate average marks
    float average = calculateAverage(marks, NUM_STUDENTS);

    // Display student data and average marks
    displayStudentData(names, marks, NUM_STUDENTS);
    printf("Average Mark: %.2f\n", average);

    return 0;
}

// Function to calculate the average of the marks
float calculateAverage(const float marks[], int count) {
    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }
    return sum / count;
}

// Function to display student names, marks, and the average
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count) {
    printf("\nStudent Data:\n");
    for (int i = 0; i < count; i++) {
        printf("Student %d: %s, Mark: %.2f\n", i + 1, names[i], marks[i]);
    }
}
