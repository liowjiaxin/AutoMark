#include <stdio.h>
#include <string.h>

// Set the total length of name and total number of student required
#define NAME_LENGTH 50
#define STUDENT_COUNT 3

// Function to calculate the average marks
float calculateAverage(const float marks[], int count) 
{
    float sum = 0.0;
    for (int i = 0; i < count; i++) 
    {
        sum += marks[i];
    }
    return sum / count;
}

// Function to show the student names and marks
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count) 
{
    printf("\nStudent Names and Marks:\n");
    for (int i = 0; i < count; i++) 
    {
        printf("%s: %.2f\n", names[i], marks[i]);
    }
}

// Function to clear the input buffer
void clearInputBuffer() 
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() 
{
    char names[STUDENT_COUNT][NAME_LENGTH];
    float marks[STUDENT_COUNT];

    // Ask user to enter student names and marks
    for (int i = 0; i < STUDENT_COUNT; i++) 
    {
        printf("Enter the name of student %d: ", i + 1);
        fgets(names[i], sizeof(names[i]), stdin);

        // Remove the trailing newline from fgets
        // search '\n' in names[i] then change it to null '\0'
        names[i][strcspn(names[i], "\n")] = '\0';

        printf("Enter the mark of student %d: ", i + 1);
        scanf("%f", &marks[i]);
        // Remove the input buffer from scanf since '\n' will be left in the buffer
        clearInputBuffer(); 
    }

    float averageMark = calculateAverage(marks, STUDENT_COUNT);

    displayStudentData(names, marks, STUDENT_COUNT);
    printf("\nAverage Mark: %.2f\n", averageMark);

    return 0;
}

