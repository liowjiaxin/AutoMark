//include
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
Student* createStudent(const char* name, int id, float grade) {
    // Write your code (1 mark)
    Student* newStudent = (Student*)malloc(sizeof(Student));    //create a new student node
    if (!newStudent){
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(newStudent->name,name);                              //insert information into new student node
    newStudent->id=id;
    newStudent->grade=grade;
    newStudent->next=NULL;                                      //mark next node as NULL as end of list
    return newStudent;
}

// Function to insert a new student record
void insertStudent(const char* name, int id, float grade) {
    // Write your code (1 mark)
    Student* newStudent=createStudent(name,id,grade);           //create a new student node with information filled
    if (head == NULL){                                          //if no student is recorded, then set new student node as head node
        head=newStudent;
    }else{                                                      //if got student record, check node in linked list until no record
        Student* current = head;
        while (current->next !=NULL){
            current=current->next;
        }
        current->next=newStudent;                               //add new student node into link list
    }
}

// Function to display all student records
void displayStudents() {
    // Write your code (1 mark)
    if (head==NULL){                                            //if no student is recorded, return main menu
        printf("No student is recorded.\n");
        return;
    }
    Student* current=head;                                      //display student record in all node from head node to end
    while (current !=NULL){
        printf("Name: %s, ID: %d, Grade: %.2f\n", current->name, current->id, current->grade);
        current = current->next;
    }
}

// Function to search for a student by ID
Student* searchStudentByID(int id) {
    // Write your code (1 mark)
    Student* current =head;                                     //compare Id with id in all node from head node to end until found
    while (current != NULL){
        if (current->id==id){                                   //if Id found, return current node with information
            return current;
        }
        current=current->next;
    }
    return NULL;                                                //if id not found, return NULL
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
    /**EXPLANATION
    Selection sort is used as this linked list only look forward but not look backward.
    Once go forward the linked list, cannot go backward to check the grade.
    So just makesure smallest grade is placed for the current node when compare to next grade until end
    All grades before current node never greater than current node grade.**/
void sortStudents() {
    // Write your code (1 mark)
    if (head ==NULL){                                           //if no student is recorded, return main menu
        printf("No record to be sorted.\n");
        return;
    }
    if (head->next == NULL){                                    //if only one student is recorded, no need to sort, return main menu
        printf("Only one record no need to be sorted.\n");
        return;
    }
    for (Student* i=head;i!=NULL;i=i->next){                    //Process all node one by one
        for (Student*j=i->next;j!=NULL;j=j->next){              //Check current node with all node that next to it in the lists
            if (j->grade < i->grade){                           //If any node grade next to current node less than current node, swap record
                char tempName[100];
                strcpy(tempName,i->name);
                strcpy(i->name,j->name);
                strcpy(j->name, tempName);

                int tempId=i->id;
                i->id=j->id;
                j->id=tempId;

                float tempGrade=i->grade;
                i->grade=j->grade;
                j->grade=tempGrade;
            }
        }   //Make sure always the smallest grade among current node to all node next to it in the list is stored at current node (select smallest)
    }       //All node has been swap until each node has the smallest grade when compare to every nodes next to it in the list
    printf("Records sorted by grade using Selection Sort.\n");  
}

// Main function to drive the program
int main() {

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
                } else {
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