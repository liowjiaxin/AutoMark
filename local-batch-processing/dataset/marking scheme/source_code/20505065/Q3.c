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

// Function prototypes
Student* createStudent(const char* name, int id, float grade);
void insertStudent(const char* name, int id, float grade);
void displayStudents();
Student* searchStudentByID(int id);
void deleteList();
void sortStudents();

int main() {
    int choice, id;
    char name[100];
    float grade;

    do {
        printf("\nMenu:\n");
        printf("1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records by Grade\n");
        printf("4. Search Record by ID\n");
        printf("5. Delete List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

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
                printf("Records sorted by grade.\n");
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
                printf("List deleted.\n");
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

Student* createStudent(const char* name, int id, float grade) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if (!newStudent) {
        printf("Memory allocation failed.\n");
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
    printf("Student record inserted.\n");
}

void displayStudents() {
    if (!head) {
        printf("No student records to display.\n");
        return;
    }
    Student* current = head;
    printf("\n%-20s %-10s %-10s\n", "Name", "ID", "Grade");
    printf("------------------------------------\n");
    while (current) {
        printf("%-20s %-10d %-10.2f\n", current->name, current->id, current->grade);
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
    while (current) {
        Student* temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;
}

void sortStudents() {
    if (!head || !head->next) {
        return;
    }
    for (Student* i = head; i->next; i = i->next) {
        for (Student* j = i->next; j; j = j->next) {
            if (i->grade > j->grade) {
                // Swap records
                char tempName[100];
                int tempID;
                float tempGrade;

                strcpy(tempName, i->name);
                tempID = i->id;
                tempGrade = i->grade;

                strcpy(i->name, j->name);
                i->id = j->id;
                i->grade = j->grade;

                strcpy(j->name, tempName);
                j->id = tempID;
                j->grade = tempGrade;
            }
        }
    }
}
