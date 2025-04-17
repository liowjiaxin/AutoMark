#include <stdio.h>  // for standard input-output
#include <string.h>  // for string functions

#define NAME_LENGTH 50  // max length for student names
#define NUM_STUDENTS 3 // number of students specified

// This function calculates the average mark
float calculateAverage(const float marks[], int count) {
    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }
    return (count > 0) ? (sum / count) : 0.0; 
}

// This fnction displays the student names, marks, and the average mark.
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], float average) {
    printf("\nStudent Names & Marks:\n");
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("%s: %.2f\n", names[i], marks[i]);
    }
    printf("Average Mark: %.2f\n", average);
}

int main() {
    char studentNames[NUM_STUDENTS][NAME_LENGTH];
    float studentMarks[NUM_STUDENTS];

    // tThis will prompt the user to enter student names and marks.
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Please enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", studentNames[i]); 

        printf("You may enter the mark of student %d: ", i + 1);
        scanf("%f", &studentMarks[i]);
    }

    // This calculates the average mark
    float avgMark = calculateAverage(studentMarks, NUM_STUDENTS);

    // This will print the students' names, marks, and their average mark.
    displayStudentData(studentNames, studentMarks, avgMark);

    return 0;
}