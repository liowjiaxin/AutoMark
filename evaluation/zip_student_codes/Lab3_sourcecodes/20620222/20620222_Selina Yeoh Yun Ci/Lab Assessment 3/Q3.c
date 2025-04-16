#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Structure for Student
typedef struct Student {
    char name[100];
    int id;
    float grade;
    struct Student* next;
} Student;

Student* head = NULL;
// Function to create a new student node
Student* createStudent(const char* name, int id, float grade) {
    Student*new = (Student*)malloc(sizeof(Student));
    if(!new){
        printf("Memory allocation failed. \n");
        exit(EXIT_FAILURE);
    }

    strcpy(new -> name, name);
    new -> id = id;
    new -> grade = grade;
    new -> next = NULL;
    return new;
}

// Function to insert a new student record
void insertStudent(const char* name, int id, float grade) {
    Student*new = createStudent(name, id, grade);
    if(head == NULL){
        head = new;
    }else{
        Student* temp = head;
        while(temp ->next !=NULL){
            temp = temp -> next;
        }
        temp -> next = new;
    }
    printf("Student record successfully added.\n");
}

// Function to display all student records
void displayStudents() {
    if (head==NULL){
        printf("No student records to display.\n");
        return;
    }
    Student* temp = head;
    puts("*********************************************");
    puts("              Student Records");
    puts("*********************************************");
    while(temp!=NULL){
        printf("Name: %s, ID: %d, Grade: %.2f\n", temp -> name, temp -> id, temp -> grade);
        temp = temp -> next;
    }
    puts("*********************************************");
}

// Function to search for a student by ID
Student* searchStudentByID(int id) {
    Student* temp = head;
    while(temp!=NULL){
        if(temp -> id ==id){
            return temp;
        }
        temp = temp -> next;
    }
    return NULL;
}

// Function to delete the entire list
void deleteList() {
    Student* current = head;
    Student* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
    printf("All student records deleted.\n");
}

void freeMemory() {
 deleteList();
}
// Sort function to sort the student records by grade based on an algorithm of your choice
void sortStudents() {
    if (head == NULL || head->next == NULL) {
        printf("Not enough records to sort.\n");
        return;
    }

    int swapped;
    Student *ptr1;
    Student *lptr = NULL;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->grade > ptr1->next->grade) {
                // Swap the grades
                float tempGrade = ptr1->grade;
                ptr1->grade = ptr1->next->grade;
                ptr1->next->grade = tempGrade;

                // Swap the IDs
                int tempID = ptr1->id;
                ptr1->id = ptr1->next->id;
                ptr1->next->id = tempID;

                // Swap the names
                char tempName[100];
                strcpy(tempName, ptr1->name);
                strcpy(ptr1->name, ptr1->next->name);
                strcpy(ptr1->next->name, tempName);

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);

    printf("Records sorted successfully.\n");
}

// Main function to drive the program
int main() {
   int choice, id;
   char name[100];
   float grade;
       do {
        puts("***************************************************************");
        puts("             Student Record Management System");
        puts("***************************************************************");
        puts("                   1.  Insert Student Record");
        puts("                   2.  Display Student Records");
        puts("                   3.  Sort Records");
        puts("                   4.  Search Record by ID");
        puts("                   5.  Delete List");
        puts("                   6.  Exit");
        puts("***************************************************************");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character
        switch (choice) {
            case 1:
                printf("Enter Name: ");
                fgets(name, sizeof(name), stdin);
                strtok(name, "\n");
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Grade: ");
                scanf("%f", &grade);
                insertStudent(name, id, grade);
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                sortStudents();
                break;
            case 4:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                Student* found = searchStudentByID(id);
                if (found) {
                    printf("Found: Name: %s, ID: %d, Grade: %.2f\n",
                    found->name, found->id, found->grade);
                } 
                else {
                    printf("Student not found.\n");
                }
                break;
            case 5:
                deleteList();
                printf("List deleted.\n");
                break;
            case 6:
                freeMemory();
                printf("Exiting...\n");
                break;
                default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);
    return 0;
}