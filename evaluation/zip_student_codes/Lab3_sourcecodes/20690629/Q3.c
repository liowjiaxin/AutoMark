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
Student* createStudent(const char* name, int id, float grade) 
{ 
    // create new student node and assign a pointer to it
    // assign name, id and grade to it
    Student* node = (Student*)malloc(sizeof(Student));
    strcpy(node->name, name);
    node->id = id;
    node->grade = grade;
    node->next = NULL;
    return node;
}  

// Function to insert a new student record 
void insertStudent(const char* name, int id, float grade) 
{ 
    // creat student
    Student *new = createStudent(name, id, grade);
    Student *temp = head;
    if (head == NULL) 
        head = new;
    else
    {
        // traverse the list and insert the node at the end
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
    }
} 

// Function to display all student records 
void displayStudents() 
{    
    if (head == NULL) return;
    Student *node = head;
    printf("\n");
    // traverse the list and print out attributes of each node
    while (node != NULL)
    {
        printf("%s,  %d,  %.2f\n", node->name, node->id, node->grade);
        node = node->next;
    }
}  

// Function to search for a student by ID 
Student* searchStudentByID(int id) 
{ 
    // traverse the list and check the id of each node agains the input id
    Student* node = head;
    while(node != NULL)
    {
        if (node->id == id) return node;
        node = node->next;
    }
    return NULL;
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

// splitting lists into halves
void splitList(Student* source, Student** front, Student** back)
{
    // a fast pointer that points to the next node after the next node to determine end of list
    // a slow pointer that points to the next node to determine middle of list
    Student* slow = source;
    Student* fast = source->next;

    while (fast != NULL && fast->next != NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    // splitting list to first half and second half
    *front = source;
    *back = slow->next;

    slow->next = NULL;
}

// merge sorted lists after splitting happens
Student* mergeLists(Student *p, Student *q)
{
    Student *ans = NULL;
    // if first half is empty, return remaining of second half
    if (p == NULL) return q;
    // if second half is empty, return remaining of first half
    if (q == NULL) return p;

    // compare value of node in first half and value of node in second half
    if (p->grade <= q->grade)
    {
        // move to next node in first half
        ans = p;
        ans->next = mergeLists(p->next, q);
    }
    else
    {
        // move to next node in second half
        ans = q;
        ans->next = mergeLists(p, q->next);
    }

    return ans;
}

// Sort function to sort the student records by grade based on an algorithm of your choice 
void sortStudents(Student** source) 
{ 
    // merge sort
    if (*source == NULL || (*source)->next == NULL) return;

    Student* front;
    Student* back;
    // split lists
    splitList(*source, &front, &back);
    // merge sorted lists
    sortStudents(&front);
    sortStudents(&back);

    *source = mergeLists(front, back);
}  

// Main function to drive the program 
int main() 
{      
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
                sortStudents(&head);                                 
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