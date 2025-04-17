#include <stdio.h>
#define NUM_STUDENTS 3
#define NAME_LENGTH 50

// Function prototypes
float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]); 

int main()
{
    // define the element 
    char names[NUM_STUDENTS][NAME_LENGTH];
    float marks[NUM_STUDENTS];
    
    // Prompt user to enter the student names and marks
    for (int i = 0; i < NUM_STUDENTS; i++) {
        // Student's name
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]);

        // Student's mark
        printf("Enter the mark of student %d: ", i + 1);
        scanf("%f", &marks[i]);
    }

    // calculate average marks
    float average = calculateAverage(marks, NUM_STUDENTS);

    // display students data
    printf("\nStudent Names and Marks:\n");
    displayStudentData(names, marks);   

    // display average mark of students
    printf("\nAverage Mark: %.2f\n ", average);

    return 0;
}


// Function to calculate the average mark
float calculateAverage(const float marks[], int count) {
    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }
    return sum / count;
}

// Function to display student names and marks
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]) {
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("%s: %.2f\n", names[i], marks[i]);
    }
}