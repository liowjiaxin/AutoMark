#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 100
#define MAX_CATEGORY_LEN 50

// Struct to hold grocery item information
typedef struct {
    char name[MAX_NAME_LEN];
    char category[MAX_CATEGORY_LEN];
    int quantity;
    float price;
} GroceryItem;

// Struct to hold availability status
typedef struct {
    bool inStock;
    bool outOfStock;
} AvailabilityStatus;

// Struct to manage the inventory
typedef struct {
    GroceryItem items[MAX_ITEMS];
    AvailabilityStatus status[MAX_ITEMS];
    int count;
} GroceryInventory;

// Function prototypes
void addItem(GroceryInventory* inventory);
void listItems(GroceryInventory* inventory);
void updateQuantity(GroceryInventory* inventory);
void removeItem(GroceryInventory* inventory);

int main() {
    GroceryInventory inventory = {.count = 0};
    int choice;

    do {
        printf("\nGrocery Inventory Management System:\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
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
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to add a grocery item
void addItem(GroceryInventory* inventory) {
    if (inventory->count >= MAX_ITEMS) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    GroceryItem* item = &inventory->items[inventory->count];
    AvailabilityStatus* status = &inventory->status[inventory->count];

    printf("Enter item name: ");
    fgets(item->name, MAX_NAME_LEN, stdin);
    item->name[strcspn(item->name, "\n")] = '\0'; // Remove newline character

    printf("Enter category: ");
    fgets(item->category, MAX_CATEGORY_LEN, stdin);
    item->category[strcspn(item->category, "\n")] = '\0';

    printf("Enter quantity: ");
    scanf("%d", &item->quantity);

    printf("Enter price: ");
    scanf("%f", &item->price);

    status->inStock = item->quantity > 0;
    status->outOfStock = !status->inStock;

    inventory->count++;
    printf("Grocery item added successfully!\n");
}

// Function to list all grocery items
void listItems(GroceryInventory* inventory) {
    if (inventory->count == 0) {
        printf("No grocery items in the inventory.\n");
        return;
    }

    
    for (int i = 0; i < inventory->count; i++) {
        GroceryItem* item = &inventory->items[i];
        AvailabilityStatus* status = &inventory->status[i];

        
        printf("Name: %s\n", item->name);
        printf("Category: %s\n", item->category);
        printf("Quantity: %d\n", item->quantity);
        printf("Price: %.2f\n", item->price);
        printf("Status: %s\n", status->inStock ? "In Stock" : "Out of Stock");
    }
}

// Function to update the quantity of a grocery item
void updateQuantity(GroceryInventory* inventory) {
    if (inventory->count == 0) {
        printf("No items in inventory to update.\n");
        return;
    }

    char name[MAX_NAME_LEN];
    printf("Enter the name of the grocery item to update quantity: ");
    fgets(name, MAX_NAME_LEN, stdin);
    name[strcspn(name, "\n")] = '\0';

    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            printf("Enter new quantity for %s: ", name);
            scanf("%d", &inventory->items[i].quantity);

            inventory->status[i].inStock = inventory->items[i].quantity > 0;
            inventory->status[i].outOfStock = !inventory->status[i].inStock;

            printf("Quantity updated successfully!\n");
            return;
        }
    }

    printf("Item not found in inventory.\n");
}

// Function to remove a grocery item
void removeItem(GroceryInventory* inventory) {
    if (inventory->count == 0) {
        printf("No items in inventory to remove.\n");
        return;
    }

    char name[MAX_NAME_LEN];
    printf("Enter the name of the grocery item to remove: ");
    fgets(name, MAX_NAME_LEN, stdin);
    name[strcspn(name, "\n")] = '\0';

    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            
            for (int j = i; j < inventory->count - 1; j++) {
                inventory->items[j] = inventory->items[j + 1];
                inventory->status[j] = inventory->status[j + 1];
            }

            inventory->count--;
            printf("Grocery item '%s' removed successfully!\n", name);
            return;
        }
    }

    printf("Item not found in inventory.\n");
}
