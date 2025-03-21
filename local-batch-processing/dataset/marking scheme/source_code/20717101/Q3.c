#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a student record
typedef struct Student {
    char name[100];
    int id;
    float grade;
    struct Student* next;
} Student;

Student* head = NULL; // Head of the linked list

// Function prototypes
Student* createStudent(const char* name, int id, float grade);
void insertStudent(const char* name, int id, float grade);
void displayStudents();
Student* searchStudentByID(int id);
void deleteList();
void sortStudents();

int main() {
    int choice;
    char name[100];
    int id;
    float grade;

    while (1) {
        printf("\nStudent Records Management:\n");
        printf("1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records by Grade\n");
        printf("4. Search Record by ID\n");
        printf("5. Delete All Records\n");
        printf("6. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from input buffer

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline

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
                printf("All records deleted.\n");
                break;
            case 6:
                deleteList();
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

// Function to create a new student node
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

// Function to insert a new student record
void insertStudent(const char* name, int id, float grade) {
    Student* newStudent = createStudent(name, id, grade);
    newStudent->next = head;
    head = newStudent;
    printf("Student record added successfully.\n");
}

// Function to display all student records
void displayStudents() {
    if (!head) {
        printf("No student records found.\n");
        return;
    }

    printf("\nStudent Records:\n");
    Student* current = head;
    while (current) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", current->name, current->id, current->grade);
        current = current->next;
    }
}

// Function to search for a student by ID
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

// Function to delete the entire list
void deleteList() {
    Student* current = head;
    while (current) {
        Student* next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
}

// Function to sort student records by grade
void sortStudents() {
    if (!head || !head->next) {
        printf("Not enough records to sort.\n");
        return;
    }

    for (Student* i = head; i && i->next; i = i->next) {
        for (Student* j = head; j->next; j = j->next) {
            if (j->grade > j->next->grade) {
                // Swap records
                char tempName[100];
                int tempID = j->id;
                float tempGrade = j->grade;

                strcpy(tempName, j->name);
                j->id = j->next->id;
                j->grade = j->next->grade;
                strcpy(j->name, j->next->name);

                strcpy(j->next->name, tempName);
                j->next->id = tempID;
                j->next->grade = tempGrade;
            }
        }
    }
    printf("Records sorted by grade successfully.\n");
}
