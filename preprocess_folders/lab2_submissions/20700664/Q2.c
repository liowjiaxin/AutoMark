#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define stuNum 3
#define NAME_LENGTH 50
float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]); // NAME_LENGTH 50 

int main(){
    const char names[stuNum][NAME_LENGTH];
    const float marks[stuNum];
    int count;
    

    for(int i=0; i<stuNum;i++){
        printf("Enter the name of student %d:", i);
        scanf(" %[^\n]", names[i][i]);
        printf("Enter the mark of student %d: ", i);
        scanf("%f", marks[i]);
    }
    
    displayStudentData;
    calculateAverage;
    printf("Average Mark: %f", calculateAverage);
    return 0;
}

float calculateAverage(const float marks[], int count){
    float *average;
    int i;
    for(i=0; i<count; i++){
        *average += marks[i];
    }
    *average /= count;
    return *average;
}

void displayStudentData(const char names[stuNum][NAME_LENGTH], const float marks[]){
    printf("Students Names and Marks:");
    for(int i=0; i<stuNum; i++){
        printf("%c: %f",names[i][i], marks[i]);
    }
}