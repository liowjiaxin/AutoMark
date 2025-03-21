#include <stdio.h>
#include <string.h>
#define MAX_ITEMS 100

typedef struct
{
    char name[100];
    char category[50];
    int quantity;
    float price;
    int inStock; // 1 for in stock & 0 for out of stock
} GroceryItem;

GroceryItem inventory[MAX_ITEMS];
int itemCount = 0;

void addGroceryItem()
{
    if (itemCount >= MAX_ITEMS)
    {
        printf("Inventory full. Cannot add more items.\n");
        return;
    }

    GroceryItem item;
    printf("Enter item name: ");
    scanf(" %[^\n]", item.name);
    printf("Enter category: ");
    scanf(" %[^\n]", item.category);
    printf("Enter quantity: ");
    scanf("%d", &item.quantity);
    printf("Enter price: ");
    scanf("%f", &item.price);
    item.inStock = item.quantity > 0 ? 1 : 0;

    inventory[itemCount++] = item;
    printf("Item added successfully.\n");
}

void listGroceryItems()
{
    if (itemCount == 0)
    {
        printf("No items in inventory.\n");
        return;
    }

    printf("\nInventory List:\n");
    for (int i = 0; i < itemCount; i++)
    {
        printf("Item %d:\n", i + 1);
        printf("Name: %s\n", inventory[i].name);
        printf("Category: %s\n", inventory[i].category);
        printf("Quantity: %d\n", inventory[i].quantity);
        printf("Price: %.2f\n", inventory[i].price);
        printf("Status: %s\n", inventory[i].inStock ? "In Stock" : "Out of Stock");
        printf("\n");
    }
}

void updateQuantity()
{
    char name[100];
    printf("Enter the name of the item to update quantity: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < itemCount; i++)
    {
        if (strcmp(inventory[i].name, name) == 0)
        {
            printf("Current quantity: %d\n", inventory[i].quantity);
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            inventory[i].inStock = inventory[i].quantity > 0 ? 1 : 0;
            printf("Quantity updated successfully.\n");
            return;
        }
    }
    printf("Item not found.\n");
}

void removeGroceryItem()
{
    char name[100];
    printf("Enter the name of the item to remove: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < itemCount; i++)
    {
        if (strcmp(inventory[i].name, name) == 0)
        {
            for (int j = i; j < itemCount - 1; j++)
            {
                inventory[j] = inventory[j + 1];
            }
            itemCount--;
            printf("Item removed successfully.\n");
            return;
        }
    }
    printf("Item not found.\n");
}

int main()
{
    int choice;
    do
    {
        printf("\nMenu:\n");
        printf("1. Add Grocery Item\n");
        printf("2. List Grocery Items\n");
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
            printf("Exiting\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}