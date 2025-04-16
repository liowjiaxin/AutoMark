#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure for Student
typedef struct Student{
    char name[100];
    int id;
    float grade;
    struct Student* next;   // Pointer to the next node in the list
}Student;


Student* globalHead = NULL; //refer to pointer to the start of linked list

//Function to create a new student node
Student* createStudent(const char* name, int id, float grade){
    Student* newNode = (Student*)malloc(sizeof(Student)); //allocate memory for newNode
    if (!newNode){
        perror("Memory Allocation failed.\n"); //display error message and exit is memory allocation fail
        exit(1);
    }
    // Initialize the new node with given data
    strcpy(newNode->name, name);    //place name in node
    newNode->id = id;               //place id in node
    newNode->grade = grade;         //place grade in node
    newNode->next = NULL;           //set next pointer to NULL, node does not link to another node
    return newNode;                 
}

//Function to insert a new student record
//The function takes a double pointer (Student **head) 
//because the head pointer itself is being updated. 
//By passing a pointer to the head, the function can directly modify the head pointer 
//in the calling function.
void insertStudent (Student** head, const char* name, int id, float grade){
    Student* newNode = createStudent(name, id, grade);  //assign the new node created to newNode
    newNode->next = *head;                              //link newNode to the current head
    *head = newNode;                                    // Update head to point to the new node
}

//Function to display all student records
void displayStudents(Student* node){
    if(node == NULL){ //check whether the list is empty
        printf("Record is empty. No record to display.\n");
        return;
    }
    while(node!=NULL){
        //display the first node in the list and move to the next node until the node is NULL
        printf("Name: %s, ID: %d, Grade: %.2f\n", node->name, node->id, node->grade);
        node = node->next;
    }
}

//Function to search for a student by ID
Student* searchStudentByID (int id){
    Student *search = globalHead;
    //loop from the beginning of the list to compare the target id with the id in each node
    while(search!=NULL){    // Traverse the list
        if(search->id == id){
            return search;  //if found, return the node
        }
        search=search->next;//else, assign the next node to the current node
    }
    return NULL; //if not found, return NULL
}

//Function to delete the entire list
void deleteList(Student** head){
    Student* current = *head;   //begin at the head of the list
    Student* next;              //declare temporary pointer to store the next node

    while(current!=NULL){
        next=current->next;     //store the next node
        free(current);          //free current node
        current=next;           //move to the next node
    }
    *head = NULL;               //assign NULL to head pointer to show that the list is now empty
    
}

//Function to split the linked list into two halves
Student* split(Student *head){
    Student* fast = head;   // Fast pointer moves two steps at a time
    Student* slow = head;   // Slow pointer moves two steps at a time

    // Move fast pointer two steps and slow pointer one step until fast reaches the end
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        if (fast != NULL) {
            slow = slow->next;
        }
    }
    // Split the list into two halves
    Student* temp = slow->next; //temp = second half which starts after the slow pointer
    slow->next = NULL; // first half link to NULL, terminate the first half, split the first half and second half
    return temp; //return the second half to mergeSort
}

// Function to merge two sorted linked lists
Student* merge(Student* first, Student* second) {
  
    // If either list is empty, return the other list
    if (first == NULL) return second;
    if (second == NULL) return first;

    // Pick the smaller grade between first and second nodes
    if (first->grade < second->grade) {
        first->next = merge(first->next, second); //merge remaining list
        return first;
    }
    else {
        // else if second node is greater than first node
        second->next = merge(first, second->next); //merge remaining list
        return second;
    }
}

// Function to perform merge sort on a linked list
Student* mergeSort(Student* head) {
  
    // Base case: if the list is empty or has only one node, 
    // it's already sorted
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Split the list into two halves
    Student* second = split(head);

    // Recursively sort each half
    head = mergeSort(head); //First half
    second = mergeSort(second); //Second half

    // Merge the two sorted halves
    return merge(head, second);
}

//Free memory by deleting the entire list
void freeMemory(Student **head){
    deleteList(head);
}

//Main function to drive the program
int main(){
    int choice, id;
    char name[100];
    float grade;

    do{
        //display menu for at least one time
        printf("\n***** Student Records Management System *****\n");
        printf("\t1. Insert Student Record\n");
        printf("\t2. Display Student Records\n");
        printf("\t3. Sort Records\n");
        printf("\t4. Search Record by ID\n");
        printf("\t5. Delete List\n");
        printf("\t6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); //to consume newline character;

        switch(choice){
            case 1:
                printf("Enter Name: "); //scan for student name
                fgets(name, sizeof(name), stdin);
                strtok(name, "\n");
                
                int repeat = 0; //repeat flag
                int invalid = 0;//invalid flag
                do{
                    repeat=0; //reset the flag
                    invalid=0;//reset the flag
                    Student* current = globalHead; 

                    printf("Enter ID: ");   //scan for student ID
                    scanf("%d", &id);
                    
                    if(id<0){               //check whether ID is valid 
                        invalid=1;          //if no, set the invalid flag
                        printf("ID cannot be negative. Try again.\n"); //print error message
                    }

                    while(current!=NULL){           //compare whether the inputted ID already existed in the list
                        if(current->id == id){
                            repeat = 1;             //if yes, set the repeat flag
                            printf("ID %d is in record. ID cannot be repeated. Try again.\n", id);
                            break;
                        }
                        current=current->next;      //else, move to the next node to continue comparing until the node is NULL
                    }
                }while(repeat==1 || invalid==1);    //if either the ID is repeated or invalid, ask user to input again

                printf("Enter Grade: ");           
                scanf("%f", &grade);                //scan for student grade

                insertStudent(&globalHead, name, id, grade);    //when all details are inputted correctly, insert the student record into the list
                printf("Record inserted successfully.\n\n");    //display success message
                break;

            case 2:
                displayStudents(globalHead);
                break;

            case 3:
                if (globalHead == NULL){            //check whether the list is empty
                    printf("Record is empty. No records to sort.\n");
                    break;
                }
                globalHead = mergeSort(globalHead); //if no, sort the list according to grade
                printf("Records sorted successfully in ascending order of grades.\n\n");
                printf("Sorted records: \n");
                displayStudents(globalHead);        //display the sorted records to user
                break;

            case 4:
                if (globalHead == NULL){            //check whether the list is empty
                    printf("Record is empty. No records to search.\n");
                    break;
                }
                printf("Enter ID to search: "); 
                scanf("%d", &id);                   //scan for ID to search
                Student* found = searchStudentByID(id); //assign the node found to 'found'
                if (found){
                    printf("Student with ID %d is found in record.\n", id);
                    //display the student records searched by user
                    printf("Name: %s, ID: %d, Grade: %.2f\n", found->name, found->id, found->grade);
                }
                else{
                    //if no node is found, NULL will be returned by the function
                    //if found == NULL, display not found message
                    printf("Student with ID %d is not found in record.\n", id);
                }
                break;

            case 5:
                deleteList(&globalHead);
                printf("List is entirely deleted.\n");
                break;

            case 6:
                freeMemory(&globalHead);
                printf("Thank you for using Student Records Management System.\nTerminating program...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n\n");
                break;

        }
    }while(choice != 6); //while choice is not exit, loop back to print the menu for user to input

    return 0;
}