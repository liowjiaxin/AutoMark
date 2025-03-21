#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Student
typedef struct Student {
    char name[100];
    int id;
    float grade;
    struct Student* next;   // Pointer to the next student in the list
} Student;

Student* head = NULL;

// Function to create a new student node
Student* createStudent(const char* name, int id, float grade) {
    // Allocate memory for the new student node
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if (newStudent == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Copy the student details into the ode
    strcpy(newStudent->name, name);
    newStudent->id = id;
    newStudent->grade = grade;
    newStudent->next = NULL;    // Initialize the next pointer to NULL

    return newStudent;  // Return the newly created student node
}

// Function to insert a new student record
void insertStudent(const char* name, int id, float grade) {
    // Create a new student node
    Student* newStudent = createStudent(name, id, grade);

    // Insert the node at the beginnning of the list
    newStudent->next = head;
    head = newStudent;

    printf("Student record inserted successfully.\n");
}

// Function to display all student ecords
void displayStudents() {
    // Check is the list is empty
    if (head == NULL) {
        printf("No student records found.\n");
        return;
    }

    // Tranverse the list and print each student record
    Student* current = head;
    printf("\nStudent Records:\n");
    while (current != NULL) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", current->name, current->id, current->grade);
        current = current->next;
    }
}

// Function to search for a student by ID
Student* searchStudentByID(int id) {
    // Trancerse the list to find the student with the given ID
    Student* current = head;
    while (current != NULL) {
        if (current->id == id) {
            return current; // Return the student ode if found
        }
        current = current->next;
    }
    return NULL;    // Return NULL if the student node if found
}

// Function to delete the entire list
void deleteList() {
    Student* current = head;
    Student* next;

    // Free each node in the list
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    head = NULL;    //Reset the head pointer to NULL
    printf("All student records deleted.\n");
}

// Utility function to free memory (alias for deleteList)
void freeMemory() {
    deleteList();
}

// Sort function to sort the student records by grade using based on Bubble sort
void sortStudents() {
    // Check if the list is empty or has only one element
    if (head == NULL || head-> next == NULL) {
        return;
    }

    int swapped;
    Student* ptr1;
    Student* lptr = NULL;

    // Bubble Sort implementation
    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->grade > ptr1->next->grade) {
                // Swap the student details
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
    } while (swapped);

    printf("Student records sorted by grade.\n");
}

// Main function to drive the program
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
        getchar();  // To consume the newline character

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, sizeof(name), stdin);
                strtok(name, "\n"); // Remove newline character
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter grade: ");
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
                printf("Student Found: %s, ID: %d, Grade: %.2f\n", found->name, found->id, found->grade);
            } else {
                printf("Student with ID %d, not found.\n", id);
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
