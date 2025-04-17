/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#define NAME_LENGTH 50 // Maximum length for a student name
#define STUDENT_COUNT 3 // The number of students

float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count);

int main() {
    char names[STUDENT_COUNT][NAME_LENGTH]; 
    float marks[STUDENT_COUNT];           
    int i;

    // Prompt the user to enter names and marks
    for (i = 0; i < STUDENT_COUNT; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]); // Input name
        printf("Enter the mark of student %d: ", i + 1);
        scanf("%f", &marks[i]); // Input marks
    }

    // Calculate the average mark
    float average = calculateAverage(marks, STUDENT_COUNT);

    // Display the student data and average mark
    displayStudentData(names, marks, STUDENT_COUNT);
    printf("\nAverage Mark: %.2f\n", average);

    return 0;
}

// Function to calculate the average mark of the students
float calculateAverage(const float marks[], int count) {
    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }
    return sum / count;
}

// Function to display all the student names, marks, and the average
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count) {
    printf("\nStudent Names and Marks:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %.2f\n", names[i], marks[i]);
    }
}
