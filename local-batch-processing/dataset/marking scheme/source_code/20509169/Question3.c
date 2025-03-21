#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Student
typedef struct Student {
    char name[100];              // Student's name
    int id;                      // Student's ID
    float grade;                 // Student's grade
    struct Student* next;        // Pointer to the next student in the linked list
} Student;

Student* head = NULL;            // Pointer to the head of the linked list

// Function prototypes
Student* createStudent(const char* name, int id, float grade);
void insertStudent(const char* name, int id, float grade);
void displayStudents();
void sortStudents();
Student* searchStudentByID(int id);
void deleteList();

// Function to create a new student node
Student* createStudent(const char* name, int id, float grade) {
    Student* newStudent = (Student*)malloc(sizeof(Student)); // Allocate memory for a new student
    strcpy(newStudent->name, name);                         // Copy name
    newStudent->id = id;                                    // Set ID
    newStudent->grade = grade;                              // Set grade
    newStudent->next = NULL;                                // Initialize next pointer to NULL
    return newStudent;
}

// Function to insert a new student record into the linked list
void insertStudent(const char* name, int id, float grade) {
    Student* newStudent = createStudent(name, id, grade);   // Create a new student node
    if (head == NULL) {                                     // If the list is empty
        head = newStudent;                                  // Set head to the new student
    } else {
        Student* temp = head;                               // Traverse to the end of the list
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newStudent;                            // Append the new student at the end
    }
    printf("Student inserted successfully.\n");
}

// Function to display all student records
void displayStudents() {
    if (head == NULL) {
        printf("No student records found.\n");
        return;
    }

    Student* temp = head;                                   // Start from the head of the list
    printf("\nStudent Records:\n");
    while (temp != NULL) {                                  // Traverse the list
        printf("Name: %s, ID: %d, Grade: %.2f\n", temp->name, temp->id, temp->grade);
        temp = temp->next;                                  // Move to the next student
    }
}

// Function to sort students by grade in ascending order
void sortStudents() {
    if (head == NULL || head->next == NULL) return;         // If 0 or 1 student, no need to sort

    Student* i;
    Student* j;
    float tempGrade;
    int tempID;
    char tempName[100];

    for (i = head; i != NULL; i = i->next) {                // Bubble sort algorithm
        for (j = i->next; j != NULL; j = j->next) {
            if (i->grade > j->grade) {                      // Swap if grades are out of order
                // Swap grades
                tempGrade = i->grade;
                i->grade = j->grade;
                j->grade = tempGrade;

                // Swap IDs
                tempID = i->id;
                i->id = j->id;
                j->id = tempID;

                // Swap names
                strcpy(tempName, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, tempName);
            }
        }
    }
    printf("Students sorted by grade successfully.\n");
}

// Function to search for a student by ID
Student* searchStudentByID(int id) {
    Student* temp = head;                                   // Start from the head of the list
    while (temp != NULL) {
        if (temp->id == id) return temp;                    // Return the student if ID matches
        temp = temp->next;
    }
    return NULL;                                            // Return NULL if not found
}

// Function to delete the entire list and free memory
void deleteList() {
    Student* temp = head;
    while (temp != NULL) {
        Student* next = temp->next;                         // Store the next node
        free(temp);                                         // Free the current node
        temp = next;                                        // Move to the next node
    }
    head = NULL;                                            // Set head to NULL after deletion
    printf("All student records deleted successfully.\n");
}

// Main function to provide a menu for the program
int main() {
    int choice, id;
    char name[100];
    float grade;

    do {
        // Display menu options
        printf("\nMenu:\n");
        printf("1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records by Grade\n");
        printf("4. Search Record by ID\n");
        printf("5. Delete All Records\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                fgets(name, sizeof(name), stdin);
                strtok(name, "\n"); // Remove newline character
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
                break;
            case 6:
                printf("Exiting program.\n");
                deleteList(); // Clean up memory before exit
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6); // Continue until user chooses to exit

    return 0;
}
