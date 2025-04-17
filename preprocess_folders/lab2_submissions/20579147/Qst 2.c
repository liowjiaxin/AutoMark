#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>




// Function to calculate the average of marks
float calculateAverage(float marks[], int count) {
    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }
    return sum / count;
}

// Function to display student names and marks
void displayStudentData(char names[][50], float marks[], int count) {
    printf("\nStudent Data:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Marks: %.2f\n", names[i], marks[i]);
    }
}

int main() {
    char names[3][50];  // Array to store names of 3 students and allow only fifty characters
    float marks[3];     // Array to store marks of 3 students

    // Prompt the user to enter student names and marks
    for (int i = 0; i < 3; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]); // Read the whole line for the student's name
        printf("Enter marks of student %d: ", i + 1);
        scanf("%f", &marks[i]); // Read the marks for the student
    }





}





