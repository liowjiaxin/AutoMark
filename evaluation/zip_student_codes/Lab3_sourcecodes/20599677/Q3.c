#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Student {
    char name[100];
    int id;
    float grade;
    struct Student* next;
} Student;
Student* head = NULL;

// Function to create a new student node
Student* createStudent(const char* name, int id, float grade) {
    Student* create_student = (Student*)malloc(sizeof(Student)); //allocate memory for new student node
    if(create_student == NULL){
        printf("Error: Failed to create a new student node.\n");
        exit(1);
    }
    strcpy(create_student->name, name); //copy student's name into node
    create_student->id = id; //set student id
    create_student->grade = grade; //set student's grade
    create_student->next = NULL; //initialize next pointer to NULL
    return create_student; 
}

// Function to insert a new student record
void insertStudent(const char* name, int id, float grade) {
    Student* add_student = createStudent(name, id, grade);
    add_student->next = head; //
    head = add_student;
}

// Function to display all student records
void displayStudents() {
    Student* list_students = head;
    while(list_students != NULL){ 
        printf("Name: %s, ID: %d, Grade: %.2f\n", list_students->name, list_students->id, list_students->grade);
        list_students = list_students->next; //move to next node
    }

    //empty list
    if(head == NULL){
        printf("No student records found.\n");
        return;
    }

}

// Function to search for a student by ID
Student* searchStudentByID(int id) {
    Student* search_students = head;
    while(search_students != NULL){
        if(search_students->id == id){
            return search_students;
        }
        search_students = search_students->next; //move to next node
    }
    return NULL;

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

void freeMemory(){
    deleteList();
}

//Sort function to sort the student records by grade based on bubble sort
void sortStudents(){
    int swapped;
    Student *ptr, *sort_students = NULL;

    do{
        swapped = 0;
        ptr = head;

        while(ptr->next != sort_students){
            //compare grades
            if(ptr->grade > ptr->next->grade){
                //sort grade
                float sort_grade = ptr->grade;
                ptr->grade = ptr->next->grade;
                ptr->next->grade = sort_grade;

                //sort name
                char sort_name[100];
                strcpy(sort_name, ptr->name);
                strcpy(ptr->name, ptr->next->name);
                strcpy(ptr->next->name, sort_name);

                //sort ID
                int sort_id = ptr->id;
                ptr->id = ptr->next->id;
                ptr->next->id = sort_id;

                swapped = 1; //swap occurred
            }
            ptr = ptr->next; //move to next node
        }
        sort_students = ptr; //update list
    }while(swapped);
    printf("Records sorted by grade using Bubble Sort.\n");

}

int main(){
    int choice, id;
    char name[100];
    float grade;

    do{
        printf("\n1. Insert Student Record\n");
        printf("2. Display student Records\n");
        printf("3. Sort Records\n");
        printf("4. Search Record by ID\n");
        printf("5. Delete List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character

        switch(choice){
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
                if(found){
                    printf("Found: Name: %s, ID: %d, Grade: %.2f\n", found->name, found->id, found->grade);
                }else{
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
    
    }while(choice != 6);

    return 0;

}