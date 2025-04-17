//Libraries
#include <complex.h>
#include <stdlib.h>
#include <stdio.h>
//Preprocessors
#define MAX_STUDENTS 3
#define NAME_LENGTH 50

// Funcion takes average  and by average I mean arthimethic mean
float calculateAverage(const float marks[], int count) {
    float sum = 0.0;
    for (int increment = 0; increment < count; increment++) {
        sum += marks[increment];
    }
    return sum / count;
}

// Displayer Function that gives it in Text form in the terminal
//TO-Do, adding color to C - terminal code somehow
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count) {
    printf("Student Data:\n");
    for (int increment = 0; increment < count; increment++) {
        printf("Name: %s, Mark: %.2f\n", names[increment], marks[increment]);
    }
    printf("Average Mark: %.2f\n", calculateAverage(marks, count));
}
// Main Function to execute the main body of code

int main() {
    char studentNames[MAX_STUDENTS][NAME_LENGTH];
    float studentMarks[MAX_STUDENTS];

    // Input student data
    for (int increment = 0; increment < MAX_STUDENTS; increment++) {
        printf("Enter name of student %d: ", increment + 1);
        scanf(" %[^\n]", studentNames[increment]);
        printf("Enter mark of student %d: ", increment + 1);
        scanf("%f", &studentMarks[increment]);
    }

    // Display student data and average
    displayStudentData(studentNames, studentMarks, MAX_STUDENTS);
    return EXIT_SUCCESS;
}
