#include <stdio.h>
float marks[3];
char names[3];
float calculateAverage(const float marks[], int count);
//void displayStudentData(const char names[][NAME_LENGTH], const float marks[]); // NAME_LENGTH 50

int main() {
    for (size_t i=0;i<3;i++){
        int j=i+1;
        printf("\nEnter the name of student %d:",&j);
        scanf("%s", &names[i]);
        printf("\nEnter the name of student %d:",&j);
        scanf("%lf", &marks[i]);
    }
    printf("\nAverage Mark: %lf", calculateAverage(marks,3));

    return 0;
}
float calculateAverage(const float marks[], int count){
    float average;
    float total=0;
    for (size_t i=0;i<count;i++){
        total+=marks[i];
    }
    average = (total/count);
    return average;
}