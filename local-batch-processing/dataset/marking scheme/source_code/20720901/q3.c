#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Structure for Student
typedef struct Student
{
  char name[100];
  int id;
  float grade;
  struct Student *next;
} Student;
Student *head = NULL;

// Function to create a new student node
Student *createStudent(const char *name, int id, float grade)
{
  // Write your code (1 mark)
  Student *newStu = (Student *)malloc(sizeof(Student));
  if (!newStu)
  {
    printf("Fail to allocate memory...\n");
    return NULL;
  }

  strcpy(newStu->name, name);
  newStu->id = id;
  newStu->grade = grade;
  newStu->next = NULL;

  printf("\n");

  return newStu;
}
// Function to insert a new student record
void insertStudent(const char *name, int id, float grade)
{
  // Write your code (1 mark)
  Student *newStu = createStudent(name, id, grade);
  // if no Student return
  if (!newStu)
  {
    printf("Error occurred when insert Student");
    return;
  }

  // no student in the list
  if (head == NULL)
  {
    head = newStu;
  }
  else
  {
    Student *firstStu = head;
    // loop until last node
    while (firstStu->next != NULL)
    {
      firstStu = firstStu->next;
    }
    firstStu->next = newStu;
  }
}
// Function to display all student records
void displayStudents()
{
  // Write your code (1 mark)
  Student *currentStu = head;
  if (!currentStu)
  {
    printf("No student found\n");
    return;
  }

  while (currentStu)
  {
    printf("Name: %s, ID: %li, Grade: %.2f\n", currentStu->name, currentStu->id, currentStu->grade);
    currentStu = currentStu->next;
  }
}

// Function to search for a student by ID
Student *searchStudentByID(int id)
{
  // Write your code (1 mark)
  Student *currentStu = head;
  while (currentStu != NULL)
  {
    if (currentStu->id == id)
    {
      return currentStu;
    }
    currentStu = currentStu->next;
  }

  return NULL;
}

// Function to delete the entire list
void deleteList()
{
  Student *current = head;
  Student *next;
  while (current != NULL)
  {
    next = current->next;
    free(current);
    current = next;
  }
  head = NULL;
}

void freeMemory()
{
  deleteList();
}

// Sort function to sort the student records by grade based on an algorithm of your choice
void sortStudents()
{
  // Write your code (1 mark)
  // store number of student in linked list
  int length = 0;
  Student *current = head;
  while (current != NULL)
  {
    length++;
    current = current->next;
  }

  int index = 0;
  int flag;

  while (index < length)
  {
    Student *nextNode = head;
    Student *prevNode = head;
    flag = 0;

    while (nextNode->next != NULL)
    {
      Student *ptr = nextNode->next;
      if (nextNode->grade > ptr->grade)
      {
        flag = 1;
        // swap
        if (nextNode == head)
        {
          nextNode->next = ptr->next;
          ptr->next = nextNode;
          prevNode = ptr;
          head = prevNode;
        }
        else
        {
          nextNode->next = ptr->next;
          ptr->next = nextNode;
          prevNode->next = ptr;
          prevNode = ptr;
        }
        continue;
      }
      prevNode = nextNode;
      nextNode = nextNode->next;
    }

    // If no swap occurred, break the loop
    if (!flag)
    {
      break;
    }

    ++index;
  }
  printf("Records sorted by grade using Bubble Sort.\n\n");
}

// Main function to drive the program
int main()
{
  int choice, id;
  char name[100];
  float grade;
  do
  {
    printf("\n1. Insert Student Record\n");
    printf("2. Display Student Records\n");
    printf("3. Sort Records (Bubble sort)\n");
    printf("4. Search Record by ID\n");
    printf("5. Delete List\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar(); // To consume the newline character
    switch (choice)
    {
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
      Student *found = searchStudentByID(id);
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