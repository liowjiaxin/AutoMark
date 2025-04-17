#include <stdio.h>
#define STUDENT_COUNT 3
#define NAME_LENGTH 50

float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]);

int main()
{
    char names[STUDENT_COUNT][NAME_LENGTH];
    float marks[STUDENT_COUNT];
    float average;

    // User Input (Name & Marks)
    for (int i = 0; i < STUDENT_COUNT; i++)
    {
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]);                         // Able to read name with spaces, instead of using fgets
        printf("Enter the mark of student %d: ", i + 1);
        scanf("%f", &marks[i]);
    }

    // CALL Function: Display Student Data
    displayStudentData(names, marks);

    // CALL Function: Calculate Average
    average = calculateAverage(marks, STUDENT_COUNT);
    // Display Average Mark
    puts("");
    printf("Average Mark: %.2f\n", average);

    return 0;
}

// Function: Calculate Average ----------------------------------------------
float calculateAverage(const float marks[], int count)
{
    float sum = 0.0;

    for (int i = 0; i < count; i++)
    {
        sum += marks[i];
    }

    return sum / (float)count;
}

// Function: Display Student Data -------------------------------------------
void displayStudentData(const char names[][NAME_LENGTH], const float marks[])
{
    puts("");
    printf("Student Names and Marks:\n");

    for (int i = 0; i < STUDENT_COUNT; i++)
    {
        printf("%s: %.2f\n", names[i], marks[i]);
    }
    
}