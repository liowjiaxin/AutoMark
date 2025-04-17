#include <stdio.h>
#define NAME_LENGTH 50
#define MAX_STUDENTS 3

float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]);

float calculateAverage(const float marks[], int count) { 
    float total = 0;
    for (int i = 0; i < count; i++) {
        total += marks[i]; // accumulate marks
    }
    return total / count; 
}

// Function to display student data
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]) {
    printf("Students Names and Marks:\n");
    for (int i = 0; i < MAX_STUDENTS; i++) {
        printf("Name: %s, Marks: %.2f\n", names[i], marks[i]);
    }

    // Calculate and print the average mark
    printf("Average mark: %.2f\n", calculateAverage(marks, MAX_STUDENTS)); 
}
int main() {
    char names[MAX_STUDENTS][NAME_LENGTH];
    float marks[MAX_STUDENTS];

    // loop for input 
    for (int i = 0; i < MAX_STUDENTS; i++) { 
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]); // names to store names input

        printf("Enter the mark of the student %d: ", i + 1);
        scanf("%f", &marks[i]); // marks to store marks input
    }

    displayStudentData(names, marks); // Call to display student data

    return 0;
}





