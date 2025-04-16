#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
    char name[100];
    int id;
    char grade;
    struct Student *next;
} Student;

Student *head = NULL;

// Function prototypes
Student *createStudent(const char *name, int id, char grade);
void insertStudent(const char *name, int id, char grade);
void displayStudents();
Student *searchStudentByID(int id);
void deleteList();
void sortStudents();
void freeMemory();

// Function to create a new student node
Student *createStudent(const char *name, int id, char grade)
{
    Student *newStudent = (Student *)malloc(sizeof(Student));
    if (!newStudent)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(newStudent->name, name);
    newStudent->id = id;
    newStudent->grade = grade;
    newStudent->next = NULL;
    return newStudent;
}

// Function to insert a new student record into the linked list
void insertStudent(const char *name, int id, char grade)
{
    if (grade < 'A' || grade > 'F')
    {
        printf("Invalid grade. Please enter a capital letter between A and F.\n");
        return;
    }
    Student *newStudent = createStudent(name, id, grade);
    newStudent->next = head;
    head = newStudent;
}

// Function to display all student records
void displayStudents()
{
    if (!head)
    {
        printf("No student records available.\n");
        return;
    }
    printf("\nStudent Records:\n");
    Student *current = head;
    while (current)
    {
        printf("Name: %s, ID: %d, Grade: %c\n", current->name, current->id, current->grade);
        current = current->next;
    }
}

// Function to search for a student record by ID
Student *searchStudentByID(int id)
{
    Student *current = head;
    while (current)
    {
        if (current->id == id)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to delete the entire linked list
void deleteList()
{
    Student *current = head;
    while (current)
    {
        Student *temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;
}

// Function to sort the student records by grade
void sortStudents()
{
    if (!head || !head->next)
    {
        printf("\nNo sorting needed. The list has one or no records.\n");
        return;
    }

    Student *sorted = NULL;
    Student *current = head;

    while (current)
    {
        Student *next = current->next;

        if (!sorted || current->grade < sorted->grade)
        {
            current->next = sorted;
            sorted = current;
        }
        else
        {
            Student *temp = sorted;
            while (temp->next && temp->next->grade <= current->grade)
            {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        current = next;
    }

    head = sorted;
    printf("\nRecords sorted by grade.\n");
    displayStudents();
}

// Function to free all allocated memory
void freeMemory()
{
    deleteList();
}

int main()
{
    int choice;
    char name[100];
    int id;
    char grade;

    do
    {
        printf("\nMenu:\n");
        printf("1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records by Grade\n");
        printf("4. Search Record by ID\n");
        printf("5. Delete All Records\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter name: ");
            scanf("%s", name);
            printf("Enter ID: ");
            scanf("%d", &id);
            do
            {
                printf("Enter grade (A-F): ");
                scanf(" %c", &grade);
                if (grade < 'A' || grade > 'F')
                {
                    printf("Invalid grade. Please enter a capital letter between A and F.\n");
                }
            } while (grade < 'A' || grade > 'F');
            insertStudent(name, id, grade);
            break;
        case 2:
            displayStudents();
            break;
        case 3:
            sortStudents();
            break;
        case 4:
            printf("\nEnter ID to search: ");
            scanf("%d", &id);
            Student *found = searchStudentByID(id);
            if (found)
            {
                printf("Record found: Name: %s, ID: %d, Grade: %c\n", found->name, found->id, found->grade);
            }
            else
            {
                printf("No record found with ID %d.\n", id);
            }
            break;
        case 5:
            deleteList();
            printf("All records deleted.\n");
            break;
        case 6:
            freeMemory();
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
