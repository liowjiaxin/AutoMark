#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50

// Student structure definition
typedef struct Student {
    char name[MAX_NAME];
    int id;
    float grade;
    struct Student* next;
} Student;

// Global variable - List head
Student* head = NULL;

// Function declarations
Student* createStudent(const char* name, int id, float grade);
void insertStudent(const char* name, int id, float grade);
void displayStudents();
Student* searchStudentByID(int id);
void deleteList();
void freeMemory();
void sortStudents();
int getMenuChoice();

int main() {
    int choice;
    char name[MAX_NAME];
    int id;
    float grade;
    Student* found;

    while (1) {
        choice = getMenuChoice();
        
        switch (choice) {
            case 1: // Insert student record
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Grade: ");
                scanf("%f", &grade);
                insertStudent(name, id, grade);
                break;
                
            case 2: // Display student records
                displayStudents();
                break;
                
            case 3: // Sort records
                sortStudents();
                printf("Records sorted by grade using Bubble Sort.\n");
                break;
                
            case 4: // Search record
                printf("Enter ID to search: ");
                scanf("%d", &id);
                found = searchStudentByID(id);
                if (found) {
                    printf("Found student: Name: %s, ID: %d, Grade: %.2f\n", 
                           found->name, found->id, found->grade);
                } else {
                    printf("Student not found.\n");
                }
                break;
                
            case 5: // Delete list
                deleteList();
                printf("List deleted.\n");
                break;
                
            case 6: // Exit
                freeMemory();
                printf("Exiting...\n");
                return 0;
        }
    }
    
    return 0;
}

// Create new student node
Student* createStudent(const char* name, int id, float grade) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if (newStudent == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    
    strncpy(newStudent->name, name, MAX_NAME - 1);
    newStudent->name[MAX_NAME - 1] = '\0';
    newStudent->id = id;
    newStudent->grade = grade;
    newStudent->next = NULL;
    
    return newStudent;
}

// Insert student record
void insertStudent(const char* name, int id, float grade) {
    Student* newStudent = createStudent(name, id, grade);
    
    if (head == NULL) {
        head = newStudent;
    } else {
        newStudent->next = head;
        head = newStudent;
    }
}

// Display all student records
void displayStudents() {
    Student* current = head;
    
    if (current == NULL) {
        printf("No records to display.\n");
        return;
    }
    
    while (current != NULL) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", 
               current->name, current->id, current->grade);
        current = current->next;
    }
}

// Search student by ID
Student* searchStudentByID(int id) {
    Student* current = head;
    
    while (current != NULL) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    
    return NULL;
}

// Delete entire list
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

// Free memory
void freeMemory() {
    deleteList();
}

// Bubble sort implementation
void sortStudents() {
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
            if (current->grade > current->next->grade) {
                // Swap data
                char tempName[MAX_NAME];
                strcpy(tempName, current->name);
                int tempId = current->id;
                float tempGrade = current->grade;
                
                strcpy(current->name, current->next->name);
                current->id = current->next->id;
                current->grade = current->next->grade;
                
                strcpy(current->next->name, tempName);
                current->next->id = tempId;
                current->next->grade = tempGrade;
                
                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
}

// Display menu and get user choice
int getMenuChoice() {
    int choice;
    do {
        printf("\n1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records\n");
        printf("4. Search Record by ID\n");
        printf("5. Delete List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
    } while (choice < 1 || choice > 6);
    
    return choice;
}
