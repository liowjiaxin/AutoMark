#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLIST 10

// global variable declaration
int counter_linkedlist;

// Structure for Student
typedef struct Student 
{
    char name[100];
    int id;
    float grade;
    struct Student *next;
} Student;
Student *head = NULL;
Student *list[MAXLIST];

// function prototype declaration
Student* createStudent(const char* name, int id, float grade);
void insertStudent(const char* name, int id, float grade);
void displayStudents();
Student* searchStudentByID(int id);
void deleteList();
void freeMemory();
void sortStudents();
void merge_sort_divide(int left_index, int right_index);
void merge_sort_combine(int left_index, int middle_index, int right_index);

// Main function to drive the program
int main() 
{
    int choice, id;
    char name[100];
    float grade;
    
    // set Student *list[MAXLIST] pointers to NULL
    memset(list, 0, sizeof(list));

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
        getchar();      // To consume the newline character

        switch (choice) 
        {
        case 1:
            if (counter_linkedlist >= MAXLIST)
            {
                printf("Maximum number of student records reached!\n");
                break;
            }
            
            printf("Enter Name: ");
            fgets(name, sizeof(name), stdin);
            strtok(name, "\n");     // To consume the newline character

            printf("Enter ID: ");
            scanf("%d", &id);

            // checker to prevent user from entering duplciate student IDs
            int n = 0;
            for (int i = 0; i < counter_linkedlist; i++)
            {
                if (id == list[i]->id)
                {
                    n = 1;      // set the duplicate flag
                    printf("Student ID already in use!\n");
                    break;      // this break only breaks the for loop, not the switch case
                }
            }

            if (n == 1)
            {
                break;          // break from switch case if duplicate flag is set
            }
            
            printf("Enter Grade: ");
            scanf("%f", &grade);

            // if user enters grade lesser than 0 or more than 100, break from switch case
            if (grade < 0 || grade > 100)
            {
                printf("Grade must be between 0 and 100 inclusive.\n");
                break;
            }

            insertStudent(name, id, grade);
            break;
        case 2:
            displayStudents();
            break;
        case 3:
            printf("Records sorted by grade using Merge Sort.\n");
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
            break;
        }
    } 
    while (choice != 6);

    return 0;
}

// Function to creates a new student node and return a pointer to it
Student* createStudent(const char* name, int id, float grade) 
{
    // Write your code (1 mark)
    // allocate memory for new student node
    list[counter_linkedlist] = malloc(sizeof(Student));

    // copy user input values 
    strcpy(list[counter_linkedlist]->name, name);
    list[counter_linkedlist]->id = id;
    list[counter_linkedlist]->grade = grade;

    return list[counter_linkedlist];
}

// Function to insert a new student record into the linked list
void insertStudent(const char* name, int id, float grade) 
{
    // Write your code (1 mark)
    
    // this commented out old code is to set the first user input to be the head node
    // the head node will point to the second input in the list
    // then the 2nd input will point to 3rd etc.
    /*
    if (head == NULL && counter_linkedlist == 0)
    {
        head = createStudent(name, id, grade);
        counter_linkedlist++;
    }
    else
    {
        list[counter_linkedlist] = createStudent(name, id, grade);
        counter_linkedlist++;
    }
    */

    // a new head node is set after every user input according to sample output
    Student *new_head = NULL;
    new_head = createStudent(name, id, grade);

    // set current input's next pointer to point to prev input's address
    // and prev input's next pointer to NULL
    if (counter_linkedlist > 0)
    {
        // for any subsequent user inputs, those inputs will point to the old head node
        list[counter_linkedlist]->next = head;
        head = new_head;
    }
    else
    {
        // this else statement will only run once at the start when user inputs the first student record
        list[counter_linkedlist]->next = NULL;
        head = new_head;
    }

    counter_linkedlist++;
}

// Function to display all student records
void displayStudents() 
{
    // Write your code (1 mark)
    if (counter_linkedlist == 0)
    {
        printf("No student records saved.\n");
    }
    
    // reinitialise *current to point to next node every iteration
    Student *current = head;
    while(current != NULL) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", current->name, current->id, current->grade);
        current = current->next;
    }
}

// Function to search for a student record by student ID 
// and return a pointer to the corresponding student node.
Student *searchStudentByID(int id) 
{
    // Write your code (1 mark)
    // loop through struct list to find identical id
    for (int i = 0; i < counter_linkedlist; i++)
    {
        if (id == list[i]->id)
        {
            return list[i];
        }
    }
    return NULL;
}

