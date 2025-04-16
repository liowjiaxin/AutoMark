#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 101

// Define Linked List
typedef struct Student{
    char name[MAX_NAME];
    int id;
    float grade;
    struct Student* next;   // Pointer to the next student node
} Student;

// Head of the linked list
Student* head = NULL;


// Function to create new student struct
Student* createStudent(const char* name, int id, float grade) {
    // Create student node
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if (newStudent == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    // Copy all the infomation to the new student node
    strcpy(newStudent->name, name);
    newStudent->id = id;
    newStudent->grade = grade;
    newStudent->next = NULL;
    return newStudent;
}

// Function to insert new student infomation
void insertStudent(const char* name, int id, float grade) {
    Student* newStudent = createStudent(name, id, grade);
    if (!newStudent) {
        return;
    }
    // Put the newStudent to the first node (head)
    newStudent->next = head;
    head = newStudent;
}

// Function to display all the student infomation
void displayStudents() {
    if (head == NULL) {
        printf("There is no student records.\n");
        return;
    }
    // Get current node (Initialise with the first node)
    Student* current = head;
    // Until current node reaches the last node(NULL)
    while (current != NULL) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", current->name, current->id, current->grade);
        current = current->next;
    }
}

// Function to search student by using id
Student* searchStudentByID(int id) {
    Student* current = head;
    // Until current node reaches the last node(NULL)
    while (current != NULL) { 
        if (current->id == id) { 
            printf("Matching ID found\n");  
            return current; 
        } 
        // If not match with the current node id then update the current node with the next node
        current = current->next; 
    }
    printf("The provided ID was not found in the student records.\n");
    return NULL;
}

// Function to delete the entire list
void deleteList() {
    Student* current = head;
    Student* next;
    // Until current node reaches the last node(NULL)
    while (current != NULL) {
        next = current->next;
        free(current);
        // Shift all node to one front
        current = next;
    }
    head = NULL;
}

void freeMemory() {
    deleteList();
}

// Function to perform bubble sort about student grades
void sortStudents() {
    if (head == NULL) {
        return;
    }
    // flag which indicates that the two current and the next node are sorted -> go to sort the next node
    int pass;
    Student* current = head;
    Student* last = NULL;   // pointer to the last
    
    do {
        pass = 0;
        current = head;
        // Until current node reaches the last node(NULL)
        while (current->next != last) {
            if (current->grade > current->next->grade) {
                // Define temporary variables to hold information
                char tmp_name[MAX_NAME];
                strcpy(tmp_name, current->name);
                int tmp_id = current->id;
                int tmp_grade = current->grade;
                // Swipe the current with the next node
                strcpy(current->name, current->next->name);
                current->id = current->next->id;
                current->grade = current->next->grade;
                // Swipe the next node with the current
                strcpy(current->next->name, tmp_name);
                current->next->id = tmp_id;
                current->next->grade = tmp_grade;

                pass = 1;
            }
            // Go to the next node
            current = current->next;
        }
        last = current; // update the last to the last sorted element
    } while (pass);
    printf("Records sorted by grade using Bubble Sort.\n");
}


int main() {
    int choice, id;
    char name[100];
    float grade;
    do {
        printf("\n1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records (Bubble Sort)\n");
        printf("4. Search Record by ID\n");
        printf("5. Delete List\n");
        printf("6. Exit\n");
        while (1) {
            printf("Enter your choice: ");
            if (scanf("%d", &choice) != 1 || choice < 1 || choice > 6) {
                printf("Invalid input. Enter again.\n");
                while (getchar() != '\n'); // To consume the newline character
                continue;
            }
            getchar(); // To consume the newline character
            break;
        }
        switch (choice) {
            case 1:
                printf("Enter Name: ");
                fgets(name, sizeof(name), stdin);
                strtok(name, "\n");
                while (1) {
                    printf("Enter ID: ");
                    if (scanf("%d", &id) != 1 || id < 0) {
                        printf("Invalid ID. Enter again.\n");
                        while (getchar() != '\n');
                        continue;
                    }
                    break;
                }
                
                while (1) {
                    printf("Enter Grade: ");
                    if (scanf("%f", &grade) != 1 || grade < 0) {
                        printf("Invalid Grade. Enter again.\n");
                        while (getchar() != '\n');
                        continue;
                    }
                    break;
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