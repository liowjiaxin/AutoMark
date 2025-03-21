#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student 
{
    char name[100];
    int id;
    float grade;
    struct Student* next;
} Student;

Student* head = NULL;

Student* createStudent(const char* name, int id, float grade)  
{
    Student* newStudent = (Student*)malloc(sizeof(Student)); //dynamically allocates memory for new Student node using malloc
    if (newStudent == NULL)  //check if malloc is successful
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(newStudent->name, name); //copies the name entered into the name parameter to the name field of the Student structure
    newStudent->id = id; //access the id field of the new Student structure and sets the id field of the new student to the value of the id parameter
    newStudent->grade = grade; //set the grade field of the new Student structire to the value of the grade parameter
    newStudent->next = NULL; //initialize the next ptr of the Student struct to NULL to make sure the newly created node is not linked to any other node initially
    return newStudent; //return the pointer to the newly created and initialized Student struct so can be used by other parts of the program
}

void insertStudent(const char* name, int id, float grade);
void displayStudents();
void sortStudents();
void searchStudentID(int id);
void deleteList();

int main() {
    int choice, id;
    char name[100];
    float grade;

    do {
        printf("\n1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records \n");
        printf("4. Search Record by ID\n");
        printf("5. Delete List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

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
                searchStudentID(id);
                break;
            case 5:
                deleteList();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void insertStudent(const char* name, int id, float grade) //insert new student record into the linked list
{
    Student* newStudent = createStudent(name, id, grade); //dynamically allocate memory and iniitializes the fields of the new node with name, id and grade and stored in newStudent
    newStudent->next = head; //link the new student node to the current list
    head = newStudent; //updates the head ptr to point to the new node bc the new node is inserted at the beginning of the list
    printf("Student record inserted.\n");
}

void displayStudents() 
{
    if (head == NULL) 
    {
        printf("No student records available.\n");
        return;
    }

    Student* current = head;
    printf("Student Records:\n");
    while (current != NULL) 
    {
        printf("Name: %s\nID: %d\nGrade: %.2f\n", current->name, current->id, current->grade);
        current = current->next;
    }
}

//sort student records in ascending order based on grades
void sortStudents() //sorted using bubble sort because student records is a small dataset and can be sorted efficiently using bubble sort
{
    if (head == NULL || head->next == NULL)  //if the list is empty, there are no nodes to sort or, if the list has only one node, so we dont need to sort
    {
        printf("No sorting needed.\n");
        return;
    }

    int swapped; //flag to track whethere any elements were swapped and used to determine if the swapping is complete
    Student* ptr1; //pointer to TRAVERSE the list during sorting
    Student* lptr = NULL; //pointer to mark the last sorted element so we can reduce the range of traversal in each iteration
    do //continue sorting until no swaps are performed
    {
        swapped = 0;
        ptr1 = head; //reset the traversal pointer to the beginning of the list

        while (ptr1->next != lptr)  //traverses the list until ptr1->next reaches lptr which is the last sorted element
        {
            if (ptr1->grade > ptr1->next->grade) //if grade of the current node (ptr->grade) > than grade of nect node (ptr1->next->grade), the two nodes are swapped 
            {
                //temporarily store current node's data (ptr1) in local variables
                float tempGrade = ptr1->grade; 
                int tempId = ptr1->id;
                char tempName[100];
                strcpy(tempName, ptr1->name);

                //copy data from the next node (ptr->next) into the current node (ptr1)
                ptr1->grade = ptr1->next->grade; 
                ptr1->id = ptr1->next->id;
                strcpy(ptr1->name, ptr1->next->name);

                //copy the data stored in the temp variables into the next node(ptr->next)
                ptr1->next->grade = tempGrade;
                ptr1->next->id = tempId;
                strcpy(ptr1->next->name, tempName);

                swapped = 1; //update the swap flag
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
    printf("Student records sorted by grade using bubble sort. \n");
}

void searchStudentID(int id) 
{
    Student* current = head; //a pointer current is initialized to point to the first node (head) of the linked list
    while (current != NULL) 
    {
        if (current->id == id) 
        {
            printf("Student found:\n");
            printf("Name: %s\nID: %d\nGrade: %.2f\n", current->name, current->id, current->grade);
            return;
        }
        current = current->next;
    }
    printf("Student not found.\n");
}

void deleteList() 
{
    Student* current = head;
    while (current != NULL) 
    {
        Student* next = current->next; //a ptr next is initialized to point to the next node in the list to make sure the reference to the rest of the linked list 
                                        //is not lost after the current node is deleted
        free(current);
        current = next;
    }
    head = NULL;
    printf("List deleted.\n");
}