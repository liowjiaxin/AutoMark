#include <stdio.h>

#define NUM_STUDENTS 3
#define NAME_LENGTH 50

// Function prototypes
float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]);

int main() {
    char names[NUM_STUDENTS][NAME_LENGTH];  // Array to store student names
    float marks[NUM_STUDENTS];               // Array to store student marks

    // Step 1: Prompt the user to enter the names and marks
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]);  // To read a full name with spaces

        printf("Enter marks for student %d: ", i + 1);
        scanf("%f", &marks[i]);
    }

    // Step 2: Calculate the average mark
    float average = calculateAverage(marks, NUM_STUDENTS);

    // Step 3: Display the student data and average
    displayStudentData(names, marks);
    printf("Average mark: %.2f\n", average);

    return 0;
}

// Function to calculate the average of the marks
float calculateAverage(const float marks[], int count) {
    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }
    return sum / count;
}

// Function to display student names and marks
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]) {
    printf("\nStudent Names and Marks:\n");
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Names: %s, Marks: %.2f\n", names[i], marks[i]);
    }
}
