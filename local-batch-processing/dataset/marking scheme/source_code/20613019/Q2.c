#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 100
#define CATEGORY_LENGTH 50

// Structure represent grocery item
typedef struct {
    char name[NAME_LENGTH];
    char category[CATEGORY_LENGTH];
    int quantity;
    float price;
} GroceryItem;

// Structure represent inventory
typedef struct {
    GroceryItem items[MAX_ITEMS];
    int itemCount;
} GroceryInventory;

// Function prototypes
void addItem(GroceryInventory *inventory);
void listItems(const GroceryInventory *inventory);
void updateQuantity(GroceryInventory *inventory);
void removeItem(GroceryInventory *inventory);
void displayMenu();

int main() {
    GroceryInventory inventory = { .itemCount = 0 };
    int choice;

    do {
        displayMenu();
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

// Display
void displayMenu() {
    printf("\nGrocery Inventory Management System\n");
    printf("1. Add Grocery Item\n");
    printf("2. List All Grocery Items\n");
    printf("3. Update Quantity\n");
    printf("4. Remove Grocery Item\n");
    printf("5. Exit\n");
}

// Add 
void addItem(GroceryInventory *inventory) {
    if (inventory->itemCount >= MAX_ITEMS) {
        printf("Inventory is full! Cannot add more items.\n");
        return;
    }

    GroceryItem *item = &inventory->items[inventory->itemCount];

    printf("Enter Item Name: ");
    fgets(item->name, NAME_LENGTH, stdin);
    item->name[strcspn(item->name, "\n")] = 0; 

    printf("Enter Category: ");
    fgets(item->category, CATEGORY_LENGTH, stdin);
    item->category[strcspn(item->category, "\n")] = 0;

    printf("Enter Quantity: ");
    scanf("%d", &item->quantity);

    printf("Enter Price: ");
    scanf("%f", &item->price);

    inventory->itemCount++;
    printf("Grocery item added successfully!\n");
}

// List 
void listItems(const GroceryInventory *inventory) {
    if (inventory->itemCount == 0) {
        printf("No grocery items in the inventory.\n");
        return;
    }

    for (int i = 0; i < inventory->itemCount; i++) {
        const GroceryItem *item = &inventory->items[i];
        printf("\nName: %s\n", item->name);
        printf("Category: %s\n", item->category);
        printf("Quantity: %d\n", item->quantity);
        printf("Price: %.2f\n", item->price);
        printf("Status: %s\n", item->quantity > 0 ? "In Stock" : "Out of Stock");
    }
}

// Update
void updateQuantity(GroceryInventory *inventory) {
    char name[NAME_LENGTH];
    printf("Enter name of the grocery item to update quantity: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; 

    for (int i = 0; i < inventory->itemCount; i++) {
        GroceryItem *item = &inventory->items[i];
        if (strcmp(item->name, name) == 0) {
            printf("Enter new quantity for %s: ", item->name);
            scanf("%d", &item->quantity);
            printf("Quantity updated successfully!\n");
            return;
        }
    }

    printf("Item not found in the inventory.\n");
}

// Remove
void removeItem(GroceryInventory *inventory) {
    char name[NAME_LENGTH];
    printf("Enter name of the grocery item to remove: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0;

    for (int i = 0; i < inventory->itemCount; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            for (int j = i; j < inventory->itemCount - 1; j++) {
                inventory->items[j] = inventory->items[j + 1];
            }
            inventory->itemCount--;
            printf("Grocery item '%s' removed successfully!\n", name);
            return;
        }
    }

    printf("Item not found in the inventory.\n");
}
