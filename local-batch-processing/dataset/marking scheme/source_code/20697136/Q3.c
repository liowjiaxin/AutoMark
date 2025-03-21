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

Student* createStudent(const char* name, int id, float grade);
void insertStudent(const char* name, int id, float grade);
void displayStudents(Student* head);
Student* searchStudentByID(int id);
void sortStudents();
void deleteList();
void freeMemory();

// Main function to drive the program
int main() {
    int choice, id;
    char name[100];
    float grade;

    do {
        printf("\n1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records (choose sorting method)\n");
        printf("4. Search Record by ID\n");
        printf("5. Delete List\n");
        printf("6. Exit\n");
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
                displayStudents(head);
                break;
            case 3:
                sortStudents();
                break;
            case 4:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                searchStudentByID(id);
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
// Function to create a new student node
Student* createStudent(const char* name, int id, float grade) {
    head = (Student*) malloc(sizeof(Student)); // allocate memory space
    if (head == NULL){
        printf("No Memory Available. \n"); // error message
    } 
    else {
        // defining elements
        strcpy(head->name,name); 
        head->id = id;
        head->grade = grade;
        head->next = NULL;
    }
    return head;
}

// Function to insert a new student record
void insertStudent(const char* name, int id, float grade) {
    createStudent(name, id, grade);
}

// Function to display all student records
void displayStudents(Student* head) {
    Student * current = head;
    if(current == NULL){
        printf("No student records to display.\n");
    }
    while(current != NULL){ // while there are elements
        printf("Name: %s, ID: %d, Grade: %.2f\n", head->name, head->id, head->grade); // print their data
        current = current->next;
    }
}

// Function to search for a student by ID
Student* searchStudentByID(int id) {
    if (id == head->id){ // if user input is equal to an ID
        printf("Name: %s, ID: %d, Grade: %.2f\n", head->name, head->id, head->grade); // print the student's data
    }
    else {
        printf("Student not found.\n"); // if it is not equal, print error message
    }
    return 0;
}

// Sort function to sort the student records by grade based on an algorithm of your choice
void sortStudents() {
    //qsort(, , sizeof(), );
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
}
void freeMemory() {
    deleteList();
}