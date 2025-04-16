#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for student
typedef struct Student {
    char name[100];
    int id;
    float grade;
    struct Student* next;
} Student;

Student* head = NULL;

// Function to create a new student node
Student* createStudent(const char* name, int id, float grade) {
    // Allocate memory space for new student structure
    Student* newStudent = (Student*)malloc(sizeof(Student));
    // Copy/Assign strings/variables to their respective fields
    strcpy(newStudent->name, name);
    newStudent->id = id;
    newStudent->grade = grade;
    newStudent->next = NULL;
    return newStudent;
}

// Function to insert a new student record
void insertStudent(const char* name, int id, float grade) {
    // Add new studdent record to the front (LIFO)
    Student* addStudent = createStudent(name, id, grade);
    addStudent->next = head;
    head = addStudent;
}

// Function to display all student records
void displayStudents() {
    // Assign head struct to student
    Student* student = head;
    // Print student records while pointer is not 'NULL'
    while (student != NULL) {
        printf("Name: %s\nID: %d\nGrade: %.2f\n", student->name, student->id, student->grade);
        student = student->next;
    }
}

// Sort function to sort the student record by grade based on algorithm of choice
void sortStudents() {
    // Count how many students are in the list by incrementing a variable 'count'
    int count = 0;
    Student* studentCount = head;
    while (studentCount != NULL) {
        count++;
        studentCount = studentCount->next;
    }

    // Use a bubble sort as algorithm for its simplicity
    for (int pass = 1; pass < count; pass++) {
        int swapped = 0;
        // Define and initialise current and previous student
        Student* currentStudent = head;
        Student* previousStudent = NULL;

        // Loop
        for (int i = 0; i < count - pass; i++) {
            // Create a pointer to the next student
            Student* temp = currentStudent->next;
            // Compare adjacent names insensitive to case — temp->name is essentially (currentStudent->next)'s name
            // If the first student and second student's names are not in ordder
            if (strcasecmp(currentStudent->name, temp->name) > 0) {
                // If a swap is made, update the head pointer to point to the temporary pointer (assign temp to head)
                if (previousStudent == NULL) {
                    head = temp;
                } else { // Otherwise, update the previous's next pointer to the temporary pointer
                    previousStudent->next = temp;
                }

                // Either way, reassign the pointers
                currentStudent->next = temp->next;  // Skip the temp node
                temp->next = currentStudent;        // 'Move' temp in front of currentStudent
                swapped = 1;
            } else {
                // Increment pointers. The 'front' student's pointer is assigned to the back, next immediate pointer is now the front. 
                previousStudent = currentStudent;
                currentStudent = temp;
            }
            if (swapped) {
                // If a swap has occured, the 'back' student's pointer is the next immediate pointer
                previousStudent = temp;
            }
        }

        // List is sorted if no swaps are made
        if (!swapped) {
            break;
        }
    }
    displayStudents();
}

// Function to search for a student by ID
Student* searchStudentByID(int id) {
    Student* foundStud = head;
    while (foundStud != NULL) {
        // Return student struct if ID is equal
        if (foundStud->id == id) {
            return foundStud;
        }
        // Increment struct pointer
        foundStud = foundStud->next;
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

void freeMemory() {
    deleteList();
}


// Main function
int main() {
    int choice, id;
    char name[100];
    float grade;

    do {
        printf("\n1. Insert student record\n2. Display student records\n3. Sort records\n");
        printf("4. Search by ID\n5. Delete list\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, sizeof(name), stdin);
                strtok(name, "\n");
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter grade: ");
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
                printf("List deleted.\n");
                break;
            case 6:
                freeMemory();
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    while (choice != 6);

    return 0;
}