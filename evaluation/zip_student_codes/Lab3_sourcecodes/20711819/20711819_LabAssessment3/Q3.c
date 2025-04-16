#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// student structure
struct UwUstudent{
    char name[101];
    char id[101];
    float grade;
};

// struct uwu node for linked list
struct UwUNode{
    struct UwUstudent* student; // point to a student struct
    struct UwUNode *next; // point to next node
};

struct UwUNode *head = NULL; // head node

// create a new node uwu
struct UwUNode* createNode(char *name, char *id, float grade){
    struct UwUNode *newNode = (struct UwUNode*)malloc(sizeof(struct UwUNode)); // create a new node pointer
    struct UwUstudent *newStudent = (struct UwUstudent*)malloc(sizeof(struct UwUstudent)); // create a new student object
    
    int i = 0;
    // copy the char in name to newStudent's name
    for (; name[i] != '\0'; i++)
        newStudent->name[i] = name[i];
    newStudent->name[i] = '\0';

    int j = 0;
    // copy the char in id to newStudent's id
    for (; id[j] != '\0'; j++)
        newStudent->id[j] = id[j];
    newStudent->id[j] = '\0';

    newStudent->grade = grade;
    newNode->student = newStudent;
    return newNode;
}

// insert the node to linked list
void insertNode(char *name, char *id, float grade){
    struct UwUNode *newNode = (struct UwUNode*)malloc(sizeof(struct UwUNode));
    newNode = createNode(name, id, grade);
    newNode->next = head; // point to the current head
    head = newNode; // the new node becomes the new head
}

// function to display the student record in linked list
void displayLinkedList(){
    struct UwUNode *temp = head; // temp to traverse through the linked list
    while (temp != NULL){
        printf("Name: %s, ID: %s, Grade: %.2f\n", temp->student->name, temp->student->id, temp->student->grade);
        temp = temp->next;
    }
}

// function to sort the linked list
void sortLinkedList(){
    struct UwUNode *temp = head; // temp to traverse through the linked list
    int count = 0;
    while (temp != NULL){
        count++;
        temp = temp->next;
    }
    struct UwUstudent **hold = (struct UwUstudent**)malloc(sizeof(struct UwUstudent) * count);
    struct UwUstudent *hold2 = (struct UwUstudent*)malloc(sizeof(struct UwUstudent));
    temp = head;
    for (int i = 0; i < count; i++){
        hold[i] = temp->student;
        temp = temp->next;
    }

    for (int i = 0; i < count; i++){ // bubble sort cause I was slacking and do it last minute and didnt go on to do my research, teehee
        for (int j = 0; j < count-1; j++){
            if (hold[j]->grade > hold[j+1]->grade){
                hold2 = hold[j+1];
                hold[j+1] = hold[j];
                hold[j] = hold2;
            }
        }
    }

    temp = head;
    int i = 0;
    while (temp != NULL){
        temp->student = hold[i++];
        temp = temp->next;
    }
}

// search record by id
void searchStudent(){
    int printed = 0;
    char hold[101];
    printf("\nSearching student by ID...\n");
    printf("Please enter the student's ID: ");
    scanf("%s", hold);

    struct UwUNode *temp = head; // temp to traverse through the linked list
    while (temp != NULL){
        if (strcmp(hold, temp->student->id) == 1){
            printf("Found studnet!\n");
            printf("Name: %s, ID: %s, Grade: %.2f\n", temp->student->name, temp->student->id, temp->student->grade);
            printed++;
            break;
        }
        temp = temp->next;
    }
    if (printed == 0)
        printf("No record of %s found.\n", hold);
}

// delete the list
void deleteList(){
    struct UwUNode *temp = head; // temp to traverse through the linked list
    while (head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(){
    int choice, i, j;
    char name[101], id[101], hold;
    float grade;
    do{
        printf("\n1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records\n");
        printf("4. Search Record by ID\n");
        printf("5. Delete List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        i = 0;
        j = 0;
        switch (choice){
            case 1:
                printf("Enter Name: ");
                for (scanf(" %c", &hold); hold != '\n'; scanf("%c", &hold))
                    name[i++] = hold;
                name[i] = '\0';
                printf("Enter ID: ");
                for (scanf(" %c", &hold); hold != '\n'; scanf("%c", &hold))
                    id[j++] = hold;
                id[j] = '\0';
                printf("Enter Grade: ");
                scanf("%f", &grade);
                insertNode(name, id, grade);
                break;
            case 2:
                displayLinkedList();
                break;
            case 3:
                sortLinkedList();
                printf("Sorted list:\n");
                displayLinkedList();
                break;
            case 4:
                searchStudent();
                break;
            case 5:
                deleteList();
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice, please try again!");
                break;
        }
    }while(choice != 6);
}