#include <stdio.h>

#define NAME_LENGTH 50
#define STUDENT_NUM 3

//FUnction prototype
float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], float average);

int main() {
    char names[STUDENT_NUM][NAME_LENGTH];
    float marks[STUDENT_NUM];

    // Input student names and marks
    for (int i = 0; i < STUDENT_NUM; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]);  // Use " %[^\n]" to read a full line of input
        printf("Enter the mark of student %d: ", i + 1);
        scanf("%f", &marks[i]);
    }

    // Calculate the average mark
    float average = calculateAverage(marks, STUDENT_NUM);

    // Display student data and average mark
    displayStudentData(names, marks, average);

    return 0;
}

// Function to calculate the average mark
float calculateAverage(const float marks[], int count) {
    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }
    return sum / count;
}

// Function to display student names, marks, and the average mark
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], float average) {
    printf("\nStudent Names and Marks:\n");
    for (int i = 0; i < STUDENT_NUM; i++) {
        printf("%s: %.2f\n", names[i], marks[i]);
    }
    // Print the result 
    printf("\nAverage Mark: %.2f\n", average);
}

