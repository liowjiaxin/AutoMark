#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define NAME_LENGTH 50

// Function prototype
float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const
float marks[]); // NAME_LENGTH 50 
void r_whitespaces();


int main(){
    char sNames[3][NAME_LENGTH];
    float sMarks[3];
    for (int i=0; i<3; i++){
        r_whitespaces();    // remove whitespaces after student 1 marks
        
        printf("Enter the name of student %d: ", i+1);
        fgets(sNames[i], sizeof(sNames), stdin);
        sNames[i][strcspn(sNames[i], "\n")] = 0;    // remove newline after entering name
        
        printf("Enter the mark of student %d: ", i+1);
        float mark=0;
        scanf("%f", &mark);
        sMarks[i] = mark;       // scan and save student mark to sMarks[i]
    }
    
    printf("\n");
    displayStudentData(sNames, sMarks);

    float average = calculateAverage(sMarks, 3);
    printf("\nAverage mark: %.2f", average);
    
    return 0;
}

float calculateAverage(const float marks[], int count){
    float sum=0;
    for (int i=0; i<count; i++){
        sum += marks[i];    
    }
    return sum/count;       // return average
}

void displayStudentData(const char names[][NAME_LENGTH], const
float marks[]){
    puts("Student names & marks: ");
    for (int i=0; i<3; i++){
        printf("%s: %.2f\n", names[i], marks[i]);   // print student names & marks
    }
} 

// remove whitespaces before entering names (after entering float marks)
void r_whitespaces(){
    int ch;
        while ((ch = getchar()) != '\n')
            continue; //discard any leftover whitespaces
            //getchar() reads a character from the input buffer, discards and repeat until the character is not a newline ('\n') or end-of-file (EOF)
}