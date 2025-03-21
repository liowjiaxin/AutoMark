#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Student
{
    // Student's name
    char name[100];
    // student id
    int id;
    // student grade
    float grade;
    // point to the next student in the linked list
    struct Student *next;
} Student;

// head pointer
Student *head = NULL;

// main menu funtion to let user chose the options
void displayMenu()
{
    printf("\n1. Insert Student Record\n");
    printf("2. Display Student Records\n");
    printf("3. Sort Records\n");
    printf("4. Search Record by ID\n");
    printf("5. Delete List\n");
    printf("6. Exit\n");
}

// create student funtion, by creating a new student and return the function
Student *createStudent(const char *name, int id, float grade)
{
    // this part is used to allocate  memory for new student
    Student *newNode = (Student *)malloc(sizeof(Student));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    // Used to initialize the student node
    strcpy(newNode->name, name);
    newNode->id = id;
    newNode->grade = grade;
    newNode->next = NULL;
    return newNode;
}

// insert a new student record into the linked list
void insertStudent(const char *name, int id, float grade)
{

    Student *newStudent = createStudent(name, id, grade);
    if (newStudent == NULL)
        return;

    // if the inserted list is empty set the first student as the head  of the list
    if (head == NULL)
    {
        head = newStudent;
    }
    else
    {
        // point to the last of the list and than connect the new student to the end of the list
        Student *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newStudent;
    }
}

// Displaying all the listed out
void displayStudents()
{
    // error handling , ensure the list is not empty
    if (head == NULL)
    {
        printf("No student records to display.\n");
        return;
    }

    Student *temp = head;
    while (temp != NULL)
    {
        printf("Name: %s, ID: %d, Grade: %.2f\n", temp->name, temp->id, temp->grade);
        // pointer point to the next student to display out the whole list
        temp = temp->next;
    }
}

// Search function
// point to one by one than return the search value, returning Null if none of it match
Student *searchStudentByID(int id)
{
    Student *temp = head;
    while (temp != NULL)
    {
        if (temp->id == id)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

//
void deleteList()
{
    Student *current = head;
    Student *next;

    // loop through the list until the current pointer is NUll
    while (current != NULL)
    {
        next = current->next;
        // free the memory
        free(current);
        current = next;
    }
    // reseting the head to NULL after the process
    head = NULL;
    printf("List deleted.\n");
}

// free memory function
void freeMemory()
{
    deleteList();
}

// Bubble sort function , to sort the list in ascending order by grade  after choosing option 3
void sortStudents()
{
    // validation if the list enough student to sort or not
    if (head == NULL || head->next == NULL)
    {
        printf("Not enough student to sort.\n");
        return;
    }

    int sort;
    Student *Current, *Last_Sorted = NULL;

    do
    {
        sort = 0;
        Current = head;

        while (Current->next != Last_Sorted)
        {
            // Exchanging the current and next data to sort
            if (Current->grade > Current->next->grade)
            {

                char tempName[100];
                int tempID;
                float tempGrade;

                strcpy(tempName, Current->name);
                tempID = Current->id;
                tempGrade = Current->grade;

                strcpy(Current->name, Current->next->name);
                Current->id = Current->next->id;
                Current->grade = Current->next->grade;

                strcpy(Current->next->name, tempName);
                Current->next->id = tempID;
                Current->next->grade = tempGrade;

                sort = 1;
            }
            // move to the next pair
            Current = Current->next;
        }

        // update for the last sorted node
        Last_Sorted = Current;
    } while (sort);

    printf("Records sorted by grade using Bubble Sort.\n");
}

int main()
{
    int choice, id;
    char name[100];
    float grade;

    // used to display the Menu and options, than prompt the user to enter the choices
    do
    {
        displayMenu();

        printf("Enter your choice: ");
        while (scanf("%d", &choice) != 1)
        {
            printf("Invalid choice. Please try again. ");
            // clear buffer
            while (getchar() != '\n')
                ;
        }
        // get rid of the new line
        getchar();

        // create few cases for entering the details of student
        // and do error handling for the user enter value
        switch (choice)
        {
        case 1:
            printf("Enter Name: ");
            while (1)
            {
                if (fgets(name, sizeof(name), stdin))
                {
                    name[strcspn(name, "\n")] = '\0';
                    // remove newline character
                    if (strlen(name) > 0)
                        break;
                }
                printf("Invalid input. Please enter a valid Name: ");
            }

            printf("Enter ID: ");
            while (scanf("%d", &id) != 1 || id <= 0)
            {
                printf("Invalid input! Please enter a positive integer : ");
                // clear buffer
                while (getchar() != '\n')
                    ;
            }

            printf("Enter Grade: ");
            while (scanf("%f", &grade) != 1 || grade < 0.0 || grade > 100.0)
            {
                printf("Invalid input! Please enter a positive integer between 0 and 100: ");
                while (getchar() != '\n')
                    ;
            }

            // implement each created function to the menu
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
            while (scanf("%d", &id) != 1 || id <= 0)
            {
                printf("Invalid input! Please enter a positive integer for ID: ");
                while (getchar() != '\n')
                    ;
            }

            Student *found = searchStudentByID(id);
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
            break;

        case 6:
            // free memory and exit
            freeMemory();
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}