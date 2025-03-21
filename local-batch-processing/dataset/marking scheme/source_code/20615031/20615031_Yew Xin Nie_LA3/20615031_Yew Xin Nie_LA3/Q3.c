#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct definition for a student node
typedef struct Student {
    char name[100];
    int id;
    float grade;
    struct Student* next;
} Student;

// Head pointer for the linked list //
Student* head = NULL;

                // Function prototypes //
// Function to create a new student node//
Student* createStudent(const char* name, int id, float grade){
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

// Function to insert a student into the linked list
void insertStudent(const char* name, int id, float grade){
    Student* newStudent = createStudent(name, id, grade);
    newStudent->next = head;
    head = newStudent;
}

// Function to display all student records in the linked list
void displayStudents(){
    if (!head) {
        printf("No student records available.\n");
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
Student* searchStudentByID(int id){
    Student* current = head;
    while (current) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to delete the entire linked list and frees the allocated memory
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

// Function to ensure all memory is freed 
void freeMemory() {
    deleteList();
}

// Function to sort the student records by grades using bubble sorting alogrithm
void sortStudents() {
    if (!head || !head->next) {
        return; // No sorting needed for empty or single-node list
    }

    // Bubble Sort for simplicity
    int swapped; // keep track of swaps were made during an iteration
    Student* pass;  // a pointer that traverses the lsit during each pass
    Student* last_pass = NULL;  // marks the last sorted position in the list

// Ensure sorting until no swaps until end of the list
    do {
        swapped = 0;    // Reset swapped flag for each pass
        pass = head;    // Starting of the list

        // Make sure the list is in the correct order
        while (pass->next != last_pass) {
            if (pass -> grade > pass -> next -> grade) {
                // Swap grades
                float tempGrade = pass ->grade;
                pass ->grade = pass -> next -> grade;
                pass-> next -> grade = tempGrade;

                // Swap IDs
                int tempID = pass -> id;
                pass -> id = pass -> next -> id;
                pass -> next -> id = tempID;

                // Swap names
                char tempName[100];
                strcpy(tempName, pass -> name);
                strcpy(pass -> name, pass -> next -> name);
                strcpy(pass -> next -> name, tempName);

                swapped = 1; // Shows that list is unsorted
            }
            pass = pass -> next;
        }
        last_pass = pass;   // the last node is in the correct position
    } while (swapped == 0); 
}

int main() {
    // Decalre variable and intialize zone//
    int choice, id = 0;
    char name[100];
    float grade = 0.0;
    Student* foundStudent;

    do {
        printf("\nStudent Records Management System\n");
        printf("\t1. Insert Student Record\n");
        printf("\t2. Display Student Records\n");
        printf("\t3. Sort Records by Grade\n");
        printf("\t4. Search Record by ID\n");
        printf("\t5. Delete All Records\n");
        printf("\t6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // To consume the newline character

        switch (choice) {
            // Insert Student Record //
            case 1:
                printf("Enter student's name: ");
                getchar();              // Clear newline from input buffer
                fgets(name, sizeof(name), stdin);
                strtok(name, "\n");     // Remove newline

                printf("Enter student's ID: ");
                scanf("%d", &id);

                printf("Enter student's grade: ");
                scanf("%f", &grade);

                insertStudent(name, id, grade);
                printf("Student record inserted successfully.\n");
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                sortStudents();
                printf("Student records sorted by grade.\n");
                break;

            case 4:
                printf("Enter the ID to search: ");
                scanf("%d", &id);
                Student* found = searchStudentByID(id);
                if (found) {
                    printf("Student Found:\n");
                    printf("Name: %s, ID: %d, Grade: %.2f\n", found->name, found->id, found->grade);
                } else {
                    printf("Student not found.\n");
                }
                break;

            case 5:
                deleteList();
                printf("List deleted.\n");
                break;

            case 6:
                freeMemory();
                printf("Exiting program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}












