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
    // Allocate memory for the new student
    Student *newStudent = (Student *)malloc(sizeof(Student));
    if (newStudent == NULL)
    {
        printf("Memory allocation failed!\n"); // Print error message if memory allocation fails
        exit(1);
    }

    // Initialise a pointer that will point to the head of the list
    Student *current = head;

    // Loop from the head to the end of the list to check if the student already exists
    while (current != NULL)
    {
        if (strcmp(current->name, name) == 0)
        {
            printf("\"%s\" already exist in the system\n", name);
            return NULL;
        }
        else if (current->id == id)
        {
            printf("ID %d already exist in the system\n", id);
            return NULL;
        }
        current = current->next;
    }

    // Copy student name and assign ID and grade to the new student node
    strcpy(newStudent->name, name);
    newStudent->id = id;
    newStudent->grade = grade;
    newStudent->next = NULL;
    return newStudent;
}

// Function to insert a new student record
void insertStudent(const char *name, int id, float grade)
{
    // Check if the grade is within the valid range
    if (grade < 0 || grade > 100)
    {
        printf("Invalid grade. Grade should be between 0 and 100.\n");
        return;
    }
    // Create a new student record
    Student *newStudent = createStudent(name, id, grade);
    // createStudent function will return NULL if the student already exists
    if (newStudent == NULL)
    {
        return;
    }
    // Set the next pointer of the new student to the head of the list
    newStudent->next = head;
    head = newStudent;
}

// Function to display all student records
void displayStudents()
{
    // Check if the list is empty
    if (head == NULL)
    {
        printf("No student records to display.\n");
        return;
    }
    // Initialise a pointer that will point to the head of the list
    Student *current = head;

    // Loop from the head to the end of the list to print each student record
    // Loop will continue until the current pointer reaches the end of the list
    while (current != NULL)
    {
        printf("Name: %s, ID: %d, Grade: %.2f\n", current->name, current->id, current->grade);
        current = current->next; // Let that pointer to shift to the next node
    }
}

// Function to search for a student by ID
Student *searchStudentByID(int id)
{
    // Initialise a pointer that will point to the head of the list
    Student *current = head;

    // Loop from the head to the end of the list to search for the student record
    // Linear search
    while (current != NULL)
    {
        if (current->id == id)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
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

// Sort function to sort the student records by grade
// Sort by bubble sort algorithm
void sortStudents()
{
    if (head == NULL || head->next == NULL)
    {
        printf("Not enough records to sort.\n");
        return;
    }
    int swapped;
    Student *ptr1;
    Student *lptr = NULL;

    do
    {
        // Set swapped to 0, a variable to check if the list is sorted
        // Will come back as 0 if no swaps are made in the list
        swapped = 0;
        ptr1 = head;

        // loop through the list
        while (ptr1->next != lptr)
        {
            if (ptr1->grade > ptr1->next->grade)
            {
                // Swap the data between both the nodes
                char tempName[100];
                int tempId;
                float tempGrade;

                // Copy the data of the first node to temporary variables
                strcpy(tempName, ptr1->name);
                tempId = ptr1->id;
                tempGrade = ptr1->grade;

                // Copy the data of the second node to the first node
                strcpy(ptr1->name, ptr1->next->name);
                ptr1->id = ptr1->next->id;
                ptr1->grade = ptr1->next->grade;

                // Copy the data of the first node which is stored in the temporary variables to the second node
                strcpy(ptr1->next->name, tempName);
                ptr1->next->id = tempId;
                ptr1->next->grade = tempGrade;

                // Set swapped to 1 to indicate that a swap has been made
                swapped = 1;
            }
            ptr1 = ptr1->next; // Set ptr1 to the next node in the list
        }
        lptr = ptr1; // Set lptr to the last node where the swap was made because based on bubble sort the last element is guranteed to be the largest
        // Reducing the number of loop for next iteration by 1
    } while (swapped);

    printf("Student records sorted by grade.\n");
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
        printf("3. Sort Records by Grade\n");
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
            strtok(name, "\n"); // Remove trailing newline
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
            deleteList();
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
