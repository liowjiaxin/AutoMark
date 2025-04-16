#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_ITEMS 100

// 定义杂货项目的结构体
typedef struct 
{
    char name[100]; // 名称
    char category[50]; // 类别
    int quantity; // 数量
    float price; // 价格
    bool inStock; // 是否有库存
} GroceryItem;

// 杂货库存
GroceryItem inventory[MAX_ITEMS];
int itemCount = 0; // 当前库存中的物品数量

// 函数声明
void addGroceryItem(); // 添加杂货项目
void listGroceryItems(); // 列出所有杂货项目
void updateQuantity(); // 更新杂货项目数量
void removeGroceryItem(); // 移除杂货项目

int main2() //使用时删除main后的字符防程序无法运行
{
    int choice;
    do
    {
        // 打印菜单
        printf("\nGrocery Inventory Menu:\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
        case 1:
            addGroceryItem();
            break;
        case 2:
            listGroceryItems();
            break;
        case 3:
            updateQuantity();
            break;
        case 4:
            removeGroceryItem();
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// 添加杂货项目
void addGroceryItem()
{
    if (itemCount >= MAX_ITEMS) 
    {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    GroceryItem newItem;

    printf("Enter item name: ");
    getchar(); // 清除缓冲区
    fgets(newItem.name, sizeof(newItem.name), stdin);
    strtok(newItem.name, "\n"); // 移除换行符

    printf("Enter category: ");
    fgets(newItem.category, sizeof(newItem.category), stdin);
    strtok(newItem.category, "\n"); // 移除换行符

    printf("Enter quantity: ");
    scanf("%d", &newItem.quantity);

    printf("Enter price: ");
    scanf("%f", &newItem.price);

    newItem.inStock = newItem.quantity > 0; // 根据数量设置库存状态

    inventory[itemCount++] = newItem; // 添加到库存
    printf("Item added successfully!\n");
}

// 列出所有杂货项目
void listGroceryItems() 
{
    if (itemCount == 0) 
    {
        printf("Inventory is empty.\n");
        return;
    }

    printf("\n%-20s %-15s %-10s %-10s %-10s\n", "Name", "Category", "Quantity", "Price", "In Stock");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < itemCount; i++) 
    {
        printf("%-20s %-15s %-10d $%-9.2f %-10s\n",
            inventory[i].name,
            inventory[i].category,
            inventory[i].quantity,
            inventory[i].price,
            inventory[i].inStock ? "Yes" : "No");
    }
}

// 更新杂货项目数量
void updateQuantity() 
{
    char name[100];
    printf("Enter the name of the item to update: ");
    getchar(); // 清除缓冲区
    fgets(name, sizeof(name), stdin);
    strtok(name, "\n"); // 移除换行符

    for (int i = 0; i < itemCount; i++) 
    {
        if (strcmp(inventory[i].name, name) == 0)
        {
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            inventory[i].inStock = inventory[i].quantity > 0; // 更新库存状态
            printf("Quantity updated successfully!\n");
            return;
        }
    }

    printf("Item not found.\n");
}

// 移除杂货项目
void removeGroceryItem() 
{
    char name[100];
    printf("Enter the name of the item to remove: ");
    getchar(); // 清除缓冲区
    fgets(name, sizeof(name), stdin);
    strtok(name, "\n"); // 移除换行符

    for (int i = 0; i < itemCount; i++) 
    {
        if (strcmp(inventory[i].name, name) == 0)
        {
            // 将后续元素前移覆盖要移除的元素
            for (int j = i; j < itemCount - 1; j++)
            {
                inventory[j] = inventory[j + 1];
            }
            itemCount--;
            printf("Item removed successfully!\n");
            return;
        }
    }

    printf("Item not found.\n");
}
