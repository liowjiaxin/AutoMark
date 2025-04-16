#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITEMS 100

// Define Color Codes
#define RESET_COLOR "\x1b[0m"
#define GREEN_COLOR "\x1b[32m"

// STRUCTURES:
//      Item
typedef struct
{
    char name[100];
    char category[50];
    int quantity;
    float price;
} GroceryItem;

//      Status
typedef struct
{
    bool inStock;
    bool outOfStock;
} AvailabilityStatus;

//      Inventory
typedef struct
{
    GroceryItem items[MAX_ITEMS];
    AvailabilityStatus status[MAX_ITEMS];
    int count;
} GroceryInventory;

// FUNCTIONS:
//      Add Items
void addGroceryItem(GroceryInventory *inventory)
{
    if (inventory->count >= MAX_ITEMS)
    {
        printf("Inventory full. Can't add more items.\n");
        return;
    }

    GroceryItem item;
    printf("Enter Item Name: ");
    fgets(item.name, 100, stdin);
    item.name[strcspn(item.name, "\n")] = '\0';             // Remove newline character (\n) that will be automatically added when using "fgets"

    printf("Enter Category: ");
    fgets(item.category, 50, stdin);
    item.category[strcspn(item.category, "\n")] = '\0';     // Remove newline character (\n) that will be automatically added when using "fgets"

    printf("Enter Quantity: ");
    scanf("%d", &item.quantity);

    printf("Enter Price: ");
    scanf("%f", &item.price);
    getchar();                                              // Clear newline character (\n)

    inventory->items[inventory->count] = item;
    inventory->status[inventory->count].inStock = item.quantity > 0;
    inventory->status[inventory->count].outOfStock = item.quantity == 0;

    inventory->count++;
    printf("Grocery item added successfully!\n");
}

//      Display All Items
void listAllGroceryItems(const GroceryInventory *inventory)
{
    if (inventory->count == 0)
    {
        printf("No grocery items in the inventory.\n");
        return;
    }

    for (int i = 0; i < inventory->count; i++)
    {
        printf("Name: %s\n", inventory->items[i].name);
        printf(GREEN_COLOR "Category: %s\n" RESET_COLOR, inventory->items[i].category);
        printf("Quantity: %d\n", inventory->items[i].quantity);
        printf("Price: %.2f\n", inventory->items[i].price);
        printf("Status: %s\n\n", 
               inventory->status[i].inStock ? "In Stock" : "Out of Stock");
    }
}

//      Update Item Quantity
void updateQuantity(GroceryInventory *inventory)
{
    if (inventory->count == 0)
    {
        printf("No grocery items in the inventory to update.\n");
        return;
    }

    char name[100];
    printf("Enter name of the grocery item to update quantity: ");
    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = '\0';

    for (int i = 0; i < inventory->count; i++)
    {
        if (strcmp(inventory->items[i].name, name) == 0)
        {
            printf("Enter new quantity for %s: ", name);
            scanf("%d", &inventory->items[i].quantity);
            getchar();                                              // Clear newline character (\n)

            inventory->status[i].inStock = inventory->items[i].quantity > 0;
            inventory->status[i].outOfStock = inventory->items[i].quantity == 0;

            printf("Quantity updated successfully!\n");
            return;
        }
    }

    printf("Grocery item '%s' not found in the inventory.\n", name);
}

//      Remove Item
void removeGroceryItem(GroceryInventory *inventory)
{
    if (inventory->count == 0)
    {
        printf("No grocery items in the inventory to remove.\n");
        return;
    }

    char name[100];
    printf("Enter name of the grocery item to remove: ");
    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = '\0';

    for (int i = 0; i < inventory->count; i++)
    {
        if (strcmp(inventory->items[i].name, name) == 0)
        {
            for (int j = i; j < inventory->count - 1; j++)
            {
                inventory->items[j] = inventory->items[j + 1];
                inventory->status[j] = inventory->status[j + 1];
            }
            inventory->count--;
            printf("Grocery item '%s' removed successfully!\n", name);
            return;
        }
    }

    printf("Grocery item '%s' not found in the inventory.\n", name);
}

// MAIN PROGRAM ----------------------------------------------------------------------------------------------------------------------
int main()
{
    GroceryInventory inventory = {.count = 0};
    int choice;

    // Main Menu Loop
    while(1)
    {
        puts("");
        printf("Grocery Inventory Management System\n");
        printf("1. Add Grocery Items\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();                                              // Clear newline character (\n)

        switch (choice)
        {
            case 1:
                addGroceryItem(&inventory);
                break;

            case 2:
                listAllGroceryItems(&inventory);
                break;

            case 3:
                updateQuantity(&inventory);
                break;

            case 4:
                removeGroceryItem(&inventory);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("INVALID. Try again.\n");
        }

        if (choice == 5)
        {
            break;
        }
    }

    return 0;
}