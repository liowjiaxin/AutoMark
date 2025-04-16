#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Student

typedef struct Student {

    char name [100];
    int id;
    float grade;
    struct Student* next;

} Student;

Student* head = NULL; // initially list is empty, so head == NULL

// Function to create a new student node

Student* createstudent (const char* name, int id, float grade ){

    Student* newStudentEntry = (Student*)malloc(sizeof(Student));
    // allocate memory dynamically for a new Student structure
    // the allocated memory stored in newStudent pointer

    if (!newStudentEntry){
        printf("Memory allocation failed.\n");
        exit (1);
    }

    strcpy (newStudentEntry->name,name);
    newStudentEntry->id = id;
    newStudentEntry->grade = grade;
    newStudentEntry->next = NULL;
    return newStudentEntry; // go back to the Student struct

}

// Function to insert a new student record (this always gets added at the LAST pos of linked list)

void insertStudent(const char* name, int id, float grade){

    Student* insertnewStudent = createstudent(name,id,grade); // use the previous linked list struct for student records

    if (head == NULL){ // head = first node in linked list, if head = NULL insertnewStudent is the first node
        head = insertnewStudent;
    }

    else{

        Student* temp = head; // temporary pointer to traverse the linked list

        while (temp->next !=NULL){ // goes through the list until next == NULL
            temp = temp->next;
        }

        temp->next = insertnewStudent; // next == NUll means last node in list, append insertnewStudent here
    }

    printf("Student record added successfully.\n");

}

// Function to display all student records

void displayStudents() {

    if (head == NULL){ // this means empty linked list

        printf("No student records available to display.");
        return;

    }

    printf("Student Records: \n");

    Student* temp = head; // use temp as a counter

    while (temp != NULL) { // print out all the nodes

        printf("Name: %s, ID: %d, Grade: %.2f\n",temp->name,temp->id,temp->grade);
        temp = temp->next; // move on to next node

    }

}

// Function to search for a student by ID

Student* searchStudentByID(int id) {

    Student* temp = head; //set counter index

    while (temp !=NULL){ // loop through the list

        if (temp->id == id){ // look for the same id

            return temp; // return match if found

        }

        temp=temp->next; // go to next node if not
    }

}

// Function to delete the entire list

void deleteList() {
    Student* current = head;
    Student* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
        }

    head = NULL;
}

void freeMemory() {
    deleteList();
}

// Sort function to sort the student records by grade based on an algorithm of your choice

void sortStudents() { // bubble sort is used here

    if (head == NULL || head->next == NULL){
        printf("No sorting needed as list contains no records / one student record only.");
        return;
    }

    int swapped = 1; // needs to be true for loop to start

    Student* currentpointer; // pointer used to compare 2 nodes
    Student* lastpointer = NULL; // last node pointer

    while (swapped){

        swapped=0;
        currentpointer = head;

        while (currentpointer->next != lastpointer){

            if (currentpointer->grade > currentpointer->next->grade){

                // higher grade gets swapped to the back of the list

                float tempStoreGrade = currentpointer->grade;
                currentpointer->grade = currentpointer->next->grade;
                currentpointer->next->grade = tempStoreGrade;

                // id of higher grade gets swapped to the back of the list as well

                int tempStoreId = currentpointer->id;
                currentpointer->id = currentpointer->next->id;
                currentpointer->next->id = tempStoreId;

                // name of higher grade gets swapped to the back of the list as well

                char tempStoreName [100];
                strcpy (tempStoreName,currentpointer->name);
                strcpy (currentpointer->name,currentpointer->next->name);
                strcpy (currentpointer->next->name,tempStoreName);

                swapped = 1; // flag showing a swap is done, this repeats until no swaps are made

            }

            currentpointer=currentpointer->next; // move to next node comparison

        }

        lastpointer=currentpointer; // update the last node of list to lastpointer

    }

    printf("Records sorted by grade using Bubble Sort Algorithm.\n");
} 

// Main function to drive the program 

int main() {

    int choice, id;
    char name[100];
    float grade; 

    do {
        printf("\n1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records (choose sorting method)\n");
        printf("4. Search Record by ID\n");
        printf("5. Delete List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character 

    

    switch (choice) {

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

            if (found) {
                printf("Found: Name: %s, ID: %d, Grade: %.2f\n",found->name, found->id, found->grade);
            } 
            else {
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

    } while (choice!=6);

    return 0;

}
