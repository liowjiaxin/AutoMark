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
    // Allocation of memory for new student:
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if (!newStudent) {  // Check if malloc succeeded
        printf("Memory allocation failed!\n");
        return NULL;
    }

    // Copy detials to new student node
    strcpy(newStudent->name, name);
    newStudent->id = id;
    newStudent->grade = grade;
    //Next pointer NULL
    newStudent->next = NULL;
    return newStudent;
}

// Function to insert a new student record
void insertStudent(const char* name, int id, float grade) {
    // Creation of new node
    Student* newStudent = createStudent(name, id, grade); 
    if (!newStudent) {  // Checking successful allocation of memeory
        return; // If failed, return early
    }

    // Insert at the beginning of the list
    newStudent->next = head;
    head = newStudent; 
}

// Function to display all student records
void displayStudents() {
    // Check if list is empty
    if (head == NULL) { 
        printf("No student records to display.\n");
        return;
    }

    //traverse list and display details
    Student* current = head;
    while (current != NULL) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", current->name, current->id, current->grade);
        current = current->next; // Move to next student
    }
}

// Function to search for a student by ID
Student* searchStudentByID(int id) {
    //Start at head of list
    Student* current = head;
    // Traverse the list
    while (current != NULL) {
        if (current->id == id) {// ID checking
            return current;
        }
        current = current->next; // Move to next student
    }
    return NULL;
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

// Function to free memory when program exits
void freeMemory() {
    deleteList();
}

// Function to sort student records by grade using Bubble Sort
void sortStudents() {
    if (head == NULL || head->next == NULL) {
        return; // No need to sort if there's 0 or 1 student
    }

    
    printf("Sorting grades using Bubble Sort...\n");

    int swapped; // Flag to check if a swap occurred
    Student* ptr1;
    Student* ptr2 = NULL;


    // Bubble sort
    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != ptr2) {
            // Compare grades
            if (ptr1->grade > ptr1->next->grade) {
                // Swap grades, IDs, and names
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

                swapped = 1; // Set flag when when swap occurrs
            }
            ptr1 = ptr1->next;
        }
        ptr2 = ptr1;
    } while (swapped);

    // Display the sorted records
    displayStudents();
}

// Main function to drive the program
int main() {
    int choice, id;
    char name[100];
    float grade;

    do {
        printf("\n1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records by Grade\n");
        printf("4. Search Record by ID\n");
        printf("5. Delete List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a valid number.\n");
            while (getchar() != '\n');  // Clear invalid input
            continue;
        }



        getchar(); // To consume the newline character
        switch (choice) {
            case 1:
                printf("Enter Name: ");
                fgets(name, sizeof(name), stdin);
                strtok(name, "\n");

                printf("Enter ID: ");
                if (scanf("%d", &id) != 1) {
                    printf("Invalid input! Please enter a valid ID.\n");
                    while (getchar() != '\n');
                    continue;
                }

                printf("Enter Grade (between 0 - 100): ");
                if (scanf("%f", &grade) != 1 || grade < 0 || grade > 100) {
                    printf("Invalid grade! Please enter a value between 0 and 100.\n");
                    while (getchar() != '\n');
                    continue;
                }

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
                if (scanf("%d", &id) != 1) {
                    printf("Invalid input! Please enter a valid ID.\n");
                    while (getchar() != '\n');
                    continue;
                }

                Student* found = searchStudentByID(id);
                if (found) {
                    printf("Found: Name: %s, ID: %d, Grade: %.2f\n", found->name, found->id, found->grade);
                } else {
                    printf("Student not found.\n");
                }
                break;
            case 5:
                deleteList();
                printf("List deleted.\n");
                break;
            case 6:
                freeMemory(); // free remainming allocated memory
                printf("Exiting...\n"); 
                break;
            default:
                printf("Invalid choice! Please try again.\n"); // error handling
        }
    } while (choice != 6);

    return 0;
}
