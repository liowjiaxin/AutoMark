#include <stdio.h>
#define NUM_STUDENTS 3
#define NAME_LENGTH 50

// function prototypes
float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]); // NAME_LENGTH 50

int main() {
    char names[NUM_STUDENTS][NAME_LENGTH];
    float marks[NUM_STUDENTS];

    // Input student names and marks
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf_s(" %[^\n]", names[i], NAME_LENGTH); 
        printf("Enter marks of student %d: ", i + 1);
        scanf_s("%f", &marks[i]);
    }

    // Calculate average
    float average = calculateAverage(marks, NUM_STUDENTS);

    // Display student names and marks
    printf("\nStudents Names and Marks:\n");
    displayStudentData(names, marks);

    // Display average mark
    printf("\nAverage Mark: %.2f\n", average);

    return 0;
}

// Function to calculate average
float calculateAverage(const float marks[], int count) {
    float sum = 0.0;

    // calculate sum of the marks of students
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }

    // Calculate and return the average
    return sum / count;
}

// Function to display students names and marks
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]) {

    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("%s: %.2f\n", names[i], marks[i]);
    }
}
