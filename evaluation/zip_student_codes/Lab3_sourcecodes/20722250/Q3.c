#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure for Student
typedef struct Student {
    char name[100];
    int id;
    float grade;
    struct Student* next;
} Student;

Student* head = NULL;

// function prototypes
Student* createStudent(const char* name, int id, float grade);
void insertStudent(const char* name, int id, float grade);
void displayStudents();
void sortStudents();
Student* searchStudentByID(int id);
void deleteList();
void freeMemory();
void displayMenu();

int main() 
{
    int choice;
    char name[100];
    int id;
    float grade;

    do 
    {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline character

        switch (choice) 
        {
            case 1: // insert student record
                printf("Enter name: ");
                fgets(name, sizeof(name), stdin);
                strtok(name, "\n"); // remove newline character
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter grade: ");
                scanf("%f", &grade);
                insertStudent(name, id, grade);
                break;

            case 2: // display student records
                if (head == NULL) // if list empty
                {
                    printf("No student records available to display.\n");
                }
                displayStudents();
                break;

            case 3: // sort student records
                if (head == NULL)
                {
                    printf("No student records available to sort.\n");
                }
                else
                {
                    sortStudents();
                    printf("Student records sorted by grade successfully using Selection Sort.\n");
                }
                break;

            case 4: // search student record by id
                if (head == NULL)
                {
                    printf("No student records available to search.\n");
                }
                else
                {
                    printf("Enter ID to search: ");
                    scanf("%d", &id);
                    Student* found = searchStudentByID(id);
                    if (found) 
                    {
                        printf("Student record found:\n");
                        printf("Name: %s, ID: %d, Grade: %.2f\n", found->name, found->id, found->grade);
                    } 
                    else 
                    {
                        printf("Student record not found.\n");
                    }
                }
                break;

            case 5: // delete list
                deleteList();
                printf("List deleted.\n");
                break;

            case 6: // exit
                freeMemory();
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

// function to create a new student node
Student* createStudent(const char* name, int id, float grade) 
{
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if (newStudent == NULL) 
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    
    strcpy(newStudent->name, name);
    newStudent->id = id;
    newStudent->grade = grade;
    newStudent->next = NULL;

    return newStudent;
}

// function to insert a new student record
void insertStudent(const char* name, int id, float grade) 
{
    Student* newStudent = createStudent(name, id, grade);
    newStudent->next = head;
    head = newStudent;
}

// function to display all student records
void displayStudents() 
{
    Student* current = head;
    
    while (current != NULL) 
    {
        printf("Name: %s, ID: %d, Grade: %.2f\n", current->name, current->id, current->grade);
        current = current->next;
    }
}

// function to sort the student records by grade using selection sort algorithm
void sortStudents() 
{
    Student* current = head;
    Student* min;
    Student* next;

    while (current != NULL) 
    {
        min = current;
        next = current->next;

        while (next != NULL) 
        {
            if (next->grade < min->grade) 
            {
                min = next;
            }
            next = next->next;
        }

        if (min != current) 
        {
            char tempName[100];
            int tempID;
            float tempGrade;

            // swap name            
            strcpy(tempName, current->name);
            strcpy(current->name, min->name);
            strcpy(min->name, tempName);

            // swap id
            tempID = current->id;
            current->id = min->id;
            min->id = tempID;
            
            // swap grade
            tempGrade = current->grade;
            current->grade = min->grade;
            min->grade = tempGrade;
        }
        current = current->next;
    }
}

// function to search for a student record by ID
Student* searchStudentByID(int id) 
{
    Student* current = head;

    while (current != NULL) 
    {
        if (current->id == id) // if match found, return current
        {
            return current;
        }
        current = current->next; // else, move to the next node
    }
    return NULL;
}

// function to delete the entire list
void deleteList() 
{
    Student* current = head;
    Student* next;

    while (current != NULL) 
    {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
}

// function to free all allocated memory
void freeMemory() 
{
    deleteList();
}

// function to display menu
void displayMenu()
{
    printf("\nStudent Record Management System\n");
    printf("1. Insert Student Record\n");
    printf("2. Display Student Records\n");
    printf("3. Sort Student Records\n");
    printf("4. Search Student Record by ID\n");
    printf("5. Delete List\n");
    printf("6. Exit\n");
}
