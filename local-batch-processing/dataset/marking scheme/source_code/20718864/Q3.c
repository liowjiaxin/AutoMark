#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

// Structure for Student 
typedef struct Student 
{ 
    char name[100]; 
    int id; 
    float grade;    
    struct Student* next; 
} Student; 

Student* head = NULL; 


// Create new student by allocating the memory  
Student* createStudent(const char* name, int id, float grade) 
{ 
    // Allocate memory for the student
    Student* newStudent = malloc(sizeof(Student));

    // Checks if memory allocation is succesfull or not. If not, return NULL
    if (newStudent == NULL) 
    {
        printf("Memory allocation fails");
        return NULL;
    }

    // Set student details
    newStudent->id = id;
    newStudent->grade = grade;
    strcpy(newStudent->name, name);

    return newStudent; 
}


void insertStudent(const char* name, int id, float grade) 
{
    // Allocating memory for the new student
    Student* newStudent = createStudent(name, id, grade);

    // Check if memory allocation is succesfull or not, if not then return
    if (newStudent == NULL) 
    {
        printf("Memory allocation failed.\n");
        return;
    }

    newStudent->next = head;  
    head = newStudent;        

    printf("Student added.\n");
}


void displayStudents() 
{
    // Check if the list is empty or not
    if (head == NULL) 
    {
        printf("No students found.\n");
        return;
    }

    // Traverse through the list and find the student's information (with pointer)
    Student* current = head;
    // Will keep printing as long as there are still some students
    while (current != NULL) 
    {
        printf("Name: %s, ID: %d, Grade: %.2f\n", current->name, current->id, current->grade);
        current = current->next;  
    }
}


// Function to search for a student by ID
Student* searchStudentByID(int id)
{
    // sets the 'current' to the 'head', which mean the first student on the lsit
    Student* current = head;
    // While loop continues as long there are still some students left in this list
    while (current != NULL)
    {
        if (current->id == id)
        {
            return current; 
        }
        current = current->next;  
    }

    // If the student is not found, return NULL
    return NULL;
    printf("Student not found");
}


// Function to delete the entire list 
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

void freeMemory() 
{ 
 deleteList(); 
} 


// Function to sort student records by grade using Bubble Sort
void sortStudents() 
{
    // Make sure that there is student
    if (head == NULL) 
    {
        printf("No students to sort.\n");
        return;
    }

    // Decalre the variable
    Student* current;
    Student* next;
    int swapped;

    // Use bubble sort to swap until there is no more to swap (based on grades in ascending order)
    /// Reason why I use bubble sort is because it is simple and easy to use compared to other sort method 
    do 
    {
        swapped = 0;
        current = head;

        // Use while loop to go through each student
        while (current != NULL && current->next != NULL)
        {
            next = current->next;

            // Compare grades of two adjacent students
            if (current->grade > next->grade) 
            {
                // Swap grades if the current grade is higher than the next's grade
                float tempGrade = current->grade;
                current->grade = next->grade;
                next->grade = tempGrade;

                swapped = 1;  
            }
            current = current->next;
        }
    } while (swapped);  

    printf("Students sorted by grade.\n");
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
                Student* found = searchStudentByID(id); 
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
                printf("Exiting the system...\n"); 
                break; 
            default: 
                printf("Invalid choice! Please try again.\n"); 
        } 
    } 
    while (choice != 6); 
}