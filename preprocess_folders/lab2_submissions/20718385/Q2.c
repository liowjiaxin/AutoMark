#include <stdio.h>

#define NAME_LENGTH 50
#define STUDENT_COUNT 3

// Function prototypes
float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count);

// Function to calculate average marks
float calculateAverage(const float marks[], int count) {
    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }
    return sum / count;
}

// Function to display student data
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count) {
    printf("\nStudent Data:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Marks: %.2f\n", names[i], marks[i]);
    }
}

int main() {
    char names[STUDENT_COUNT][NAME_LENGTH];
    float marks[STUDENT_COUNT];
    
    // Input student names and marks
    for (int i = 0; i < STUDENT_COUNT; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]); // Reading name with spaces
        printf("Enter the marks of %s: ", names[i]);
        scanf("%f", &marks[i]);
    }
    
    // Calculate average
    float average = calculateAverage(marks, STUDENT_COUNT);
    
    // Display student data and average marks
    displayStudentData(names, marks, STUDENT_COUNT);
    printf("\nAverage Marks: %.2f\n", average);
    
    return 0;
}


