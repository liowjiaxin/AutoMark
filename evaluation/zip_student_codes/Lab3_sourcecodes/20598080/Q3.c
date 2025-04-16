# include <stdio.h>
# include <stdlib.h>
# include <string.h>

// Structure for Student 
typedef struct Student {
    char name[100];  // Name of the student
    int id;  // Unique ID of the student
    float grade;  // Grade of the student
    struct Student* next;  // Pointer to the next student in the list
} Student;

Student* head = NULL;  // Head of the linked list (initially empty)

// Function to create a new student node
Student* createStudent(const char* name, int id, float grade) {
    Student* newStudent = (Student*)malloc(sizeof(Student));  // Allocate memory for a new student
    if (!newStudent) {
        printf("Memory allocation failed.\n");
        exit(1);  // Exit if memory allocation fails
    }
    strcpy(newStudent->name, name);  // Set the student's name
    newStudent->id = id;  // Set the student's ID
    newStudent->grade = grade;  // Set the students's grade
    newStudent->next = NULL;  // Initialize the next pointer to NULL
    return newStudent;
}

// Function to insert a new student record
void insertStudent(const char*name, int id, float grade) {
    Student* newStudent = createStudent(name, id, grade);  // Create a new student node
    newStudent->next = head;  // Link the new student to the current head
    head = newStudent;  // Update head to point to the new student
    printf("Student record inserted successfully!\n");
}

// Function to display all student records
void displayStudents() {
    if (!head) {  // Check if the list is empty
        printf("No student records found.\n");
        return;
    }

    printf("\nStudent Records:\n");
    Student* current = head;
    while (current) {  // Traverse the list and print each student's details
        printf("Name: %s, ID: %d, Grade: %.2f\n", current->name, current->id, current->grade);
        current = current->next;
    }
}

// Function to search for a student by ID
Student* searchStudentByID(int id) {
    Student* current =  head;  // Start from the head of the list
    while (current) {  // Traverse the list
        if (current->id == id) {  // Check if the current student's ID matches
            return current;
        }
        current = current->next;
    }
    return NULL;  // Return NULL if the student is not found
}

// Function to delete the entire list
void deleteList() {
    Student* current = head;  // Start from the head of the list
    Student* next;

    while (current != NULL) {  // Traverse the list
        next = current->next;  // Store the pointer to the next student
        free(current);  // Free the current node
        current = next;  // Move to the next student
    }
    head = NULL;  // Reset the head to NULL
}
void freeMemory() {
    deleteList();
}

// Sort function to sort the student records by grade based on an algorithm of your choice
// Bubble Sort is chosen becasuse it is simple to implement and sufficient for small datasets such as this linked list of student records.
void sortStudents() {
    if (!head || !head->next) {  // Check if there are less than 2 students
        printf("Not enough records to sort.\n");
        return;
    }

    int swapped;
    Student *current, *prev = NULL;

    do {
        swapped = 0;
        current = head;

        while (current->next !=prev) {
            if (current->grade > current->next->grade) { // Compare grades
                // Swap data
                char tempName[100];
                int tempID;
                float tempGrade;

                strcpy(tempName, current->name);
                tempID = current->id;
                tempGrade = current->grade;

                strcpy(current->name, current->next->name);
                current->id = current->next->id;
                current->grade = current->next->grade;

                strcpy(current->next->name, tempName);
                current->next->id = tempID;
                current->next->grade = tempGrade;
 
                swapped = 1;  // Mark as swapped
            }
            current = current->next;  // Move to the next pair
        }
        prev = current;  // Reduce the range of unsorted elements
    } while (swapped);

    printf("Records sorted by grade using Bubble Sort.\n");
}

// Main function to drive the program
int main() {
    
    int choice, id;
    char name[100];
    float grade;

    do {
        // Display menu
        printf("\n1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records (choose sorting method)\n");
        printf("4. Search Record by ID\n");
        printf("5. Delete List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // To consume the newline character

        switch (choice) {
            case 1:  // Insert a new student record
                printf("Enter Name: ");
                fgets(name, sizeof(name), stdin);
                strtok(name, "\n");
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Grade: ");
                scanf("%f", &grade);
                insertStudent(name, id, grade);
                break;
            case 2:  // Display all student records
                displayStudents();
                break;
            case 3:  // Sort student recors
                sortStudents();
                break;
            case 4:  // Search for a student by ID
                printf("Enter ID to search: ");
                scanf("%d", &id);
                Student* found = searchStudentByID(id);
                if (found) {
                    printf("Found: Name: %s, ID: %d, Grade: %.2f\n", found->name, found->id, found->grade);
                } else {
                    printf("Student not found.\n");
                }
                break;
            case 5:  // Delte the entire list
                deleteList();
                printf("List deleted.\n");
                break;
            case 6:  // Exit the program
                freeMemory();
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid chocie! Please try again.\n");
        }
    } while (choice != 6);  // Repeat until the user chooses to exit

    return 0;
}