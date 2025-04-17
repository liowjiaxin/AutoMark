#include <stdio.h>

#define NUM_STUDENTS 3
#define NAME_LENGTH 50

// Function Prototypes
float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]);

int main() {
    // Arrays to store student names and marks
    char names[NUM_STUDENTS][NAME_LENGTH];
    float marks[NUM_STUDENTS];
    
    // Loop to input student data
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]);  // Read name with spaces

        printf("Enter marks for %s: ", names[i]);
        scanf("%f", &marks[i]);  // Read marks
    }

    // Calculate the average mark
    float average = calculateAverage(marks, NUM_STUDENTS);

    // Display student data and average mark
    displayStudentData(names, marks);
    printf("Average mark: %.2f\n", average);

    return 0;
}

// Function to calculate the average mark
float calculateAverage(const float marks[], int count) {
    float sum = 0.0;
    
    // Calculate sum of marks
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }

    // Return the average
    return sum / count;
}

// Function to display student names, marks, and average
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]) {
    printf("\nStudent Data:\n");
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Student %d: %s, Marks: %.2f\n", i + 1, names[i], marks[i]);
    }
}
