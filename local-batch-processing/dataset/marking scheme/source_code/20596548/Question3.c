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

Student* head = NULL; // Head pointer to the linked list

// Function prototypes as per the skeleton
Student* createStudent(const char* name, int id, float grade); 
void insertStudent(const char* name, int id, float grade); 
void displayStudents(); 
Student* searchStudentByID(int id); 
void deleteList(); 
void freeMemory();  
void sortStudents();  

// Function to create a new student node
Student* createStudent(const char* name, int id, float grade) { 
    Student* newStudent = (Student*)malloc(sizeof(Student)); 
    strcpy(newStudent->name, name); 
    newStudent->id = id; 
    newStudent->grade = grade; 
    newStudent->next = NULL; 
    return newStudent; 
} 

// Function to insert a new student record into the linked list
void insertStudent(const char* name, int id, float grade) { 
    Student* newStudent = createStudent(name, id, grade); 
    newStudent->next = head; 
    head = newStudent; 
} 

// Function to display all student records
void displayStudents() { 
    if (head == NULL) { 
        printf("No students found!\n"); 
        return; 
    } 

    Student* current = head; 
    while (current != NULL) { 
        printf("Name: %s, ID: %d, Grade: %.2f\n", current->name, current->id, current->grade); 
        current = current->next; 
    } 
} 

// Function to search for a student by ID
Student* searchStudentByID(int id) { 
    Student* current = head; 
    while (current != NULL) { 
        if (current->id == id) { 
            return current; // Found the student 
        } 
        current = current->next; 
    } 
    return NULL; // Student not found 
} 

// Function to delete the entire linked list and free memory
void deleteList() { 
    Student* current = head; 
    Student* next; 
    while (current != NULL) { 
        next = current->next; 
        free(current); // Free the current node 
        current = next; 
    } 
    head = NULL; // Set head to NULL after deletion 
} 

// Function to ensure all memory is freed before the program exits
void freeMemory() { 
    deleteList(); // Free all the allocated memory for the list 
} 

// Function to sort the student records by grade using a simple sorting algorithm (Bubble Sort)
void sortStudents() { 
    if (head == NULL || head->next == NULL) { 
        return; // No need to sort if the list is empty or has only one student 
    } 

    for (Student* i = head; i != NULL; i = i->next) { 
        for (Student* j = i->next; j != NULL; j = j->next) { 
            if (i->grade > j->grade) { 
                // Swap the grades, IDs, and names of the students
                float tempGrade = i->grade; 
                i->grade = j->grade; 
                j->grade = tempGrade; 

                int tempId = i->id; 
                i->id = j->id; 
                j->id = tempId; 

                char tempName[100]; 
                strcpy(tempName, i->name); 
                strcpy(i->name, j->name); 
                strcpy(j->name, tempName); 
            } 
        } 
    } 
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
                strtok(name, "\n"); // Remove newline character from name 
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
                printf("Records sorted by grade.\n"); 
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
    } while (choice != 6); 

    return 0; 
}
