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
    if (!newStudent) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(newStudent->name, name);
    newStudent->id = id;
    newStudent->grade = grade;
    newStudent->next = NULL;
    return newStudent;
}

void insertStudent(const char* name, int id, float grade) {
    Student* newStudent = createStudent(name, id, grade);
    newStudent->next = head;
    head = newStudent;
    printf("Student record added.\n");
}

void displayStudents() {
    if (!head) {
        printf("No student records found.\n");
        return;
    }
    Student* current = head;
    printf("\nStudent Records:\n");
    printf("-----------------------------------\n");
    while (current) {
        printf("Name: %s ID: %d Grade: %.2f\n", current->name, current->id, current->grade);
        current = current->next;
    }
}

Student* searchStudentByID(int id) {
    Student* current = head;
    while (current) {
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
    printf("All student records deleted.\n");
}

void sortStudents() {
    if (!head || !head->next) {
        printf("Not enough records to sort.\n");
        return;
    }

    int swapped;
    Student *ptr1, *lptr = NULL;

    while (1) {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->grade > ptr1->next->grade) {
                char tempName[100];
                int tempID;
                float tempGrade;

                strcpy(tempName, ptr1->name);
                tempID = ptr1->id;
                tempGrade = ptr1->grade;

                strcpy(ptr1->name, ptr1->next->name);
                ptr1->id = ptr1->next->id;
                ptr1->grade = ptr1->next->grade;

                strcpy(ptr1->next->name, tempName);
                ptr1->next->id = tempID;
                ptr1->next->grade = tempGrade;

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;

        if (!swapped) break;
    }

    printf("Records sorted using Bubble Sort.\n");
}

int main() {
    int choice, id;
    char name[100];
    float grade;

    while (1) {
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
                deleteList();
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

