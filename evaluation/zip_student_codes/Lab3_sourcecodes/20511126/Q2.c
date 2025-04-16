#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// defining the Grocery struct
typedef struct
{
    char name[100];
    char category[50];
    int quantity;
    float price;
} Grocery;

// defining the AvailabilityStatus struct
typedef struct
{
    bool instock;    // true if the item is in stock
    bool notinstock; // opposite of instock
} AvailabilityStatus;

// defining the GroceryInventory struct
typedef struct
{
    Grocery items[100];                   // array of grocery items
    AvailabilityStatus availability[100]; // array of availability statuses
    int itemCount;                        // count of total grocery items
} GroceryInventory;

// function declarations
void addItem(GroceryInventory *inventory);
void listItems(const GroceryInventory *inventory);
void updateQuantity(GroceryInventory *inventory);
void removeItem(GroceryInventory *inventory);

int main()
{
    GroceryInventory inventory = {.itemCount = 0};
    int choice;

    do
    {
        printf("\nGrocery Inventory Management System:\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove a Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // remove newline left by scanf

        switch (choice)
        {
        case 1:
            addItem(&inventory);
            break;
        case 2:
            listItems(&inventory);
            break;
        case 3:
            updateQuantity(&inventory);
            break;
        case 4:
            removeItem(&inventory);
            break;
        case 5:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// function to add a grocery item to the inventory
void addItem(GroceryInventory *inventory)
{
    if (inventory->itemCount > 100)
    {
        printf("Inventory is full, cannot add more items.\n");
        return;
    }

    Grocery *item = &inventory->items[inventory->itemCount];
    AvailabilityStatus *status = &inventory->availability[inventory->itemCount];

    printf("Enter item name: ");
    fgets(item->name, sizeof(item->name), stdin);
    item->name[strcspn(item->name, "\n")] = '\0'; // remove trailing newline

    printf("Enter category: ");
    fgets(item->category, sizeof(item->category), stdin);
    item->category[strcspn(item->category, "\n")] = '\0'; // remove trailing newline

    printf("Enter quantity: ");
    scanf("%d", &item->quantity);
    getchar(); // remove newline

    printf("Enter price: ");
    scanf("%f", &item->price);
    getchar(); // remove newline

    // uppdate availability
    status->instock = (item->quantity > 0);
    status->notinstock = !status->instock;

    inventory->itemCount++;
    printf("Item added successfully.\n");
}

// function to list all grocery items in the inventory
void listItems(const GroceryInventory *inventory)
{
    if (inventory->itemCount == 0)
    {
        printf("No items in the inventory.\n");
        return;
    }
    printf("\n");
    for (int i = 0; i < inventory->itemCount; i++) // for loop to print all items pointed by inventory
    {
        const Grocery *item = &inventory->items[i];
        const AvailabilityStatus *status = &inventory->availability[i];

        printf("  Name: %s\n", item->name);
        printf("  Category: %s\n", item->category);
        printf("  Quantity: %d\n", item->quantity);
        printf("  Price: $%.2f\n", item->price);
        printf("  Status: %s\n", status->instock ? "In Stock" : "Out of Stock");
    }
}

// function to update the quantity of a grocery item
void updateQuantity(GroceryInventory *inventory)
{
    char name[100];
    printf("Enter the name of the item to update quantity: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // remove trailing newline

    for (int i = 0; i < inventory->itemCount; i++)
    {
        if (strcmp(inventory->items[i].name, name) == 0) // if the item name pointed at my inventory is the same as user input, ask for new quantity
        {
            printf("Enter new quantity: ");
            scanf("%d", &inventory->items[i].quantity); // assign new quantity to the item
            getchar();                                  // remove newline

            // update availability status
            inventory->availability[i].instock = (inventory->items[i].quantity > 0);
            inventory->availability[i].notinstock = !inventory->availability[i].instock;

            printf("Quantity updated successfully.\n");
            return;
        }
    }
    printf("Item not found in the inventory.\n"); // error if item is not found in the array
}

// function to remove a grocery item from the inventory
void removeItem(GroceryInventory *inventory)
{
    char name[100];
    printf("Enter the name of the item to remove: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // remove trailing newline

    for (int i = 0; i < inventory->itemCount; i++)
    {
        if (strcmp(inventory->items[i].name, name) == 0)
        {
            for (int j = i; j < inventory->itemCount - 1; j++) // shift all items after the removed item one step forward
            {
                inventory->items[j] = inventory->items[j + 1];
                inventory->availability[j] = inventory->availability[j + 1];
            }
            inventory->itemCount--; // decrease itemCount
            printf("Item removed successfully.\n");
            return;
        }
    }
    printf("Item not found in the inventory.\n");
}