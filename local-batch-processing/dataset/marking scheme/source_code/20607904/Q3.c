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
    Student* new_student = (Student*)malloc(sizeof(Student));
    if (new_student == NULL) {
        printf("Memory allocation failed!\n");
        exit(1); // Exit program if memory allocation fails
    }

    strcpy(new_student->name, name);
    new_student->id = id;
    new_student->grade = grade;
    new_student->next = NULL;
    return new_student;
}

// Function to insert a new student record
void insertStudent(const char* name, int id, float grade) {
    Student* new_student = createStudent(name, id, grade);
    if (!head) {
        head = new_student;
        printf("Successfully added student to record\n");
        return;
    }

    Student* current = head;
    while(current->next != NULL) {
        current = current->next;
    }
    current->next = new_student;

    printf("Successfully added student to record\n");
}

// Function to display all student records
void displayStudents() {
    if(!head) {
        printf("No student records\n");
        return;
    }
    Student* current = head;
    while (current != NULL) {
        printf("Name: %s, ID: %d, Grade: %.2f\n",current->name, current->id, current->grade);
        current = current->next;
    }
}

// Function to search for a student by ID
Student* searchStudentByID(int id) {
    if(!head) {
        printf("No student records\n");
        return NULL;
    }

    Student* current = head;
    while (current != NULL) {
        if(current->id == id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to delete the entire list
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
    
void freeMemory() {
    deleteList();
}



void sortStudents() {
    if (head == NULL || head->next == NULL) { //check is list is empty or has one element
        return;
    }

    int swapped;
    Student* current;
    Student* last_sorted = NULL; // To mark the end of the sorted portion

    do {
        swapped = 0;
        current = head;

        while (current->next != last_sorted) {
            if (current->grade > current->next->grade) {
                // Swap the data of current and next nodes
                float temp_grade = current->grade;
                current->grade = current->next->grade;
                current->next->grade = temp_grade;

                int temp_id = current->id;
                current->id = current->next->id;
                current->next->id = temp_id;

                char temp_name[100];
                strcpy(temp_name, current->name);
                strcpy(current->name, current->next->name);
                strcpy(current->next->name, temp_name);

                swapped = 1;
            }
            current = current->next;
        }
        last_sorted = current; // Reduce the range of unsorted elements
    } while (swapped);
}


// Main function to drive the program
int main() {
    int choice, id;
    char name[100];
    float grade;
    do {
        //print menu
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
                printf("Records sorted by grade using Bubble Sort");
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
                break;
            }
    } while (choice != 6);
    return 0;
}