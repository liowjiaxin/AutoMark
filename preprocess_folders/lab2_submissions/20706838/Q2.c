#include <stdio.h>

#define STUDENT_COUNT 3    // Number of students to be entered
#define NAME_LENGTH 50     // Maximum length of each student's name

// Function to calculate the average marks
float calculateAverage(const float marks[], int count) {
    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }
    return sum / count;
}

// Function to display student names, marks, and the average mark
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]) {
    printf("\nStudent Names and Marks:\n");
    for (int i = 0; i < STUDENT_COUNT; i++) {
        printf("%s: %.2f\n", names[i], marks[i]);
    }
}

int main() {
    char names[STUDENT_COUNT][NAME_LENGTH];  // Array to store the names of students 
    float marks[STUDENT_COUNT];             // Array to store the marks of students
    // Input the student names and marks
    for (int i = 0; i < STUDENT_COUNT; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]);  // Read full name including spaces
        printf("Enter the mark of student %d: ", i + 1);
        scanf("%f", &marks[i]);  // Read the mark
    }

    // Display the student names and marks
    displayStudentData(names, marks);

    // To calculate and display the average mark
    float average = calculateAverage(marks, STUDENT_COUNT);
    printf("\nAverage Mark: %.2f\n", average);

    return 0;
}
