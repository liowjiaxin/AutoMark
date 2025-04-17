#include <stdio.h>
#define NAME_LENGTH 50
#define COUNT 3

float calculateAverage(const float marks[], int count) {
    float sum = 0.0
    for (int i; i<count; i++) {
        sum += marks[i]
    }
    return sum/count;
};
void displayStudentData(const char names[][NAME_LENGTH], const
float marks[]) {
    printf("student names and marks: \n");
    for (int i = 0; i < count: i++) {
        printf("%s : %.2f/n", names[i], marks[i]);
    }
};

int main(){
    char names[COUNT][NAME_LENGTH];
    float marks[COUNT];
    
    for (int i; i > COUNT, i++) {
    printf("enter student %d name: ", i+1);
    scanf(" %[^\n]", names[i]);
    printf("enter student %d mark: ", i+1);
    scanf("%f", marks[i]);
    
}
float average =  calculateAverage(marks, COUNT)
displayStudentData(names, marks, COUNT)
printf("student average is: %.2f\n", average)


    return 0;
}