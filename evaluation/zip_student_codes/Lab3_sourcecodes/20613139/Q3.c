#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a student record
typedef struct Student {
    char name[100];        // Name of the student
    int id;                // Student ID
    float grade;           // Grade of the student
    struct Student* next;  // Pointer to the next student in the linked list
} Student;

// Head pointer to the linked list
Student* head = NULL;

// Function declarations
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
        // Display menu options
        printf("\nStudent Records Management\n");
        printf("1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records\n");
        printf("4. Search Record by ID\n");
        printf("5. Delete List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                // Input details for the new student
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
                printf("Records sorted by grade using Bubble Sort.\n");
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
                deleteList(); // Ensure memory is freed before exiting
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
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

    // Insert at the beginning of the list
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
            return current; // Return pointer to the student record if found
        }
        current = current->next;
    }
    return NULL; // Return NULL if not found
}

// Function to delete the entire linked list
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

// Function to sort student records by grade using bubble sort
void sortStudents() {
    if (!head || !head->next) {
        return; // No sorting needed for empty or single-node lists
    }

    int swapped;
    Student* ptr;
    Student* lptr = NULL;

    do {
        swapped = 0;
        ptr = head;

        while (ptr->next != lptr) {
            if (ptr->grade > ptr->next->grade) {
                // Swap data of adjacent nodes
                char tempName[100];
                int tempID;
                float tempGrade;

                strcpy(tempName, ptr->name);
                tempID = ptr->id;
                tempGrade = ptr->grade;

                strcpy(ptr->name, ptr->next->name);
                ptr->id = ptr->next->id;
                ptr->grade = ptr->next->grade;

                strcpy(ptr->next->name, tempName);
                ptr->next->id = tempID;
                ptr->next->grade = tempGrade;

                swapped = 1;
            }
            ptr = ptr->next;
        }
        lptr = ptr;
    } while (swapped);
}
