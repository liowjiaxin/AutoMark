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
    if (!newStudent) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    strcpy(newStudent->name, name);
    newStudent->id = id;
    newStudent->grade = grade;
    newStudent->next = NULL;
    return newStudent;
}

// Function to insert a student
void insertStudent(const char* name, int id, float grade) {
    Student* newStudent = createStudent(name, id, grade);
    if (!newStudent) return;
    newStudent->next = head;
    head = newStudent;
}

// Function to display all students
void displayStudents() {
    if (!head) {
        printf("No records to be displayed.\n");
        return;
    }
    Student* current = head;
    while (current) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", current->name, current->id, current->grade);
        current = current->next;
    }
}

// Function to search for a student by ID
void searchStudentByID(int id) {
    Student* current = head;
    while (current) {
        if (current->id == id) {
            printf("Found! Name: %s, ID: %d, Grade: %.2f\n", current->name, current->id, current->grade);
            return;
        }
        current = current->next;
    }
    printf("Student with ID %d not found. Please ensure the correct ID is entered.\n", id);
}

// Function to sort students by grade
void sortStudents() {
    for (Student* i = head; i && i->next; i = i->next) {
        Student* min = i;
        for (Student* j = i->next; j; j = j->next) {
            if (j->grade < min->grade) min = j;
        }
        if (min != i) {
            // swapping student data
            char tempName[100];
            int tempID = i->id;
            float tempGrade = i->grade;

            strcpy(tempName, i->name);
            strcpy(i->name, min->name);
            strcpy(min->name, tempName);

            i->id = min->id;
            i->grade = min->grade;

            min->id = tempID;
            min->grade = tempGrade;
        }
    }
}

// Function to delete the entire list
void deleteList() {
    Student* current = head;
    while (current) {
        Student* temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;
    printf("All records deleted.\n");
}

// Main function
int main() {
    int choice, id;
    float grade;
    char name[100];

    do {
        printf("\n1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records\n");
        printf("4. Search Record by ID\n");
        printf("5. Delete List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1 || choice < 1 || choice > 6) { // to ensure valid user input
            printf("Invalid choice. Please enter a number between 1 to 6.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
            // 1. Insert Student Record
                printf("Enter name: ");
                while (getchar() != '\n');
                scanf("%[^\n]", name);
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter grade: ");
                scanf("%f", &grade);
                insertStudent(name, id, grade);
                break;

            case 2:
            // 2. Display Student Records
                displayStudents();
                break;

            case 3:
            //3. Sort Records
                sortStudents();
                printf("Records sorted by grade.\n");
                break;

            case 4:
            //4. Search Record by ID
                printf("Enter student ID to search: ");
                scanf("%d", &id);
                searchStudentByID(id);
                break;

            case 5:
            //5. Delete List
                deleteList();
                break;

            case 6:
            //6. Exit
                deleteList();
                printf("Exiting...\n");
                break;
        }
    } while (choice != 6); //menu loops until user exits
    
    return 0;
}
