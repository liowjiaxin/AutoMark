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
    Student* temp = (Student*)malloc(sizeof(Student));
    strcpy(temp->name, name);
    temp->id = id;
    temp->grade = grade;
    temp->next = NULL;
    return temp;
}
// Function to insert a new student record
void insertStudent(const char* name, int id, float grade) {
    Student* new = createStudent(name, id, grade);
    if(new != NULL) {
        Student* previous = NULL;
        Student* current = head;
        //loop to fint the correct location in list
        while(current != NULL && id > current->id) {
            previous = current;
            current = current->next;
        }
        
        if(previous ==NULL) { //insert new node at the head
            new->next = head;
            head = new;
        } else { //insert new node between previous and current
            previous->next = new;
            new->next = current;
        }
    }

}
// Function to display all student records
void displayStudents() {
    Student* current = head;
    printf("ID\tName\t\t\tGrade\n");
    while (current != NULL) {
        printf("%d\t%-s\t\t\t%.2f\n", current->id, current->name, current->grade);
        current = current->next;
    }
}
// Function to search for a student by ID
Student* searchStudentByID(int id) {
    Student* previous = NULL;
    Student* current = head;
    while(current != NULL && id != current->id) {
            previous = current;
            current = current->next;
        }
    return current;
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
void sortStudents() { //selection sort algorithm
    Student *current = head;
    while (current != NULL) {
        Student *smallerNode = current; //set the min to the current node
        Student *nextNode = current->next; 

        while (nextNode != NULL) {
            if (nextNode->grade < smallerNode->grade) {
                smallerNode = nextNode; //set the node to be smaller node when the grade of the next node is smaller 
            }
            nextNode = nextNode->next; //move to next node
        }
        //Swap the data of the current node with the minimum node
        if (smallerNode != current) {
            //Swap name
            char tempName[100];
            strcpy(tempName, current->name);
            strcpy(current->name, smallerNode->name);
            strcpy(smallerNode->name, tempName);
            //Swap ID
            int tempId = current->id;
            current->id = smallerNode->id;
            smallerNode->id = tempId;
            //Swap grade
            float tempGrade = current->grade;
            current->grade = smallerNode->grade;
            smallerNode->grade = tempGrade;
        }
        //Move to the next node in the list
        current = current->next;
    }
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
    printf("Found: Name: %s, ID: %d, Grade: %.2f\n",
    found->name, found->id, found->grade);
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
