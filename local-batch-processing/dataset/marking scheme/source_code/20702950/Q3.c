#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure for a student
typedef struct Student {
    char name[100];
    int id;
    float grade;
    struct Student* next;
} Student;

Student* head = NULL;

//Function to create a student node
Student* createStudent(const char* name, int id, float grade) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if (newStudent == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(newStudent->name, name);
    newStudent->id = id;
    newStudent->grade = grade;
    newStudent->next = NULL;
    return newStudent;
}

//Function to insert a student node
void insertStudent(const char* name, int id, float grade) {
    Student* newStudent = createStudent(name, id, grade);
    newStudent->next = head;
    head = newStudent;
}

//Function to diplay all the student records
void displayStudents() {
    if (head == NULL) {
        printf("No records to display.\n");
        return;
    }
    Student* current = head;
    while (current != NULL) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", current->name, current->id, current->grade);
        current = current->next;
    }
}

//Function to search student by their ID
Student* searchStudentByID(int id) {
    Student* current = head;
    while (current != NULL) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

//Function to delete the whole list
void deleteList() {
    Student* current = head;
    Student* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
    printf("List deleted successfully.\n");
}

//Function to sort the student records based on their grade
void sortStudents() {
    if (head == NULL || head->next == NULL) {
        return;
    }

    for (Student* i = head; i != NULL; i = i->next) {
        for (Student* j = i->next; j != NULL; j = j->next) {
            if (i->grade > j->grade) {
                char tempName[100];
                int tempId;
                float tempGrade;

                strcpy(tempName, i->name);
                tempId = i->id;
                tempGrade = i->grade;

                strcpy(i->name, j->name);
                i->id = j->id;
                i->grade = j->grade;

                strcpy(j->name, tempName);
                j->id = tempId;
                j->grade = tempGrade;
            }
        }
    }
    printf("Records sorted by grade using Bubble Sort.\n");
}


void freeMemory() {
    deleteList();
}


int main() {
    int choice, id;
    char name[100];
    float grade;

    //Menu
    do {
        printf("\n1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records\n");
        printf("4. Search Record by ID\n");
        printf("5. Delete List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

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
                    printf("Found: Name: %s, ID: %d, Grade: %.2f\n", found->name, found->id, found->grade);
                } else {
                    printf("Student not found.\n");
                }
                break;
            case 5:
                deleteList();
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
