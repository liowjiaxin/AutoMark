#include<stdio.h>
#define a 3
#define name_length 50

void display(const char name[][name_length], const float mark[]);
void average(const float mark[], int count);


int main(){
    char name[a][name_length];
    float mark[a];
    for(size_t i=0;i<a;i++){
        printf("Enter the name of student %zu:",i+1);
        scanf("  %c ", &name[i][name_length]);
        printf("Enter the mark of student %zu:", i+1);
        scanf("%f", &mark[i]);
    }

  
}