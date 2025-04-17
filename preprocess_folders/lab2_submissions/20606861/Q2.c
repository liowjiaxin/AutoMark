#include <stdio.h>
#define numst 3  // number of student
#define maxnamelenght 50  // Maximum length for student names


// Function to calculate the average of the marks
float getAverage(float marks[], int total) {
    float sum = 0;
    for (int i = 0; i < total; i++) {
        sum += marks[i]; // Add each mark to the sum
    }
    return sum / total; // Return the average
}

// Function to display student names and their marks
void showStudentData(char names[][maxnamelenght], float marks[]) {
    printf("\nStudent Names and Marks:\n");
    for (int i = 0; i < numst; i++) {
        printf("%s: %.2f\n", names[i], marks[i]); // Print name and mark
    }
}

int main() {
    char studentNames[numst][maxnamelenght];// Array to store names
    float studentMarks[numst];// Array to store marks

    // Collect names and marks from the user
    for (int i = 0; i < numst; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf(" %[^\n]", studentNames[i]); // Read the full name with spaces
        printf("Enter marks for student %d: ", i + 1);
        scanf("%f", &studentMarks[i]); // Read the marks
    }

    // Calculate the average of the marks
    float average = getAverage(studentMarks, numst);

    // Display the names, marks, and average
    showStudentData(studentNames, studentMarks);
    printf("\nAverage Mark: %.2f\n", average); // Print the average

    return 0;
}
