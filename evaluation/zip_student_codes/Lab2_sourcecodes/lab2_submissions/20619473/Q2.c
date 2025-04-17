#include <stdio.h> // Include standard input/output library
#include <string.h>
#include <ctype.h> // For isalpha()

#define MAX_STUDENTS 3
#define MAX_NAME_LENGTH 100

// Validate names
int validateName(const char *name) {
    if (strlen(name) == 0) return 0; // Name can't be empty
    for (int i = 0; i < strlen(name); i++) {
        if (!isalpha(name[i]) && name[i] != ' ') return 0; // Alphabetical characters only
    }
    return 1;
}

// Calculate the average marks
float calculateAverage(float marks[], int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += marks[i];
    }
    return sum / size;
}

int main() {
    char studentNames[MAX_STUDENTS][MAX_NAME_LENGTH];
    float studentMarks[MAX_STUDENTS];
    float averageMark;

    for (int i = 0; i < MAX_STUDENTS; i++) {
        // Input and validate name
        while (1) {
            printf("Enter the name of student %d: ", i + 1);
            fgets(studentNames[i], MAX_NAME_LENGTH, stdin);

            // Remove trailing newline from fgets
            studentNames[i][strcspn(studentNames[i], "\n")] = '\0';

            if (validateName(studentNames[i])) {
                break;
            } else {
                printf("Invalid name. Please enter alphabetic characters only.\n");
            }
        }

        // Input and validate marks
        while (1) {
            printf("Enter the mark of student %d: ", i + 1);
            if (scanf("%f", &studentMarks[i]) == 1 && studentMarks[i] >= 0) {
                break;
            } else {
                printf("Invalid mark. Please enter a non-negative number.\n");
                while (getchar() != '\n'); // Clear input buffer
            }
        }
        while (getchar() != '\n'); // Clear input buffer
    }

    // Display student names and marks
    printf("\nStudent names and marks:\n");
    for (int i = 0; i < MAX_STUDENTS; i++) {
        printf("%s: %.2f\n", studentNames[i], studentMarks[i]);
    }

    // Calculate and display average mark
    averageMark = calculateAverage(studentMarks, MAX_STUDENTS);
    printf("\nAverage mark: %.2f\n", averageMark);

    return 0;
}