// Function to delete the entire list
void deleteList() 
{
    // ensure that after list has been deleted, user can still enter up to MAXLIST number of inputs before reaching limit
    counter_linkedlist = 0;

    Student *current = head;
    Student *next;
    while (current != NULL) 
    {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;

    for (int i = 0; i < counter_linkedlist; i++)
    {
        free(list[i]);
    }
} 

// called when exiting to just delete everything
void freeMemory() 
{
    deleteList();
}

// Sort function to sort the student records by grade based on an algorithm of your choice
void sortStudents() 
{
    // Write your code (1 mark)
    // Merge Sort is my choice of sorting algorithm 
    // because it has a consistent time complexity of O(n log n)
    // which is very efficient for large sets of data such as student records.
    // e.g. UoNM's 2024 Y01 School of Computer Science already has 180+ undergrads like
    merge_sort_divide(0, counter_linkedlist - 1);
}

// Merge Sort algorithm function to split array into 2 subarrays recursively
void merge_sort_divide (int left_index, int right_index) 
{
    // after continuous splitting, the middle index will be equal to the left index
    // e.g. left = 0, right = 1, hence middle = 0
    // when middle index is passed on to merge_sort_divide as right index for further splitting,
    // this if condition will make the function return back to the previous subarray
    if (left_index < right_index) 
    { 
        int middle_index = left_index + (right_index - left_index)/2;

        //further divide left side half into 2 halves
        merge_sort_divide(left_index, middle_index);

        //further divide right side half into 2 halves
        merge_sort_divide(middle_index + 1, right_index);

        //combine 2 elements together, gradually into an array
        merge_sort_combine(left_index, middle_index, right_index);
    }
}

// Merge Sort algorithm function to combine 2 subarrays
void merge_sort_combine(int left_index, int middle_index, int right_index) 
{
    int leftside_length = middle_index - left_index + 1;
    int rightside_length = right_index - middle_index;

    // temp left&right pointer arrays
    Student *left_arrayPTR[leftside_length];
    Student *right_arrayPTR[rightside_length];

    for (int i = 0; i < leftside_length; i++) 
    {
        left_arrayPTR[i] = list[left_index + i];
    }

    for (int j = 0; j < rightside_length; j++) 
    {
        right_arrayPTR[j] = list[middle_index + 1 + j];
    }

    int i, j, k;
    Student temp;
    Student *current = &temp;

    // DO NOT SET NEW HEAD NODE BEFORE SORTING IN FOR LOOP
    // THIS WILL REQUIRE THE i AND j COUNTER VALUES TO ALTER, SETTING i = 1, j = 1 DOES NOT WORK
    // FIND AND SET THE HEAD NODE AFTER SORTING FOR LOOP
    /*
    if ( i < leftside_length && ( j >= rightside_length || left_arrayPTR[i]->grade <= right_arrayPTR[j]->grade ) )
    {
        head = left_arrayPTR[i];
    }
    else 
    {
        head = right_arrayPTR[j];
    }
    */

    // in this for loop, current.next will point to the list[i] being assessed
    // then current will be set to "become" list[i]
    // in the next iteration, current will still be the prev list[i],
    // which the program will set the prev list[i] to point to the current list[i] being assessed
    for ( (i = 0, j = 0, k = left_index); k <= right_index; k++)
    {
        if ( i < leftside_length && ( j >= rightside_length || left_arrayPTR[i]->grade <= right_arrayPTR[j]->grade ) )
        {
            current->next = left_arrayPTR[i];
            current = current->next;
            i++;
        }
        else 
        {
            current->next = right_arrayPTR[j];
            current = current->next;
            j++;
        }
    }

    // Hence, this means that the loop will end with the last list[i] that was assessed to be pointing to itself
    // therefore, the list[last]'s, which is also "current", pointer will be set to NULL
    // indicating that the list[last] is the "tail" with the highest grade value
    current->next = NULL;
    head = temp.next;
    // prior to the for loop, *current = &temp, and then in the first iteration of the for loop, 
    // current.next (aka temp.next) = list[first], hence instead creating an if/else statement prior to the for loop,
    // temp is used to hold list[first], so that i can implement:
    // head = temp.next = list[first]

    // after sorting, each list[i] will no longer point to list[i + 1],
    // hence i used this for loop to make it so that the linked list indices are in order as well
    current = head;
    for (k = left_index; k <= right_index; k++) 
    {
        list[k] = current;
        current = current->next;
    }
}