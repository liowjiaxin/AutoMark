#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Student
typedef struct Student
{
    char name[100];
    int id;
    float grade;
    struct Student *next;
} Student;

Student *head = NULL;

// Function to create a new student node
Student *createStudent(const char *name, int id, float grade)
{
    Student *NewStudent = (Student *)malloc(sizeof(Student)); // NewStudent is the pointer that points to the first node of the linked list
    strcpy(NewStudent->name, name);
    NewStudent->id = id;
    NewStudent->grade = grade;
    NewStudent->next = NULL; // pointer that points to the next part of the linked list declared to NULL
    return NewStudent;
}

// Function to insert a new student record
void insertStudent(const char *name, int id, float grade)
{
    Student *NewStudent = createStudent(name, id, grade);
    if (!head) // if head pointer is empty, NewStudent becomes the first node in the list
    {
        head = NewStudent;
    }
    else // if its not empty, we find the last node in the list to make it NewStudent
    {
        Student *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = NewStudent; // by the end of the loop, temp points to the last node in the list
    }
    printf("Student record added.\n");
}

// Function to display all student records
void displayStudents()
{
    if (!head)
    {
        printf("No student records to display.\n");
        return;
    }
    Student *temp = head;
    printf("\nStudent Records:\n");
    while (temp)
    {
        printf("Name: %s, ID: %d, Grade: %.2f\n", temp->name, temp->id, temp->grade);
        temp = temp->next; // iterate through the nodes, printing them all out until the last node is reached
    }
}

// Function to search for a student by ID
Student *searchStudentByID(int id)
{
    Student *temp = head;
    while (temp)
    {
        if (temp->id == id)
        {
            return temp; // iterate through the nodes, if one of the nodes are the same as id, return temp
        }
        temp = temp->next;
    }
}

// Function to delete the entire list
void deleteList()
{
    Student *current = head;
    Student *next;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
}

void freeMemory()
{
    deleteList();
}

// Sort function to sort the student records by grade based on an
// algorithm of your choice
void sortStudents()
{
    // using bubble sort
    Student *i, *j;
    for (i = head; i != NULL; i = i->next) // outer loop that iterates through the nodes
    {
        for (j = i->next; j != NULL; j = j->next) // inner loop that iterates through the nodes after i
        {
            if (i->grade < j->grade)
            {
                // swap the contents of the two nodes
                char tempName[100];
                int tempID;
                float tempGrade;

                strcpy(tempName, i->name);
                tempID = i->id;
                tempGrade = i->grade;

                strcpy(i->name, j->name);
                i->id = j->id;
                i->grade = j->grade;

                strcpy(j->name, tempName);
                j->id = tempID;
                j->grade = tempGrade;
            }
        }
    }
    printf("Student records sorted by grade in descending order.\n");
}

// Main function to drive the program
int main()
{
    int choice, id;
    char name[100];
    float grade;
    do
    {
        printf("\n1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records (choose sorting method)\n");
        printf("4. Search Record by ID\n");
        printf("5. Delete List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character
        switch (choice)
        {
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
            Student *found = searchStudentByID(id);
            if (found)
            {
                printf("Found: Name: %s, ID: %d, Grade: %.2f\n",
                       found->name, found->id, found->grade);
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