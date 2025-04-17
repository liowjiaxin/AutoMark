#include<stdio.h>
#define NAME_LENGTH 50
#define STUDENT 3
float calculateAverage(float marks[],int count){
    //calculate the sum of marks
    float sum = 0;
    for(int i = 0; i < count;i++){
        sum += marks[i];
    }
    //return average
    return sum / count;
}
void displayStudentData(char names[][NAME_LENGTH],float marks[]){
    //dispaly the student name and marks
    printf("Student Names and Marks:\n");
    for(int i = 0; i < STUDENT; i++){
        printf("%s:%.2f\n",names[i],marks[i]);
    }
}
int main(){
    char names[STUDENT][NAME_LENGTH];
    float marks[STUDENT];
    int count = 0;
    //comment use to enter the student data
    for(int i = 0 ;i < STUDENT ;i++){
        printf("Enter the name of student %d:",i+1);
        scanf(" %s[^\n]",&names[i]);
        printf("Enter the mark of student %d:",i+1);
        scanf(" %f",&marks[i]);
        count++;
    }
    //calculate the average
    float average = calculateAverage(marks,count);
    //display data
    displayStudentData(names,marks);
    printf("\n\nAverage Mark:%.2f",average);

}