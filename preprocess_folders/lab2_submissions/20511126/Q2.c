#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STUDENT_COUNT 3
#define NAME_LENGTH 50

// Function prototypes
float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count);

int main()
{
    char names[STUDENT_COUNT][NAME_LENGTH];
    float marks[STUDENT_COUNT];

    // input student names and marks
    for (int i = 0; i < STUDENT_COUNT; i++)
    {
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]);
        printf("Enter the marks of student %d: ", i + 1);
        scanf("%f", &marks[i]);
    }

    // for the average of the marks
    float average = calculateAverage(marks, STUDENT_COUNT);

    // display the student data and average mark
    displayStudentData(names, marks, STUDENT_COUNT);
    printf("\nAverage mark: %.2f\n", average);

    return 0;
}

// function for calculating avarage
float calculateAverage(const float marks[], int count)
{
    float sum = 0.0;
    for (int i = 0; i < count; i++)
    {
        sum += marks[i];
    }
    return sum / count;
}

// function for displaying student data
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count)
{
    printf("Student Data: \n");
    for (int i = 0; i < count; i++)
    {
        printf("%s: %.2f\n", names[i], marks[i]);
    }
}
