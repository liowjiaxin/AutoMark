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
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if (newStudent == NULL) {
        printf("Memory allocation failed\n");
        exit(1); // Exit if memory allocation fails
    }
    strcpy(newStudent->name, name);
    newStudent->id = id;
    newStudent->grade = grade;
    newStudent->next = NULL;
    return newStudent;
}

// Function to insert a new student record
void insertStudent(const char* name, int id, float grade) {
    Student* newStudent = createStudent(name, id, grade);
    if (head == NULL) {
        head = newStudent;  // If the list is empty, the new student becomes the head
    } else {
        newStudent->next = head; // Point the new student's next to the current head
        head = newStudent; // Make the new student the new head
    }
}

// Function to display all student records
void displayStudents() {
    if (head == NULL) {
        printf("No students in the list.\n");
        return;
    }
    Student* temp = head;
    while (temp != NULL) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", temp->name, temp->id, temp->grade);
        temp = temp->next;
    }
}

// Function to search for a student by ID
Student* searchStudentByID(int id) {
    Student* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            return temp; // Return the student node if the ID matches
        }
        temp = temp->next;
    }
    return NULL; // Return NULL if student not found
}

// Function to delete the entire list
void deleteList() {
    Student* current = head;
    Student* next;
    while (current != NULL) {
        next = current->next;
        free(current); // Free memory for each student
        current = next;
    }
    head = NULL; // Set head to NULL after deleting all nodes
}

void freeMemory() {
    deleteList();
}

// Sort function to sort the student records by grade using bubble sort
void sortStudents() {
    if (head == NULL || head->next == NULL) {
        return; // No need to sort if the list has 0 or 1 student
    }

    int swapped;
    Student* ptr1;
    Student* ptr2 = NULL;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != ptr2) {
            if (ptr1->grade > ptr1->next->grade) { // Change condition to sort in ascending order
                // Swap grades
                float tempGrade = ptr1->grade;
                int tempID = ptr1->id;
                char tempName[100];
                strcpy(tempName, ptr1->name);

                ptr1->grade = ptr1->next->grade;
                ptr1->id = ptr1->next->id;
                strcpy(ptr1->name, ptr1->next->name);

                ptr1->next->grade = tempGrade;
                ptr1->next->id = tempID;
                strcpy(ptr1->next->name, tempName);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        ptr2 = ptr1; // Decrease the range of the list to be sorted
    } while (swapped);
}

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
                strtok(name, "\n");
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
                printf("Records sorted by grade using bubble sort.\n");
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
