#include <stdio.h>
#include <string.h>

#define NAME_LENGTH 50
// Define the student structure
struct student {
    char name[NAME_LENGTH];
    float marks;
};

// Function to calculate the average marks
float calculateAverage(const float marks[], int count) {
    float sum = 0.0;
    for (int i = 0; i < count; ++i) {
        sum += marks[i];
    }
    return sum / count;
}

// Function to display student information
void displayStudentData(struct student s[], int count) {
    printf("\nStudent Names and Marks:\n");
    for (int i = 0; i < count; ++i) {
        printf("%s: %.1f\n", s[i].name, s[i].marks);
    }
}

int main() {
    struct student s[3];
    char marksInput[10]; 
    int i;

    // Collecting student data
    for (i = 0; i < 3; ++i) {
        printf("Enter the name of student %d: ", i + 1);
        fgets(s[i].name, sizeof(s[i].name), stdin); 


        char *newline = strchr(s[i].name, '\n');
        if (newline) *newline = '\0';

        while (1) {
            printf("Enter the marks of student %d: ", i + 1);
            fgets(marksInput, sizeof(marksInput), stdin);

            // Convert marks input to float
            if (sscanf(marksInput, "%f", &s[i].marks) == 1 && s[i].marks >= 0) {
                break; // Valid marks
            } else {
                printf("Error: Please enter a valid positive number for marks.\n");
            }
        }
    }

    // Display student data
    displayStudentData(s, 3);

    // Calculate and display average marks
    float marksArray[3];
    for (i = 0; i < 3; ++i) {
        marksArray[i] = s[i].marks;
    }
    float average = calculateAverage(marksArray, 3);
    printf("\nAverage Marks: %.2f\n", average);

    return 0;
}