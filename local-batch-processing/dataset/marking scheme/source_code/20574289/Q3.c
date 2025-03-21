// --------------------------------------

// Library Header Pull
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --------------------------------------

// Structure for Student
typedef struct Student {
    char name[100];
    int StudentID;
    float grade;
    struct Student* next;   // Pointer to the next Student in the linked list of students
} Student;

// -------------------------------------

// Global VAR for the head/top of the list of students
Student* head = NULL;

// Function to create a new student node
Student* createStudent(const char* name, int StudentID, float grade) {
    // Write your code (1 mark)
    // Allocation of MEM for a new student
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if (newStudent == NULL) {
        printf("Memory allocation failed!\n");
        exit(1); // Exit the program if memory allocation fails
    }
    // Initialization of the fields for the new student
    strcpy(newStudent->name, name);
    newStudent->StudentID = StudentID;
    newStudent->grade = grade;
    newStudent->next = NULL;
    return newStudent;
}

// Function to insert a new student record
void insertStudent(const char* name, int StudentID, float grade) {
    // Write your code (1 mark)
    Student* newStudent = createStudent(name, StudentID, grade);
    if (head == NULL) {
        head = newStudent;                  // If the lis is empty, set the head/top to the new/next student
    } else {
        Student* current = head;            // Add the new student at the end of the linked list
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newStudent;
    }
}

// Function to display all student records
void displayStudents() {
    // Write your code (1 mark)
    if (head == NULL) {
        printf("List is empty.\n");     // Data Validation & Error Handling with Return Handler
        return;
    }

    // While loop used to go through the LL and print each students list while the node its on is not empty.
    Student* current = head;
    while (current != NULL) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", current->name, current->StudentID, current->grade);
        current = current->next;
    }
}

// Function to delete the entire list
void deleteList() {
    Student* current = head;
    Student* next;
    // Using a While loop to go through the LL and free every node it goes through
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;            // Setting the Head/Top to NULL to state that the list is empty now.
}

void freeMemory() {
    deleteList();
}

// Sort function to sort the student records by grade using Bubble Sort
void sortStudents() {
    // Write your code (1 mark)
    // Choosing Bubble Sort as I already understand how to implement it from the Group Project

    int swapped;
    Student *ptr1;
    Student *lptr = NULL;

    // In case that the list is empty, return immediately as no sorting is needed.
    if (head == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = head;

                // While loop to go through the LL and compare the adjacent student's grades.
        while (ptr1->next != lptr) {

                // If the current students grade is higher than the next student's grade, swap them together/pointers used.
            if (ptr1->grade > ptr1->next->grade) {

                // Swap data of the nodes without swapping the nodes themselves
                char tempName[100];
                strcpy(tempName, ptr1->name);
                strcpy(ptr1->name, ptr1->next->name);
                strcpy(ptr1->next->name, tempName);

                int tempId = ptr1->StudentID;
                ptr1->StudentID = ptr1->next->StudentID;
                ptr1->next->StudentID = tempId;

                float tempGrade = ptr1->grade;
                ptr1->grade = ptr1->next->grade;
                ptr1->next->grade = tempGrade;

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;    // Last swap/node swapped is set at the end of the list.
    } while (swapped);  // If any swaps occur, continue swapping until they stop.
}

// Advanced partial search feature for Student ID
void searchPartialID() {
    char searchTerm[20]; // Assuming ID is stored as a string for partial search
    int found = 0; // Flag to check if any match is found

    printf("Enter the partial or full ID to search: ");
    scanf(" %[^\n]", searchTerm);

    // While loop used to go through the LL and look for matching IDs
    Student* current = head;
    while (current != NULL) {
        char idString[20];
        sprintf(idString, "%d", current->StudentID); // Convert ID to string for comparison

        // strstr mnemonic used to search for parts of the ID
        if (strstr(idString, searchTerm) != NULL) {
            printf("Match found: Name: %s, ID: %d, Grade: %.2f\n",
                   current->name, current->StudentID, current->grade);
            found = 1;
        }
        current = current->next;
    }

    if (!found) {
        printf("No students found with the given partial ID.\n");
    }
}

// Main function to drive the program
int main() {
    int choice, StudentID;
    char name[100];
    float grade;
    printf("Welcome to the Student Recordkeeping & Information Processing Program [Inspired from RAISA] \nFor assistance in any inquiries or bug reporting, kindly refer to your closest handler or contact efyms24.\nEnjoy!\n- efyms24\n\n");
    do {
        printf("\n1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records (Bubble Sort in Ascending Order for Grades)\n");
        printf("4. Partial Search by ID\n"); // Implemented Partial Search function inspired and adapted from the Group Project [Contact Management System]
        printf("5. Delete List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character

        switch (choice) {
            case 1:
                printf("\nEnter Name: ");
                fgets(name, sizeof(name), stdin);
                strtok(name, "\n"); // Remove the trailing newline from fgets()
                printf("Enter ID: ");
                scanf("%d", &StudentID);
                printf("Enter Grade: ");
                scanf("%f", &grade);
                insertStudent(name, StudentID, grade);
                break;
            case 2:
                printf("\n");
                displayStudents();
                break;
            case 3:
                printf("\n");
                sortStudents();
                printf("Records sorted by grade in ascending order using Bubble Sort.\n");
                break;
            case 4: // Now calls searchPartialID()
                printf("\n");
                searchPartialID();
                break;
            case 5:
                printf("\n");
                deleteList();
                printf("List deleted.\n");
                break;
            case 6:
                printf("\n");
                freeMemory();
                printf("Exiting...\n");
                break;
            default:
                printf("\n");
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
