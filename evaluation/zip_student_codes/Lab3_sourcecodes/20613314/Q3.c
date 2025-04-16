#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>



typedef struct Student{
    char name[100];
    int id;
    float grade;
    struct Student* next; //pointer to the next student (The list is sorted by name)
}Student;

Student* head = NULL; // list entry


void insertStudent(const char* name, int id, float grade); // Inserts a new student record into the linked list. 
void displayStudents(); // Displays all current student records in the linked list.
Student* searchStudentByID(int id); // Searches for a student record by student ID and returns a pointer to the corresponding student node.
void deleteList(); // Deletes the entire linked list and frees the allocated memory.
void freeMemory(); // A utility function to ensure that all memory is freed when the program exits.
Student* createStudent(const char* name, int id, float grade); // Creates a new student node and returns a pointer to it.
void sortStudents(); // Sort the student records by grade according to a sorting algorithm of your choice. 


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
                printf("Student has been added to the list.\n");
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



// Function to create a new student node
Student* createStudent(const char* name, int id, float grade) {
    Student *stud = (Student*)malloc(sizeof(Student));
    strcpy(stud->name, name);
    stud->id = id;
    stud->grade = grade;
    stud->next = NULL;
    return stud;
}


// Function to insert a new student record
void insertStudent(const char* name, int id, float grade) {
    //allocate memory
    Student* stud = createStudent(name, id, grade);

    // if list is empty
    if (head == NULL) {
        head = stud;
        return;
    }

    // if list is not empty
    Student* next = head;
    head = stud;
    stud->next = next;
}




// Function to display all student records
void displayStudents() {
    if (head == NULL) printf("List is empty.\n");

    for (Student* curr = head; curr != NULL; curr = curr->next){
        printf("Name: %s, ID: %d, Grade: %.2f\n", curr->name, curr->id, curr->grade);
    }
}



// Function to search for a student by ID
Student* searchStudentByID(int id) {
    if (head == NULL) return NULL; // if list is empty

    for (Student* curr = head; curr != NULL; curr = curr->next){
        if (curr->id == id) return curr;
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


// compare function for quick sort
int compare(const void* aP, const void* bP){
    Student* a = *(Student**)aP; // cast double-pointer to single-pointer
    Student* b = *(Student**)bP; // cast double-pointer to single-pointer
    float grade1 = a->grade;
    float grade2 = b->grade;
    float dif = grade1 - grade2;
    if (dif > 0) return 1;
    if (dif == 0) return 0;
    if (dif < 0) return -1;
}

// Sort function to sort the student records by grade based on an algorithm of your choice
void sortStudents() {
    //quick sort using an array of pointers to nodes


    // find number of elements in the list
    int n = 0; // number of students in the list
    for (Student* curr = head; curr != NULL; curr = curr->next, n++);


    // if the list is too small and no need to sort
    if (n < 2){
        printf("List is sorted.\n");
        return;
    }

    // allocate array of pointers to nodes
    Student** array = (Student**)malloc(n * sizeof(Student*));

    // fill the array
    int i = 0;
    for (Student* curr = head; curr != NULL; curr = curr->next){
        array[i] = curr;
        i++;
    }

    // sort it
    qsort(array, n, sizeof(Student*), compare); // cast compare() to prevent warning

    //change node links
    head = array[0];
    for (int i = 0; i < n - 1; i++){
        array[i]->next = array[i + 1];
    }
    array[n - 1]->next = NULL;


    printf("List is sorted.\n");
}