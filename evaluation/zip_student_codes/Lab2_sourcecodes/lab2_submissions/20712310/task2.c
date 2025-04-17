/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/



#include <stdio.h>

#define NAME_LENGTH 50
#define STUDENT_COUNT 3 //define the length and student number 


float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]);

int main() {
    char names[STUDENT_COUNT][NAME_LENGTH];
    float marks[STUDENT_COUNT];
    float average;

    
    printf("Enter the names and marks for three students:\n");
    for (int i = 0; i < STUDENT_COUNT; i++) {
        printf("Enter  the name of student  %d: ", i + 1);
        scanf(" %[^\n]", names[i]);
        getchar(); 
        printf("Enter the mark of student  %d: ", i + 1);
        scanf("%f", &marks[i]);
    }

    
    average = calculateAverage(marks, STUDENT_COUNT);

   
    displayStudentData(names, marks);
    printf("Average mark: %.2f\n", average);

    return 0;
}


float calculateAverage(const float marks[], int count) {
    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }
    return sum / count;
}


void displayStudentData(const char names[][NAME_LENGTH], const float marks[]) {
    printf("Student Names and Marks:\n");
    for (int i = 0; i < STUDENT_COUNT; i++) {
        printf("%s: %.2f\n", names[i], marks[i]);
    }
}