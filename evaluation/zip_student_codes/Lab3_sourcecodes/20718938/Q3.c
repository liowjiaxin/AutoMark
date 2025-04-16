#define _CRT_SECURE_NO_WARNINGS 
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

Student* createStudent(const char* name, int id, float grade) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    strcpy(newStudent->name, name);
    newStudent->id = id;
    newStudent->grade = grade;
    newStudent->next = NULL;
    return newStudent;
}

void insertStudent(const char* name, int id, float grade) {
    Student* newStudent = createStudent(name, id, grade);
    if (head == NULL) {
        head = newStudent;
    }
    else {
        Student* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newStudent;
    }
}

void displayStudents() {
    Student* current = head;
    while (current != NULL) {
        printf("Name: %s, ID: %d, Grade: %.2f\n",
            current->name, current->id, current->grade);
        current = current->next;
    }
}

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

void sortStudents() {
    if (head == NULL || head->next == NULL) {
        return;
    }
    Student* current;
    Student* index;
    float temp_grade;
    int temp_id;
    char temp_name[100];

    for (current = head; current != NULL; current = current->next) {
        for (index = current->next; index != NULL; index = index->next) {
            if (current->grade > index->grade) {
                temp_grade = current->grade;
                temp_id = current->id;
                strcpy(temp_name, current->name);

                current->grade = index->grade;
                current->id = index->id;
                strcpy(current->name, index->name);

                index->grade = temp_grade;
                index->id = temp_id;
                strcpy(index->name, temp_name);
            }
        }
    }
}

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
            printf("Records sorted by grade using Bubble Sort.\n");
            displayStudents();
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