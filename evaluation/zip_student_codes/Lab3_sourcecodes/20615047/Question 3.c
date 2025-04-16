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
 
// Function to create a new student
Student* createStudent(const char* name, int id, float grade) { 
    // Allocate memory for a new student
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if (!newStudent) {
        printf("Memory allocation failed.\n");
        return NULL; // Return NULL on failure
    }
    // Copy the name, id, and grade to the new student
    strcpy(newStudent->name, name);
    newStudent->id = id;
    newStudent->grade = grade;
    newStudent->next = NULL; // Initialize the next pointer to NULL
    return newStudent;
} 
 
// Function to insert a new student record 
void insertStudent(const char* name, int id, float grade) { 
    // Create a new student
    Student* newStudent = createStudent(name, id, grade);
    if (newStudent == NULL) {
        return; // Exit if memory allocation failed
    }
    // Insert the new student at the beginning of the linked list
    newStudent->next = head;
    head = newStudent;
    printf("Student record inserted successfully.\n");
} 
 
// Function to display all student records 
void displayStudents() { 
    if (!head) {
        printf("No records to display.\n");
        return;
    }
    Student* current = head;
    printf("Student Records:\n");
    while (current) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", current->name, current->id, current->grade);
        current = current->next;
    }
} 
 
// Function to search for a student by ID 
Student* searchStudentByID(int id) { 
    Student* current = head;
    while (current) {
        if (current->id == id) {
            return current; // Return if found
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
        next = current->next; // Save the next pointer
        free(current); // Free the current student node
        current = next; // Move to the next student node
    } 
    head = NULL; // Set the head pointer to NULL
} 
 
// Function to ensure all memory is freed before exiting
void freeMemory() { 
    deleteList(); 
} 
 
// Sort function to sort the student records by grade based on an algorithm of your choice 
void sortStudents() { 
    // Bubble sort is chosen
    if (!head || !head->next) {
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
                // Swap the data
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

                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
} 
 
// Main function to drive the program 
int main() { 
    int choice, id; 
    char name[100]; 
    float grade; 
 
    do { 
        printf("\n1. Insert Student Record\n"); 
        printf("2. Display Student Records\n"); 
        printf("3. Sort Records (choose sorting method)\n"); 
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
                strtok(name, "\n"); // Remove the newline character
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
                printf("Records sorted by grade using Bubble Sort.\n");
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
                freeMemory(); // Ensure all memory is freed before exiting
                printf("Exiting...\n"); 
                break; 
            default: 
                printf("Invalid choice! Please try again.\n"); 
        } 
    } while (choice != 6); 
 
    return 0; 
}