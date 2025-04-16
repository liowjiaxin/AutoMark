#include <stdio.h>  // For standard input/output functions
#include <stdlib.h>  // For extra utilities like memory allocation
#include <string.h>  // For string manipulation functions

// Structure for 'Student'
typedef struct Student {
    char name[100];
    int id;
    float grade;
    struct Student* next;
} Student;

Student* head = NULL; // This is the global pointer to the head of the linked list

// Function to create a new student node
Student* createStudent(const char* name, int id, float grade) {
    // Allocate memory for the new student
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if (newStudent == NULL) {
        printf("Memory allocation has failed!\n");
        exit(1); // Exit if the memory allocation fails
    }

    //Copy the student's name safely to prevent buffer overflow
    strncpy(newStudent->name, name, sizeof(newStudent->name) - 1);
    newStudent->name[sizeof(newStudent->name) - 1] = '\0'; // Ensure null-termination here

    // Set the student's ID and grade
    newStudent->id = id;
    newStudent->grade = grade;

    // New student's next pointer is set to NULL since there's no connection yet
    newStudent->next = NULL;

    return newStudent;
}

// Function to insert a new student record 
void insertStudent(const char* name, int id, float grade) {
    // Create a new student node
    Student* newStudent = createStudent(name, id, grade);

    // Make the new student the head of the list
    newStudent->next = head;
    head = newStudent;
}

// Function to display all student records
void displayStudents() {
    // Start at the head of the list
    Student* current = head;

    if (current == NULL) {
        printf("There are no student records to display.\n");
        return;
    }

    // Traverse the list and print each student's information
    while (current != NULL) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", current->name, current->id, current->grade);
        current = current->next;
    }
}

// Function to search for a student by ID
Student* searchStudentByID(int id) {
    // Start at the head of the list
    Student* current = head;

    // Traverse the list and search for the student with the matching ID
    while (current != NULL) {
        if (current->id == id) {
            return current; // Student found, so return a pointer to the student
        }
        current = current->next;
    }

    return NULL; // Student not found
}

// Function to delete the entire list
void deleteList() {
    Student* current = head;
    Student* next;

    // Traverse the list and free the memory for each student node
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    head = NULL; // Reset the head to 'NULL' (meaning empty list)
}

// This is a utility function to ensure that all memory is freed when program exits
void freeMemory() {
    deleteList();
}

// Sort function to sort the student records by grade based on an algorithm of your choice
void sortStudents() {
    
    /* 
       'Bubble Sort' was chosen because it's simplest to implement for a linked list, 
       though not the most efficient for large lists. For larger datasets, 'Merge Sort' 
       or 'Quick Sort' are better choices. 
    */

    int swapped;
    Student *ptr1;
    Student *lptr = NULL;

    // Checking for an empty list here
    if (head == NULL) {
        printf("There are no records to sort.\n");
        return;
    }

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->grade > ptr1->next->grade) {
                // Swap the data of the two nodes
                char tempName[100];
                strcpy(tempName, ptr1->name);
                strcpy(ptr1->name, ptr1->next->name);
                strcpy(ptr1->next->name, tempName);

                int tempId = ptr1->id;
                ptr1->id = ptr1->next->id;
                ptr1->next->id = tempId;

                float tempGrade = ptr1->grade;
                ptr1->grade = ptr1->next->grade;
                ptr1->next->grade = tempGrade;

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
    
    printf("The records were sorted by grade using 'Bubble Sort'.\n");
}

// Main function to drive our program
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
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        getchar(); // This to consume the newline character left by the scanf

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                fgets(name, sizeof(name), stdin);
                strtok(name, "\n"); // Remove trailing newline from fgets
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
                    printf("The student was not found.\n");
                }
                break;
            case 5:
                deleteList();
                printf("The list has been deleted.\n");
                break;
            case 6:
                freeMemory();
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}