#include <stdio.h>
#define NAME_LENGTH 100

float calculateAverage(const float marks[], int count) {
    float sum = 0;
    for (int i=0;i<=count;i++) {
        sum += marks[i];
    }
    float avg = sum/count;
    return avg;
}

void displayStudentData(const char names[][NAME_LENGTH], const float marks[]) {
    for (int i=0;i<100;i++) {
        printf("%s",names[i]);
    }
}

int main(void){

    char names[NAME_LENGTH];
    char *namesptr=names;
    float marks[4]={};
    float *markptr=marks;
    int count=3;

    puts("Please enter name of student 1: ");
    scanf("%s", names);
    puts("\nPlease enter mark of student 1: ");
    scanf("%f", markptr+0);
    puts("\nPlease enter name of student 2: ");
    scanf("%s", names+30);
    puts("\nPlease enter mark of student 2: ");
    scanf("%f", markptr+1);
    puts("\nPlease enter name of student 3: ");
    scanf("%s", names+60);
    puts("\nPlease enter mark of student 3: ");
    scanf("%f", markptr+2);

    printf("\nThe average of the students' marks is %.2f", calculateAverage(marks, count));

    displayStudentData(names, marks);

}