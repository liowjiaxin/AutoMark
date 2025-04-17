#include <stdio.h>
#define NAME_LENGTH 50 //declaring length of names array
int main(){
    float calculateAverage(const float marks[], int count); 
    void displayStudentData(const char names[][NAME_LENGTH], const float marks[]);  // NAME_LENGTH 50
    char names[NAME_LENGTH];
    float marks[]={0.0};
    for(int i=1;i<=3;++i){
        printf("Enter name of student %d: ",i,names[i]);
        scanf(" %[^\n]", &names[i]);
        printf("Enter marks of student %d: ",i,marks[i]);
        scanf("%f", &marks[i]);

    }

}

void displayStudentData(const char array[][NAME_LENGTH],const float arr[]){
    printf("Student Names and Marks: \n");
        for(int n= 0;n<=2;++n){
            printf("%s :",array[n]);
            printf("%.2f \n",arr[n]);
        }
    printf("\n");
    return;
}




float calculateAverage(const float arr[],int count){
    float sum=0.0, avg;
    for (int j= 0;j<=2;++j){
        scanf("%f",&arr[j]);
        sum+= arr[j];
        count++;
    }
    avg=sum/count;
    printf("Average Mark: %.2f", avg );
}