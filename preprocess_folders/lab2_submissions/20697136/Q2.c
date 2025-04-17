#include <stdio.h>
#include <string.h>

float calculateAverage(float a, float b, float c);
void displayStudentData(char array1[3], float array2[]);

int main(void){
    char names[3];
    float marks[3];

    for(int i = 1; i<=3; i++){
        printf("Enter the name of student %d: ", i);
        scanf(" %[^\n]", &names[i-1]);
        printf("Enter the mark of student %d: ", i);
        scanf("%f", &marks[i-1]);
    }
    printf("Student Names and Marks:\n");
    displayStudentData(names, marks);

    printf("Average Mark: %.2f", calculateAverage(marks[0], marks[1], marks[2]));
}

void displayStudentData(char array1[3], float array2[3]){
    printf("%c: %.2f\n", array1[0], array2[0]);
    printf("%c: %.2f\n", array1[1], array2[1]);
    printf("%c: %.2f\n", array1[2], array2[2]);
    return;
}

float calculateAverage(float a, float b, float c){
    float average = (a+b+c)/3;
    return average;
}