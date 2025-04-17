#include <stdio.h>

#define NAME_LENGTH 50
#define STUDENT_COUNT 3

// Struct definition
struct Student {
    char name[NAME_LENGTH];
    float mark;
};

// Function prototypes
float calculateAverage(const struct Student students[], int count);
void displayStudentData(const struct Student students[], int count);

int main() {
    struct Student students[STUDENT_COUNT];

    // Input student names and marks
    for (int i = 0; i < STUDENT_COUNT; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", students[i].name);  // Using %[^\n] to read names with spaces
        printf("Enter the mark of student %d: ", i + 1);
        scanf("%f", &students[i].mark);
    }

    // Calculate the average mark
    float average = calculateAverage(students, STUDENT_COUNT);

    // Display student names and marks
    displayStudentData(students, STUDENT_COUNT);

    // Display the average mark
    printf("Average Mark: %.2f\n", average);

    return 0;
}

// Function to calculate the average mark
float calculateAverage(const struct Student students[], int count) {
    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += students[i].mark;
    }
    return sum / count;
}

// Function to display student names and marks
void displayStudentData(const struct Student students[], int count) {
    printf("\nStudent Names and Marks:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %.2f\n", students[i].name, students[i].mark);
    }
}
