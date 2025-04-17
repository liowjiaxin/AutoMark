#include <stdio.h>
#define MAX 50
#define NAME_LENGTH 50

// function prototypes
float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]); // NAME_LENGTH 50 

int main() {
    char names[MAX][NAME_LENGTH];
    float marks[MAX];
    // prompt user to enter student names and marks
    for (int i = 0; i < 3; i++) {
        printf("Enter the name of student %d: ", i+1);
        scanf(" %[^\n]", names[i]);
        printf("Enter student marks: ");
        scanf("%f", &marks[i]);
    }
    displayStudentData(names, marks); // call the function displayStudentData

    return 0;
}

// function to display student names, marks and the average mark
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]) {
    printf("\nStudent names and Marks:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s: %.2f\n", names[i], marks[i]);
    }
    printf("\nAverage Mark: %.2f\n", calculateAverage(marks, 3)); // display the average mark by calling the function calculateAverage
}

// function to calculate the average mark
float calculateAverage(const float marks[], int count) {
    float avg = 0;
    avg = (marks[0] + marks[1] + marks[2]) / count;
    return avg;
}