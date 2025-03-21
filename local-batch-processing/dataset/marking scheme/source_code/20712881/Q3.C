#include <stdio.h>
#include <stdlib.h>       // provides functions for dynamic memory management (malloc, free)
#include <string.h>       // provides functions for string manipulation

// Structure for Student
typedef struct Student {
    char name[100];     // string for name
    int id;             // integer for id
    float grade;        // floating-point for student grade
    struct Student* next;      // pointer to next student node
} Student;

Student* head = NULL;    // global pointer points to first node in linked list

// Function to create a new student node
Student* createStudent(const char* name, int id, float grade) {
    Student* newStudent = (Student*)malloc(sizeof(Student));    // allocate memory for new student
    if (!newStudent) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    strcpy(newStudent->name, name);      // copy provided name into new node
    newStudent->id = id;
    newStudent->grade = grade;
    newStudent->next = NULL;
    return newStudent;
}

// Function to insert a new student record
void insertStudent(const char* name, int id, float grade) {
    Student* newStudent = createStudent(name, id, grade);
    if (!newStudent) return;

    if (!head) {               // if list is empty, new student becomes the head
        head = newStudent;
    } else {
        Student* temp = head;
        while (temp->next) {       // if not empty, iterate through list to find last node
            temp = temp->next;
        }
        temp->next = newStudent;
    }
    printf("Student record added successfully!\n");
}

// Function to display all student records
void displayStudents() {
    if (!head) {
        printf("No student records to display.\n");
        return;
    }

    Student* temp = head;
    printf("\nStudent Records:\n");
    while (temp) {                              // go through loop and print details of each node
        printf("Name: %s, ID: %d, Grade: %.2f\n", temp->name, temp->id, temp->grade);
        temp = temp->next;
    }
}

// Function to sort student records by grade in ascending order
void sortStudents() {
    if (!head || !head->next) {     // no need to sort if list empty or has one node
        printf("No need to sort. Not enough records.\n");
        return;
    }

    Student* i, *j;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->grade > j->grade) {
                // Swap student details
                char tempName[100];
                int tempID;
                float tempGrade;

                strcpy(tempName, i->name);
                tempID = i->id;
                tempGrade = i->grade;

                strcpy(i->name, j->name);
                i->id = j->id;
                i->grade = j->grade;

                strcpy(j->name, tempName);
                j->id = tempID;
                j->grade = tempGrade;
            } // nested loops compare grades of all pairs of nodes
        }
    }
    printf("Students sorted by grade.\n");
}

// Function to search for a student by ID
Student* searchStudentByID(int id) {
    Student* temp = head;
    while (temp) {
        if (temp->id == id) {      // compare id of each node with target
            return temp;           // if match found, return a pointer to node
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to delete the entire list
void deleteList() {
    Student* temp = head;
    while (temp) {        // iterates through list freeing each node
        Student* next = temp->next;
        free(temp);
        temp = next;
    }
    head = NULL;       // sets head to NULL
    printf("All student records deleted.\n");
}

// Main function
int main() {
    int choice, id;
    char name[100];
    float grade;

    Student* found = NULL;  // Declare the `found` pointer before the switch statement

    // Provides menu for user interaction
    do {
        printf("\nMenu:\n");
        printf("1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Students by Grade\n");
        printf("4. Search Student by ID\n");
        printf("5. Delete List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Used fgets for names and scanf for integers and floats
        switch (choice) {
            case 1:
                // Clear buffer before reading the name
                printf("Enter Name: ");
                getchar(); // Clear input buffer
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline character

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
                found = searchStudentByID(id);
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
                deleteList();
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);     // repeats until user selects 6

    return 0;
}
