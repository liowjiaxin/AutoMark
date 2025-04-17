#include <stdio.h>
#include <stdlib.h>
#define STUD_COUNT 3
#define NAME_LENGTH 50

float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count);

int main(void)
{
    char names[3][NAME_LENGTH];
    float marks[3];
    float average;
    printf("Enter student names and marks\n");

    for (int i = 0; i < 3; i++)
    {
        printf("Student %d name: ", i + 1);
        scanf(" %[^\n]", names[i]);

        printf("Student %d marks: ", i + 1);
        scanf("%f", &marks[i]);
    }

    average = calculateAverage(marks, 3);
    displayStudentData(names, marks, 3);
    printf("average: %.2f", average);

}

float calculateAverage(const float marks[], int count)
{
    float total;
    float avg;

    total = 0.0;
    for (int i = 0; i < count; i++)
    {
        total += marks[i];
    }
    avg = total / count;
    return avg;
}

void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("%s: ", names[i]);
        printf("%.2f", marks[i]);
        printf("\n");
    }
}