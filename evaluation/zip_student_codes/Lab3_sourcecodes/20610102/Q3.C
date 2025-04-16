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
    // Allocate memory for a new student
    Student* newStudent = (Student*)malloc(sizeof(Student));
    
    // Check if memory allocation was successful
    if (newStudent == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    
    // Copy name, set id and grade
    strcpy(newStudent->name, name);
    newStudent->id = id;
    newStudent->grade = grade;
    newStudent->next = NULL;
    
    return newStudent;
}

// Function to insert a new student record
void insertStudent(const char* name, int id, float grade) {
    // Create a new student node
    Student* newStudent = createStudent(name, id, grade);
    
    // If memory allocation failed, return
    if (newStudent == NULL) {
        return;
    }
    
    // If list is empty or new student should be at the beginning
    if (head == NULL || head->id > newStudent->id) {
        newStudent->next = head;
        head = newStudent;
        return;
    }
    
    // Find the right position to insert
    Student* current = head;
    while (current->next != NULL && current->next->id < newStudent->id) {
        current = current->next;
    }
    
    // Insert the new student
    newStudent->next = current->next;
    current->next = newStudent;
    
    printf("Student record inserted successfully!\n");
}

// Function to display all student records
void displayStudents() {
    // Check if list is empty
    if (head == NULL) {
        printf("No student records found.\n");
        return;
    }
    
    printf("\n--- Student Records ---\n");
    printf("%-30s %-10s %-10s\n", "Name", "ID", "Grade");
    printf("----------------------------------------------\n");
    
    // Traverse the list and print each student's details
    Student* current = head;
    while (current != NULL) {
        printf("%-30s %-10d %-10.2f\n", 
               current->name, 
               current->id, 
               current->grade);
        current = current->next;
    }
}

// Function to search for a student by ID
Student* searchStudentByID(int id) {
    Student* current = head;
    
    // Traverse the list to find student with matching ID
    while (current != NULL) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    
    // Return NULL if student not found
    return NULL;
}

// Function to delete the entire list
void deleteList() {
    Student* current = head;
    Student* next;
    
    // Free each node in the list
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    
    // Set head to NULL
    head = NULL;
    printf("List deleted successfully.\n");
}

// Function to free memory and exit
void freeMemory() {
    deleteList();
}

// Function to swap two students
void swap(Student* a, Student* b) {
    // Temporary struct to hold swap data
    Student temp;
    strcpy(temp.name, a->name);
    temp.id = a->id;
    temp.grade = a->grade;
    
    strcpy(a->name, b->name);
    a->id = b->id;
    a->grade = b->grade;
    
    strcpy(b->name, temp.name);
    b->id = temp.id;
    b->grade = temp.grade;
}

// Bubble Sort algorithm to sort students by grade
// Chosen for its simplicity and ease of implementation
// Time complexity: O(n^2), Space complexity: O(1)
void sortStudents() {
    // Check if list is empty or has only one element
    if (head == NULL || head->next == NULL) {
        return;
    }
    
    int swapped;
    Student* current;
    Student* last = NULL;
    
    do {
        swapped = 0;
        current = head;
        
        while (current->next != last) {
            // Compare and swap if current grade is greater than next
            if (current->grade > current->next->grade) {
                swap(current, current->next);
                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
    
    printf("Students sorted by grade successfully!\n");
}

int main() {
    int choice, id;
    char name[100];
    float grade;
    
    do {
        printf("\n--- Student Record Management System ---\n");
        printf("1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records\n");
        printf("4. Search Record by ID\n");
        printf("5. Delete List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        
        // Input validation
        if (scanf("%d", &choice) != 1) {
            // Clear input buffer
            while (getchar() != '\n');
            printf("Invalid input. Please enter a number.\n");
            continue;
        }
        
        // Consume newline
        getchar();
        
        switch (choice) {
            case 1:
                printf("Enter Name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                
                printf("Enter ID: ");
                if (scanf("%d", &id) != 1) {
                    printf("Invalid ID input.\n");
                    while (getchar() != '\n');
                    continue;
                }
                
                printf("Enter Grade: ");
                if (scanf("%f", &grade) != 1) {
                    printf("Invalid grade input.\n");
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
                    printf("Invalid ID input.\n");
                    while (getchar() != '\n');
                    continue;
                }
                
                Student* found = searchStudentByID(id);
                if (found) {
                    printf("Found: Name: %s, ID: %d, Grade: %.2f\n", 
                           found->name, found->id, found->grade);
                } else {
                    printf("Student not found.\n");
                }
                break;
            
            case 5:
                deleteList();
                break;
            
            case 6:
                freeMemory();
                printf("Exiting...\n");
                break;
            
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}