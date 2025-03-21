#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

// Structure for Student 
 typedef struct Student { 
    char name[100]; // Array to store student names
    int id; // to student id
    float grade;
    struct Student* next; // pointer to the next student in the list
} Student; 

Student* head = NULL; 

// Function to create a new student 
Student* createStudent(const char* name, int id, float grade) { 
    // Allocate memory for a new student 
    Student* newStudent = (Student*)malloc(sizeof(Student)); 
    
    // Copy the student data into the new student
    strcpy(newStudent->name, name);
    newStudent->id = id;
    newStudent->grade = grade;
    newStudent->next = NULL; // The  next pointer will be NULL ,it is a new student
    
    return newStudent; 
} 

// Function to insert a new student record 
void insertStudent(const char* name, int id, float grade) { 
    // Create a new student node using the provided data
    Student* newStudent = createStudent(name, id, grade);
    
    // If the list is empty, the new student becomes the head
    if (head == NULL) {
        head = newStudent;
    } else {
        // Otherwise, we need to insert it at the end of the list
        Student* current = head;
        while (current->next != NULL) {
            current = current->next; // Move to the last student
        }
        current->next = newStudent; // Add the new student after the last student
    }
    
    printf("Student record inserted successfully.\n");
} 

// Function to display all student records 
void displayStudents() { 
    // If the list is empty, print a message
    if (head == NULL) {
        printf("No student records available.\n");
        return;
    }
    
    // loop through the list and display each students data
    Student* current = head;
    while (current != NULL) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", current->name, current->id, current->grade);
        current = current->next; // Move to the next student
    }
} 

// Function to search for a student by ID 
Student* searchStudentByID(int id) { 
    // Loop through the list to find a student with the matching ID
    Student* current = head;
    while (current != NULL) {
        if (current->id == id) {
            return current; // Return the student if found
        }
        current = current->next;
    }
    return NULL; // Return NULL if the student is not found
} 

// Function to delete the entire list 
void deleteList() { 
    Student* current = head; 
    Student* next; 
    
    while (current != NULL) { 
        next = current->next; 
        free(current); // Free the memory of the current student node
        current = next; // Move to the next student
    } 
    
    head = NULL; // Set head to NULL since the list is empty now
} 

// Sort function to sort the student records by grade using Bubble Sort 
void sortStudents() { 
    if (head == NULL) {
        printf("No records to sort.\n");
        return;
    }
    
    int swapped;
    
    // Bubble Sort to sort students by grade in ascending order
    do {
        swapped = 0;
        Student* current = head;
        Student* prev = NULL;
        Student* next = head->next;
        
        while (next != NULL) {
            if (current->grade > next->grade) {
                // Swap the students' data without using a temporary variable
                if (prev != NULL) {
                    prev->next = next;  
                }
                
                current->next = next->next;  // Point the current node to the node after next
                next->next = current;  // Point the next record to the current node
                
                if (current == head) {
                    head = next; // If we swapped the head record, update head
                }
                
                swapped = 1; // Set swapped to 1 to continue sorting
            }
            
            prev = current;
            current = next;
            next = next->next;
        }
    } while (swapped);
    
    printf("Student records sorted by grade.\n");
} 

// Free memory to ensure that all memory is freed when the program exits
void freeMemory() { 
    deleteList(); 
}

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
        scanf("%d", &choice); 
        getchar(); // To consume the newline character 
        
        switch (choice) { 
            case 1: 
                printf("Enter Name: "); 
                fgets(name, sizeof(name), stdin); 
                strtok(name, "\n"); // Remove newline character from input
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
                    printf("Found: Name: %s, ID: %d, Grade: %.2f\n", 
                           found->name, found->id, found->grade); 
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
    } while (choice != 6); 
    
    return 0; 
}
