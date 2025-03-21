#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 100
#define MAX_CATEGORY_LEN 50

// Struct for grocery item
typedef struct {
    char name[MAX_NAME_LEN];
    char category[MAX_CATEGORY_LEN];
    int quantity;
    float price;
} GroceryItem;

// Struct for availability status
typedef struct {
    bool inStock;
    bool outOfStock;
} AvailabilityStatus;

// Struct for grocery inventory
typedef struct {
    GroceryItem items[MAX_ITEMS];
    AvailabilityStatus status[MAX_ITEMS];
    int itemCount;
} GroceryInventory;

// Function prototypes
void addGroceryItem(GroceryInventory *inventory);
void listGroceryItems(const GroceryInventory *inventory);
void updateQuantity(GroceryInventory *inventory);
void removeGroceryItem(GroceryInventory *inventory);

//main function
int main() {
    GroceryInventory inventory = { .itemCount = 0 };
    int choice;

    do {
        printf("\nGrocery Inventory Management System\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character after input

        switch (choice) {
            case 1:
                addGroceryItem(&inventory);
                break;
            case 2:
                listGroceryItems(&inventory);
                break;
            case 3:
                updateQuantity(&inventory);
                break;
            case 4:
                removeGroceryItem(&inventory);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    return 0;
}

//add a grocery item
void addGroceryItem(GroceryInventory *inventory) {
    if (inventory->itemCount >= MAX_ITEMS) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    GroceryItem *newItem = &inventory->items[inventory->itemCount];
    AvailabilityStatus *newStatus = &inventory->status[inventory->itemCount];

    printf("Enter item name: ");
    fgets(newItem->name, MAX_NAME_LEN, stdin);
    newItem->name[strcspn(newItem->name, "\n")] = '\0';

    printf("Enter category: ");
    fgets(newItem->category, MAX_CATEGORY_LEN, stdin);
    newItem->category[strcspn(newItem->category, "\n")] = '\0';

    printf("Enter quantity: ");
    scanf("%d", &newItem->quantity);

    printf("Enter price: ");
    scanf("%f", &newItem->price);
    getchar();

    // Update availability status
    newStatus->inStock = (newItem->quantity > 0);
    newStatus->outOfStock = (newItem->quantity <= 0);

    inventory->itemCount++;
    printf("Grocery item added successfully!\n");
}

//list all grocery items
void listGroceryItems(const GroceryInventory *inventory) {
    if (inventory->itemCount == 0) {
        printf("No grocery items in the inventory.\n");
        return;
    }

    printf("\nGrocery Items:\n");
    for (int i = 0; i < inventory->itemCount; i++) {
        const GroceryItem *item = &inventory->items[i];
        const AvailabilityStatus *status = &inventory->status[i];

        printf("Name: %s\n", item->name);
        printf("Category: %s\n", item->category);
        printf("Quantity: %d\n", item->quantity);
        printf("Price: $%.2f\n", item->price);
        printf("Availability: %s\n", status->inStock ? "In Stock" : "Out of Stock");
    }
}

//update quantity
void updateQuantity(GroceryInventory *inventory) {
    char name[MAX_NAME_LEN];
    printf("Enter the name of the grocery item to update quantity: ");
    fgets(name, MAX_NAME_LEN, stdin);
    name[strcspn(name, "\n")] = '\0';

    for (int i = 0; i < inventory->itemCount; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            printf("Enter new quantity for %s: ", name);
            scanf("%d", &inventory->items[i].quantity);
            getchar();

            // Update availability status
            inventory->status[i].inStock = (inventory->items[i].quantity > 0);
            inventory->status[i].outOfStock = (inventory->items[i].quantity <= 0);

            printf("Quantity updated successfully!\n");
            return;
        }
    }
    printf("Item not found.\n");
}

//remove a grocery item
void removeGroceryItem(GroceryInventory *inventory) {
    char name[MAX_NAME_LEN];
    printf("Enter the name of the grocery item to remove: ");
    fgets(name, MAX_NAME_LEN, stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove newline

    for (int i = 0; i < inventory->itemCount; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            // Shift items to remove the selected item
            for (int j = i; j < inventory->itemCount - 1; j++) {
                inventory->items[j] = inventory->items[j + 1];
                inventory->status[j] = inventory->status[j + 1];
            }
            inventory->itemCount--;
            printf("Grocery item '%s' removed successfully.\n", name);
            return;
        }
    }
    printf("Item not found.\n");
}

