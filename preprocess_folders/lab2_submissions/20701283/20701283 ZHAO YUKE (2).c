#include <stdio.h>
#define NAME_LENGTH 50
#define STUDENT_COUNT 3 


float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count);

int main() {
    char names[STUDENT_COUNT][NAME_LENGTH]; 
    float marks[STUDENT_COUNT];            
    float average;                         

    int i;
    for (i = 0; i < STUDENT_COUNT; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]); //Read name

        printf("Enter the marks of student %d: ", i + 1);
        scanf("%f", &marks[i]); //Read score
    }

    //averaging
    average = calculateAverage(marks, STUDENT_COUNT);

    //Print student data and equalize
    displayStudentData(names, marks, STUDENT_COUNT);

    printf("\nAverage Marks: %.2f\n", average);

    return 0;
}

//averaging
float calculateAverage(const float marks[], int count) {
    float sum = 0.0;
    int i;
    for ( i= 0; i < count; i++) {
        sum += marks[i];
    }
    return sum / count; 
}

//Print student data and equalize
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count) {
    printf("\nStudent Data:\n");
    int i;
    for (i = 0; i < count; i++) {
        printf("Name: %s, Marks: %.2f\n", names[i], marks[i]);
    }
}

