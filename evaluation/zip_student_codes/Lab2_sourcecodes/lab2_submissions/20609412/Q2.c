#include <stdio.h>
#include <string.h>

// Predefine
#define NAME 50
#define STUDENTS 3

// Average marks fx
float calculateAverage(const float marks[], int count) {
    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }
    return sum / count;
}

// Display fx
void displayStudentData(const char names[][NAME], const float marks[], int count) 
{
    printf("\nStudent Names and Marks:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %.2f\n", names[i], marks[i]);
    }
}

// Clear input fx
void clearInputBuffer() 
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    char names[STUDENTS][NAME];
    float marks[STUDENTS];

    //Get user input
    for (int i = 0; i < STUDENTS; i++) {
        printf("Enter the name of student %d: ", i + 1);
        fgets(names[i], sizeof(names[i]), stdin);

        names[i][strcspn(names[i], "\n")] = '\0';

        printf("Enter the mark of student %d: ", i + 1);
        scanf("%f", &marks[i]);

        clearInputBuffer(); 
    }

    float averageMark = calculateAverage(marks, STUDENTS);

    displayStudentData(names, marks, STUDENTS);
    printf("\nAverage Mark: %.2f\n", averageMark);

    return 0;
}