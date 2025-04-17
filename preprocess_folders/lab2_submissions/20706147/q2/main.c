/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][50], const float marks[]);

int main() {
    int NUM_STUDENTS = 3;  // Number of students (could also be user input)
    int NAME_LENGTH = 50;   // Maximum length of each student's name

    // Arrays to store student names and marks
    char names[NUM_STUDENTS][NAME_LENGTH];
    float marks[NUM_STUDENTS];
    
    // Prompt the user to enter student names and marks
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]);  // Read full name, including spaces
        
        printf("Enter marks for student %d: ", i + 1);
        scanf("%f", &marks[i]);  // Read the marks as a floating-point number
    }

    // Calculate the average marks
    float average = calculateAverage(marks, NUM_STUDENTS);
    
    // Display the student data and average marks
    displayStudentData(names, marks);
    printf("Average mark: %.2f\n", average);

    return 0;
}

// Function to calculate the average of marks
float calculateAverage(const float marks[], int count) {
    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }
    return sum / count;  // Return the average
}

// Function to display student names, marks, and average
void displayStudentData(const char names[][50], const float marks[]) {
    printf("\nStudent Data:\n");
    for (int i = 0; i < 3; i++) {  // The number of students is hardcoded as 3
        printf("Student %d: %s, Marks: %.2f\n", i + 1, names[i], marks[i]);
    }
}
