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
    Student* newStudent = (Student*)malloc(sizeof(Student));        // malloc returns a pointer to the allocated memory
    if (!newStudent) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    strcpy(newStudent->name, name);     // copy name string into name field
    newStudent->id = id;        // Assign id values to newStudent structure
    newStudent->grade = grade;      // // Assign grade values to newStudent structure
    newStudent->next = NULL;        // Set next pointer of newStudent structure to NULL
    return newStudent;
}

// Function to insert a new student record
void insertStudent(const char* name, int id, float grade) {
    Student* newStudent = createStudent(name, id, grade);
    if (!newStudent) return;
    if (!head) {
        head = newStudent;
    } else {
        Student* temp = head;
        while (temp->next) {
            temp = temp->next;      // Move to the next
        }
        temp->next = newStudent;    // Point to newStudent
    }
    printf("Student record added successfully.\n");
}

// Function to display all student records
void displayStudents() {
    if (!head) {
        printf("No student records found.\n");
        return;
    }
    Student* temp = head;
    printf("\nStudent Records:\n");
    while (temp) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", temp->name, temp->id, temp->grade);
        temp = temp->next;
    }
}

// Function to search for a student by ID
Student* searchStudentByID(int id) {
    Student* temp = head;
    while (temp) {
        if (temp->id == id) return temp;        // Check if the pointed id matches teh give id, if yes, return temp
        temp = temp->next;          // if not match, move to the next node
    }
    return NULL;
}

// Function to delete the entire list
void deleteList() {
    Student* current = head;
    Student* next;

    while (current) {
        next = current->next;
        free(current);      // Remove the allocated memory
        current = next;     // Point to the next one
    }

    head = NULL;
    printf("All student records deleted.\n");
}

// Sort function to sort the student records by grade based on an algorithm of your choice
void sortStudents() {
    if (!head || !head->next) return;

    for (Student* i = head; i->next; i = i->next) {
        for (Student* j = i->next; j; j = j->next) {
            if (i->grade > j->grade) {
                // Swap data
                char tempName[100];
                int tempID = i->id;
                float tempGrade = i->grade;

                // Bubble sort
                strcpy(tempName, i->name);      // i coppied to temp
                strcpy(i->name, j->name);       // j is coppied to i
                strcpy(j->name, tempName);      // temp is coppied to j

                i->id = j->id;      // swap i and j id
                j->id = tempID;     // swap j and tempid

                i->grade = j->grade;        // swap i and j grade
                j->grade = tempGrade;       // swap j and tempgrade
            }
        }
    }
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
                    printf("Found:\n Name: %s, ID: %d, Grade: %.2f\n", found->name, found->id, found->grade);
                } else {
                    printf("Student not found.\n");
                }
                break;
            case 5:
                deleteList();
                break;
            case 6:
                deleteList();
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
