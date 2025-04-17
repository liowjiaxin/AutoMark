#include <stdio.h>

void displayStudentData(const char *names[50], float marks[]){
    printf("Students names and marks:\n");
    for (int i = 0; i < 3; i++){
        printf("%s: %.2f\n", names[i], marks[i]);
    }
}

float calculateAverage(float marks[], int count){
    float average = 0.0;
    for (int i = 0; i < count; i++){
        average += marks[i];
    }
    return average / (float) count;
}

int main(){
    char student1[50], student2[50], student3[50], hold = ' ';
    char *names[50] = {student1, student2, student3};
    float marks[3];
    
    int index = 0;
    printf("Enter the name of sudent1: ");
    for (scanf(" %c", &hold); hold != '\n'; scanf("%c", &hold)){
        student1[index] = hold;
        index++;
    }
    printf("Enter the mark of student1: ");
    scanf("%f", &marks[0]);
    
    index = 0;
    printf("Enter the name of sudent2: ");
    for (scanf(" %c", &hold); hold != '\n'; scanf("%c", &hold)){
        student2[index] = hold;
        index++;
    }
    printf("Enter the mark of student2: ");
    scanf("%f", &marks[1]);
    
    index = 0;
    printf("Enter the name of sudent3: ");
    for (scanf(" %c", &hold); hold != '\n'; scanf("%c", &hold)){
        student3[index] = hold;
        index++;
    }
    printf("Enter the mark of student3: ");
    scanf("%f", &marks[2]);
    
    displayStudentData(names, marks);
    printf("Average mark: %f", calculateAverage(marks, 3));
}