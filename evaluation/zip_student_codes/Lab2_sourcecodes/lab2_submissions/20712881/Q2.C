#include <stdio.h>
#include <string.h>

#define NAME_LENGTH 50
#define STUDENT_COUNT 3

//Structure to store student data
typedef struct {
    char name[NAME_LENGTH];
    float mark;
} Student;

//Function prototypes
float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count);

int main() {
    Student students[STUDENT_COUNT];
    float marks[STUDENT_COUNT];
    char names[STUDENT_COUNT][NAME_LENGTH];

    //Input student names and marks
    for (int i = 0; i < STUDENT_COUNT; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", students[i].name);  // Read full name with spaces
        strcpy(names[i], students[i].name); // Copy name for function
        printf("Enter the mark of %s: ", students[i].name);
        scanf("%f", &students[i].mark);
        marks[i] = students[i].mark; // Copy mark for function
    }

    //Calculate average mark
    float averageMark = calculateAverage(marks, STUDENT_COUNT);

    //Display data and average
    displayStudentData(names, marks, STUDENT_COUNT);
    printf("The average mark is: %.2f\n", averageMark);

    return 0;
}

// Function to calculate the average of marks
float calculateAverage(const float marks[], int count) {
    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }
    return sum / count;
}

// Function to display student names and marks
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count) {
    printf("\nStudent Data:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Mark: %.2f\n", names[i], marks[i]);
    }
}