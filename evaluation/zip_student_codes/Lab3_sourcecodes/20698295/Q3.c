#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Student
typedef struct Student {
    char name[100];
    int id;
    float grade;
    struct Student *next;
} Student;

//global head pointer
Student* head = NULL;

// Function to create a new student node
Student* createStudent(const char *name, int id, float grade) {

    //allocate memory for new student
    Student *newstudent= (Student *)malloc(sizeof(Student));
    if (!newstudent) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    strncpy(newstudent->name,name,sizeof(newstudent->name)-1);
    newstudent->id=id;
    newstudent->grade=grade;
    newstudent->next=NULL;  //set next pointer to NULL

    return newstudent;
}


// Function to insert a new student record
void insertStudent(const char* name, int id, float grade) {
    Student *newstudent= createStudent(name,id,grade);
    if(!newstudent){      //exit function if creation failed
        return;
    }
    newstudent->next=head;
    head=newstudent;
    printf("Student record inserted successfully.\n");

}


// Function to display all student records
void displayStudents() {
    if (head == NULL) {
        printf("No student records to display.\n");
        return;
    }
    Student *current = head;  //start at head of list

    printf("\nStudent Records:\n");
    while (current != NULL) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", current->name, current->id, current->grade);
        current = current->next;
    }
}


// Function to search for a student by ID
Student* searchStudentByID(int id) {
    if (head == NULL) {
        printf("No student records present.\n");
        return NULL;
    }    

    Student *current =head;
    while(current!=NULL){
        if(current->id==id){
            return current;
        }
        current=current->next;
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

void freeMemory() {
    deleteList();
}

// Sort function to sort the student records by grade using bubblesort algorithm
void sortStudents() {
    if (head == NULL) {
        printf("No student records present.\n");
        return;
    } 

    Student *current=head;
    float gradetemp;
    int idtemp;
    char nametemp[100];
    int swapped,i;
    Student *ptr1;
    Student *lptr=NULL;

    do{
        swapped=0;
        ptr1=head;

        while (ptr1->next!=lptr){
            if(ptr1->grade > ptr1->next->grade){  //if current grade is larger than grade pointed to by next pointer

                //put current grade,id,name in respective temp arrays
                gradetemp=ptr1->grade;
                idtemp=ptr1->id;
                strncpy(nametemp,ptr1->name,sizeof(nametemp));

                //swap grade, ID,name
                ptr1->grade= ptr1->next->grade;
                ptr1->id=ptr1->next->id;
                strncpy(ptr1->name,ptr1->next->name,sizeof(ptr1->name));
                
                ptr1->next->grade=gradetemp;
                ptr1->next->id=idtemp;
                strncpy(ptr1->next->name,nametemp,sizeof(ptr1->next->name));

                swapped=1;

            }
            ptr1=ptr1->next;
        }

        lptr=ptr1;  //reduce unsorted pointer

    }while(swapped);
    printf("Records sorted by using Bubble Sort.\n");

}

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

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("Invalid input. Please enter a number between 1 and 5.\n");
            choice = 0; // Ensure choice isn't treated as valid
        } else {
            switch (choice) {
            
                case 1:
                    printf("Enter Name: ");
                    getchar();
                    fgets(name, sizeof(name), stdin);
                    name[strcspn(name, "\n")] = '\0';
                    
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
                //take user input for ID to search
                    printf("Enter ID to search: ");
                    scanf("%d", &id);

                    Student* found = searchStudentByID(id);
                    if (found!=NULL) {
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
                //if choice if invalid
                    printf("Invalid choice! Please try again.\n");
                }
            }
    } while (choice != 6); //loop menu until user exits

    return 0;
}