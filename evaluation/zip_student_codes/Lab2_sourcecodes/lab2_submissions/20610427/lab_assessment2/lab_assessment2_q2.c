#include <stdio.h>
#include <string.h>
#define NAME_LENGTH 50 
#define studentnum 3 

// Function prototypes
float calculateAverage(const int marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const int marks[], int count);

int main() {
    char names[studentnum][NAME_LENGTH]; 
    int marks[studentnum];          
    float average;

    for (int i = 0; i < studentnum; i++) {
        printf("Enter the name of student %d: ", i + 1);
        fgets(names[i], NAME_LENGTH, stdin);

        size_t len = strlen(names[i]);
        if (len > 0 && names[i][len - 1] == '\n') {
            names[i][len - 1] = '\0';
        }

        printf("Enter the marks of student %d: ", i + 1);
        scanf("%d", &marks[i]);
        getchar(); 
    }

    average = calculateAverage(marks, studentnum);

    displayStudentData(names, marks, studentnum);

    printf("\nAverage Mark: %.2f\n", average);

    return 0;
}

float calculateAverage(const int marks[], int count) {
    int total = 0;
    for (int i = 0; i < count; i++) {
        total += marks[i];
    }
    return (float)total / count;
}


void displayStudentData(const char names[][NAME_LENGTH], const int marks[], int count) {
    printf("\nStudent names and marks:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Marks: %d\n", names[i], marks[i]);
    }
}