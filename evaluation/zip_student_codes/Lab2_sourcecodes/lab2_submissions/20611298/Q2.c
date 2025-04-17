#include <stdio.h>

#define NUM_STUDENTS 3
#define NAME_LENGTH 50

// function prototypes
float CalculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]);

// function to calculate the average of marks
float CalculateAverage(const float marks[], int count) {
    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }
    return sum / count;
}

// Function to display student names and marks
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]) {
    printf("\nStudent Names and Marks:\n");
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("%s: %.2f\n", names[i], marks[i]);
    }
}

int main() {
    char names[NUM_STUDENTS][NAME_LENGTH];
    float marks[NUM_STUDENTS];

    // prompt user to key in student names and marks
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]);
        printf("Enter mark of student %d: ", i + 1);
        scanf("%f", &marks[i]);
    }

    // calculate average mark using the function
    float average = CalculateAverage(marks, NUM_STUDENTS);

    // display student data and average mark
    displayStudentData(names, marks);
    printf("\nAverage Mark: %.2f\n", average);

    return 0;
}
