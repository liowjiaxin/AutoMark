#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold student info
typedef struct Student {
    char name[100];  // Student's name
    int id;          // Student's ID
    float grade;     // Student's grade
    struct Student* next;  // Pointer to the next student in the list
} Student;

// The start of our list (points to the first student)
Student* head = NULL;

// Function to create a new student (adding a new record)
Student* createStudent(const char* name, int id, float grade) {
    // Create memory space for a new student
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if (newStudent == NULL) {
        printf("memory allocation failed.\n");
        return NULL;  // Return NULL if we couldn't create a student
    }

    // Copy the student's details into the new record
    strcpy(newStudent->name, name);
    newStudent->id = id;
    newStudent->grade = grade;
    newStudent->next = NULL;  // No next student for now

    return newStudent;  // Send back the new student
}

// Function to add a new student to the end of the list
void insertStudent(const char* name, int id, float grade) {
    // Create the new student
    Student* newStudent = createStudent(name, id, grade);
    if (newStudent == NULL) {
        return;  // If something went wrong, just return
    }

    // If the list is empty, make this the first student
    if (head == NULL) {
        head = newStudent;
    } else {
        // Traverse to the end of the list and add the new student there
        Student* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newStudent;  // Link the new student to the last one
    }
}

// Function to print out all the students in the list
void displayStudents() {
    if (head == NULL) {
        printf("No student records yet.\n");
        return;  // If the list is empty, just show a message and return
    }

    // Go through each student in the list and print their details
    Student* temp = head;
    while (temp != NULL) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", temp->name, temp->id, temp->grade);
        temp = temp->next;  // Move to the next student
    }
}

// Function to search for a student by their ID
Student* searchStudentByID(int id) {
    // Look through the list for a student with the given ID
    Student* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            return temp;  // Found the student, return their info
        }
        temp = temp->next;  // Move to the next student
    }
    return NULL;  // No student found with that ID
}

// Function to delete all students and clear the list
void deleteList() {
    Student* current = head;
    Student* next;

    // Go through the list and free each student one by one
    while (current != NULL) {
        next = current->next;  // Save the next student
        free(current);  // Free the current student from memory
        current = next;  // Move to the next student
    }
    head = NULL;  // The list is now empty, so set head to NULL
}

// Sort the students by grade (bubble sort because its easier)
void sortStudents() {
    // If there's no student or just one, no need to sort
    if (head == NULL || head->next == NULL) {
        return;
    }

    int swapped;
    Student* temp;
    do {
        swapped = 0;  // Start with no swaps
        temp = head;

        // Go through the list and swap students if their grades are out of order
        while (temp != NULL && temp->next != NULL) {
            if (temp->grade > temp->next->grade) {
                // Swap their data (name, id, and grade)
                float tempGrade = temp->grade;
                int tempID = temp->id;
                char tempName[100];
                strcpy(tempName, temp->name);

                // Swap the students
                temp->grade = temp->next->grade;
                temp->id = temp->next->id;
                strcpy(temp->name, temp->next->name);

                temp->next->grade = tempGrade;
                temp->next->id = tempID;
                strcpy(temp->next->name, tempName);

                swapped = 1;  // Mark that we made a swap
            }
            temp = temp->next;  // Move to the next student
        }
    } while (swapped);  // Keep sorting until no more swaps are needed
}

// Function to clean up memory when we're done
void freeMemory() {
    deleteList();  // Delete all student records
}

// Main function
int main() {
    int choice, id;
    char name[100];
    float grade;

    do {
        // Show the menu options
        printf("\n1. Insert Student Record\n");
        printf("2. Display Students REcords\n");
        printf("3. Sort Students Record\n");
        printf("4. Search Record by ID\n");
        printf("5. Delete All Records\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // This gets rid of the newline character left by scanf

        switch (choice) {
            case 1:
                // Add a new student
                printf("Enter Name: ");
                fgets(name, sizeof(name), stdin);  // Get the name from the user
                strtok(name, "\n");
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Grade: ");
                scanf("%f", &grade);
                insertStudent(name, id, grade);  // Add the student to the list
                break;

            case 2:
                // Show all students
                displayStudents();
                break;

            case 3:
                // Sort students by Record
                sortStudents();
                printf("Students sorted by grade using Bubble sort.\n");
                break;

            case 4:
                // Search for a student by ID
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
                // Delete all student records
                deleteList();
                printf("All records deleted.\n");
                break;

            case 6:
                // Exit the program
                freeMemory();
                printf("Goodbye!\n");
                break;

            default:
                // If the user enters an invalid option
                printf("Oops! That's not a valid choice. Try again.\n");
        }
    } while (choice != 6);  // Keep running the menu until the user chooses to exit

    return 0;  // All done, exit the program
}
