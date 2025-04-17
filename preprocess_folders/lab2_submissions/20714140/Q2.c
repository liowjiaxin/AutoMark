#include <stdio.h>
#include <string.h> 
#define NAME_LENGTH 50
#define STUDENT_NUM 3

float calculateAverage(const float marks[], int count){
    int total = 0;
    float average;
    for(int i = 0; i<count;i++){
        total += marks[i];
    }
    average = (float) total / count;
}

void displayStudentData(const char names[][NAME_LENGTH], const float marks[]){
    printf("Student Names and Marks: \n");
    for (int j = 1; j<=3;j++){
        printf("%c: %.2f\n",names[j],marks[j]);
    }
}

int main()
{
    float marks[STUDENT_NUM];
    char names[STUDENT_NUM][NAME_LENGTH];
    int lineCount = 0;
    
    for (int i = 1;i<=STUDENT_NUM;i++){
        printf("Enter the name of student %d: ",i);
        while (lineCount < NAME_LENGTH) { 
            fgets(names[lineCount], NAME_LENGTH, stdin); 
            // Remove newline character if present 
            names[lineCount][strcspn(names[lineCount], "\n")] = '\0'; 
            lineCount++;
            break;
        }
        
        printf("Enter the mark of student %d: ",i);
        scanf("%f",&marks[i]);
    }
    
    displayStudentData(names,marks);
    float ave = calculateAverage(marks,STUDENT_NUM);
    printf("\nAverage Mark: %.2f",ave);
    return 0;
}