#include <stdio.h>
#include <string.h>
#define NAME_LENGTH 50
#define STUDENT_NUM 3

// function prototype
float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]); // NAME_LENGTH 50

void displayStudentData(const char names[][NAME_LENGTH], const float marks[])
{
  printf("\nStudent Names and Marks: \n");
  for (int i = 0; i < STUDENT_NUM; i++)
  {
    printf("%s: %.2f\n", names[i], marks[i]);
  }
}

float calculateAverage(const float marks[], int count)
{
  // used to store final result
  float total;
  for (int i = 0; i < count; i++)
  {
    total += marks[i];
  }
  printf("\n");
  float result = (total / count);

  return result;
}

int main()
{
  // create the name and marks array to store the user (question state 3 students)
  char names[STUDENT_NUM][NAME_LENGTH];
  float marks[STUDENT_NUM];
  // find the length of the array used for input loop (either one is ok)
  int length = sizeof(marks) / sizeof(marks[0]);

  // user input;
  for (int i = 0; i < length; i++)
  {
    int index = i + 1;
    printf("Enter the name of student %d: ", index);
    scanf(" %[^\n]", names[i]);

    printf("Enter the mark of student %d: ", index);
    scanf("%f", &marks[i]);
    getchar();
  }

  displayStudentData(names, marks);
  float result = calculateAverage(marks, STUDENT_NUM);
  printf("Average Mark: %.2f", result);

  return 0;
}