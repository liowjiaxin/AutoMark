#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义学生记录的结构体
typedef struct Student 
{
    char name[100];
    int id;
    float grade;
    struct Student* next;
} Student;

Student* head = NULL; // 链表的头指针

// 函数声明
Student* createStudent(const char* name, int id, float grade); // 创建学生节点
void insertStudent(const char* name, int id, float grade); // 插入学生记录
void displayStudents(); // 显示所有学生记录
void sortStudents(); // 按成绩排序学生记录
Student* searchStudentByID(int id); // 根据ID查找学生记录
void deleteList(); // 删除整个链表

int main3() //使用时删除main后的字符防程序无法运行
{
    int choice, id;
    char name[100];
    float grade;

    do 
    {
        printf("\nStudent Record Menu:\n");
        printf("1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records by Grade\n");
        printf("4. Search Record by ID\n");
        printf("5. Delete All Records\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
        case 1:
            printf("Enter Name: ");
            getchar(); // 清除缓冲区
            fgets(name, sizeof(name), stdin);
            strtok(name, "\n"); // 移除换行符
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
            printf("Records sorted by grade successfully!\n");
            break;

        case 4:
            printf("Enter ID to search: ");
            scanf("%d", &id);
            Student* found = searchStudentByID(id);
            if (found) 
            {
                printf("Found: Name: %s, ID: %d, Grade: %.2f\n", found->name, found->id, found->grade);
            }
            else 
            {
                printf("Student not found.\n");
            }
            break;

        case 5:
            deleteList();
            printf("All records deleted successfully!\n");
            break;

        case 6:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

// 创建学生节点
Student* createStudent(const char* name, int id, float grade)
{
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if (!newStudent)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(newStudent->name, name);
    newStudent->id = id;
    newStudent->grade = grade;
    newStudent->next = NULL;
    return newStudent;
}

// 插入学生记录
void insertStudent(const char* name, int id, float grade) 
{
    Student* newStudent = createStudent(name, id, grade);
    newStudent->next = head;
    head = newStudent;
    printf("Student record inserted successfully!\n");
}

// 显示所有学生记录
void displayStudents()
{
    if (!head) 
    {
        printf("No records to display.\n");
        return;
    }

    printf("\n%-20s %-10s %-10s\n", "Name", "ID", "Grade");
    printf("----------------------------------------\n");
    Student* current = head;
    while (current) 
    {
        printf("%-20s %-10d %-10.2f\n", current->name, current->id, current->grade);
        current = current->next;
    }
}

// 按成绩排序学生记录
void sortStudents() 
{
    if (!head || !head->next)
    {
        return; // 链表为空或只有一个节点时无需排序
    }

    Student* i;
    Student* j;
    for (i = head; i->next; i = i->next)
    {
        for (j = i->next; j; j = j->next)
        {
            if (i->grade > j->grade) 
            {
                // 交换节点数据
                char tempName[100];
                int tempID;
                float tempGrade;

                strcpy(tempName, i->name);
                tempID = i->id;
                tempGrade = i->grade;

                strcpy(i->name, j->name);
                i->id = j->id;
                i->grade = j->grade;

                strcpy(j->name, tempName);
                j->id = tempID;
                j->grade = tempGrade;
            }
        }
    }
}

// 根据ID查找学生记录
Student* searchStudentByID(int id) 
{
    Student* current = head;
    while (current) 
    {
        if (current->id == id) 
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// 删除整个链表
void deleteList()
{
    Student* current = head;
    while (current) 
    {
        Student* temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;
}
