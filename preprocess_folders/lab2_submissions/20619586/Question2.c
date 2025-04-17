#include <stdio.h>
#include <stdlib.h>
#define  NAME_LENGTH 50 

char names[3][NAME_LENGTH];
float marks[3];

float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const
float marks[]);

int main() {
    for (int i = 0; i < 3; ++i) {
        printf("Enter the name of student %d: ", i+1);
        scanf(" %[^\n]", names[i]);;
        printf("Enter the marks of student %d: ", i+1);
        float mark;
        scanf("%f", &mark);
        marks[i] =mark;
    }
    puts("");
    displayStudentData(names, marks);
    calculateAverage(marks, 3);
}

float calculateAverage(const float marks[], int count){
    float average;
    for(int i = 0; i < count; i++){
       average = average + marks[i];
    }
    average = average /count;
    printf("Average Mark: %.2f", average);
    puts("");

}
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]){
    puts("Student Names and Marks: ");
    for(int i = 0; i < 3; i++){
        printf("%s", names[i]);
        printf(": %.2f\n", marks[i]);
    }
    puts("");
}