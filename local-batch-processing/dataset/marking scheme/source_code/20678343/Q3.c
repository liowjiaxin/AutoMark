#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a student record
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
    int choice, id;
    char name[100];
    float grade;

    // Menu for student record management
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records by Grade\n");
        printf("4. Search Record by ID\n");
        printf("5. Delete All Records\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                scanf(" %[^
]", name);
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
                    printf("Student not found!\n");
                }
                break;
            case 5:
                deleteList();
                printf("All records deleted successfully!\n");
                break;
            case 6:
                deleteList(); // Free memory before exiting
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

// Function to create a new student node
Student* createStudent(const char* name, int id, float grade) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    strcpy(newStudent->name, name);
    newStudent->id = id;
    newStudent->grade = grade;
    newStudent->next = NULL;
    return newStudent;
}

// Function to add a student to the list
void insertStudent(const char* name, int id, float grade) {
    Student* newStudent = createStudent(name, id, grade);
    newStudent->next = head; // Insert at the beginning
    head = newStudent;
    printf("Student added successfully!\n");
}

// Function to display all students
void displayStudents() {
    if (head == NULL) {
        printf("No student records found.\n");
        return;
    }
    Student* temp = head;
    printf("Student Records:\n");
    while (temp != NULL) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", temp->name, temp->id, temp->grade);
        temp = temp->next;
    }
}

// Function to search for a student by ID
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

// Function to delete the entire list
void deleteList() {
    Student* temp = head;
    while (temp != NULL) {
        Student* toDelete = temp;
        temp = temp->next;
        free(toDelete);
    }
    head = NULL;
}

// Function to sort students by grade
void sortStudents() {
    if (head == NULL || head->next == NULL) return;

    int swapped;
    Student* ptr;
    Student* lptr = NULL;

    do {
        swapped = 0;
        ptr = head;

        while (ptr->next != lptr) {
            if (ptr->grade > ptr->next->grade) {
                char tempName[100];
                int tempID;
                float tempGrade;

                strcpy(tempName, ptr->name);
                strcpy(ptr->name, ptr->next->name);
                strcpy(ptr->next->name, tempName);

                tempID = ptr->id;
                ptr->id = ptr->next->id;
                ptr->next->id = tempID;

                tempGrade = ptr->grade;
                ptr->grade = ptr->next->grade;
                ptr->next->grade = tempGrade;

                swapped = 1;
            }
            ptr = ptr->next;
        }
        lptr = ptr;
    } while (swapped);
}
