#include <stdio.h>
#define NAME_LENGTH 50

float calculateAverage(const float marks[]){
    float sum=0;
    float average;
    for (int a=0;a<3;a++){
        sum+=marks[a];
    }
    average=sum/3;
    return average;
}

void displayStudentData(const char name[][NAME_LENGTH],const float marks[]){
    printf("Student Names and Marks: \n");
    for (int a=0;a<3;a++){
        printf("%s: %.2f\n",name[a],marks[a]);
    }
}

int main(){
    char name[3][NAME_LENGTH];
    float marks[3];
    
    for (int i=0;i<3;i++){
        printf("Enter the name of student %d: ",i+1);
        if (i!=0){
            while (getchar()!='\n');
        }
        scanf("%[^\n]",name[i]);
        printf("Enter the mark of student %d: ",i+1);
        scanf("%f",&marks[i]);
    }
    puts("");
    displayStudentData(name,marks);
    puts("");
    printf("Average Mark: %.2f",calculateAverage(marks));
}