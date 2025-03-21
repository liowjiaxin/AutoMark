#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a Student
typedef struct Student {
    char name[100];         //student name with a maximum size
    int id;                 //student 's unique ID
    float grade;            //student grade
    struct Student* next;   //pointer to the next student in the list
    } Student;

Student* head = NULL; //global head pointer for the linked list

// Function to create a new student node
Student* createStudent(const char* name, int id, float grade) {
// allocate memory for a new student:
    Student *newStudent = (Student*)malloc(sizeof(Student));
    
    //check for memory allocation failure
    if (newStudent ==NULL){
        printf("Memory allocation failed \n"); //error message is failed
        return NULL;
    }
    
    //initialise the new student's data
    strcpy(newStudent->name,name);  //copy the name
    newStudent->id=id;              //set id
    newStudent->grade =grade;       //set grade
    newStudent->next =NULL;         //set the next pointer to NULL
    return newStudent;              //return the new student node
}

// Function to insert a new student record at beginning of list
void insertStudent(const char* name, int id, float grade) {
// create a new student node
    Student* newStudent= createStudent(name,id,grade);

    //check if creation failed
    if(newStudent ==NULL){
        return;
    }

    //insert the new student at the head of list
    newStudent->next=head;
    head=newStudent;


}

// Function to display all student records
void displayStudents() {
 // check if list is empty
    if(head ==NULL){
        printf("No student records found.\n"); //error message if list is empty
        return;
    }

    //traverse the list and display each students details
    Student* temp=head;
    while(temp !=NULL){
        printf("Name: %s, ID:%d, Grade: %.2f\n",temp->name, temp->id, temp->grade); //print all details
        temp =temp->next; //move to next student
    }
}

// Function to search for a student by ID
Student* searchStudentByID(int id) {
 // traverse list to find student using the given ID
    Student* temp=head;
    while(temp !=NULL){
        if (temp->id ==id){ //check if id matches
            return temp; //return student if found
        }
        temp= temp->next; //not found then move to next student
    }
    return NULL; //return NULL if no student with the given ID is found
}

// Function to delete the entire list
void deleteList() {
    Student* current = head; //start at the head of list
    Student* next;

    //free memory for each node in list
    while (current != NULL) {
    next = current->next;   //save the next node
    free(current);          //free the current node
    current = next;         //move to the next node
    }
    head = NULL; //set head pointer to NULL
}

void freeMemory() { //function to free all allocated memory
 deleteList();
}

// Sort function to sort the student records by grade based on an algorithm of your choice
void sortStudents() {
// check if list is empty
    if(head ==NULL || head->next ==NULL){
        return;//no need sort if list is empty or only have one element
    }

    //bubble sort implementation
    Student* temp;
    Student* i;
    Student* j;
    float tempGrade;    //temporary variable for swapping grades
    char tempName[100];//temp varaible for swapping names
    int tempID;         //temp variable for swapping IDs

    //outer loop to iteerate through the list
    for(i=head; i !=NULL; i=i->next){
        //inner loop for comparisons
        for(j=i->next; j!=NULL;j=j->next){
            //compare grades and swap if out of order
            if (i->grade > j->grade){
                //swap student records
                tempGrade= i->grade;
                i->grade=j->grade;
                j->grade=tempGrade;

                //swap ids
                tempID= i->id;
                i->id=j->id;
                j->id=tempID; 

                //swap names
                strcpy(tempName, i->name);
                strcpy(i->name,j->name);
                strcpy(j->name,tempName);               
            }
        }
    }
    printf("Records sorted by grade using Bubble Sort.");
}

// Main function to drive the program
int main() {
    int choice, id; //variable for choice and ID
    char name[100]; //buffer for student's name
    float grade;//variable for student's grade

    do { //main loop for menu
        printf("\n1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records (choose sorting method)\n");
        printf("4. Search Record by ID\n");
        printf("5. Delete List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");//prompt user for input of choice
        scanf("%d", &choice); //read user's choice
        getchar(); // To consume the newline character
        switch (choice) {

            //choice1- insert new student record
            case 1:
                printf("Enter Name: ");
                fgets(name, sizeof(name), stdin); //read name with spaces
                strtok(name, "\n"); //remove trailing newline
                printf("Enter ID: "); 
                scanf("%d", &id);//read the ID
                printf("Enter Grade: ");
                scanf("%f", &grade); //read Grade
                insertStudent(name, id, grade); //call out function insertStudent 
                break;

            //choice 2- display student records list
            case 2:
                displayStudents(); //call function to display all student records
                break;

            //choice3- sort students by grade
            case 3:
                sortStudents(); //call function sortStudents
                break;

            //choice 4- Search student by using ID
            case 4:
                printf("Enter ID to search: "); //prompt user for ID
                scanf("%d", &id); //read ID
                Student* found = searchStudentByID(id);  //call function searchStudentByID
                if (found) {
                printf("Found: Name: %s, ID: %d, Grade: %.2f\n",
                found->name, found->id, found->grade); //print student's details when match found
                } else {
                printf("Student not found.\n"); //error message when no student found 
                }
                break;

            //choice5- delete all student records
            case 5:
                deleteList(); //call function deleteList
                printf("List deleted.\n");//display message that list has been deleted
                break;

            //choice 6- exit program
            case 6:
                freeMemory();
                printf("Exiting...\n");
                break;

            //handle invalid choice (not 1-6)
            default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6); //repeat until user chooses to exit.
    
    return 0;
} 