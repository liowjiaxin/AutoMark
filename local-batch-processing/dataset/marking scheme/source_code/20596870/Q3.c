#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Student
typedef struct Student {
    char name [100]; // Name of student
    int id; // ID of student
    float grade; // grade of student
    struct Student* next; // Pointer to the next student in the list
} Student;

// Pointer to the head of the linked list
Student* head = NULL;

// Function to create a new student node
Student* createStudent (const char* name, int id, float grade) {
    // Dynamically allocate memory for a new student
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if (newStudent) { // Check if memory allocation is successful
        strcpy (newStudent->name, name); // Copy name to structure
        newStudent ->id = id; // Set id
        newStudent ->grade = grade; // Set grade
        newStudent ->next = NULL; // Initialize the next pointer to NULL
    }
    return newStudent;
}

// Function to insert a new student record
void insertStudent (const char* name, int id, float grade) {
    // Create a new student node
    Student* newStudent = createStudent(name, id, grade);
    if (!head) { // Set new student as the head if list is empty
        head = newStudent;
    } else {
        Student* temp = head;
        // Traverse to the end of list
        while (temp->next) {
            temp = temp->next;
        }
        // Add new student at the end
        temp->next = newStudent;
    }
}

// Function to display all student records
void displayStudents() {
    Student* temp = head;
    if (!temp) { // Display message if list is empty
        printf ("No records to display.\n");
        return;
    }
    printf ("Student records: \n");
    // Traverse list and print each students details
    while (temp) {
        printf ("Name: %s, ID: %d, Grade: %.2f\n", temp->name, temp->id, temp->grade);
        temp = temp->next;
    }
}

// Function to search for a student by ID
Student* searchStudentById (int id) {
    // Traverse list and search student via ID
    Student* temp = head;
    while (temp) {
        if (temp->id == id) return temp; // Return student node if found
        temp = temp->next;
    }
    return NULL; // Return NULL if not found
}

// Function to delete the entire list
void deleteList() {
    Student* current = head;
    Student* next;

    // Traverse list and free each node
    while (current != NULL) {
        next = current->next;
        free (current); // Free memory allocated for the current node
        current = next;
    }
    head = NULL; // Reset head pointer to NULL
}

// Function to free memory before exiting program
void freeMemory() {
    deleteList();
}

// Sort function to sort the student records by grade based on Bubble Sort
void sortStudents() {
    if (!head || !head ->next) { // If list is empty or has only 1 node, no need to sort
        printf ("No records to sort.\n");
        return;
    }

    int swapped; // Flag to track if any swapping occurred
    Student *ptr1, *lptr = NULL;

    do {
        swapped = 0;
        ptr1 = head;

        // Compare nodes and swap data if needed
        while (ptr1->next != lptr) {
            if (ptr1->grade > ptr1->next->grade) {
                float tempGrade = ptr1->grade;
                int tempID = ptr1->id;
                char tempName[100];
                strcpy(tempName, ptr1->name);

                ptr1->grade = ptr1->next->grade;
                ptr1->id = ptr1->next->id;
                strcpy(ptr1->name, ptr1->next->name);

                ptr1->next->grade = tempGrade;
                ptr1->next->id = tempID;
                strcpy(ptr1->next->name, tempName);

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);

    printf ("Records sorted by grade using Bubble Sort.\n");
}

// Main function to drive the program
int main () {

    int choice, id;
    char name [100];
    float grade;

    do {
        printf ("\n1. Insert Student Record\n");
        printf ("2. Display Student records\n");
        printf ("3. Sort Records\n");
        printf ("4. Search Records\n");
        printf ("5. Delete List\n");
        printf ("6. Exit\n");
        printf ("Enter your choice: ");
        scanf ("%d", &choice);
        getchar(); // to consume the newline character

        switch (choice) {
            case 1:
                printf ("Enter Name: ");
                fgets(name, sizeof(name), stdin);
                strtok (name, "\n");
                printf ("Enter ID: ");
                scanf ("%d", &id);
                printf ("Enter Grade: ");
                scanf ("%f", &grade);
                insertStudent(name, id, grade);
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                sortStudents();
                break;

            case 4:
                printf ("Enter ID to search: ");
                scanf ("%d", &id);
                Student* found = searchStudentById(id);
                if (found) {
                    printf ("Found: Name: %s, ID: %d, Grade: %.2f\n", found->name, found->id, found->grade);
                } else {
                    printf ("Student not found.\n");
                }
                break;

            case 5:
                deleteList();
                printf ("List deleted.\n");
                break;

            case 6:
                freeMemory ();
                printf ("Exiting...\n");
                break;

            default:
                printf ("Invalid choice ! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}