#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize struct Student for data
typedef struct Student {
    char name[100];       
    int id;               
    float grade;          
    struct Student* next; 
} Student;

Student* head = NULL; // Head pointer for the linked list

void insertStudent(const char* name, int id, float grade); 
void displayStudents();
Student* searchStudentByID(int id);
void deleteList(); 
void freeMemory();
Student* createStudent(const char* name, int id, float grade);
void sortStudents(); 

// Main function to drive the program
int main() {
    int choice, id;
    char name[100];
    float grade;

    do {
        // Display menu options
        printf("\nMenu:\n");
        printf("1. Insert Student Record\n");
        printf("2. Display Records\n");
        printf("3. Sort Records\n");
        printf("4. Search by ID\n");
        printf("5. Delete List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        while (getchar() != '\n');

        // Use switch case to determine what function to use
        switch (choice) {
            case 1:
                // Input new student record
                printf("Enter Name: ");
                fgets(name, sizeof(name), stdin); // Read a line of input
                name[strcspn(name, "\n")] = '\0'; // Clear input buffer

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
                printf("Records sorted by grade using bubble sort.\n");
                break;

            case 4:
                // Search for a student record by ID
                printf("Enter ID to search: ");
                scanf("%d", &id);
                Student* found = searchStudentByID(id);
                if (found) {
                    printf("Found: Name: %s, ID: %d, Grade: %.2f\n", (*found).name, (*found).id, (*found).grade);
                } else {
                    printf("Student not found.\n");
                }
                break;

            case 5:
                // Delete the entire linked list
                deleteList();
                printf("List of student records have been deleted.\n");
                break;

            case 6:
                // Exit the program 
                printf("Exiting program...\n");
                deleteList(); // Delete the list before exiting
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6); // Loops if doesnt chooses 6 to exit

    return 0;
}

// Function to create a new student record
Student* createStudent(const char* name, int id, float grade) {
    // Dynamically allocate memory for a new student 
    Student* newStudent = (Student*)malloc(sizeof(Student));
    
    // Set the student's attributes
    strcpy((*newStudent).name, name);
    (*newStudent).id = id;
    (*newStudent).grade = grade;
    (*newStudent).next = NULL; // Initialize the next pointer to NULL
    
    return newStudent;
}

// Function to insert a new student record at the beginning of the linked list
void insertStudent(const char* name, int id, float grade) {
    // Create a new student record
    Student* newStudent = createStudent(name, id, grade);
    
    // Link new student to the current head
    (*newStudent).next = head;
    
    // New student becomes the head pointer
    head = newStudent;
}

// Function to display all student records in the linked list
void displayStudents() {
    // Temporary pointer to traverse the linked list
    Student* current = head;
    
    // Checks if the list is empty
    if (!current) {
        printf("No student records found.\n");
        return;
    }

    // Go through the list and print all student details
    while (current) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", (*current).name, (*current).id, (*current).grade);
        current = (*current).next;
    }
}

// Function to search for a student record by their ID
Student* searchStudentByID(int id) {
    Student* current = head; // Start at the first record

    // Go through the list to find the matching ID
    while (current) {
        if ((*current).id == id) {
            return current; // Return the pointer to the matching student 
        }
        current = (*current).next; 
    }
    return NULL; // Return NULL if not found
}

// Function to sort the student records by grade in ascending order 
void sortStudents() { 
    // Skip sorting if the list is empty or has only one element 
    if (!head || !(*head).next) { 
        return; 
    } 
    
    int swapped; 
    Student *i; 
    Student *prev = NULL; // Pointer to mark the end of the sorted part of the list 

    // Use bubble sort to sort the records
    do { 
        swapped = 0; 
        i = head;  // Start from the head of the list 

        // Traverse the list up to the sorted part 
        while ((*i).next != prev) { 
            // Compare the current student's grade with the next student's grade 
            if ((*i).grade > (*(*i).next).grade) { 
                // Swap data between the current student and the next student 
                char tempName[100]; 
                int tempID; 
                float tempGrade; 

                strcpy(tempName, (*i).name); 
                tempID = (*i).id; 
                tempGrade = (*i).grade; 

                strcpy((*i).name, (*(*i).next).name); 
                (*i).id = (*(*i).next).id; 
                (*i).grade = (*(*i).next).grade; 

                strcpy((*(*i).next).name, tempName); 
                (*(*i).next).id = tempID; 
                (*(*i).next).grade = tempGrade; 

                swapped = 1; // Set swapped flag to 1 
            } 

            i = (*i).next; // Move to the next student in the list 
        } 

        prev = i; // Move the sorted boundary one step backward 

    } while (swapped); // Repeat until no swaps are made in a complete pass 
}


// Function to delete the entire linked list and free allocated memory
void deleteList() {
    Student* current = head; // Start at the head of the list

    // Traverse and free each record
    while (current) {
        Student* temp = current; 
        current = (*current).next; // Move to the next record
        free(temp); 
    }
    
    head = NULL; // Set head to NULL after deleting all records
}