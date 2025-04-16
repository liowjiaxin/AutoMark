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

// Function to create a new student node
Student* createStudent(const char* name, int id, float grade) {
    Student *newStudent = malloc(sizeof(Student));     // Allocate new memory for new student input

    if (newStudent != NULL) {               // An if else statement to ensure memory allocation is successful before the program proceeds
        strcpy(newStudent -> name, name);   // Copies the student name input into the node
        newStudent -> id = id;              // Transfers the student id input into the node
        newStudent -> grade = grade;        // Transfers the student grade input into the node
        newStudent -> next = NULL;          // After every data has been input, the current node does not link to another node
    }
    return newStudent;                      // Returns the pointer to the newly created struct
}

// Function to insert a new student record
void insertStudent(const char* name, int id, float grade) {
    Student *newStudent = createStudent(name, id, grade);   // Creates a new node and calls the function createStudent to get the values for the node

    if (newStudent != NULL) {           // An if else statement to ensure memory allocation is successful before the program proceeds
        newStudent -> next = head;      // Program inserts new node at the beginning of the list
        head = newStudent;
    }
}

// Function to display all student records
void displayStudents() {
    if (head == NULL) {     // Output a message if the student record is empty/no student records have been input yet
        puts("Empty Student Records.\n");
    } else {
        puts("\nStudent Records:\n");

        Student *newStudent = head;             // Start the list from the head

        while (newStudent != NULL) {            // An if else statement to ensure memory allocation is successful before the program proceeds
            printf("Name: %s, ID: %d, Grade: %.2f\n", newStudent->name, newStudent->id, newStudent->grade);     // Prints out the following data
            newStudent = newStudent -> next;    // Move to the next node
        }
    }
}

// Function to search for a student by ID
Student* searchStudentByID(int id) {    
    Student *newStudent = head;              // Start the list from the head
    while (newStudent != NULL) {             // Ensures memory allocation is successful before the program proceeds
        if (newStudent -> id == id) {        // If the id user input matches a student's id in the list, return with the matching student (in context with menu below, found is true)
            return newStudent;
        }
        newStudent = newStudent -> next;     // Program runs each list until the list with the matching id is found
    }
    return NULL;                             // If no matches, program returns a NULL terminatore (or found is false)
}

// Function to delete the entire list
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

void freeMemory() {
    deleteList();
}

// Sort function to sort the student records by grade based on an algorithm of your choice
void sortStudents() {
    if (head == NULL) {     // Output a message if the student record is empty/no student records have been input yet
        puts("Empty Student Records.\n");
    } else {
        int swapped;
        Student *node;              // Start from first node
        Student *lastNode = NULL;   // Tracks the last node in the sorted order

        do {
            swapped = 0;
            node = head;

            // Buffer sort
            while (node->next != lastNode) {    // Bubble sort continues until the current reading node is the last node
                if (node->grade > node->next->grade) {    // Swaps data if the current id is more than the next id
                    // Declare temporary variables to store the information of the current student
                    int tempID = node->id;
                    float tempGrade = node->grade;
                    char tempName[100];
                    strcpy(tempName, node->name);

                    // Transfer the student information of the next student to the current student
                    node->id = node->next->id;
                    node->grade = node->next->grade;
                    strcpy(node->name, node->next->name);

                    // Finally transfer the temporary variables into the next student
                    node->next->id = tempID;
                    node->next->grade = tempGrade;
                    strcpy(node->next->name, tempName);

                    swapped = 1;
                }
                node = node->next; // Once done the program compares the next student to use as the current student and the following student to be the next student
            }
            lastNode = node;   // Updates the last node to just be node

        } while (swapped);
        puts("Records sorted by grade using Bubble Sort.\n");
    }
}

// Main function to drive the program
int main() {
    int choice, id;
    char name[100];
    float grade;
    do {
        printf("\n1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records (choose sorting method)\n");
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
                    printf("Found: Name: %s, ID: %d, Grade: %.2f\n",
                    found->name, found->id, found->grade);
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
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}