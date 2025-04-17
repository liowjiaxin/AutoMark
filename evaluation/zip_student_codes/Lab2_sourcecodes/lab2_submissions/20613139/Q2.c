#include <stdio.h>
#include <string.h>

#define STUDENTS 3
#define NAME_LENGTH 50

// Function to calculate the average
float calculateAverage(const float marks[], int count) {
    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }
    return sum / count;
}

// Function to display student data
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count) {
    printf("\nStudent Data:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Marks: %.2f\n", names[i], marks[i]);
    }
}

int main() {
    char names[STUDENTS][NAME_LENGTH];
    float marks[STUDENTS];

    // Input student names and marks
    for (int i = 0; i < STUDENTS; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]); // Read name with spaces
        printf("Enter the marks of %s: ", names[i]);
        scanf("%f", &marks[i]);
    }

    // Calculate the average
    float average = calculateAverage(marks, STUDENTS);

    // Display the data
    displayStudentData(names, marks, STUDENTS);

    // Display the average
    printf("\nAverage Marks: %.2f\n", average);

    return 0;
}
