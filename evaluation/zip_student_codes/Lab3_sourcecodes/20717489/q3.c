#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

// Structure for Student
typedef struct Student {
    char name[MAX_NAME_LENGTH];
    int id;
    float grade;
    struct Student* next;
} Student;

Student* head = NULL;

// Function prototypes
Student* createStudent(const char* name, int id, float grade);
void insertStudent(const char* name, int id, float grade);
void displayStudents();
void sortStudents();
Student* searchStudentByID(int id);
void deleteList();
void freeMemory();

int main() {
    int choice, id;
    char name[MAX_NAME_LENGTH];
    float grade;

    do {
        printf("\n1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records\n");
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
            name[strcspn(name, "\n")] = 0; // Remove newline
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
            printf("Records sorted by grade using bubble sort\n");
            break;
        case 4:
            printf("Enter ID to search: ");
            scanf("%d", &id);
            Student* found = searchStudentByID(id);
            if (found) {
                printf("Found: Name: %s, ID: %d, Grade: %.2f\n", found->name, found->id, found->grade);
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

Student* createStudent(const char* name, int id, float grade) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if (newStudent) {
        strcpy(newStudent->name, name);
        newStudent->id = id;
        newStudent->grade = grade;
        newStudent->next = NULL;
    }
    return newStudent;
}

void insertStudent(const char* name, int id, float grade) {
    Student* newStudent = createStudent(name, id, grade);
    if (newStudent) {
        newStudent->next = head;
        head = newStudent;
    }
}

void displayStudents() {
    Student* temp = head;
    while (temp != NULL) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", temp->name, temp->id, temp->grade);
        temp = temp->next;
    }
}

void sortStudents() {
    int swapped;
    Student* ptr1, * lptr = NULL;
    do {
        swapped = 0;
        ptr1 = head;
        while (ptr1->next != lptr) {
            if (ptr1->grade > ptr1->next->grade) {
                char tempName[MAX_NAME_LENGTH];
                int tempID;
                float tempGrade;

                strcpy(tempName, ptr1->next->name);
                strcpy(ptr1->next->name, ptr1->name);
                strcpy(ptr1->name, tempName);

                tempID = ptr1->next->id;
                ptr1->next->id = ptr1->id;
                ptr1->id = tempID;

                tempGrade = ptr1->next->grade;
                ptr1->next->grade = ptr1->grade;
                ptr1->grade = tempGrade;

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

Student* searchStudentByID(int id) {
    Student* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

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