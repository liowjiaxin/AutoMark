#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

// Structure for Student
typedef struct Student {
 char name[100];
 int id;
 float grade;
 struct Student* next;
} Student;
Student* head = NULL;
// Function to create a new student node 
void insertStudent(const char* name, int id, float grade);
void displayStudents();
Student* searchStudentByID(int id);
void deleteList();
void freeMemory();
Student* createStudent(const char* name, int id, float grade);
void sortStudents();
void bubbleSortStudents();
void displayMenu();

// Main program
int main() {
    int choice, id;
    float grade;
    char name[MAX_NAME_LENGTH];
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                // Insert new student
                printf("Enter student name: ");
                getchar();  // To clear the buffer
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline character
                
                printf("Enter student ID: ");
                scanf("%d", &id);
                
                printf("Enter student grade: ");
                scanf("%f", &grade);
                
                insertStudent(name, id, grade);
                break;
            case 2:
                // Display all students
                displayStudents();
                break;
            case 3:
                // Sort students by grade
                sortStudents();
                break;
            case 4:
                // Search for student by ID
                printf("Enter student ID to search: ");
                scanf("%d", &id);
                
                Student* student = searchStudentByID(id);
                if (student != NULL) {
                    printf("Student found: %s (ID: %d, Grade: %.2f)\n", student->name, student->id, student->grade);
                } else {
                    printf("Student with ID %d not found.\n", id);
                }
                break;
            case 5:
                // Delete entire list
                deleteList();
                printf("All student records have been deleted.\n");
                break;
            case 6:
                // Exit program
                freeMemory();
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("\nStudent Records Management\n");
    printf("1. Insert Student Record\n");
    printf("2. Display Student Records\n");
    printf("3. Sort Student Records by Grade\n");
    printf("4. Search Student by ID\n");
    printf("5. Delete All Records\n");
    printf("6. Exit\n");
}

// Function to create a new student node
Student* createStudent(const char* name, int id, float grade) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if (!newStudent) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(newStudent->name, name);
    newStudent->id = id;
    newStudent->grade = grade;
    newStudent->next = NULL;
    return newStudent;
}

// Function to insert a new student into the linked list
void insertStudent(const char* name, int id, float grade) {
    Student* newStudent = createStudent(name, id, grade);
    
    // Insert the new student at the beginning of the list
    newStudent->next = head;
    head = newStudent;
    printf("Student record inserted successfully!\n");
}

// Function to display all student records
void displayStudents() {
    if (head == NULL) {
        printf("No student records found.\n");
        return;
    }
    
    Student* current = head;
    printf("\nStudent Records:\n");
    while (current != NULL) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", current->name, current->id, current->grade);
        current = current->next;
    }
}

// Function to search for a student record by ID
Student* searchStudentByID(int id) {
    Student* current = head;
    while (current != NULL) {
        if (current->id == id) {
            return current;  // Return pointer to the student found
        }
        current = current->next;
    }
    return NULL;  // Return NULL if student not found
}

// Function to delete the entire list and free the memory
void deleteList() {
    Student* current = head;
    Student* next;
    
    while (current != NULL) {
        next = current->next;
        free(current);  // Free current student node
        current = next;
    }
    
    head = NULL;  // Set head to NULL to indicate the list is empty
}

// Function to free all memory when exiting the program
void freeMemory() {
    deleteList();  // Delete the list and free memory before exit
}

// Bubble sort implementation to sort students by grade (ascending order)
void bubbleSortStudents() {
    if (head == NULL) {
        return;  // No students to sort
    }
    
    int swapped;
    Student* current;
    Student* lastPtr = NULL;

    do {
        swapped = 0;
        current = head;

        while (current->next != lastPtr) {
            if (current->grade > current->next->grade) {
                // Swap the students
                float tempGrade = current->grade;
                int tempID = current->id;
                char tempName[MAX_NAME_LENGTH];
                strcpy(tempName, current->name);

                current->grade = current->next->grade;
                current->id = current->next->id;
                strcpy(current->name, current->next->name);

                current->next->grade = tempGrade;
                current->next->id = tempID;
                strcpy(current->next->name, tempName);

                swapped = 1;
            }
            current = current->next;
        }
        lastPtr = current;
    } while (swapped);
    printf("Student records sorted by grade.\n");
}

// Function to sort the student records
void sortStudents() {
    bubbleSortStudents();  // Using Bubble Sort
}
