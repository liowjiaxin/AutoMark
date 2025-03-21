#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct for Student
typedef struct Student {
    char name[100];
    int id;
    float grade;
    struct Student* next;
} Student;

Student* head = NULL; // start of the linked list

// function to create a new student node
Student* createStudent(const char* name, int id, float grade) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if (!newStudent) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(newStudent->name, name);
    newStudent->id = id;
    newStudent->grade = grade;
    newStudent->next = NULL;
    return newStudent;
}

//function to insert a new student record
void insertStudent(const char* name, int id, float grade) {
    Student* newStudent = createStudent(name, id, grade);
    newStudent->next = head;
    head = newStudent;
    printf("Student record inserted successfully.\n");
}

// function to get a validated integer
int getValidatedInteger(const char* prompt) {
    int value;
    char buffer[50];
    while (1) {
        printf("%s", prompt);
        fgets(buffer, sizeof(buffer), stdin);
        if (sscanf(buffer, "%d", &value) == 1) {
            return value;
        } else {
            printf("Invalid input. Please enter a valid integer.\n");
        }
    }
}

// function to get a validated float
float getValidatedFloat(const char* prompt) {
    float value;
    char buffer[50];
    while (1) {
        printf("%s", prompt);
        fgets(buffer, sizeof(buffer), stdin);
        if (sscanf(buffer, "%f", &value) == 1) {
            return value;
        } else {
            printf("Invalid input. Please enter a valid number.\n");
        }
    }
}

// function to display all student records
void displayStudents() {
    if (!head) {
        printf("No student records found.\n");
        return;
    }

    printf("\nStudent Records:\n");
    Student* current = head;
    while (current) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", current->name, current->id, current->grade);
        current = current->next;
    }
}

// function to search for a student by ID
Student* searchStudentByID(int id) {
    Student* current = head;
    while (current) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// function to delete the entire list
void deleteList() {
    Student* current = head;
    while (current) {
        Student* temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;
    printf("All student records deleted successfully.\n");
}


//function that uses bubble sort the student records by grade in ascending order
//I used bubble sort because it's easy to implement and it's efficiency will not become a problem because this program uses a small sample size
void sortStudents() {
    if (!head || !head->next) {
        printf("Not enough records to sort.\n");
        return;
    }

    for (Student* i = head; i != NULL; i = i->next) {
        for (Student* j = i->next; j != NULL; j = j->next) {
            if (i->grade > j->grade) {
                // Swap grades
                float tempGrade = i->grade;
                i->grade = j->grade;
                j->grade = tempGrade;

                // Swap IDs
                int tempID = i->id;
                i->id = j->id;
                j->id = tempID;

                // Swap names
                char tempName[100];
                strcpy(tempName, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, tempName);
            }
        }
    }
    printf("Student records sorted by grade in ascending order.\n");
}

int main() {

    //initialise variables
    int choice;
    char name[100];
    int id;
    float grade;

    //do while loop
    do {

        //print menu
        printf("\nMenu:\n");
        printf("1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records by Grade\n");
        printf("4. Search Record by ID\n");
        printf("5. Delete List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        choice = getValidatedInteger("");

        //switch case
        switch (choice) {
            //insert student
            case 1:
                printf("Enter Name: ");
                fgets(name, sizeof(name), stdin);
                strtok(name, "\n"); // Remove newline
                id = getValidatedInteger("Enter ID: ");
                grade = getValidatedFloat("Enter Grade: ");
                insertStudent(name, id, grade);
                break;
            //display student
            case 2:
                displayStudents();
                break;
            //sort students 
            case 3:
                sortStudents();
                break;
            // search using id
            case 4:
                id = getValidatedInteger("Enter ID to search: ");
                Student* found = searchStudentByID(id);
                if (found) {
                    printf("Found: Name: %s, ID: %d, Grade: %.2f\n", found->name, found->id, found->grade);
                } else {
                    printf("Student not found.\n");
                }
                break;
            // delete whole list
            case 5:
                deleteList();
                break;
            // exit
            case 6:
                printf("Exiting program.\n");
                break;
            // if user give invalid choice
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

