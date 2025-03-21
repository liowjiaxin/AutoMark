/**
 * @file Q3.c
 * @brief This C program implements a linked list to store a collection of student records.
 *
 * Each record should include the student’s name, ID, and grade. The program should allow
 * the user to perform the following operations:
 *  a) Insert Student Record: Allow the user to insert new student records into the linked
 *     list.
 *  b) Display Student Records: Display all current student records in the list.
 *  c) Sort Records: Implement a sorting algorithm to sort the student records by grade in
 *     ascending order. You may choose to implement a sorting algorithm (e.g., Merge Sort,
 *     Quick Sort, Bubble Sort, Selection Sort, Insertion Sort etc.). Put in the comment on
 *     your reason for the choice of the sorting algorithm.
 *  d) Search Record by ID: Allow the user to search for a student record by student ID.
 *  e) Delete List: Provide an option to delete the entire linked list and free allocated
 *     memory.
 *
 * @author Yichen Si
 * @date 2024-12-11
 * @note code is formated by vscode
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN (100)

typedef struct record
{
    char name[MAX_NAME_LEN];
    int id;
    float grade;
    struct record *next;
} record;

record *head = NULL;

static record *create_student(const char *name, int id, float grade)
{
    record *newrecord = (record *)malloc(sizeof(record));
    if (newrecord == NULL)
    {
        printf("Error: memory allocation failed");
        return NULL;
    }

    // name length is valided at input, so it safe to strpcy
    strcpy(newrecord->name, name);
    newrecord->id = id;
    newrecord->grade = grade;
    newrecord->next = NULL;

    return newrecord;
}

static void insert_student_record(const char *name, int id, float grade)
{
    record *newrecord = create_student(name, id, grade);

    if (newrecord == NULL)
    {
        printf("Error: memory allocation failed.\n");
        return;
    }

    // head always point to the new added record.
    newrecord->next = head;
    head = newrecord;
}

static void display_student_records(void)
{
    record *current_record = head;

    if (head == NULL)
    {
        printf("Error: no records to display.\n");
        return;
    }

    // travel list till end to display each record
    while (current_record != NULL)
    {
        printf("Name: %s, ID: %d, Grade: %.2f\n", current_record->name,
               current_record->id, current_record->grade);
        current_record = current_record->next;
    }
}

static void sort_records(void)
{
    record *i;
    record *j;
    record temp;

    if (head == NULL)
    {
        printf("Error: no records to sort.\n");
        return;
    }
    // Bubble sort
    for (i = head; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->grade > j->grade)
            {
                temp.grade = i->grade;
                i->grade = j->grade;
                j->grade = temp.grade;

                temp.id = i->id;
                i->id = j->id;
                j->id = temp.id;

                strcpy(temp.name, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, temp.name);
            }
        }
    }
    printf("Records sorted by grade using Bubble Sort.\n");
}

static record *search_student(int id)
{
    record *current_record = head;

    while (current_record != NULL)
    {
        if (current_record->id == id)
        {
            return current_record;
        }
        current_record = current_record->next;
    }
    return NULL;
}

static void deleteList(void)
{
    record *current = head;
    record *next;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
}

static void freeMemory(void) { deleteList(); }

int main(void)
{
    int choice;
    char name[MAX_NAME_LEN];
    int id;
    float grade;

    do
    {
        printf("\n1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records\n");
        printf("4. Search Record by ID\n");
        printf("5. Delete List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            printf("Enter Name: ");
            fgets(name, MAX_NAME_LEN, stdin);
            long int len = strlen(name);
            if (len == MAX_NAME_LEN - 1)
            {
                while (getchar() != '\n')
                    ;
            }
            if (name[0] == '\n')
            {
                printf("Error: invalid Name.\n");
                break;
            }
            strtok(name, "\n");

            printf("Enter ID: ");

            if (scanf("%d", &id) != 1)
            {
                printf("Error: invalid ID.\n");
                while (getchar() != '\n')
                    ;
                break;
            }

            printf("Enter Grade: ");
            if (scanf("%f", &grade) != 1)
            {
                printf("Error: invalid Grade.\n");
                while (getchar() != '\n')
                    ;
                break;
            }

            insert_student_record(name, id, grade);
            break;
        case 2:
            display_student_records();
            break;
        case 3:
            sort_records();
            break;
        case 4:
            printf("Enter ID to search: ");
            scanf("%d", &id);
            while (getchar() != '\n')
                ;
            record *found = search_student(id);
            if (found)
            {
                printf("Found: Name: %s, ID: %d, Grade: %.2f\n",
                       found->name, found->id, found->grade);
            }
            else
            {
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
