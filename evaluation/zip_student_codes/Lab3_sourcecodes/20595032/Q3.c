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
    // Allocation of memory for new student is crucial
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if (newStudent == NULL) {
        printf("Memory Invalid.\n");
        return NULL;
    }

    // Assign values to the student node
    strcpy(newStudent->name, name);
    newStudent->id = id;
    newStudent->grade = grade;
    newStudent->next = NULL;

    return newStudent;
}

// Function to insert a new student record 
void insertStudent(const char* name, int id, float grade) {
    // New student node
    Student* newStudent = createStudent(name, id, grade);
    if (newStudent == NULL) return;

    // New students will show up first 
    newStudent->next = head;
    head = newStudent;

}

// Function to display all student records
void displayStudents() {
    Student* current = head;

    if (current == NULL) {
        printf("No records.\n");
        return;
    }

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
            return current;
        }
        current = current->next;
    }
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

// Sort function to sort the student records by grade based on Bubble Sort
void sortStudents() {
        if (head == NULL||head->next == NULL)return; //sorting not needed if empty

    int swapped;
    Student *current,*last = NULL;

    do {
        // reser the swapped flag at start of every outer loop
        swapped = 0;
        current = head;
        // ensures starting at head of list
         
        // ensures looping until last element 
        while (current->next != last) {


            if (current->grade > current->next->grade) {
                char tempName[100];
                int tempID;
                float tempGrade;


                // copy data stored from temporary var into next node
                strcpy(tempName, current->name);
                tempID = current->id;
                tempGrade = current->grade;

                strcpy(current->name, current->next->name);
                current->id = current->next->id;
                current->grade = current->next->grade = tempGrade;

                swapped = 1;
            }

            // move to next node
            current = current->next;
        }
        last = current;
    } while (swapped); // ensures looping until no more swaps are needed

    printf("Records sorted by grade using Bubble Sort.\n");
}

// Main function to drive the program
int main() {
    int choice, id;
    char name[100];
    float grade;

    do {
        printf("\n1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records\n");
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
