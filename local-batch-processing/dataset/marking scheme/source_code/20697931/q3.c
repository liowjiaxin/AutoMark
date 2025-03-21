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
    struct Student* student = (struct Student*)malloc(sizeof(struct Student));
    if (student == NULL) {
        printf("Memory allocation error");
        return NULL;
    }
    strcpy(student->name,name);
    student->id= id;
    student->grade=grade;
    student->next=NULL;
    return student;
    
}

// Function to insert a new student record
void insertStudent(const char* name, int id, float grade) {
    struct Student* insert_student=createStudent(name,id,grade);
    if (insert_student == NULL){
        printf("Unsuccessful");
        return;

    }
    if (head == NULL){//if head is null then the new student is the head
        head= insert_student;
    }
    else{              //traverse until end of the linked list to connect the new student
        struct Student* current= head;
        struct Student* previous= NULL;
        while (current!= NULL){
            previous=current;
            current= current->next;
        }
        
        (*previous).next=insert_student;
    }
}

// Function to display all student records
void displayStudents() {
    if (head == NULL){//if no students in linked list
        printf("No students to display");
    }
    else{
        struct Student* current=head;
        while( current != NULL){
            printf("Name:%s, ID:%d , Grade:%.2f\n",current->name,current->id,current->grade);
            current=current->next;
        }

    }
}

// Function to search for a student by ID
Student* searchStudentByID(int id) {
     if (head == NULL){//if no students then nothing to display 
        printf("No students to display");
        return NULL;
    }
    else{
        struct Student* current=head;
        int found=0;
        while( current != NULL && found==0){
            if (current->id == id ){
                found=1;
                return current;
            } 
            current=current->next;
        }
        printf("Not found");
        return NULL;

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
void sortStudents() {
     if (head == NULL){
        printf("No students to sort\n");
     }
    else{
         
    int swapped;  //flagged to check if swap occured
    Student *current;

    char temp_name[50];
    int temp_id = 0;
    float temp_grade = 0.0;

  do {
    swapped = 0;
    current = head;

    while (current->next != NULL) {
        if (current->grade > current->next->grade) {
            // Swap names using strcpy
             
            strcpy(temp_name, current->name);
            strcpy(current->name, (current->next)->name);
            strcpy((current->next)->name, temp_name);

            // Swap IDs
            temp_id = current->id;
            current->id = (current->next)->id;
            (current->next)->id = temp_id;

            // Swap grades
            temp_grade = current->grade;
            current->grade = (current->next)->grade;
            (current->next)->grade = temp_grade;

            swapped = 1;
        }
        current = current->next;
    }
    
} while (swapped);


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

                if (found != NULL ) {
                    printf("Found: Name: %s, ID: %d, Grade: %.2f\n", found->name, found->id, found->grade);
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
