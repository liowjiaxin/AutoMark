#include <stdio.h>

#define NUM_OF_STUDENTS 3
#define NAME_LENGTH 50

// function prototypes
float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]);

int main() 
{
    char names[NUM_OF_STUDENTS][NAME_LENGTH];
    float marks[NUM_OF_STUDENTS];

    // prompt user to enter 3 student names and marks
    for (int i = 0; i < NUM_OF_STUDENTS; i++) 
    {
        printf("Enter the name of student %d: ", i+1);
        scanf(" %[^\n]", names[i]); // read student name
        printf("Enter the mark of student %d: ", i+1);
        scanf("%f", &marks[i]);     // read marks
    }

    // calculate average mark
    float average = calculateAverage(marks, NUM_OF_STUDENTS);

    // display student name and average mark
    displayStudentData(names, marks);
    printf("\nAverage Mark: %.2f\n", average);

    return 0;
}

// function for calculating average mark
float calculateAverage(const float marks[], int count) 
{
    float sum = 0.0;

    for (int i = 0; i < count; i++) 
    {
        sum += marks[i];
    }

    return sum / count;
}

// function for displaying student names and marks
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]) 
{
    printf("\nStudent Names and Marks:\n");

    for (int i = 0; i < NUM_OF_STUDENTS; i++) 
    {
        printf("%s: %.2f\n", names[i], marks[i]);
    }
}
