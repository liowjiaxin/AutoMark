#include <stdio.h>

#define STUDENT_COUNT 3
#define NAME_LENGTH 50

// Function prototypes
float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count);

int main() {
    char names[STUDENT_COUNT][NAME_LENGTH];
    float marks[STUDENT_COUNT];
    int i;

    // Input student names and marks
    for (i = 0; i < STUDENT_COUNT; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]);  // Read full name including spaces without giving problems during program flow
        printf("Enter the mark of student %d: ", i + 1);
        scanf("%f", &marks[i]);
    }

    // Calculate the average mark
    float average = calculateAverage(marks, STUDENT_COUNT);

    // Display the student data and the average
    displayStudentData(names, marks, STUDENT_COUNT);
    printf("\nAverage Mark: %.2f\n", average); // prints average to 2 decimal places

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

// Function to display student data
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count) {
    printf("\nStudent Names and Marks:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %.2f\n", names[i], marks[i]);
    }
}


