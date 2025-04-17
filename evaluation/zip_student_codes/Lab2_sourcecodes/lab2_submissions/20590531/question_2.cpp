#include <stdio.h>

#define STUDENT_COUNT 3
#define NAME_LENGTH 50

// Function prototypes
float calculateAverage (const float marks[], int count) {
    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }
    return sum / count;
}

void displayStudentData (const char names[][NAME_LENGTH], const float marks[]) {
    printf ("\nStudent Names and Marks: \n");
    for (int i = 0; i < STUDENT_COUNT; i++) {
        printf ("%s: %.2f\n", names[i], marks[i]);
    }
}


int main () {
    char names[STUDENT_COUNT][NAME_LENGTH];
    float marks[STUDENT_COUNT];

    // Input student names and marks
    for (int i = 0; i < STUDENT_COUNT; i++) {
        printf ("Enter the name of student %d: ", i + 1);
        scanf (" %[^\n]", names[i]); // Read the full line for the name
        printf ("Enter the mark of student %d: ", i + 1);
        scanf ("%f", &marks[i]);
    }

    // Calculate average marks 
    float average = calculateAverage (marks, STUDENT_COUNT);

    // Display student data
    displayStudentData (names, marks);

    // Display average mark
    printf ("Average Mark: %.2f\n", average);

    return 0;
}