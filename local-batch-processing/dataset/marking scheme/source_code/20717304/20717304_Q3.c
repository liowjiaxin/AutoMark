#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stud {
    char name[100];
    int id;
    float grade;
    struct stud* next;
} stud;

stud* head = NULL;

stud* createStudent(const char* name, int id, float grade) { // add student to struct
    stud* new_stud = (stud*)malloc(sizeof(stud));
    strcpy(new_stud->name, name);
    new_stud->id = id;
    new_stud->grade = grade;
    new_stud->next = NULL;
    return new_stud;
}

void insertStudent(const char* name, int id, float grade) { // insert a new student to the list
    stud* new_stud = createStudent(name, id, grade);

    if (head == NULL) {
        head = new_stud;
    } else {
        stud* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_stud;
    }
    printf("Student record added successfully.\n");
}

void displayStudents() { // display all of the students
    if (head == NULL) {
        printf("No student records found to display\n");
        return;
    }

    stud* disp_node = head;
    while (disp_node) {
        printf("Name : %s\t ID : %d\t Grade : %.2f\n", disp_node->name, disp_node->id, disp_node->grade);
        disp_node = disp_node->next;
    }
}

void sortStudents() { // sorts students  using their ID with bubble sort 
    if (head == NULL || head->next == NULL) {
        printf("No records found to sort\n");  // i used bubble sort because it is simple, and efficient and it is easy to execute
        return;
    }

    stud* i;
    stud* j;
    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->grade > j->grade) {
                char temp_name[100];
                int temp_id = i->id;
                float temp_grade = i->grade;

                strcpy(temp_name, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, temp_name);
                i->id = j->id;
                j->id = temp_id;
                i->grade = j->grade;
                j->grade = temp_grade;
            }
        }
    }
}

stud* searchStudentByID(int id) {  // function to search student records by ID
    stud* search = head;
    while (search) {
        if (search->id == id) {
            printf("Name : %s\t ID : %d\t Grade : %.2f\n", search->name, search->id, search->grade);
            return search;
        }
        search = search->next;
    }
    printf("Student with ID %d not found.\n", id);
    return NULL;
}

void deleteList() { // function to clear the list
    stud* current_node = head;
    stud* next;

    while (current_node) {
        next = current_node->next;
        free(current_node);
        current_node = next;
    }
    head = NULL;
    printf("All student records deleted.\n");
}

void freeMemory() { // extra function to clear buffer or list 
    deleteList();
    head = NULL;
    printf("Memory cleared\n");
}

int main() {
    int choice;
    char name[100];
    int id;
    float grade;

    do {
        printf("\n1. Insert Student Record \n2. Display Student Records \n3. Sort Records \n4. Search Record by ID\n5. Delete List\n6. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter name : ");
            scanf(" %[^\n]", name);

            printf("Enter ID : ");
            scanf("%d", &id);

            printf("Enter Grade : ");
            scanf("%f", &grade);

            insertStudent(name, id, grade);
            break;

        case 2:
            displayStudents();
            break;

        case 3:
            sortStudents();
            printf("Records sorted using Bubble Sort\n");
            break;

        case 4:
            printf("Enter search ID : ");
            scanf("%d", &id);
            searchStudentByID(id);
            break;

        case 5:
            deleteList();
            break;

        case 6:
            freeMemory();
            break;

        default:
            printf("Invalid choice\n");
        }
    } while (choice != 6);
}
