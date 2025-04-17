#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_LENGTH 50

// function prototype
float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]);

int main() { // begin function main
    char name[3][NAME_LENGTH];
    float marks[3] = {0};

    for (int i = 0; i < 3; i++) {
        printf("Enter the name of student %d: ", i + 1);
        if (i != 0) {
            while(getchar() != '\n');   
            }
        scanf(" %[^\n]", name[i]);
        printf("Enter the marks of student %d: ", i + 1);
        scanf("%f", &marks[i]);
    }
    
    displayStudentData(name, marks);
    printf("\nAverage mark: %.2f", calculateAverage(marks, 3));
} // end function main


void displayStudentData(const char names[][NAME_LENGTH], const float marks[]) {
    puts("\nStudent names and marks:");
    int count = 3;
    for (int i = 0; i < count; i++) {
        printf("%s: %.2f\n", names[i], marks[i]);
    }
}

float calculateAverage(const float marks[], int count) {
    float sum = 0;
    float average = 0;

    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }
    average = sum / count;
    return average;
}