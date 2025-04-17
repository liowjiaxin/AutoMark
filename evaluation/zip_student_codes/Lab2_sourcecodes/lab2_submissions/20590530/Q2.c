#include <stdio.h>

float calculateAverage(const float marks[], int count) {
    float average = 0;
    float sum = 0;
    sum = *marks[0] + *marks[1] + *marks[2];
    average = sum / 3;
    printf("Average Mark: %.2f\n");
}

void displayStudentData(const char names[][NAME_LENGTH], const
float marks[]){
    char *ptr = names[];
    float *ptrr = const float marks[];
    printf("Student Names and Marks: \n");
    printf("%s: %.2f", *ptr[i], *ptrr[i]);
} // NAME_LENGTH 50 

int main () {
    char names[2] = {i, j, k};
    float marks[2] = {i, j, k};
    printf("Enter the name of student 1: ");
    scanf(" %[^\n]", names[i]);
    printf("Enter the mark of student 1: ");
    scanf(" %.f\n", marks[i]);
    printf("Enter the name of student 2: ");
    scanf(" %[^\n]", names[j]);
    printf("Enter the mark of student 2: ");
    scanf(" %.f\n", marks[j]);
    printf("Enter the name of student 3: ");
    scanf(" %[^\n]", names[k]);
    printf("Enter the mark of student 3: ");
    scanf(" %.f\n", marks[k]);


}