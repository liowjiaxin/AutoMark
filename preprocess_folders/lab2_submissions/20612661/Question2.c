#include <stdio.h>
#define NAME_LENGTH 50

float calculateAverage(const float mark[], int count);

void displayStudentData(const char names[][NAME_LENGTH], const float marks[]);

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // Discards leftover characters
}

float calculateAverage(const float marks[], int count){
    float average;
    average = marks[0] + marks[1] + marks[2];
    average = average / count;
    return average;
}

void displayStudentData(const char names[][NAME_LENGTH], const float marks[]){
    printf("Student Names and Marks: \n");
    for( int i = 0; i < 3; i++){
         if(i == 0){
             printf("%s: %.2f", names, marks[i]);
        }
        else if(i == 1){
             printf("%s: %.2f", names + 50, marks[i]);
        }
        else if(i == 2){
             printf("%s: %.2f", names +100, marks[i]);
        }
       clearInputBuffer();
    }
}


int main(){
    int stdNum = 3;
    char names[NAME_LENGTH * 3];
    float mark[3] = {0};

    for(int i = 0; i < 3; i++){
        printf("Enter the name of student %d: ", i+1);
        if(i == 0){
            scanf("%49s", names);
        }
        else if(i == 1){
            scanf("%49s", names + 50);
        }
        else if(i == 2){
            scanf("%49s", names + 100);
        }
        clearInputBuffer();
        printf("Enter the mark of student %d: ", i+1);
        scanf("%.2f", mark[i]);
        clearInputBuffer();

    }

    displayStudentData(names, mark);

    int average = calculateAverage(mark, stdNum);  
    printf("Average Mark: %.2f", average);  
}