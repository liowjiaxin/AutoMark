#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Student
typedef struct Student {
    char name[100];  // Student's name
    int id;          // Student's ID
    float grade;     // Student's grade
    struct Student* next;  // Pointer to the next student node
} Student;

Student* head = NULL;  // Head of the linked list (initially empty)

// Function to create a new student node
Student* createStudent(const char* name, int id, float grade) {
    Student* newStudent = (Student*)malloc(sizeof(Student));  // Allocate memory for new student
    if (newStudent == NULL) {  // Check for memory allocation failure
        printf("Memory allocation failed!\n");
        exit(1);
    }
    
    // Copy data into the new student node
    strcpy(newStudent->name, name);
    newStudent->id = id;
    newStudent->grade = grade;
    newStudent->next = NULL;  // Initially, the next pointer is NULL
    
    return newStudent;  // Return the pointer to the new student node
}

// Function to insert a new student record
void insertStudent(const char* name, int id, float grade) {
    Student* newStudent = createStudent(name, id, grade);  // Create a new student node

    if (head == NULL) {  // If the list is empty, set the new student as the head
        head = newStudent;
    } else {
        Student* current = head;
        // Traverse to the end of the list to insert the new student
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newStudent;  // Add the new student at the end
    }

    printf("Student record inserted.\n");
}

// Function to display all student records
void displayStudents() {
    if (head == NULL) {  // Check if the list is empty
        printf("No student records available.\n");
        return;
    }

    Student* current = head;
    // Traverse through the linked list and print each student record
    while (current != NULL) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", current->name, current->id, current->grade);
        current = current->next;  // Move to the next student
    }
}

// Function to search for a student by ID
Student* searchStudentByID(int id) {
    Student* current = head;
    
    // Traverse through the list to find the student by ID
    while (current != NULL) {
        if (current->id == id) {
            return current;  // Return the student node if ID matches
        }
        current = current->next;
    }

    return NULL;  // Return NULL if student with the given ID is not found
}

// Function to delete the entire linked list and free memory
void deleteList() {
    Student* current = head;
    Student* next;
    
    // Traverse and free all student nodes
    while (current != NULL) {
        next = current->next;
        free(current);  // Free memory for current student node
        current = next;
    }
    
    head = NULL;  // Reset head to NULL as the list is now empty
}

// Function to free all memory when the program exits
void freeMemory() {
    deleteList();  // Delete the list and free memory
}

// Comparison function to be used with qsort
int compareStudents(const void* a, const void* b) {
    // Cast the input pointers to Student pointers
    Student* studentA = *(Student**)a;
    Student* studentB = *(Student**)b;

    // Compare the grades of the two students
    if (studentA->grade < studentB->grade) return -1;
    if (studentA->grade > studentB->grade) return 1;
    return 0;  // Return 0 if grades are equal
}

// Function to sort the student records by grade using qsort
//QSORT has average performance and it is quite generalized function which why I chose it
void sortStudents() {
    if (head == NULL || head->next == NULL) {
        printf("Not enough students to sort.\n");
        return;
    }

    // First, we need to store the students in an array for sorting
    int count = 0;
    Student* current = head;

    // Count the total number of students
    while (current != NULL) {
        count++;
        current = current->next;
    }

    // Create an array to store student pointers
    Student** studentArray = (Student**)malloc(count * sizeof(Student*));
    if (studentArray == NULL) {
        printf("Memory allocation for sorting failed!\n");
        exit(1);
    }

    // Fill the array with student pointers
    current = head;
    for (int i = 0; i < count; i++) {
        studentArray[i] = current;
        current = current->next;
    }

    // Use qsort to sort the array of student pointers by grade
    qsort(studentArray, count, sizeof(Student*), compareStudents);

    // Re-link the sorted student nodes back into the linked list
    for (int i = 0; i < count - 1; i++) {
        studentArray[i]->next = studentArray[i + 1];
    }
    studentArray[count - 1]->next = NULL;  // The last student points to NULL

    // Set the head of the list to the first student in the sorted array
    head = studentArray[0];

    // Free the array of student pointers (we no longer need it)
    free(studentArray);

    printf("Student records sorted by grade.\n");
}

// Main function to drive the program
int main() {
    int choice, id;
    char name[100];
    float grade;

    do {
        // Display the menu for the user
        printf("\n1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records by Grade\n");
        printf("4. Search Record by ID\n");
        printf("5. Delete List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // To consume the newline character

        switch (choice) {
            case 1:
                // Insert a new student record
                printf("Enter Name: ");
                fgets(name, sizeof(name), stdin);
                strtok(name, "\n");  // Remove the trailing newline
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Grade: ");
                scanf("%f", &grade);
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
                // Delete the entire linked list
                deleteList();
                printf("Student list deleted.\n");
                break;
            case 6:
                // Exit the program and free memory
                freeMemory();
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
