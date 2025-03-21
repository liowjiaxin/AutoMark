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
                name[strcspn(name, "\n")] = '\0'; // Remove newline character
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
                printf("List deleted.\n");
                break;
            case 6:
                printf("Exiting...\n");
                deleteList(); // Free memory before exiting
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

// Function to create a new student node
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

// Function to insert a new student record
void insertStudent(const char* name, int id, float grade) {
    Student* newStudent = createStudent(name, id, grade);
    if (!head) {
        head = newStudent;
    } else {
        Student* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newStudent;
    }
}

// Function to display all student records
void displayStudents() {
    if (!head) {
        printf("No records to display.\n");
        return;
    }
    Student* temp = head;
    printf("\nStudent Records:\n");
    printf("Name\tID\tGrade\n");
    while (temp) {
        printf("%s\t%d\t%.2f\n", temp->name, temp->id, temp->grade);
        temp = temp->next;
    }
}

// Function to search for a student by ID
Student* searchStudentByID(int id) {
    Student* temp = head;
    while (temp) {
        if (temp->id == id) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to delete the entire list
void deleteList() {
    Student* current = head;
    Student* next;
    while (current) {
        next = current->next;
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
    for (Student* i = head; i->next; i = i->next) {
        for (Student* j = head; j->next; j = j->next) {
            if (j->grade > j->next->grade) {
                // Swap nodes
                float tempGrade = j->grade;
                j->grade = j->next->grade;
                j->next->grade = tempGrade;

                int tempID = j->id;
                j->id = j->next->id;
                j->next->id = tempID;

                char tempName[100];
                strcpy(tempName, j->name);
                strcpy(j->name, j->next->name);
                strcpy(j->next->name, tempName);
            }
        }
    }
    printf("Records sorted by grade.\n");
}

