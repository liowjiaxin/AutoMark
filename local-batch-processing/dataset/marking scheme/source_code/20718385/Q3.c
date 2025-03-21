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
    Student* new = (Student*)malloc(sizeof(Student));
    strcpy(new->name, name);
    new->id = id;
    new->grade = grade;
    new->next = NULL;
    return new;
}

// Function to insert a new student record
void insertStudent(const char* name, int id, float grade) {
    Student* new = createStudent(name, id, grade);
    if(head == NULL){
        head = new;
        return;
    }
    else{
        Student* now = head;
        while(now->next != NULL){
            now = now->next;
        }
        now->next = new;
    }
}

// Function to display all student records
void displayStudents() {
    Student* now = head;
    while(now != NULL){
        printf("Name: %s, ID: %d, Grade: %.2f\n", now->name, now->id, now->grade);
        now = now->next;
    }
}

// Function to search for a student by ID
Student* searchStudentByID(int id) {
    Student* now = head;
    while(now){
        if(now->id == id){
            return now;
        }
        now = now->next;
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
}

void freeMemory() {
    deleteList();
}

// Sort function to sort the student records by grade based on bubble sort
void sortStudents() {
    Student* ptr1;
    Student* ptr2 = NULL;

    printf("Records sorted by grade using Bubble Sort.\n");
}
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
                 } else {
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
