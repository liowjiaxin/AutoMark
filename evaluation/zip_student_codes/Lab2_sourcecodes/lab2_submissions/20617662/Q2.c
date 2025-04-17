#include <stdio.h>

#define NUM_STUDENTS 3    // Number of students for data
#define NAME_LENGTH 50    // Length of a students name

// Calling a function to calculate the average of the marks 
float calculateAverage(const float marks[], int count) {
    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }
    return sum / count;
}

// Another function to display student data (name, marks and average)
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count, float average) {
    printf("\nStudent Data:\n");
    for (int i = 0; i < count; i++) {
        printf("Student %d: Name: %s, Mark: %.2f\n", i + 1, names[i], marks[i]);
    }
    printf("Average Mark: %.2f\n", average);
}

int main() {
    char names[NUM_STUDENTS][NAME_LENGTH];  // Applying array to store student's name 
    float marks[NUM_STUDENTS];             // Applying array to store student's marks 
    float average;

    // Enter the student names and marks
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]);  // Read the name (including spaces)
        printf("Enter mark of student %d: ", i + 1);
        scanf("%f", &marks[i]);  
    }

    // Average mark is calculated.
    average = calculateAverage(marks, NUM_STUDENTS);

    //Display student's name, mark, and the average
    displayStudentData(names, marks, NUM_STUDENTS, average);

    return 0;
}