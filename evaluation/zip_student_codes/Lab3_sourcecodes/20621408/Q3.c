#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// STRUCTURE
//      Student
//      Structure for Student
typedef struct Student
{
    char name[100];
    int id;
    float grade;
    struct Student* next;
} Student;

Student* head = NULL;

// FUNCTIONS:
//      Create Student
//      Function to create a new student node
//      Creates a new student node and returns a pointer to it.
Student* createStudent(const char* name, int id, float grade)
{
    Student* newStudent = (Student*)malloc(sizeof(Student));

    if (!newStudent)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    strcpy(newStudent->name, name);
    newStudent->id = id;
    newStudent->grade = grade;
    newStudent->next = NULL;

    return newStudent;
}

//      Insert Student
//      Function to insert a new student record
//      Inserts a new student record into the linked list.
void insertStudent(const char* name, int id, float grade)
{
    Student* newStudent = createStudent(name, id, grade);
    newStudent->next = head;
    head = newStudent;
}

//      Display Student
//      Function to display all student records
//      Displays all current student records in the linked list.
void displayStudents()
{
    if (!head)
    {
        printf("No student records currently.\n");
        return;
    }

    Student* current = head;

    while (current)
    {
        printf("Name: %s, ID: %d, Grade: %.2f\n", current->name, current->id, current->grade);
        current = current->next;
    }
}

//      Search Student
//      Function to search for a student by ID
//      Searches for a student record by student ID and returns a pointer to the corresponding student node.
Student* searchStudentByID(int id)
{
    Student* current = head;

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

//      Delete Student List
//      Function to delete the entire list
//      Deletes the entire linked list and frees the allocated memory.
void deleteList()
{
    Student* current = head;
    Student* next;

    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }

    head = NULL;
}

//      Same as Delete Student List
//      A utility function to ensure that all memory is freed when the program exits.
void freeMemory()
{
    deleteList();
}

//      Sort Students
//      Sort function to sort the student records by grade based on an algorithm of your choice
//      Sort the student records by grade according to a sorting algorithm of your choice.
void sortStudents()
{
    if (!head || !head->next)
    {
        printf("Not enough records to sort.\n");
        return;
    }

    Student* current;
    Student* next;
    int swapped;

    // Bubble Sort
    do
    {
        swapped = 0;
        current = head;

        while (current->next)
        {
            next = current->next;
            if (current->grade > next->grade)
            {
                // Swap
                char tempName[100];
                int tempID;
                float tempGrade;

                strcpy(tempName, current->name);
                tempID = current->id;
                tempGrade = current->grade;

                strcpy(current->name, next->name);
                current->id = next->id;
                current->grade = next->grade;

                strcpy(next->name, tempName);
                next->id = tempID;
                next->grade = tempGrade;

                swapped = 1;
            }

            current = current->next;
        }
    } while (swapped);

    printf("Records sorted by grade using Bubble Sort.\n");
}

// MAIN PROGRAM ----------------------------------------------------------------------------------------------------------------------
//      Main function to drive the program
int main()
{
    int choice, id;
    char name[100];
    float grade;

    // Main Menu Loop
    do
    {
        printf("\n1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records\n");
        printf("4. Search Record by ID\n");
        printf("5. Delete List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();                                              // To consume the newline character (\n)

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                fgets(name, sizeof(name), stdin);
                strtok(name, "\n");                             // Remove trailing newline character (\n)
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

                if (found)
                {
                    printf("Found: Name: %s, ID: %d, Grade: %.2f\n", found->name, found->id, found->grade);
                }
                else
                {
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