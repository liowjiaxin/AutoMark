#include <stdio.h>
#define SIZE 3

int main() {

    double calculateAverage(double mark1, double mark2, double mark3){
    double average = (mark1+mark2+mark3)/3;
    return average;
}

    char name[SIZE];
    float mark[SIZE];
    char name1, name2, name3;
    double mark1, mark2, mark3;


        printf("Enter the name of student 1: ");
        scanf(" %[^\n]", &name1);
        printf("Enter the mark of student 1: ");
        scanf("%f",&mark1);
        printf("Enter the name of student 2: ");
        scanf(" %[^\n]", &name2);
        printf("Enter the mark of student 2: ");
        scanf("%f",&mark2);
        printf("Enter the name of student 3: ");
        scanf(" %[^\n]", &name3);
        printf("Enter the mark of student 3: ");
        scanf("%f",&mark3);

        printf("Students names and marks: ");
        printf("Student 1: %.2f",mark1);
        printf("Student 2 %.2f",mark2);
        printf("Student 3: %.2f",mark3);


        printf("Average mark: ",calculateAverage(mark1,mark2,mark3));



}
