#include <stdio.h>

#define NAME_LENGTH 50

float calculateAverage(const float marks[],int count){

    float markssum=0;
    float average;

    for (int i=0;i<count;++i){
        markssum+=marks[i];
    }

    average=markssum/(count);

    return average;

}

void displayStudentData(const char names[][NAME_LENGTH],const float marks[], int count){

    printf("Student Names and Marks:\n");
    for (int i=0;i<count;++i){
        printf("%s: %.2f\n",names[i],marks[i]);
        }
}

int main (){

    float marks[3];
    char names[50][NAME_LENGTH];
    int count = 0;

    for (int i=0;i<3;++i){
        printf("Enter the name of student %d:",count+1);
        scanf(" %*[^\n]",names[i]); // this scans for first newline so if this only it skips the remaining LOOP
        scanf("%*c");


        printf("Enter the mark of student %d:",count+1);
        scanf("%f",&marks[i]);
        count++;
    }

    displayStudentData(names,marks,count);

    float average= calculateAverage(marks,count);

    printf("Average Mark :%.2f",average);



}