
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[100];
    int id;
    float grade;
    struct Student* next;
} Student;

Student* head = NULL; 
Student* createstudent(const char* name, int id, float grade) {
    Student* newstudent = (Student*)malloc(sizeof(Student));
    strcpy(newstudent->name, name);
    newstudent->id = id;
    newstudent->grade = grade;
    newstudent->next = NULL;
    return newstudent;// create student node
}


void insertstudent(const char* name, int id, float grade) {
    Student* newstudent = createstudent(name, id, grade);
    newstudent->next = head; // Insert into the head of the linked list
    head = newstudent;
    printf("Student added!\n");
}


void displaystudents() {//display all student records
    Student* temp = head;
    if (!temp) {
        printf("No students found.\n");
        return;
    }
    while (temp) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", temp->name, temp->id, temp->grade);
        temp = temp->next;
    }
}

// bubble sort
void sortstudents() {
    if (!head || !head->next) return; // only one，no need sort

    int swapped;
    do {
        swapped = 0;
        Student *current = head, *prev = NULL;
        while (current->next) {//If the score of the current node is greater than the score of the next node, exchange the two nodes.
            if (current->grade > current->next->grade) {
                Student* temp = current->next;
                current->next = temp->next;
                temp->next = current;
                if (prev) prev->next = temp;
                else head = temp;
                swapped = 1;
            }
            prev = current;
            current = current->next;
        }
    } while (swapped);
    printf("Students sorted by grade.\n");
}

// search students by student number
void searchstudentbyID(int id) {
    Student* temp = head;
    while (temp) {
        if (temp->id == id) {
            printf("Found:Name:%s,ID:%d,Grade:%.2f\n",temp->name,temp->id,temp->grade);
            return;
        }
        temp = temp->next;
    }
    printf("Student with ID %d not found.\n", id);
}

// delete student information
void deletelist() {
    Student* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("All students deleted.\n");
}

int main() {
    int choice, id;
    float grade;
    char name[100];

    do{
        printf("\nmenu:\n1.add student\n2.display students\n3.sort students by grade\n4.search student by ID\n5.delete all records\n6.exiting\nenter your choice:");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("enter Name: ");
                scanf("%s", name);
                printf("enter ID: ");
                scanf("%d", &id);
                printf("enter Grade: ");
                scanf("%f", &grade);
                insertstudent(name, id, grade);
                break;
            case 2:
                displaystudents();
                break;
            case 3:
                sortstudents();
                break;
            case 4:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                searchstudentbyID(id);
                break;
            case 5:
            deletelist();
            break;
            case 6:
                deletelist();
                printf("Exiting...\n");
                break;
            
            default:
                printf("Invalid choice, try again.\n");
            }
            
        }
     while(choice!=6);

    return 0;
}
