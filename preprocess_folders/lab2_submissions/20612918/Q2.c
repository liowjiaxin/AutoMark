#include <stdio.h>
#define NAME_LENGTH  50

float calculateAverage(const float marks[], int count);

void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count);

int main(){
    int count = 3; 
    char names[count][NAME_LENGTH];
    float marks[count];

    //loop to enter name and mark of student
    for (int i=0; i<3; i++){
        printf("Enter the name of student %d: ", i+1);
        scanf("%s[^\n]", &names[i]);
        printf("Enter the mark of student %d: ", i+1);
        scanf("%f[^\n]", &marks[i]);
    }

    //call display function
    displayStudentData(names, marks,count);

    
}

float calculateAverage(const float marks[], int count){
    float sum = 0;
    //loop to count sum of marks
    for (int i=0; i<count; i++){
        sum += marks[i];
    }
    // calculating verage
    return sum/count;
}

void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count){
    for(int i=0; i<count; i++){
        printf("\n%s: %.2f", names[i], marks[i]); //displaying each name and marks
    }

    printf("\nAverage Mark: %.2f",  calculateAverage(marks, count)); //displaying average
}