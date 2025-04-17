#include <stdio.h>

float calculateAverage(float sumMarks,int count);
void displayStudentData(char name[][50], float marks[], int count);

int main(){
    char name[100][50];
    float marks[100];
    float sum=0;
    int counter=1;

    
 // taking input and storing it in an array
  for(int i = 0; i < 3; i++) {
     printf("Enter the name of student %d: ", counter);
     scanf(" %[^\n]", name[i]);
     printf("Enter the mark of student %d: ", counter);
     scanf("%f", &marks[i]);
     counter++;
     sum+=marks[i];
  }
    displayStudentData(name, marks,3);
    
   float average=calculateAverage(sum, 3);

    printf("\n");

  printf("Average Mark: %.2f", average);

  return 0;
}

void displayStudentData(char name[][50], float marks[],int count){
    printf("Student Names and Marks:\n");
    for(int i = 0; i < count; i++){
    printf("%s: %.2f\n", name[i], marks[i]);
    }
}

float calculateAverage(float sumMarks, int count){
    return (float)sumMarks/count;
}



