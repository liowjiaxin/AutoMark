#include <stdio.h>
#define NUM_STUDENTS 3   
#define NAME_LENGTH 50   

float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]);

int main() {
char names[NUM_STUDENTS][NAME_LENGTH]; // storage the names of the students
float marks[NUM_STUDENTS];             // storage the score of the students


for (int i = 0; i < NUM_STUDENTS; i++) {
printf("Enter the name of student %d: ", i + 1);
scanf(" %[^\n]", names[i]); // input thei names
printf("Enter the mark of student %d: ", i + 1);
scanf("%f", &marks[i]);     // input their scores
}

float average = calculateAverage(marks, NUM_STUDENTS);

displayStudentData(names, marks);
printf("\nAverage Mark: %.2f\n", average);

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
for (int i = 0; i < NUM_STUDENTS; i++) {
printf("%s: %.2f\n", names[i], marks[i]);
}
}