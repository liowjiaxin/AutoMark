#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Student structure to hold student details
typedef struct Student {
    char name[50];           // Student's name
    int id;                  // Student's ID
    float grade;             // Student's grade
    struct Student* next;    // Pointer to the next student in the list
} Student;

Student* head = NULL;        // Head pointer for the linked list

// Function to create a new student node
Student* createStudent(const char* name, int id, float grade) {
    Student* newStudent = (Student*)malloc(sizeof(Student)); // Allocate memory for a new student
    strcpy(newStudent->name, name);   // Copy the name into the new student node
    newStudent->id = id;              // Assign the ID
    newStudent->grade = grade;        // Assign the grade
    newStudent->next = NULL;          // Initialize the next pointer to NULL
    return newStudent;
}

// Insert a new student record into the linked list
void insertStudent(const char* name, int id, float grade) {
    Student* newStudent = createStudent(name, id, grade); // Create a new student node
    newStudent->next = head;     // Point the new node to the current head of the list
    head = newStudent;           // Update the head pointer to the new node
    printf("Student record inserted successfully.\n");
}

// Display all student records in the list
void displayStudents() {
    if (head == NULL) {          // Check if the list is empty
        printf("No records found.\n");
        return;
    }

    Student* temp = head;        // Temporary pointer to traverse the list
    while (temp != NULL) {       // Iterate until the end of the list
        printf("Name: %s, ID: %d, Grade: %.2f\n", temp->name, temp->id, temp->grade);
        temp = temp->next;       // Move to the next node
    }
}

// Sort the student records by grade using Bubble Sort
void sortStudents() {
    if (head == NULL || head->next == NULL) { // Check if sorting is unnecessary
        printf("No sorting needed.\n");
        return;
    }

    // Bubble Sort: Compare and swap data between adjacent nodes
    Student* i;
    Student* j;
    for (i = head; i != NULL; i = i->next) {
        for (j = head; j->next != NULL; j = j->next) {
            if (j->grade > j->next->grade) {  // Swap if the current grade is greater than the next
                // Temporary variables to hold the data
                char tempName[50];
                int tempID;
                float tempGrade;

                // Swap names
                strcpy(tempName, j->name);
                strcpy(j->name, j->next->name);
                strcpy(j->next->name, tempName);

                // Swap IDs
                tempID = j->id;
                j->id = j->next->id;
                j->next->id = tempID;

                // Swap grades
                tempGrade = j->grade;
                j->grade = j->next->grade;
                j->next->grade = tempGrade;
            }
        }
    }
    printf("Records sorted by grade using Bubble Sort.\n");
}

// Search for a student record by ID
Student* searchStudentByID(int id) {
    Student* temp = head;        // Temporary pointer to traverse the list
    while (temp != NULL) {       // Iterate through the list
        if (temp->id == id) {    // Check if the current node matches the given ID
            return temp;         // Return the matching node
        }
        temp = temp->next;       // Move to the next node
    }
    return NULL;                 // Return NULL if no match is found
}

// Delete the entire linked list
void deleteList() {
    Student* temp;
    while (head != NULL) {       // Iterate through the list
        temp = head;             // Store the current head node
        head = head->next;       // Move the head pointer to the next node
        free(temp);              // Free memory for the current node
    }
    printf("All records deleted successfully.\n");
}

int main() {
    int choice, id;
    char name[50];
    float grade;

    do {
        // Display the menu
        printf("\n1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records\n");
        printf("4. Search Record by ID\n");
        printf("5. Delete List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Insert a new student record
                printf("Enter Name: ");
                scanf(" %[^\n]s", name); // Read the name
                printf("Enter ID: ");
                scanf("%d", &id);        // Read the ID
                printf("Enter Grade: ");
                scanf("%f", &grade);     // Read the grade
                insertStudent(name, id, grade);
                break;

            case 2:
                // Display all student records
                displayStudents();
                break;

            case 3:
                // Sort student records by grade
                sortStudents();
                break;

            case 4:
                // Search for a student record by ID
                printf("Enter ID: ");
                scanf("%d", &id);
                Student* result = searchStudentByID(id);
                if (result != NULL) {
                    printf("Name: %s, ID: %d, Grade: %.2f\n", result->name, result->id, result->grade);
                } else {
                    printf("Record not found.\n");
                }
                break;

            case 5:
                // Delete all student records
                deleteList();
                break;

            case 6:
                // Exit the program
                deleteList(); // Ensure memory is freed before exiting
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}