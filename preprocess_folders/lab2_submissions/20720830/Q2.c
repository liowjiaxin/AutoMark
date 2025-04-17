#include <stdio.h>
#define NAME_LENGTH 50

// Function prototypes
float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]); 

int main() {
    // Declare variables
    char names[3][NAME_LENGTH];
    float marks[3];
    // Input student names and marks
    for (int i = 0; i < 3; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]); 
        printf("Enter the mark of student %d: ", i + 1);
        scanf("%f", &marks[i]);
    }
    displayStudentData(names, marks);
    return 0;
}

// Function to display student data
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]) {
    printf("\nStudent Names and Marks:\n");
    // Print student names and marks
    for (int i = 0; i < 3; i++) {
        printf("%s: %.2f\n", names[i], marks[i]);
    }
    // Print average mark
    printf("\nAverage Mark: %.2f\n", calculateAverage(marks, 3));
}

// Function to calculate average mark
float calculateAverage(const float marks[], int count) {
    float sum = 0;
    float result = 0;
    // Calculate sum of marks
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }
    // Calculate average mark
    result = sum/count;
    return result;
}
