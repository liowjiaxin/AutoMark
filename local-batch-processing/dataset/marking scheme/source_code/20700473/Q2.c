/**
 * @file Q2.c
 * @brief This C program manage grocery item information and item availability.
 *
 * The program menu runs in a loop, allowing users to select different actions until
 * they choose to exit.
 *
 * @author Yichen Si
 * @date 2024-12-11
 * @note code is formated by vscode
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_NAME_LEN (100)
#define MAX_CATEGORY_LEN (50)
#define MAX_ITEM_LEN (100)

typedef struct
{
    char name[MAX_NAME_LEN];
    char category[MAX_CATEGORY_LEN];
    int quantity;
    float price;
    bool status;    // availability of the item (true if in stock)
    bool used_slot; // flag to check if the slot is used, total MAX_ITEM_LEN slots
} grocery_item;

typedef struct
{
    grocery_item item[MAX_ITEM_LEN];
    int item_count;
} grocery_inventory;

grocery_inventory inventory = {0}; // initialize inventory

static void add_grocery_item(void)
{
    grocery_item newitem;

    // clear the input buffer
    while (getchar() != '\n')
        ;

    printf("Enter Item Name: ");
    fgets(newitem.name, MAX_NAME_LEN, stdin);
    strtok(newitem.name, "\n");

    printf("Enter Category: ");
    fgets(newitem.category, MAX_CATEGORY_LEN, stdin);
    strtok(newitem.category, "\n");

    // read the item quantity and validate input
    while (1)
    {
        printf("Enter Quantity: ");
        if (scanf("%d", &newitem.quantity) != 1)
        {
            printf("Error: quantitiy must be numbers. Please enter again.\n");
            while (getchar() != '\n') // clear buffer to avoid messing up next input
                ;
            continue;
        }
        break;
    }

    while (getchar() != '\n')
        ;

    while (1)
    {
        printf("Enter Pirce: ");
        if (scanf("%f", &newitem.price) != 1)
        {
            printf("Error: price must be numbers. Please enter again.\n");
            while (getchar() != '\n')
                ;
            continue;
        }
        break;
    }

    while (getchar() != '\n')
        ;

    if (newitem.quantity > 0)
    {
        newitem.status = true;
    }
    else
    {
        newitem.status = false;
    }

    // find an empty slot and add the new item
    for (int i = 0; i < MAX_ITEM_LEN; i++)
    {
        if (inventory.item[i].used_slot == false)
        {
            inventory.item[i] = newitem;
            inventory.item[i].used_slot = true;
            inventory.item_count++;
            printf("Grocery item added successfully!");
            return;
        }
    }
    printf("Error: the maximum number of inventory is %d.\n", MAX_ITEM_LEN);
}

static void list_grocery_item(void)
{
    int item = 0;
    for (int i = 0; i < MAX_ITEM_LEN; i++)
    {
        if (inventory.item[i].used_slot == true)
        {
            item = 1;
            printf("Name: %s\n", inventory.item[i].name);
            printf("Category: %s\n", inventory.item[i].category);
            printf("Quantity: %d\n", inventory.item[i].quantity);
            printf("Price: %.2f\n", inventory.item[i].price);
            printf("Status: %s\n", inventory.item[i].status ? "In Stock" : "Out of Stock");
        }
    }
    if (item == 0)
    {
        printf("No grocery items in the inventory.\n");
    }
}

static void update_grocery_item(void)
{
    char name[MAX_NAME_LEN];

    while (getchar() != '\n')
        ;

    printf("Enter name of the grocery item to update quantity: ");
    fgets(name, MAX_NAME_LEN, stdin);
    strtok(name, "\n");

    for (int i = 0; i < MAX_ITEM_LEN; i++)
    {
        if ((inventory.item[i].used_slot == true) && strcmp(inventory.item[i].name, name) == 0)
        {
            printf("Enter new quantity for %s: ", name);
            scanf("%d", &inventory.item[i].quantity);
            while (getchar() != '\n')
                ;

            if (inventory.item[i].quantity > 0)
            {
                inventory.item[i].status = true;
            }
            else
            {
                inventory.item[i].status = false;
            }

            printf("Quantity updated successfully!\n");
            return;
        }
    }
    printf("Error: there is no such item.\n");
}

static void remove_grocery_item(void)
{
    char name[MAX_NAME_LEN];
    int item = 0;

    while (getchar() != '\n')
        ;

    printf("Enter name of the grocery item to remove: ");
    fgets(name, MAX_NAME_LEN, stdin);
    strtok(name, "\n");

    for (int i = 0; i < MAX_ITEM_LEN; i++)
    {
        if ((inventory.item[i].used_slot == true) && strcmp(inventory.item[i].name, name) == 0)
        {
            item = 1;
            inventory.item[i].used_slot = false;
            printf("Grocery item '%s' removed successfully!\n", inventory.item[i].name);
            inventory.item_count--;
            break;
        }
    }
    if (item == 0)
    {
        printf("Error: there is no such item\n");
    }
}

int main(void)
{
    int choice;

    while (1)
    {
        printf("\nGrocery Inventory Management System\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Error: input must be number.\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        switch (choice)
        {
        case 1:
            add_grocery_item();
            break;
        case 2:
            list_grocery_item();
            break;
        case 3:
            update_grocery_item();
            break;
        case 4:
            remove_grocery_item();
            break;
        case 5:
            return 0;
        default:
            printf("Error: invalid choice. Please try again.\n");
        }
    }
}
