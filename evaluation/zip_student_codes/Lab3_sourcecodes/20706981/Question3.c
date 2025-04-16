#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 学生结构体
typedef struct Student {
    char name[100];
    int id;
    float grade;
    struct Student *next;
} Student;

// 链表头指针
Student *head = NULL;

// 创建新学生节点
Student *createStudent(const char *name, int id, float grade) {
    Student *newStudent = (Student *)malloc(sizeof(Student));
    strcpy(newStudent->name, name);
    newStudent->id = id;
    newStudent->grade = grade;
    newStudent->next = NULL;
    return newStudent;
}

// 插入学生记录
void insertStudent(const char *name, int id, float grade) {
    Student *newStudent = createStudent(name, id, grade);
    if (head == NULL) {
        head = newStudent;
    } else {
        Student *current = head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = newStudent;
    }
}

// 显示学生记录
void displayStudents() {
    Student *current = head;
    if (current == NULL) {
        printf("No student records.\n");
    } else {
        while (current!= NULL) {
            printf("Name: %s, ID: %d, Grade: %.2f\n", current->name, current->id, current->grade);
            current = current->next;
        }
    }
}

// 按ID搜索学生记录
Student *searchStudentByID(int id) {
    Student *current = head;
    while (current!= NULL) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// 删除链表
void deleteList() {
    Student *current = head;
    Student *next;
    while (current!= NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
}

// 释放内存（调用deleteList）
void freeMemory() {
    deleteList();
}

// 使用冒泡排序对学生记录按成绩排序
void sortStudents() {
    int swapped;
    Student *ptr1;
    Student *lptr = NULL;

    if (head == NULL) return;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next!= lptr) {
            if (ptr1->grade > ptr1->next->grade) {
                // 交换节点
                Student *temp = ptr1->next;
                ptr1->next = temp->next;
                temp->next = ptr1;
                if (ptr1 == head) {
                    head = temp;
                } else {
                    Student *prev = head;
                    while (prev->next!= ptr1) {
                        prev = prev->next;
                    }
                    prev->next = temp;
                }
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

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
        getchar(); // 处理换行符

        switch (choice) {
            case 1:
                printf("Enter Name: ");
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
                printf("Enter ID to search: ");
                scanf("%d", &id);
                Student *found = searchStudentByID(id);
                if (found) {
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
    } while (choice!= 6);

    return 0;
}